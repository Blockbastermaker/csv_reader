#ifndef _CSV_READER_H_
#define _CSV_READER_H_

#include <ifstream>
#include <string>

namespace csv {

  class InputReader {
    public:
      InputReader(std::istream &stream): stream(stream) {}

      ~InputReader() {}

      size_t read(char *buffer, size_t size) {
        this->stream.read(buffer, size);
        return this->stream.gcount();
      }

      bool valid() {
        return !this->stream.eof();
      }

    private:
      std::istream &stream;
  };

  class Reader {

    public:
      Reader(std::unique_ptr<InputReader> reader):
        reader(std::move(reader))
      {
        this->initializeBuffer();
      }

      void readLine(std::vector<std::string> &row) {
        // move buffer and read more stuff
        this->updateBuffer();

      }

    private:

      void initializeBuffer() {
        this->buffer = std::unique_ptr<char[]>(new char[2*BLOCK_SIZE]);

        this->current_pos = 0;
        this->buffer_size = reader.read(this->buffer.get(), 2*BLOCK_SIZE);
      }

      void updateBuffer() {
        if(this->current_pos >= BLOCK_SIZE) {
          // move buffer to the beginning
          std::memcpy(this->buffer.get(), this->buffer.get() + BLOCK_SIZE, BLOCK_SIZE);
          this->current_pos -= BLOCK_SIZE;
          this->buffer_size -= BLOCK_SIZE;
          // try to read another block
          if(this->reader->valid()) {
            this->buffer_size += this->reader.read(this->buffer.get() + BLOCK_SIZE, BLOCK_SIZE);
          }
        }
      }

      static const size_t BLOCK_SIZE = 1 << 12; // max size of a field

      InputReader reader;

      // buffer and buffer pointers
      std::unique_ptr<char[]>buffer;
      size_t start_pos;
      size_t buffer_size;
  
  };

};

#endif
