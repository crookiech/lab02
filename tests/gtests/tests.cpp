#include <gtest/gtest.h> 
#include "main.h" 
TEST(Test_createTuple, Test_the_creating_tuple) { 
  EXPECT_EQ(std::get<1>(createTuple(111111, 0, 0, 999)), 0); 
}
TEST(Test2_equation, Test_small_number) { 
  EXPECT_EQ(std::get<0>(readingFile("C:/programming/lab02/test.tsv"))[0], 113); 
}
// TEST(Test3_equation, Test_big_number) { 
//   EXPECT_EQ(equation("100x+200=900"), 7); 
// }
