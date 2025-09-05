# Regex engine

An experimental Regular Expression (regex) engine built from scratch, using the following process:
- Parse input string and store each valid regex type inside a parser struct
- Build a non-Deterministic Finite automaton, that has each character acts as a node
- Construct state transitions based on node type (or epsilon for trivial transitions)

## Usage
Use the `makefile` to easily compile all files required into two executables:
```cmd
    make all # Creates two files 'regex' and 'regex_test'
```
Then use the following command to run the files:
```cmd
	'./regex' to run regex engine with user input
    './regex_test' to run test cases on the regex engine
```

## Video example
[Link](#video-example)

### Requirements
- gcc

The `makefile` will be compiled with `gcc`.