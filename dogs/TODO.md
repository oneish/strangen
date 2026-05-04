# TODO

- move thru_processor implementation into its own header file
- work out how to combine multiple signals
- work out how to align the inputs in graph and thru_processor w.r.t. latency
- Rename snacks: baggage to bananas, demo to bread, example to toast.
- Add latency to connection and set it before calling from/to.
- Ensure latency is called on every processor at the start of closure.
- Add delay<Signal> prototype with latency, delayed [closure] operations.
- Add delay<Signal> default implementation that passes signal untouched.
- Add defaulted graph implementation constructor parameter for delay<Signal>.
- Update max input latency in from/to and use a vector of delay<Signal> closures to align each connected input (before +=).
- Maybe keep from get rid of to.