CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
SRC_DIRS := src/lib
BIN = HW07
OUT = *.o

SRCS := $(wildcard $(SRC_DIRS:=/*.cpp))
OBJS := $(SRCS:.cpp=.o)

all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): src/HW07.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

do:
	./HW07 ./input/string/case1_string.in ./input/target/case1_target.in ./output/case1.out
	./HW07 ./input/string/case2_string.in ./input/target/case2_target.in ./output/case2.out
	./HW07 ./input/string/case3_string.in ./input/target/case3_target.in ./output/case3.out
	./HW07 ./input/string/case4_string.in ./input/target/case4_target.in ./output/case4.out
	./HW07 ./input/string/case5_string.in ./input/target/case5_target.in ./output/case5.out
	./HW07 ./input/string/hidden1_string.in ./input/target/hidden1_target.in ./output/hidden1.out
	./HW07 ./input/string/hidden2_string.in ./input/target/hidden2_target.in ./output/hidden2.out
	./HW07 ./input/string/hidden3_string.in ./input/target/hidden3_target.in ./output/hidden3.out
	./HW07 ./input/string/hidden4_string.in ./input/target/hidden4_target.in ./output/hidden4.out
	./HW07 ./input/string/hidden5_string.in ./input/target/hidden5_target.in ./output/hidden5.out

check:
	$(CHECKCC) $(CHECKFLAGS) ./HW07 ./input/string/case1_string.in ./input/target/case1_target.in ./output/case1.out
	$(CHECKCC) $(CHECKFLAGS) ./HW07 ./input/string/hidden1_string.in ./input/target/hidden1_target.in ./output/hidden1.out

clean:
	rm -rf src/lib/*.o $(BIN)

compare:
	diff -w ./output/case1.out ./golden_output/case1.out
	diff -w ./output/case2.out ./golden_output/case2.out
	diff -w ./output/case3.out ./golden_output/case3.out
	diff -w ./output/case4.out ./golden_output/case4.out
	diff -w ./output/case5.out ./golden_output/case5.out
	diff -w ./output/hidden1.out ./golden_output/hidden1.out
	diff -w ./output/hidden2.out ./golden_output/hidden2.out
	diff -w ./output/hidden3.out ./golden_output/hidden3.out
	diff -w ./output/hidden4.out ./golden_output/hidden4.out
	diff -w ./output/hidden5.out ./golden_output/hidden5.out