CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = HW02


all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $< -o $@

do:
	./HW02 ./sample.in ./sample.out
	# ./HW02 ./case1.in ./case1.out
	# ./HW02 ./case2.in ./case2.out
	# ./HW02 ./case3.in ./case3.out
	# ./HW02 ./case4.in ./case4.out
	# ./HW02 ./case5.in ./case5.out

check:

	$(CHECKCC) $(CHECKFLAGS) ./HW02

clean:
	rm -rf $(OUT) *HW02