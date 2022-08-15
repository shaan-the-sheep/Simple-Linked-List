CC=g++

CFLAGS=-Wall -g

LIBS=-lCppUTest
INCS=linkedlist.h  # Add your include files here
OBJS=linkedlist.o  # Add your SOURCE obj files here
TEST_OBJS=tests.o  # Add your TEST obj files here

TEST_EXE=tests.bin

code: $(OBJS) $(INCS)

run_tests: tests
	./$(TEST_EXE)

test: $(TEST_OBJS)

tests: code test
	g++ -o $(TEST_EXE) $(OBJS) $(TEST_OBJS) $(LIBS)

.PHONY: clean

clean:
	rm *.o $(TEST_EXE)
