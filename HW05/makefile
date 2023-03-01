CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
SRC_DIRS := src/lib
BIN = HW05
OUT = *.o

SRCS := $(wildcard $(SRC_DIRS:=/*.cpp))
OBJS := $(SRCS:.cpp=.o)

all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): src/HW05.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

do:
	./HW05 ./input/sample1.in ./output/sample1.out
	./HW05 ./input/sample2.in ./output/sample2.out
	./HW05 ./input/case1.in ./output/case1.out
	./HW05 ./input/case2.in ./output/case2.out
	./HW05 ./input/case3.in ./output/case3.out
	./HW05 ./input/case4.in ./output/case4.out
	./HW05 ./input/case5.in ./output/case5.out

check:
	$(CHECKCC) $(CHECKFLAGS) ./HW05 ./input/sample1.in ./output/sample1.out
	$(CHECKCC) $(CHECKFLAGS) ./HW05 ./input/case1.in ./output/case1.out

clean:
	rm -rf src/lib/*.o $(BIN)

compare:
	diff -w ./output/sample1.out ./golden_output/sample1.out
	diff -w ./output/sample2.out ./golden_output/sample2.out
	diff -w ./output/case1.out ./golden_output/case1.out
	diff -w ./output/case2.out ./golden_output/case2.out
	diff -w ./output/case3.out ./golden_output/case3.out
	diff -w ./output/case4.out ./golden_output/case4.out
	diff -w ./output/case5.out ./golden_output/case5.out