
#line 1 "src/record_parser.ragel"
// vi:syntax=ragel

#ifndef _CSV_RECORD_PARSER_H_
#define _CSV_RECORD_PARSER_H_

#include <iostream>
#include <string>
#include <algorithm>


namespace csv {

  
#line 43 "src/record_parser.ragel"


  
#line 21 "src/record_parser.h"
static const int csv_record_parser_start = 1;
static const int csv_record_parser_first_final = 7;
static const int csv_record_parser_error = 0;

static const int csv_record_parser_en_main = 1;


#line 46 "src/record_parser.ragel"

  class RecordParser {
    public:
      RecordParser() {}

      // returns current position in buffer...
      const char* parse(const char *begin, const char *end, std::vector<std::string> &fields) {
        // initialize read pointer
        
#line 39 "src/record_parser.h"
	{
	cs = csv_record_parser_start;
	}

#line 55 "src/record_parser.ragel"

        this->p = begin;
        this->pe = end;
        this->finished = false;
        size_t current_field = 0;

        //std::cout << "--" << std::endl;
        //std::cout << std::string(this->p, this->pe);
        //std::cout << "--" << std::endl;

        
#line 56 "src/record_parser.h"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr4:
#line 16 "src/record_parser.ragel"
	{
      this->ts = p;
      this->te = p;
    }
#line 25 "src/record_parser.ragel"
	{
      try {
        fields.at(current_field).erase();
        fields[current_field].append(ts, te - ts);
      } catch(const std::out_of_range&) {
        fields.push_back(std::string(ts, te-ts));
      }
      current_field++;
    }
	goto st1;
tr8:
#line 25 "src/record_parser.ragel"
	{
      try {
        fields.at(current_field).erase();
        fields[current_field].append(ts, te - ts);
      } catch(const std::out_of_range&) {
        fields.push_back(std::string(ts, te-ts));
      }
      current_field++;
    }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 95 "src/record_parser.h"
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
#line 16 "src/record_parser.ragel"
	{
      this->ts = p;
      this->te = p;
    }
#line 21 "src/record_parser.ragel"
	{
      this->te++;
    }
	goto st2;
tr5:
#line 21 "src/record_parser.ragel"
	{
      this->te++;
    }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 126 "src/record_parser.h"
	switch( (*p) ) {
		case 10: goto tr6;
		case 34: goto st0;
		case 44: goto tr8;
	}
	goto tr5;
tr6:
#line 25 "src/record_parser.ragel"
	{
      try {
        fields.at(current_field).erase();
        fields[current_field].append(ts, te - ts);
      } catch(const std::out_of_range&) {
        fields.push_back(std::string(ts, te-ts));
      }
      current_field++;
    }
#line 35 "src/record_parser.ragel"
	{
      this->finished = true;
    }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 153 "src/record_parser.h"
	goto st0;
st0:
cs = 0;
	goto _out;
tr1:
#line 16 "src/record_parser.ragel"
	{
      this->ts = p;
      this->te = p;
    }
#line 21 "src/record_parser.ragel"
	{
      this->te++;
    }
	goto st3;
tr9:
#line 21 "src/record_parser.ragel"
	{
      this->te++;
    }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 179 "src/record_parser.h"
	switch( (*p) ) {
		case 10: goto tr10;
		case 32: goto tr9;
		case 34: goto tr11;
		case 44: goto tr8;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr9;
	goto tr5;
tr2:
#line 16 "src/record_parser.ragel"
	{
      this->ts = p;
      this->te = p;
    }
#line 21 "src/record_parser.ragel"
	{
      this->te++;
    }
#line 25 "src/record_parser.ragel"
	{
      try {
        fields.at(current_field).erase();
        fields[current_field].append(ts, te - ts);
      } catch(const std::out_of_range&) {
        fields.push_back(std::string(ts, te-ts));
      }
      current_field++;
    }
#line 35 "src/record_parser.ragel"
	{
      this->finished = true;
    }
	goto st8;
tr10:
#line 21 "src/record_parser.ragel"
	{
      this->te++;
    }
#line 25 "src/record_parser.ragel"
	{
      try {
        fields.at(current_field).erase();
        fields[current_field].append(ts, te - ts);
      } catch(const std::out_of_range&) {
        fields.push_back(std::string(ts, te-ts));
      }
      current_field++;
    }
#line 35 "src/record_parser.ragel"
	{
      this->finished = true;
    }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 238 "src/record_parser.h"
	switch( (*p) ) {
		case 32: goto tr12;
		case 34: goto tr11;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr12;
	goto st0;
tr12:
#line 21 "src/record_parser.ragel"
	{
      this->te++;
    }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 256 "src/record_parser.h"
	switch( (*p) ) {
		case 32: goto tr12;
		case 34: goto tr11;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr12;
	goto st0;
tr3:
#line 16 "src/record_parser.ragel"
	{
      this->ts = p;
      this->te = p;
    }
#line 21 "src/record_parser.ragel"
	{
      this->te++;
    }
	goto st5;
tr11:
#line 21 "src/record_parser.ragel"
	{
      this->te++;
    }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 285 "src/record_parser.h"
	if ( (*p) == 34 )
		goto tr13;
	goto tr11;
tr13:
#line 21 "src/record_parser.ragel"
	{
      this->te++;
    }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 299 "src/record_parser.h"
	switch( (*p) ) {
		case 10: goto tr14;
		case 32: goto tr13;
		case 44: goto tr8;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr13;
	goto st0;
tr14:
#line 21 "src/record_parser.ragel"
	{
      this->te++;
    }
#line 25 "src/record_parser.ragel"
	{
      try {
        fields.at(current_field).erase();
        fields[current_field].append(ts, te - ts);
      } catch(const std::out_of_range&) {
        fields.push_back(std::string(ts, te-ts));
      }
      current_field++;
    }
#line 35 "src/record_parser.ragel"
	{
      this->finished = true;
    }
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 332 "src/record_parser.h"
	switch( (*p) ) {
		case 10: goto tr14;
		case 32: goto tr13;
		case 44: goto tr8;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr13;
	goto st0;
	}
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 

	_test_eof: {}
	_out: {}
	}

#line 66 "src/record_parser.ragel"

        if(!this->finished) {
          // TODO: throw exception
          std::cout << "ERROR" << std::endl;
        } else {
          // clean fields
          this->_cleanFields(fields);
        }

        return p;
      }

    private:

      void _cleanFields(std::vector<std::string> &fields) {
        for(auto &field : fields) {
        }
      }

      // no write data, we do that manually
      const char *p, *pe, *eof;
      const char *ts, *te;
      int act, cs, top, stack[1];

      bool finished;
  };
}

#endif
