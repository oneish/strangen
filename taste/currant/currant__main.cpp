#include <stlab/concurrency/concurrency.hpp>
#include <stlab/pre_exit.hpp>
#include <iostream>

struct sum
{
    stlab::process_state _state = stlab::process_state::await;
    int _sum = 0;
    void await(int n) { _sum += n; }
    int yield() { _state = stlab::process_state::await; return _sum; }
    void close() { _state = stlab::process_state::yield; }
    auto state() const { return std::make_pair(_state, std::chrono::milliseconds(0)); }
};

int main()
{
    std::cout << "currant\n";
    {
        stlab::sender<int> send;
        send(42);

        stlab::receiver<int> receive;
        std::cout << "receive.ready(): " << receive.ready() << "\n";
        receive.set_ready();
        std::cout << "receive.ready(): " << receive.ready() << "\n";

        auto chan = stlab::channel<int>(stlab::default_executor);
        send = chan.first;
        receive = chan.second;
        auto discard = receive | [](int x) {
            std::cout << "received: " << x << "\n";
        };
        std::cout << "receive.ready(): " << receive.ready() << "\n";
        receive.set_ready();
        std::cout << "receive.ready(): " << receive.ready() << "\n";
        send(42);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    {
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
        send.close();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        /*prints 1 3 6 6*/
    }
    std::cout << "before pre_exit()\n";
    stlab::pre_exit();
    std::cout << "after pre_exit()\n";
    return 0;
}
