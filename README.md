# Regex engine

An experimental Regular Expression (regex) engine built from scratch, using the following process:
- Parse input string and store each valid regex type inside a parser struct
- Build a non-Deterministic Finite automaton, that has each character acts as a node
- construct state transitions based on node type (or episilon for trivial transitions)