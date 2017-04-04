CC=g++
CFLAGS=-c -Wall -std=c++14 -O3 -fPIC

# change to whichever you use...
GTEST_INCLUDE=/usr/local/gtest/1.8.0/include
GTEST_LIBS=/usr/local/gtest/1.8.0/lib/*.a

.PHONY: clean csv_reader.h

all: test

test: csv_reader_test.o
	$(CC) *.o $(GTEST_LIBS) -pthread -lpthread -o test

csv_reader_test.o: csv_reader.h
	$(CC) $(CFLAGS) -I$(GTEST_INCLUDE) csv_reader_test.cc

clean:
	rm -f *.o test

