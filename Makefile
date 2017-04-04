CC=g++
CFLAGS=-c -Wall -std=c++14 -O3 -fPIC

# change to whichever you use...
GTEST_INCLUDE=/usr/local/gtest/1.8.0/include
GTEST_LIBS=/usr/local/gtest/1.8.0/lib/*.a

.PHONY: clean csv_reader.h

all: test

test: csv_reader.h
	$(MAKE) -wC test test

csv_reader.h:
	ragel -C -G2 csv_reader.rl -o csv_reader.h

clean:
	rm -f csv_reader.h
	$(MAKE) -wC test clean

