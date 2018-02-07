#ifndef _CSV_READER_TEST_H_
#define _CSV_READER_TEST_H_

#include <iostream>
#include <fstream>

#include <gtest/gtest.h>

#include "../csv_reader.h"

class CSVReaderTest : public ::testing::Test {
  protected:
};


// should not work in any way...
TEST_F(CSVReaderTest, TestEmptyFile) {
  std::ifstream file_stream("./test/fixtures/empty.csv", std::ios_base::in | std::ios_base::binary);
  auto reader = csv::Reader<>(std::make_unique<csv::input::StreamReader>(file_stream));

  ASSERT_FALSE(reader.valid()); // nothing to read...
  ASSERT_TRUE(reader.end());
}

TEST_F(CSVReaderTest, TestSimpleCSV) {
  std::ifstream file_stream("./test/fixtures/simple.csv", std::ios_base::in | std::ios_base::binary);
  auto reader = csv::Reader<>(std::make_unique<csv::input::StreamReader>(file_stream));

  ASSERT_FALSE(reader.end());
  ASSERT_TRUE(reader.valid()); // nothing to read...

  std::vector<std::string> results;
  reader.readLine(results);

  ASSERT_EQ(results[0], "a");
  ASSERT_EQ(results[1], "b");
  ASSERT_EQ(results[2], "c");
  ASSERT_EQ(results[3], "d");

  ASSERT_FALSE(reader.end());
  ASSERT_TRUE(reader.valid());
  results.clear();
  reader.readLine(results);

  ASSERT_EQ(results[0], "e");
  ASSERT_EQ(results[1], "f");
  ASSERT_EQ(results[2], "g");
  ASSERT_EQ(results[3], "h");

  ASSERT_FALSE(reader.valid());
  ASSERT_TRUE(reader.end());
}

TEST_F(CSVReaderTest, TestQuotedCSV) {
  std::ifstream file_stream("./test/fixtures/simple_quoted.csv", std::ios_base::in | std::ios_base::binary);
  auto reader = csv::Reader<>(std::make_unique<csv::input::StreamReader>(file_stream));

  ASSERT_FALSE(reader.end());
  ASSERT_TRUE(reader.valid()); // nothing to read...

  std::vector<std::string> results;
  reader.readLine(results);

  ASSERT_EQ(results[0], "a");
  ASSERT_EQ(results[1], "b");
  ASSERT_EQ(results[2], "c, d");

  ASSERT_FALSE(reader.end());
  ASSERT_TRUE(reader.valid());
  results.clear();
  reader.readLine(results);

  ASSERT_EQ(results[0], "e");
  ASSERT_EQ(results[1], "f\"g");
  ASSERT_EQ(results[2], "h");

  ASSERT_FALSE(reader.valid());
  ASSERT_TRUE(reader.end());
}

TEST_F(CSVReaderTest, TestInvalidCSV) {
  std::ifstream file_stream("./test/fixtures/invalid.csv", std::ios_base::in | std::ios_base::binary);
  auto reader = csv::Reader<>(std::make_unique<csv::input::StreamReader>(file_stream));

  ASSERT_FALSE(reader.end());
  ASSERT_TRUE(reader.valid()); // nothing to read...

  std::vector<std::string> results;

  ASSERT_FALSE(reader.end());
  ASSERT_TRUE(reader.valid());
  ASSERT_THROW({
    reader.readLine(results);
  }, csv::error::file_parsing);
  ASSERT_FALSE(reader.valid());
  ASSERT_FALSE(reader.end());
}

TEST_F(CSVReaderTest, TestMultipleBlocksValid) {
  std::ifstream file_stream("./test/fixtures/short_block.csv", std::ios_base::in | std::ios_base::binary);
  auto reader = csv::Reader<32>(std::make_unique<csv::input::StreamReader>(file_stream));

  ASSERT_FALSE(reader.end());
  ASSERT_TRUE(reader.valid()); // nothing to read...

  std::vector<std::string> results;
  reader.readLine(results);

  ASSERT_EQ(results[0], "Carrot");
  ASSERT_EQ(results[1], "Cabbage");
  ASSERT_EQ(results[2], "Cauliflower");
  ASSERT_EQ(results[3], "Peas");

  ASSERT_FALSE(reader.end());
  ASSERT_TRUE(reader.valid());
  results.clear();
  reader.readLine(results);

  ASSERT_EQ(results[0], "Pineapple");
  ASSERT_EQ(results[1], "Pear");
  ASSERT_EQ(results[2], "Peach");
  ASSERT_EQ(results[3], "Prune");

  ASSERT_FALSE(reader.end());
  ASSERT_TRUE(reader.valid());
  results.clear();
  reader.readLine(results);

  ASSERT_EQ(results[0], "Switzerland");
  ASSERT_EQ(results[1], "Sweden");
  ASSERT_EQ(results[2], "Germany");
  ASSERT_EQ(results[3], "Spain");

  ASSERT_TRUE(reader.end());
  ASSERT_FALSE(reader.valid());
}

TEST_F(CSVReaderTest, TestMultipleBlocksInvalid) {
  std::ifstream file_stream("./test/fixtures/short_block.csv", std::ios_base::in | std::ios_base::binary);
  auto reader = csv::Reader<16>(std::make_unique<csv::input::StreamReader>(file_stream));

  ASSERT_TRUE(reader.valid()); // nothing to read...

  // the first works
  std::vector<std::string> results;
  reader.readLine(results);

  ASSERT_EQ(results[0], "Carrot");
  ASSERT_EQ(results[1], "Cabbage");
  ASSERT_EQ(results[2], "Cauliflower");
  ASSERT_EQ(results[3], "Peas");

  ASSERT_FALSE(reader.end());
  ASSERT_TRUE(reader.valid());
  results.clear();
  // the second does not
  ASSERT_THROW({
    reader.readLine(results);
  }, csv::error::file_parsing);
  ASSERT_FALSE(reader.valid());
  ASSERT_FALSE(reader.end());
}

#endif
