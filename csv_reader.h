
#line 1 "csv_reader.rl"
// vim:syntax=ragel

#ifndef _CSV_READER_H_
#define _CSV_READER_H_

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory>


namespace csv {

  namespace error {

    struct base : std::exception {
      virtual void formatErrorMessage() const = 0;

      const char* what() const throw() {
        this->formatErrorMessage();
        return error_message.c_str();
      }

      mutable std::string error_message;
    };

    struct with_field_num {
      with_field_num(size_t field_num): field_num(field_num) {}
      size_t field_num;
    };

    struct with_record_num {
      with_record_num(size_t record_num): record_num(record_num) {}
      size_t record_num;
    };

    struct with_file_name {
      with_file_name(std::string file_name): file_name(file_name) {}
      std::string file_name;
    };

    // ERRORS

    struct record_parsing :
      base,
      with_field_num {

      record_parsing(size_t field_num): with_field_num(field_num) {}

      virtual void formatErrorMessage() const {
        std::ostringstream stream;
        stream << "Parsing error in field " << this->field_num;
        this->error_message = stream.str();
      }
    };

    struct file_parsing :
      base,
      with_field_num,
      with_record_num,
      with_file_name {

      file_parsing(const std::string &file_name, size_t row_num, size_t field_num):
        with_field_num(field_num),
        with_record_num(record_num),
        with_file_name(file_name) {}

      virtual void formatErrorMessage() const {
        std::ostringstream stream;
        stream << "Parsing error in file '" << this->file_name << "', record " << \
          this->record_num << ", field " << this->field_num;
        this->error_message = stream.str();
      }
    };

  }

  //
  // RECORD PARSER
  //

  
#line 125 "csv_reader.rl"


  
#line 92 "csv_reader.h"
static const int csv_record_parser_start = 1;
static const int csv_record_parser_first_final = 7;
static const int csv_record_parser_error = 0;

static const int csv_record_parser_en_main = 1;


#line 128 "csv_reader.rl"

  class RecordParser {
    public:
      RecordParser() {}

      // returns current position in buffer...
      size_t parse(const char *begin, const char *end, std::vector<std::string> &fields) const {
        // declare values
        const char *p, *pe;
        const char *ts, *te;
        int cs;

        // initialize all values
        
#line 115 "csv_reader.h"
	{
	cs = csv_record_parser_start;
	}

#line 142 "csv_reader.rl"

        p = begin;
        pe = end;
        bool finished = false;
        size_t current_field = 0, chars_read = 0;

        
#line 128 "csv_reader.h"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr1:
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st1;
tr4:
#line 87 "csv_reader.rl"
	{
      ts = p;
      te = p;
    }
#line 96 "csv_reader.rl"
	{
      fields.push_back(std::string(ts, te-ts));
      current_field++;
    }
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st1;
tr9:
#line 96 "csv_reader.rl"
	{
      fields.push_back(std::string(ts, te-ts));
      current_field++;
    }
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 171 "csv_reader.h"
	switch( (*p) ) {
		case 10: goto tr2;
		case 32: goto tr1;
		case 34: goto tr3;
		case 44: goto tr4;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr1;
	goto tr0;
tr0:
#line 87 "csv_reader.rl"
	{
      ts = p;
      te = p;
    }
#line 92 "csv_reader.rl"
	{
      te++;
    }
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st2;
tr5:
#line 92 "csv_reader.rl"
	{
      te++;
    }
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 210 "csv_reader.h"
	switch( (*p) ) {
		case 10: goto tr7;
		case 32: goto tr6;
		case 34: goto st0;
		case 44: goto tr9;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr6;
	goto tr5;
tr10:
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st3;
tr6:
#line 96 "csv_reader.rl"
	{
      fields.push_back(std::string(ts, te-ts));
      current_field++;
    }
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 241 "csv_reader.h"
	switch( (*p) ) {
		case 10: goto tr11;
		case 32: goto tr10;
		case 44: goto tr1;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr10;
	goto st0;
st0:
cs = 0;
	goto _out;
tr2:
#line 87 "csv_reader.rl"
	{
      ts = p;
      te = p;
    }
#line 96 "csv_reader.rl"
	{
      fields.push_back(std::string(ts, te-ts));
      current_field++;
    }
#line 109 "csv_reader.rl"
	{
      finished = true;
    }
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st7;
tr7:
#line 96 "csv_reader.rl"
	{
      fields.push_back(std::string(ts, te-ts));
      current_field++;
    }
#line 109 "csv_reader.rl"
	{
      finished = true;
    }
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st7;
tr11:
#line 109 "csv_reader.rl"
	{
      finished = true;
    }
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 302 "csv_reader.h"
	goto st0;
tr3:
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 314 "csv_reader.h"
	if ( (*p) == 34 )
		goto tr13;
	goto tr12;
tr12:
#line 87 "csv_reader.rl"
	{
      ts = p;
      te = p;
    }
#line 92 "csv_reader.rl"
	{
      te++;
    }
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st5;
tr14:
#line 92 "csv_reader.rl"
	{
      te++;
    }
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 347 "csv_reader.h"
	if ( (*p) == 34 )
		goto tr15;
	goto tr14;
tr13:
#line 87 "csv_reader.rl"
	{
      ts = p;
      te = p;
    }
#line 92 "csv_reader.rl"
	{
      te++;
    }
#line 101 "csv_reader.rl"
	{
      // some little bit of lookahead
      if(*(p + 1) != '"') {
        fields.push_back(std::string(ts, te-ts));
        current_field++;
      }
    }
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st6;
tr15:
#line 92 "csv_reader.rl"
	{
      te++;
    }
#line 101 "csv_reader.rl"
	{
      // some little bit of lookahead
      if(*(p + 1) != '"') {
        fields.push_back(std::string(ts, te-ts));
        current_field++;
      }
    }
#line 113 "csv_reader.rl"
	{
      chars_read++;
    }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 396 "csv_reader.h"
	switch( (*p) ) {
		case 10: goto tr11;
		case 32: goto tr10;
		case 34: goto tr14;
		case 44: goto tr1;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr10;
	goto st0;
	}
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 

	_test_eof: {}
	_out: {}
	}

#line 149 "csv_reader.rl"

        if(!finished) {
          throw error::record_parsing(current_field);
        } else {
          this->_cleanFields(fields);
        }

        return chars_read;
      }

    private:

      void _cleanFields(std::vector<std::string> &fields) const {
        for(auto &field : fields) {
          // remove end " if exists
          if(field.back() == '"') {
            field.erase(field.end() - 1);

            // replace "" for " only in quoted fields
            // TODO: there is maybe a better way to do that...
            size_t index = 0;
            while(true) {
              index = field.find("\"\"", index);
              if(index == std::string::npos) break;
              field.replace(index, 2, "\"");
              index += 2;
            }
          }
        }
      }
  };


  //
  // FILE PARSER
  //

  namespace input {
    class Reader {
      public:
        Reader() {}
        virtual ~Reader() {}

        virtual size_t read(char *buffer, size_t size) = 0;
        virtual const std::string name() const = 0;
        virtual bool valid() const = 0;
        virtual bool end() const = 0;
    };

    class StreamReader : public Reader {
      public:
        StreamReader(std::unique_ptr<std::istream> stream): stream(std::move(stream)) {}
        virtual ~StreamReader() {}

        virtual size_t read(char *buffer, size_t size) {
          this->stream->read(buffer, size);
          return this->stream->gcount();
        }

        virtual bool valid() const {
          return this->stream->good();
        }

        virtual bool end() const {
          return this->stream->eof();
        }

        virtual const std::string name() const {
          return "stream";
        }

      private:
        std::unique_ptr<std::istream> stream;
    };
  }

  template
  <
    size_t BLOCK_SIZE = 1 << 24
  >
  class Reader {

    public:
      Reader(std::unique_ptr<input::Reader> reader):
        reader(std::move(reader))
      {
        this->_initializeBuffer();
      }

      void readLine(std::vector<std::string> &row) {
        if(!this->valid()) return;

        // move buffer and read more stuff
        this->_updateBuffer();
        this->current_record++;

        // parse line
        try {
          size_t read_chars = this->record_parser.parse(this->buffer.get() + this->current_pos, \
            this->buffer.get() + this->buffer_size, row);
          this->current_pos += read_chars;
        } catch(const error::record_parsing& e) {
          this->invalid_due_to_parse_error = true;
          throw error::file_parsing(this->reader->name(), this->current_record, e.field_num);
        }
      }

      bool valid() {
        return !this->invalid_due_to_parse_error && (this->reader->valid() || (this->current_pos < this->buffer_size));
      }

      bool end() {
        return this->reader->end() && (this->current_pos >= this->buffer_size);
      }

    private:

      void _initializeBuffer() {
        this->buffer = std::unique_ptr<char[]>(new char[3*BLOCK_SIZE]);

        this->current_pos = 0;
        this->buffer_size = this->reader->read(this->buffer.get(), 2*BLOCK_SIZE);
        this->_fixLastLine();
      }

      void _updateBuffer() {
        if(this->current_pos >= BLOCK_SIZE) {
          // move buffer to the beginning
          std::memcpy(this->buffer.get(), this->buffer.get() + BLOCK_SIZE, BLOCK_SIZE);
          this->current_pos -= BLOCK_SIZE;
          this->buffer_size -= BLOCK_SIZE;

          // try to read another block
          if(this->reader->valid()) {
            this->buffer_size += this->reader->read(this->buffer.get() + BLOCK_SIZE, BLOCK_SIZE);
          }

          this->_fixLastLine();
        }
      }

      void _fixLastLine() {
        // force a \n in the last position, if it's not there...

        if(!this->reader->valid() && this->buffer_size) {

          // remove end character... not needed...
          this->buffer_size--;

          // add \n
          if(this->buffer_size < 2*BLOCK_SIZE && \
            *(this->buffer.get() + this->buffer_size - 1) != '\n') {
            *(this->buffer.get() + this->buffer_size) = '\n';
            this->buffer_size++;
          }

        }
      }

      std::unique_ptr<input::Reader> reader;
      RecordParser record_parser;

      // buffer and buffer pointers
      std::unique_ptr<char[]> buffer;
      size_t current_pos;
      size_t buffer_size;
      size_t current_record = 0;

      bool invalid_due_to_parse_error = false;
  };

}

#endif
