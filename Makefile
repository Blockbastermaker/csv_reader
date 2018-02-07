CC=clang-4.0
CFLAGS=-c -std=c++14 -O3 -fPIC -Wall
LDFLAGS=-lstdc++

export # export all variables

.PHONY: clean csv_reader.h

all: test

test: csv_reader.h
	$(MAKE) -wC test test
	./test/test

csv_reader.h:
	ragel -C -G2 csv_reader.rl -o csv_reader.h

clean:
	rm -f csv_reader.h
	$(MAKE) -wC test clean
