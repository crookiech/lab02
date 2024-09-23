#include <gtest/gtest.h> 
#include "functions.h" 

TEST(IPAddressTest, CreateTupleTest) {
  auto ipTuple = createTuple(192.2, 168, 1.000, 1);
  ASSERT_EQ(std::get<0>(ipTuple), 192);
  ASSERT_EQ(std::get<1>(ipTuple), 168);
  ASSERT_EQ(std::get<2>(ipTuple), 1);
  ASSERT_EQ(std::get<3>(ipTuple), 1);
}

TEST(IPAddressTest, ReadingFileTest) {
  std::vector<std::tuple<int, int, int, int>> expectedIPAddresses = {
    {192, 168, 1, 1},
    {10, 0, 0, 1},
    {172, 16, 0, 1},
    {192, 168, 0, 1},
  };
  auto ipAddresses = readingFile("C:/programming/lab02/test.tsv"); // Для локального тестирования
  // auto ipAddresses = readingFile("../test.tsv"); // Для тестирования в github actions
  ASSERT_EQ(ipAddresses, expectedIPAddresses);
}

TEST(IPAddressTest, SortIPAdressesTest) {
  std::vector<std::tuple<int, int, int, int>> ipAddresses = {
    {192, 168, 1, 1},
    {10, 0, 0, 1},
    {172, 16, 0, 1},
    {192, 168, 0, 1},
  };
  sortIPAdresses(ipAddresses);
  std::vector<std::tuple<int, int, int, int>> expectedIPAddresses = {
    {192, 168, 1, 1},
    {192, 168, 0, 1},
    {172, 16, 0, 1},
    {10, 0, 0, 1},
  };
  ASSERT_EQ(ipAddresses, expectedIPAddresses);
}