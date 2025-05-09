#include "../../sauce/strange/strange.h"
#include "../../sauce/strange/implementation/graph/strange__implementation__graph.h"
#include <iostream>
#include <chrono>

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

int main()
{
    std::cout << "currants\n";
    {   // single channel
        stlab::sender<int> send;
        stlab::receiver<int> receive;
        std::tie(send, receive) = stlab::channel<int>(stlab::high_executor);
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
        std::tie(send, receive) = stlab::channel<int>(stlab::high_executor);
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
        std::tie(send1, receive1) = stlab::channel<int>(stlab::high_executor);
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
        std::tie(send1, receive1) = stlab::channel<int>(stlab::high_executor);
        stlab::sender<int> send2;
        stlab::receiver<int> receive2;
        std::tie(send2, receive2) = stlab::channel<int>(stlab::high_executor);
        stlab::sender<int> send3;
        stlab::receiver<int> receive3;
        std::tie(send3, receive3) = stlab::channel<int>(stlab::high_executor);
        auto hold1a = receive1
            | [&send2](int x){ send2(x*10+2); };
        auto hold1b = receive1
            | [&send3](int x){ send3(x*10+3); };
        auto zipped = stlab::zip(stlab::high_executor,
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
        std::tie(send1, receive1) = stlab::channel<int>(stlab::high_executor);
        stlab::sender<int> send2;
        stlab::receiver<int> receive2;
        std::tie(send2, receive2) = stlab::channel<int>(stlab::high_executor);
        stlab::sender<int> send3;
        stlab::receiver<int> receive3;
        std::tie(send3, receive3) = stlab::channel<int>(stlab::high_executor);
        stlab::sender<int> send4;
        stlab::receiver<int> receive4;
        std::tie(send4, receive4) = stlab::channel<int>(stlab::high_executor);
        auto hold1a = receive1
            | [&send2](int x){ send2(x*10+2); };
        auto hold1b = receive1
            | [&send3](int x){ send3(x*10+3); };
        auto hold1c = receive1
            | [&send4](int x){ send4(x*10+4); };
        auto zipped = stlab::zip(stlab::high_executor,
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
        std::function<auto (std::vector<std::string>) -> std::vector<std::string>> fun = [](std::vector<std::string> inputs) {
            std::string concat = ":";
            for (auto input : inputs)
            {
                concat += input;
            }
            concat += ".";
            std::cout << "process " << concat << "\n";
            return std::vector<std::string>(3, concat);
        };
        strange::implementation::processor<std::string> proc0{0, 1, fun};
        strange::implementation::processor<std::string> proc1{1, 3, fun};
        strange::implementation::processor<std::string> proc2{3, 1, fun};
        strange::implementation::processor<std::string> proc3{1, 0, fun};
        proc0.to(proc1, 0, 0);
        //proc1.to(proc2, 0, 0);
        proc2.from(proc1, 1, 1);
        //proc2.from(proc1, 2, 2);
        proc2.to(proc3, 0, 0);
        proc0.on_your_marks();
        proc1.on_your_marks();
        proc2.on_your_marks();
        proc3.on_your_marks();
        proc0.get_set();
        proc1.get_set();
        proc2.get_set();
        proc3.get_set();
        proc0.go();
        proc0.go();
        proc0.go();
        std::cout << "sleep\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    {   // graph
        std::vector<std::unique_ptr<strange::implementation::processor<std::string>>> subsubprocs;
        subsubprocs.push_back(std::make_unique<strange::implementation::processor<std::string>>(1, 1, [](std::vector<std::string> inputs){ return inputs; })); // output [0] "A"
        subsubprocs.push_back(std::make_unique<strange::implementation::processor<std::string>>(1, 1, [](std::vector<std::string> inputs){ return inputs; })); // input [1] "B"
        subsubprocs[1]->to(*subsubprocs[0], 0, 0); // B0 -> A0
        std::vector<std::unique_ptr<strange::implementation::processor<std::string>>> subprocs;
        subprocs.push_back(std::make_unique<strange::implementation::processor<std::string>>(3, 0)); // output [0] "C"
        subprocs.push_back(std::make_unique<strange::implementation::processor<std::string>>(0, 3)); // input [1] "D"
        subprocs.push_back(std::make_unique<strange::implementation::processor<std::string>>(std::move(subsubprocs))); // [2] "E"
        subprocs.push_back(std::make_unique<strange::implementation::processor<std::string>>(1, 1, [](std::vector<std::string> inputs){ return inputs; })); // [3] "F"
        subprocs[1]->to(*subprocs[2], 0, 0); // D0 -> E0
        subprocs[0]->from(*subprocs[2], 0, 0); // C0 <- E0
        subprocs[1]->to(*subprocs[3], 1, 0); // D1 -> F0
        subprocs[0]->from(*subprocs[3], 1, 0); // C1 <- F0
        subprocs[1]->to(*subprocs[0], 2, 2); // D2 -> C2
        strange::implementation::processor<std::string> proc{std::move(subprocs)};
        proc.on_your_marks();
        proc.get_set();
        std::vector<std::string> inputs {"hello", "world", "!"};
        for (auto input : inputs)
        {
            auto outputs = proc(inputs);
            std::cout << "graph outputs: ";
            for (auto output : outputs)
            {
                std::cout << output << " ";
            }
            std::cout << "\n";
            std::swap(inputs[0], inputs[1]);
            std::swap(inputs[1], inputs[2]);
        }
        // no sleep
    }
    {   // strange processor
        auto proc = strange::processor<std::string>::_make<strange::implementation::thru_processor<std::string>>();
        auto proc_closure = proc.closure();
        proc_closure(std::vector<std::string>{"hello", "world", "!"});
    }
    {   // strange graph
        auto subgraph = strange::graph<std::string>::_make(); // "A"
        subgraph.ins() = 1; // "B"
        subgraph.outs() = 1; // "C"
        auto proc = subgraph.add_processor(strange::processor<std::string>::_make<strange::implementation::thru_processor<std::string>>()); // "D"
        subgraph.processors()[proc].ins() = 1;
        subgraph.processors()[proc].outs() = 1;

        auto conn = subgraph.add_connection(); // B0 -> D0
        subgraph.connections()[conn].from_id() = 1;
        subgraph.connections()[conn].from_out() = 0;
        subgraph.connections()[conn].to_id() = proc;
        subgraph.connections()[conn].to_in() = 0;
        conn = subgraph.add_connection(); // D0 -> C0
        subgraph.connections()[conn].from_id() = proc;
        subgraph.connections()[conn].from_out() = 0;
        subgraph.connections()[conn].to_id() = 0;
        subgraph.connections()[conn].to_in() = 0;

        auto graph = strange::graph<std::string>::_make(); // "E"
        graph.ins() = 3; // "F"
        graph.outs() = 3; // "G"
        auto sub = graph.add_processor(subgraph); // "A"
        proc = graph.add_processor(strange::processor<std::string>::_make<strange::implementation::thru_processor<std::string>>()); // "H"
        graph.processors()[proc].ins() = 1;
        graph.processors()[proc].outs() = 1;

        conn = graph.add_connection(); // F0 -> A0
        graph.connections()[conn].from_id() = 1;
        graph.connections()[conn].from_out() = 0;
        graph.connections()[conn].to_id() = sub;
        graph.connections()[conn].to_in() = 0;
        conn = graph.add_connection(); // A0 -> G0
        graph.connections()[conn].from_id() = sub;
        graph.connections()[conn].from_out() = 0;
        graph.connections()[conn].to_id() = 0;
        graph.connections()[conn].to_in() = 0;

        conn = graph.add_connection(); // F1 -> H0
        graph.connections()[conn].from_id() = 1;
        graph.connections()[conn].from_out() = 1;
        graph.connections()[conn].to_id() = proc;
        graph.connections()[conn].to_in() = 0;
        conn = graph.add_connection(); // H0 -> G1
        graph.connections()[conn].from_id() = proc;
        graph.connections()[conn].from_out() = 0;
        graph.connections()[conn].to_id() = 0;
        graph.connections()[conn].to_in() = 1;

        conn = graph.add_connection(); // F2 -> G2
        graph.connections()[conn].from_id() = 1;
        graph.connections()[conn].from_out() = 2;
        graph.connections()[conn].to_id() = 0;
        graph.connections()[conn].to_in() = 2;

        auto graph_closure = graph.closure();
        std::vector<std::string> inputs {"hello", "world", "!"};
        for (auto input : inputs)
        {
            auto outputs = graph_closure(inputs);
            std::cout << "strange graph outputs: ";
            for (auto output : outputs)
            {
                std::cout << output << " ";
            }
            std::cout << "\n";
            std::swap(inputs[0], inputs[1]);
            std::swap(inputs[1], inputs[2]);
        }
        // no sleep
    }
    std::cout << "before pre_exit()\n";
    stlab::pre_exit();
    std::cout << "after pre_exit()\n";
    return 0;
}
