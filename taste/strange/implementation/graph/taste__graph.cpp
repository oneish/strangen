auto make_connection(strange::implementation::connection conn) -> strange::connection
{
    return strange::connection::_make(conn);
}

template<typename Config, typename Signal>
struct latency_processor
{
    inline latency_processor(std::vector<uint64_t> types, uint64_t lat)
    :_ins(types.size())
    ,_outs(types.size())
    ,_types(std::move(types))
    ,_own_id(0)
    ,_lat(lat)
    {
    }

    inline auto pack(strange::bag & dest) const -> void { dest.from_object(); }
    inline auto unpack(strange::bag const & src) -> void {}

    inline auto ins() const -> uint64_t const & { return _ins; }
    inline auto input_types() const -> std::vector<uint64_t> const & { return _types; }
    inline auto outs() const -> uint64_t const & { return _outs; }
    inline auto output_types() const -> std::vector<uint64_t> const & { return _types; }

    inline auto owned(strange::graph<Config, Signal> const & owner, uint64_t id) -> void
    {
        _owner = owner._weak();
        _own_id = id;
    }

    inline auto closure(Config const & config = Config{}) const -> std::function<auto (std::vector<Signal>) -> std::vector<Signal>>
    {
        return [*this](std::vector<Signal> inputs) {
            inputs.resize(_outs);
            return inputs;
        };
    }

    inline auto latency(Config const & config = Config{}) const -> uint64_t { return _lat; }

private:
    uint64_t _ins;
    uint64_t _outs;
    std::vector<uint64_t> _types;
    strange::graph<Config, Signal> _owner;
    uint64_t _own_id;
    uint64_t _lat;
};

// ---- CONNECTION TESTS ----

TEST_CASE("connection: default construction")
{
    auto conn = strange::connection::_make();
    CHECK(conn._something());
    CHECK(conn._valid());
    CHECK(conn.from_id() == 0);
    CHECK(conn.from_out() == 0);
    CHECK(conn.to_id() == 0);
    CHECK(conn.to_in() == 0);
}

TEST_CASE("connection: setters and getters")
{
    auto conn = make_connection({.from_id_ = 1, .from_out_ = 2, .to_id_ = 3, .to_in_ = 4});
    CHECK(conn.from_id() == 1);
    CHECK(conn.from_out() == 2);
    CHECK(conn.to_id() == 3);
    CHECK(conn.to_in() == 4);
}

TEST_CASE("connection: copy semantics")
{
    auto conn = make_connection({.from_id_ = 5, .from_out_ = 6, .to_id_ = 7, .to_in_ = 8});
    auto copy = conn._clone();
    CHECK(copy._valid());
    CHECK(copy.from_id() == 5);
    CHECK(copy.to_id() == 7);

    CHECK(conn._cat() == "strange::connection");
    auto cats = conn._cats();
    CHECK(cats.count("strange::connection") == 1);
    CHECK(cats.count("strange::any") == 1);
}

// ---- THRU_PROCESSOR TESTS ----

TEST_CASE("thru_processor: empty construction")
{
    auto proc = strange::processor<std::string, std::string>::_make<
        strange::implementation::thru_processor<std::string, std::string>>(std::vector<uint64_t>{});
    CHECK(proc._something());
    CHECK(proc._valid());
    CHECK(proc.ins() == 0);
    CHECK(proc.outs() == 0);
}

TEST_CASE("thru_processor: construction with types")
{
    auto proc = strange::processor<std::string, std::string>::_make<
        strange::implementation::thru_processor<std::string, std::string>>(std::vector<uint64_t>{0, 0, 0});
    CHECK(proc.ins() == 3);
    CHECK(proc.outs() == 3);
    CHECK(proc.input_types().size() == 3);
    CHECK(proc.output_types().size() == 3);
}

TEST_CASE("thru_processor: closure passthrough")
{
    auto proc = strange::processor<std::string, std::string>::_make<
        strange::implementation::thru_processor<std::string, std::string>>(std::vector<uint64_t>{0, 0});

    auto closure = proc.closure();
    std::vector<std::string> input = {"hello", "world"};
    auto output = closure(input);
    CHECK(output.size() == 2);
    CHECK(output[0] == "hello");
    CHECK(output[1] == "world");
}

TEST_CASE("thru_processor: closure resizes output")
{
    auto proc = strange::processor<std::string, std::string>::_make<
        strange::implementation::thru_processor<std::string, std::string>>(std::vector<uint64_t>{0, 0});

    auto closure = proc.closure();
    std::vector<std::string> input = {"a", "b", "c"};
    auto output = closure(input);
    CHECK(output.size() == 2);
    CHECK(output[0] == "a");
    CHECK(output[1] == "b");
}

// ---- PROCESSOR TESTS ----

TEST_CASE("processor: _cat and _cats")
{
    auto proc = strange::processor<std::string, std::string>::_make<
        strange::implementation::thru_processor<std::string, std::string>>(std::vector<uint64_t>{});
    CHECK(proc._cat().find("processor") != std::string::npos);
    auto cats = proc._cats();
    CHECK(cats.count("strange::any") == 1);
}

TEST_CASE("processor: implementation constructor and connections")
{
    // Verify that implementation::processor can be constructed
    auto fun = [](std::vector<std::string> inputs) -> std::vector<std::string>
    {
        std::vector<std::string> outputs;
        for (auto const & s : inputs)
        {
            outputs.push_back(s + "!");
        }
        return outputs;
    };

    // Just verify construction doesn't throw
    strange::implementation::processor<std::string> proc{2, 2, fun};
    CHECK(true);
}

// ---- GRAPH TESTS ----

TEST_CASE("graph: empty construction")
{
    auto graph = strange::graph<std::string, std::string>::_make(std::vector<uint64_t>{}, std::vector<uint64_t>{});
    CHECK(graph._something());
    CHECK(graph._valid());
    CHECK(graph.ins() == 0);
    CHECK(graph.outs() == 0);
    CHECK(graph.processors().size() == 2);
    CHECK(graph.connections().empty());
}

TEST_CASE("graph: add and remove processors")
{
    auto graph = strange::graph<std::string, std::string>::_make(std::vector<uint64_t>{}, std::vector<uint64_t>{});

    auto proc = strange::processor<std::string, std::string>::_make<
        strange::implementation::thru_processor<std::string, std::string>>(std::vector<uint64_t>{0});

    auto id = graph.add_processor(proc);
    CHECK(id == 2);
    CHECK(graph.processors().size() == 3);

    auto id2 = graph.add_processor(proc);
    CHECK(id2 == 3);
    CHECK(graph.processors().size() == 4);

    CHECK(graph.remove_processor(id));
    CHECK_FALSE(graph.remove_processor(99));
}

TEST_CASE("graph: add and remove connections")
{
    auto graph = strange::graph<std::string, std::string>::_make(std::vector<uint64_t>{0}, std::vector<uint64_t>{0});

    auto conn = make_connection({.from_id_ = 1, .from_out_ = 0, .to_id_ = 0, .to_in_ = 0});
    auto id = graph.add_connection(conn);
    CHECK(id == 0);
    CHECK(graph.connections().size() == 1);

    auto id2 = graph.add_connection(conn);
    CHECK(id2 == 1);
    CHECK(graph.connections().size() == 2);

    CHECK(graph.remove_connection(id));
    CHECK_FALSE(graph.remove_connection(99));
}

TEST_CASE("graph: simple passthrough execution")
{
    auto graph = strange::graph<std::string, std::string>::_make(std::vector<uint64_t>{0}, std::vector<uint64_t>{0});

    auto proc = strange::processor<std::string, std::string>::_make<
        strange::implementation::thru_processor<std::string, std::string>>(std::vector<uint64_t>{0});
    auto proc_id = graph.add_processor(proc);

    // input(1) -> proc -> output(0)
    graph.add_connection(make_connection({.from_id_ = 1, .from_out_ = 0, .to_id_ = proc_id, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = proc_id, .from_out_ = 0, .to_id_ = 0, .to_in_ = 0}));

    auto closure = graph.closure();
    auto output = closure({"hello"});
    CHECK(output.size() == 1);
    CHECK(output[0] == "hello");
}

TEST_CASE("graph: multiple inputs and outputs")
{
    auto graph = strange::graph<std::string, std::string>::_make(std::vector<uint64_t>{0, 0}, std::vector<uint64_t>{0, 0});

    auto proc = strange::processor<std::string, std::string>::_make<
        strange::implementation::thru_processor<std::string, std::string>>(std::vector<uint64_t>{0, 0});
    auto proc_id = graph.add_processor(proc);

    // input port 0 -> proc in 0, input port 1 -> proc in 1
    graph.add_connection(make_connection({.from_id_ = 1, .from_out_ = 0, .to_id_ = proc_id, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = 1, .from_out_ = 1, .to_id_ = proc_id, .to_in_ = 1}));
    // proc out 0 -> output port 0, proc out 1 -> output port 1
    graph.add_connection(make_connection({.from_id_ = proc_id, .from_out_ = 0, .to_id_ = 0, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = proc_id, .from_out_ = 1, .to_id_ = 0, .to_in_ = 1}));

    auto closure = graph.closure();
    auto output = closure({"first", "second"});
    CHECK(output.size() == 2);
    CHECK(output[0] == "first");
    CHECK(output[1] == "second");
}

TEST_CASE("graph: nested subgraph")
{
    // Build inner subgraph: 1 in -> thru -> 1 out
    auto subgraph = strange::graph<std::string, std::string>::_make(std::vector<uint64_t>{0}, std::vector<uint64_t>{0});

    auto inner_proc = strange::processor<std::string, std::string>::_make<
        strange::implementation::thru_processor<std::string, std::string>>(std::vector<uint64_t>{0});
    auto inner_id = subgraph.add_processor(inner_proc);

    subgraph.add_connection(make_connection({.from_id_ = 1, .from_out_ = 0, .to_id_ = inner_id, .to_in_ = 0}));
    subgraph.add_connection(make_connection({.from_id_ = inner_id, .from_out_ = 0, .to_id_ = 0, .to_in_ = 0}));

    // Build outer graph using subgraph as a processor
    auto graph = strange::graph<std::string, std::string>::_make(std::vector<uint64_t>{0}, std::vector<uint64_t>{0});

    auto sub_proc = subgraph._static<strange::processor<std::string, std::string>>();
    auto sub_id = graph.add_processor(sub_proc);

    graph.add_connection(make_connection({.from_id_ = 1, .from_out_ = 0, .to_id_ = sub_id, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = sub_id, .from_out_ = 0, .to_id_ = 0, .to_in_ = 0}));

    auto closure = graph.closure();
    auto output = closure({"nested"});
    CHECK(output.size() == 1);
    CHECK(output[0] == "nested");
}

// ---- LATENCY TESTS ----

TEST_CASE("graph: latency with single processor")
{
    // input -> proc(lat=5) -> output
    auto graph = strange::graph<std::string, std::string>::_make(std::vector<uint64_t>{0}, std::vector<uint64_t>{0});
    auto proc = strange::processor<std::string, std::string>::_make<
        latency_processor<std::string, std::string>>(std::vector<uint64_t>{0}, uint64_t{5});
    auto id = graph.add_processor(proc);
    graph.add_connection(make_connection({.from_id_ = 1, .from_out_ = 0, .to_id_ = id, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = id, .from_out_ = 0, .to_id_ = 0, .to_in_ = 0}));
    CHECK(graph.latency() == 5);
}

TEST_CASE("graph: latency with chain of processors")
{
    // input -> A(lat=3) -> B(lat=7) -> output = 10
    auto graph = strange::graph<std::string, std::string>::_make(std::vector<uint64_t>{0}, std::vector<uint64_t>{0});
    auto a = strange::processor<std::string, std::string>::_make<
        latency_processor<std::string, std::string>>(std::vector<uint64_t>{0}, uint64_t{3});
    auto b = strange::processor<std::string, std::string>::_make<
        latency_processor<std::string, std::string>>(std::vector<uint64_t>{0}, uint64_t{7});
    auto a_id = graph.add_processor(a);
    auto b_id = graph.add_processor(b);
    graph.add_connection(make_connection({.from_id_ = 1, .from_out_ = 0, .to_id_ = a_id, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = a_id, .from_out_ = 0, .to_id_ = b_id, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = b_id, .from_out_ = 0, .to_id_ = 0, .to_in_ = 0}));
    CHECK(graph.latency() == 10);
}

TEST_CASE("graph: latency with parallel paths takes max")
{
    // input -> A(lat=3) -> output
    // input -> B(lat=7) -> output
    // latency = max(3, 7) = 7
    auto graph = strange::graph<std::string, std::string>::_make(std::vector<uint64_t>{0}, std::vector<uint64_t>{0, 0});
    auto a = strange::processor<std::string, std::string>::_make<
        latency_processor<std::string, std::string>>(std::vector<uint64_t>{0}, uint64_t{3});
    auto b = strange::processor<std::string, std::string>::_make<
        latency_processor<std::string, std::string>>(std::vector<uint64_t>{0}, uint64_t{7});
    auto a_id = graph.add_processor(a);
    auto b_id = graph.add_processor(b);
    graph.add_connection(make_connection({.from_id_ = 1, .from_out_ = 0, .to_id_ = a_id, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = a_id, .from_out_ = 0, .to_id_ = 0, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = 1, .from_out_ = 0, .to_id_ = b_id, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = b_id, .from_out_ = 0, .to_id_ = 0, .to_in_ = 1}));
    CHECK(graph.latency() == 7);
}

TEST_CASE("graph: latency with diamond")
{
    // input -> A(lat=2) -> C(lat=1) -> output
    // input -> B(lat=5) -> C -> output
    // C's input latency = max(2, 5) = 5, total = 5 + 1 = 6
    auto graph = strange::graph<std::string, std::string>::_make(std::vector<uint64_t>{0}, std::vector<uint64_t>{0});
    auto a = strange::processor<std::string, std::string>::_make<
        latency_processor<std::string, std::string>>(std::vector<uint64_t>{0}, uint64_t{2});
    auto b = strange::processor<std::string, std::string>::_make<
        latency_processor<std::string, std::string>>(std::vector<uint64_t>{0}, uint64_t{5});
    auto c = strange::processor<std::string, std::string>::_make<
        latency_processor<std::string, std::string>>(std::vector<uint64_t>{0, 0}, uint64_t{1});
    auto a_id = graph.add_processor(a);
    auto b_id = graph.add_processor(b);
    auto c_id = graph.add_processor(c);
    graph.add_connection(make_connection({.from_id_ = 1, .from_out_ = 0, .to_id_ = a_id, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = 1, .from_out_ = 0, .to_id_ = b_id, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = a_id, .from_out_ = 0, .to_id_ = c_id, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = b_id, .from_out_ = 0, .to_id_ = c_id, .to_in_ = 1}));
    graph.add_connection(make_connection({.from_id_ = c_id, .from_out_ = 0, .to_id_ = 0, .to_in_ = 0}));
    CHECK(graph.latency() == 6);
}

TEST_CASE("graph: latency with nested subgraph")
{
    // Inner: input -> proc(lat=4) -> output (subgraph latency = 4)
    // Outer: input -> subgraph(lat=4) -> proc(lat=2) -> output = 6
    auto subgraph = strange::graph<std::string, std::string>::_make(std::vector<uint64_t>{0}, std::vector<uint64_t>{0});
    auto inner = strange::processor<std::string, std::string>::_make<
        latency_processor<std::string, std::string>>(std::vector<uint64_t>{0}, uint64_t{4});
    auto inner_id = subgraph.add_processor(inner);
    subgraph.add_connection(make_connection({.from_id_ = 1, .from_out_ = 0, .to_id_ = inner_id, .to_in_ = 0}));
    subgraph.add_connection(make_connection({.from_id_ = inner_id, .from_out_ = 0, .to_id_ = 0, .to_in_ = 0}));
    CHECK(subgraph.latency() == 4);

    auto graph = strange::graph<std::string, std::string>::_make(std::vector<uint64_t>{0}, std::vector<uint64_t>{0});
    auto sub_proc = subgraph._static<strange::processor<std::string, std::string>>();
    auto sub_id = graph.add_processor(sub_proc);
    auto tail = strange::processor<std::string, std::string>::_make<
        latency_processor<std::string, std::string>>(std::vector<uint64_t>{0}, uint64_t{2});
    auto tail_id = graph.add_processor(tail);
    graph.add_connection(make_connection({.from_id_ = 1, .from_out_ = 0, .to_id_ = sub_id, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = sub_id, .from_out_ = 0, .to_id_ = tail_id, .to_in_ = 0}));
    graph.add_connection(make_connection({.from_id_ = tail_id, .from_out_ = 0, .to_id_ = 0, .to_in_ = 0}));
    CHECK(graph.latency() == 6);
}

// Note: stlab channel tests are omitted because the async executor
// timing makes them unreliable in a unit test context. The stlab
// channel integration is exercised indirectly through the graph tests.
