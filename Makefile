#CC=mipsel-linux-gnu-gcc
#CFLAGS=-march=74kc -Wall -Os -g
#CC=gcc
#CFLAGS=-Wall -Os -g

all: p1-parser.c
	$(CC) $(CFLAGS) -c -o p1-lib.o p1-lib.c
	$(CC) $(CFLAGS) -c -o crc16.o crc16.c
	$(CC) $(CFLAGS) -c -o p1-parser.o p1-parser.c
	ar rcs libdsmr.a p1-lib.o crc16.o p1-parser.o

p1-parser.c:
	ragel -s p1-parser.rl

.PHONY: clean

clean:
	rm -f p1-parser.c p1-lib.o p1-parser.o crc16.o
