CC=g++

CFLAGS=-Wall

LIBS=-lCppUTest

OBJS=linkedlist.o
TEST_OBJS= tests.o
TEST_EXE=tests.bin

code: linkedlist.c linkedlist.h
	g++ -c linkedlist.c

run_tests: tests
	./$(TEST_EXE)

test: $(TEST_OBJS)
	g++ -c tests.c

tests: code $(TEST_OBJS)
	g++ -o $(TEST_EXE) $(OBJS) $(TEST_OBJS) $(LIBS)

.PHONY: clean

clean:
	rm *.o $(TEST_EXE)
