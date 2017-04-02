#include <iostream>
#include <vector>
#include <cstring>

#include "../src/record_parser.h"

int main(int argc, char *argv[]) {
  // const char *csv_record = "asd,bnm,cvb\ndfg,ert,sd\n";
  const char *csv_record = "    \"a,\nsd\",bnm\n\"dfg\"    ,\"ert\"\n";

  csv::RecordParser parser;

  std::vector<std::string> results;
  std::cout << "1:" << std::endl;
  const char *ptr = parser.parse(csv_record, csv_record + std::strlen(csv_record), results);

  for(const auto &field : results) {
    std::cout << "-" << std::endl;
    std::cout << field << std::endl;
  }

  std::cout << "2:" << std::endl;
  parser.parse(ptr, csv_record + std::strlen(csv_record), results);

  for(const auto &field : results) {
    std::cout << "-" << std::endl;
    std::cout << field << std::endl;
  }

}
