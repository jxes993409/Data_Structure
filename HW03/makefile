CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
SRC_DIRS := src/lib
BIN = HW03
OUT = *.o

SRCS := $(wildcard $(SRC_DIRS:=/*.cpp))
OBJS := $(SRCS:.cpp=.o)

all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): src/HW03.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

do:
	./HW03 ./input/sample.in ./output/sample.out
	./HW03 ./input/case1.in ./output/case1.out
	./HW03 ./input/case2.in ./output/case2.out
	./HW03 ./input/case3.in ./output/case3.out
	./HW03 ./input/case4.in ./output/case4.out
	./HW03 ./input/case5.in ./output/case5.out

check:
	$(CHECKCC) $(CHECKFLAGS) ./HW03 ./input/sample.in ./output/sample.out
	$(CHECKCC) $(CHECKFLAGS) ./HW03 ./input/case1.in ./output/case1.out

clean:
	rm -rf src/lib/*.o $(BIN)

compare:
	diff -w ./output/sample.out ./golden_output/sample.out
	diff -w ./output/case1.out ./golden_output/case1.out
	diff -w ./output/case2.out ./golden_output/case2.out
	diff -w ./output/case3.out ./golden_output/case3.out
	diff -w ./output/case4.out ./golden_output/case4.out
	diff -w ./output/case5.out ./golden_output/case5.out