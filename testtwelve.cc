#include "gtest/gtest.h"

#include "Twelve.h"

TEST(Twelve, bool) {
  EXPECT_TRUE(is::Twelve::twelve(12));
  EXPECT_FALSE(is::Twelve::twelve(13));
}

TEST(Twelve, u32string) {
  std::u32string twelve = U"douze";
  EXPECT_TRUE(is::Twelve::twelve(twelve));
}

TEST(Twelve, pair) {
  std::pair<std::string, std::string> p = {"1", "2"};
  EXPECT_TRUE(is::Twelve::twelve(p));
}

// TEST(Twelve, tuple) {
//   std::vector<std::string> t = {"1", "2"};
//   EXPECT_TRUE(is::Twelve::twelve(t));
// }

// TEST(Twelve, set){
//   std::vector<std::string> t{"1", "2"};
//   EXPECT_TRUE(is::Twelve::twelve(t));
// }

TEST(Math_Plus, Simple){
  int i = 0, j = 12;
  for(std::size_t k = 0; k < 13; ++k){
    EXPECT_TRUE(is::Twelve::twelve(i+j));
    ++i; --j;
  }
}

TEST(Math_Plus, Simple_wit_Pair){
  int i = 0, j = 12;
  for(std::size_t k = 0; k < 13; ++k){
    EXPECT_TRUE(is::Twelve::twelve(std::make_pair(i, j)));
    ++i; --j;
  }
}

TEST(Math_Minus, Simple){
  int i = 0, j = 12;
  for(std::size_t k = 0; k < 13; ++k){
    EXPECT_TRUE(is::Twelve::twelve(j - i));
    --i; --j;
  }
}

TEST(Math_Times, Simple){
  EXPECT_TRUE(is::Twelve::twelve(3*4));
  EXPECT_TRUE(is::Twelve::twelve(4*3));
  EXPECT_TRUE(is::Twelve::twelve(0.5*24));
  EXPECT_TRUE(is::Twelve::twelve(24*0.5));
}

TEST(FrenchConstant, Douze_Simple){
  std::string douze = "douze";
  EXPECT_TRUE(is::Twelve::twelve(douze));
}

TEST(FrenchConstant, Douze_Pair){
  std::pair<std::string, std::string> douze{"dou", "ze"};
  EXPECT_TRUE(is::Twelve::twelve(douze));
}

TEST(FrenchConstant, French_President){
  std::string president = "Alexandre Millerand", presidentU = "ALEXANDRE MILLERAND";
  EXPECT_TRUE(is::Twelve::twelve(president));
  EXPECT_FALSE(is::Twelve::twelve(presidentU));
}

TEST(FrenchConstant, French_President_Pair){
  std::pair<std::string, std::string> pair{"Alexandre ", "Millerand"};
  EXPECT_TRUE(is::Twelve::twelve(pair));
  pair = std::make_pair("Alexandre", "Millerand");
  EXPECT_FALSE(is::Twelve::twelve(pair));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
