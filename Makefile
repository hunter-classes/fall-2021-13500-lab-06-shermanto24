main: main.o funcs.o
	g++ -o main main.o funcs.o

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o

test-ascii: test-ascii.o
	g++ -o test-ascii test-ascii.o

funcs.o: funcs.cpp funcs.h

main.o: main.cpp funcs.h
	g++ -c main.cpp

tests.o: tests.cpp doctest.h funcs.h
	g++ -c tests.cpp

test-ascii.o: test-ascii.cpp
	g++ -c test-ascii.cpp

clean:
	rm -f main.o funcs.o tests.o test-ascii.o
