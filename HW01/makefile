CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = HW01


all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $< -o $@

do:
	./HW01 ./sample.in ./sample.out
	./HW01 ./case1.in ./case1.out
	./HW01 ./case2.in ./case2.out
	./HW01 ./case3.in ./case3.out
	./HW01 ./case4.in ./case4.out
	./HW01 ./case5.in ./case5.out

check:

	$(CHECKCC) $(CHECKFLAGS) ./HW01

clean:
	rm -rf $(OUT) *HW01