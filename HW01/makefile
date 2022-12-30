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
	rm -rf $(OUT) *HW01