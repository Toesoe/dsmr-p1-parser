CC ?= gcc
CFLAGS ?= -Wall -Os -g
ARFLAGS = rcs
OBJ = p1-parser.o p1-lib.o crc16.o

all: p1-test-p1 p1-test-d0 libdsmr.a

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

p1-parser.c:
	ragel -s p1-parser.rl

p1-test-p1: p1-test.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

p1-test-d0: p1-test-d0.o $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

libdsmr.a: $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

.PHONY: clean

clean:
	rm -f $(OBJ) p1-parser.c p1-test-p1 p1-test-d0 libdsmr.a
