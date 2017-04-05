CC=g++
CFLAGS=-Wall -std=c++14 -O3 -fPIC

export # export all variables

.PHONY: clean csv_reader.h

all: test

test: csv_reader.h
	$(MAKE) -wC test test

csv_reader.h:
	ragel -C -G2 csv_reader.rl -o csv_reader.h

clean:
	rm -f csv_reader.h
	$(MAKE) -wC test clean

