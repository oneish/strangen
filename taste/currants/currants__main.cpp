#include "../../sauce/strange/strange.h"
#include <stlab/concurrency/concurrency.hpp>
#include <stlab/pre_exit.hpp>
#include <iostream>
#include <functional>
#include <utility>
#include <chrono>
#include <tuple>
#include <thread>

struct sum
{
    stlab::process_state _state = stlab::process_state::await;
    int _sum = 0;
    void await(int n) { _sum += n; }
    int yield() { _state = stlab::process_state::await; return _sum; }
    void close() { _state = stlab::process_state::yield; }
    auto state() const { return std::make_pair(_state, std::chrono::milliseconds(0)); }
};

auto get_fun() -> std::function<auto (std::tuple<int, int, int> v) -> void>
{
    return [](std::tuple<int, int, int> v) {
        std::cout << "receive zip:" << std::get<0>(v) << "," << std::get<1>(v) << "," << std::get<2>(v) << '\n';
    };
}

template <typename Inputs, typename Outputs>
struct processor
{
private:
    template <typename Tuple>
    struct _tuple_senders;

    template <typename ... Elements>
    struct _tuple_senders<std::tuple<Elements ...>>
    {
        using type = std::tuple<stlab::sender<Elements> ...>;
    };

    template <typename Tuple>
    struct _tuple_receivers;

    template <typename ... Elements>
    struct _tuple_receivers<std::tuple<Elements ...>>
    {
        using type = std::tuple<stlab::receiver<Elements> ...>;
    };

public:
    using Receivers = typename _tuple_receivers<Inputs>::type;
    using Senders = typename _tuple_senders<Outputs>::type;

    auto receivers() const -> Receivers const &
    {
        return _receivers;
    }

    auto senders() const -> Senders const &
    {
        return _senders;
    }

    auto receivers() -> Receivers &
    {
        return _receivers;
    }

    auto senders() -> Senders &
    {
        return _senders;
    }

    auto on_your_marks() -> void
    {
        std::apply([this](auto && ... recv) {
            auto hold = stlab::zip(stlab::default_executor,
                recv ...) | [this](Inputs inputs) {
                    go(inputs);
                };
            _hold = strange::any::_make<decltype(hold)>(std::move(hold));
        }, _receivers);
    }

    auto get_set() -> void
    {
        std::apply([](auto && ... recv) {
            ((recv.set_ready()), ...);
        }, _receivers);
    }

    auto go(Inputs inputs) -> void
    {
        std::cout << "go\n";
        std::apply([](auto && ... send) {
            ((send(strange::any{}), std::cout << "sent\n"), ...);
        }, _senders);
    }

private:
    Senders _senders;
    Receivers _receivers;
    strange::any _hold;
};

int main()
{
    std::cout << "currants\n";
    {   // single channel
        stlab::sender<int> send;
        stlab::receiver<int> receive;
        std::tie(send, receive) = stlab::channel<int>(stlab::default_executor);
        auto discard = receive | [](int x) {
            std::cout << "received: " << x << "\n";
        };
        std::cout << "receive.ready(): " << receive.ready() << "\n";
        receive.set_ready();
        std::cout << "receive.ready(): " << receive.ready() << "\n";
        send(42);
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    {   // non-std coroutine
        stlab::sender<int> send;
        stlab::receiver<int> receive;
        std::tie(send, receive) = stlab::channel<int>(stlab::default_executor);
        auto hold = receive
            | sum()
            | [](int x){ std::cout << x << '\n'; };
        receive.set_ready();
        send(1);
        send(2);
        send(3);
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        /*prints 1 3 6*/
    }
    {   // split
        stlab::sender<int> send1;
        stlab::receiver<int> receive1;
        std::tie(send1, receive1) = stlab::channel<int>(stlab::default_executor);
        auto hold1a = receive1
            | [](int x){ std::cout << "receive1a:" << x << '\n'; };
        auto hold1b = receive1
            | [](int x){ std::cout << "receive1b:" << x << '\n'; };
        receive1.set_ready();
        send1(1);
        send1(2);
        send1(3);
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        /*prints 1 1 2 2 3 3*/
    }
    {   // split & join
        stlab::sender<int> send1;
        stlab::receiver<int> receive1;
        std::tie(send1, receive1) = stlab::channel<int>(stlab::default_executor);
        stlab::sender<int> send2;
        stlab::receiver<int> receive2;
        std::tie(send2, receive2) = stlab::channel<int>(stlab::default_executor);
        stlab::sender<int> send3;
        stlab::receiver<int> receive3;
        std::tie(send3, receive3) = stlab::channel<int>(stlab::default_executor);
        auto hold1a = receive1
            | [&send2](int x){ send2(x*10+2); };
        auto hold1b = receive1
            | [&send3](int x){ send3(x*10+3); };
        auto zipped = stlab::zip(stlab::default_executor,
                receive2,
                receive3)
            | [](std::tuple<int, int> v) {
                std::cout << "receive zip:" << std::get<0>(v) << "," << std::get<1>(v) << '\n';
            };

        receive1.set_ready();
        receive2.set_ready();
        receive3.set_ready();
        send1(1);
        send1(2);
        send1(3);
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        /*prints 12,13 22,23 32,33*/
    }
    {   // three-way split & join
        stlab::sender<int> send1;
        stlab::receiver<int> receive1;
        std::tie(send1, receive1) = stlab::channel<int>(stlab::default_executor);
        stlab::sender<int> send2;
        stlab::receiver<int> receive2;
        std::tie(send2, receive2) = stlab::channel<int>(stlab::default_executor);
        stlab::sender<int> send3;
        stlab::receiver<int> receive3;
        std::tie(send3, receive3) = stlab::channel<int>(stlab::default_executor);
        stlab::sender<int> send4;
        stlab::receiver<int> receive4;
        std::tie(send4, receive4) = stlab::channel<int>(stlab::default_executor);
        auto hold1a = receive1
            | [&send2](int x){ send2(x*10+2); };
        auto hold1b = receive1
            | [&send3](int x){ send3(x*10+3); };
        auto hold1c = receive1
            | [&send4](int x){ send4(x*10+4); };
        auto zipped = stlab::zip(stlab::default_executor,
                receive2,
                receive3,
                receive4)
            | get_fun();

        receive1.set_ready();
        receive2.set_ready();
        receive3.set_ready();
        receive4.set_ready();
        send1(1);
        send1(2);
        send1(3);
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        /*prints 12,13,14 22,23,24 32,33,34*/
    }
    {   // processors
        processor<std::tuple<strange::any>,
            std::tuple<strange::any, strange::any, strange::any>>
            proc1;
        processor<std::tuple<strange::any, strange::any, strange::any>,
            std::tuple<strange::any>>
            proc2;
        stlab::sender<strange::any> send;
        stlab::receiver<strange::any> receiver;
        std::tie(send, std::get<0>(proc1.receivers())) = stlab::channel<strange::any>(stlab::default_executor);
        std::tie(std::get<0>(proc1.senders()), std::get<0>(proc2.receivers())) = stlab::channel<strange::any>(stlab::default_executor);
        std::tie(std::get<1>(proc1.senders()), std::get<1>(proc2.receivers())) = stlab::channel<strange::any>(stlab::default_executor);
        std::tie(std::get<2>(proc1.senders()), std::get<2>(proc2.receivers())) = stlab::channel<strange::any>(stlab::default_executor);
        std::tie(std::get<0>(proc2.senders()), receiver) = stlab::channel<strange::any>(stlab::default_executor);
        proc1.on_your_marks();
        proc2.on_your_marks();
        auto hold = receiver
            | [](strange::any x) {
                std::cout << "received\n";
            };
        proc1.get_set();
        proc2.get_set();
        receiver.set_ready();
        send(strange::any{});
        send(strange::any{});
        send(strange::any{});
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "before pre_exit()\n";
    stlab::pre_exit();
    std::cout << "after pre_exit()\n";
    return 0;
}
