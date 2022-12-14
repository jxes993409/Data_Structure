CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = HW01


all: $(BIN)

%: %.cpp
	$(CC) $(CFLAGS) $< -o $@

do:
	./HW01 ./Sample_Input ./Sample_Output
	./HW01 ./Testcase1 ./Output1
	./HW01 ./Testcase2 ./Output2
	./HW01 ./Testcase3 ./Output3
	./HW01 ./Testcase4 ./Output4
	./HW01 ./Testcase5 ./Output5

check:

	$(CHECKCC) $(CHECKFLAGS) ./HW01

clean:
	rm -rf $(OUT) *HW01