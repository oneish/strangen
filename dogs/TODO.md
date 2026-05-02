# TODO

- renumber graph processors and connections to fill gaps
- when processors are removed, also remove their connections
- make use of connection maps when calculating latency
- last prompt:
Add an operation to the graph prototype called connections_to to get a vector of connections for the given "to" processor id and another operation called connections_from for the given "from" processor id.  Implement these using an unordered_map member variable for each one that keeps track as connections are added and removed.
