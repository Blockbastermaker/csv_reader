
# change to whichever you use...
GTEST_INCLUDE=/usr/local/gtest/1.8.0/include
GTEST_LIBS=/usr/local/gtest/1.8.0/lib/*.a

.PHONY: clean

all: test

test: csv_reader_test.o
	$(CC) *.o $(GTEST_LIBS) -pthread -lpthread -o test

csv_reader_test.o:
	$(CC) -c $(CFLAGS) -I$(GTEST_INCLUDE) csv_reader_test.cc

clean:
	rm -f *.o test

