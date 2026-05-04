# TODO

- move thru_processor implementation into its own header file
- work out how to combine multiple signals
- work out how to align the inputs in graph and thru_processor w.r.t. latency
- rename snacks: baggage to bananas, demo to bread, example to toast.
- add defaulted graph implementation constructor parameter for delay<Signal>.
- use a vector of delay<Signal> closures to align each connected input (before +=).
