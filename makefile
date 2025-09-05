main := main.c
match := match.c
parser := parser.c
util := util.c
test := test.c

all: regex_engine
	@echo "Compiling regex_engine and tests"
	@echo "	'./regex' to run regex engine with user input"
	@echo "	'./regex_test' to run test cases on the regex engine

regex_engine: 
	gcc -Wall -o regex ${main} ${match} ${parser} ${util}

test:
	gcc -Wall -o regex_test ${test} ${match} ${parser} ${util}

clean:
	rm -v regex