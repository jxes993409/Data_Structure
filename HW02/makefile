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

check:

	$(CHECKCC) $(CHECKFLAGS) ./HW02

clean:
	rm -rf $(OUT) *HW02