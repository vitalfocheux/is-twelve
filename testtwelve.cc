#include "gtest/gtest.h"

#include "Twelve.h"

TEST(Twelve, bool) {
  EXPECT_TRUE(is::Twelve::twelve(12));
  EXPECT_FALSE(is::Twelve::twelve(13));
}

TEST(Twelve, u32string) {
  EXPECT_TRUE(is::Twelve::twelve(U"douze"));
}

TEST(Twelve, pair) {
  std::pair<std::string, std::string> p = {"1", "2"};
  EXPECT_TRUE(is::Twelve::twelve(p));
}

TEST(Twelve, tuple) {
  std::vector<std::string> t = {"1", "2"};
  EXPECT_TRUE(is::Twelve::twelve(t));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
