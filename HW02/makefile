CC = g++
CFLAGS = -g -Wall
OBJS = readfile.o get_id_name.o execute.o
BIN = HW02


all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): HW02.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

do:
	./HW02 ./input/sample.in ./output/sample.out
	./HW02 ./input/case1.in ./output/case1.out
	./HW02 ./input/case2.in ./output/case2.out
	./HW02 ./input/case3.in ./output/case3.out
	./HW02 ./input/case4.in ./output/case4.out
	./HW02 ./input/case5.in ./output/case5.out

check:
	$(CHECKCC) $(CHECKFLAGS) ./HW02

clean:
	rm -rf $(OUT) *HW02 *.o