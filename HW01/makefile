CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = HW01

all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $< -o $@

do:
	./HW01 ./input/sample.in ./output/sample.out
	./HW01 ./input/case1.in ./output/case1.out
	./HW01 ./input/case2.in ./output/case2.out
	./HW01 ./input/case3.in ./output/case3.out
	./HW01 ./input/case4.in ./output/case4.out
	./HW01 ./input/case5.in ./output/case5.out

check:
	$(CHECKCC) $(CHECKFLAGS) ./HW01

clean:
	rm -rf HW01

compare:
	diff -w ./output/sample.out ./golden_output/sample.out
	diff -w ./output/case1.out ./golden_output/case1.out
	diff -w ./output/case2.out ./golden_output/case2.out
	diff -w ./output/case3.out ./golden_output/case3.out
	diff -w ./output/case4.out ./golden_output/case4.out
	diff -w ./output/case5.out ./golden_output/case5.out