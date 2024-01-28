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


TEST(Twelve, vector){
  std::vector<std::string> t{"1", "2"};
  EXPECT_TRUE(is::Twelve::twelve(t));
}


TEST(Twelve, v){
  std::vector<std::vector<std::string>> t{{"1", "2"}};
  EXPECT_TRUE(is::Twelve::twelve(t));
}

TEST(Twelve, map){
  std::map<int, std::string> maMap = {
        {1, "1"},
        {2, "2"}
    };
  EXPECT_TRUE(is::Twelve::twelve(maMap));
}

// TEST(Twelve, m){
//    std::map<std::map<std::string, int>, int> map = {
//         {
//             {{"1", 42}, {"2", 17}},  // Première map
//             10  // Valeur associée à la première map
//         }
//     };
//   EXPECT_TRUE(is::Twelve::twelve(map));
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

TEST(Math_Divide, Simple){
  EXPECT_TRUE(is::Twelve::twelve(24/2));
  EXPECT_TRUE(is::Twelve::twelve(24/2.0));
  EXPECT_TRUE(is::Twelve::twelve(24.0/2));
  EXPECT_TRUE(is::Twelve::twelve(24.0/2.0));
}

TEST(Math, Wee){
  EXPECT_TRUE(is::Twelve::twelve(((((((((1 + 2) * 3) - 4) / 5) % 6) << 1) >> 1) ^ 7) & 8) | 9);
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

TEST(FrenchConstant, French_President_Vector){
  std::vector<std::string> president{"Alexandre", " ", "Millerand"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Alexandre ", "Millerand"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Alexandre", " Millerand"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Alexandre ", " Millerand"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Alexandre", "Millerand"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Alexandre Millerand";
  std::vector<std::string> presidentV;
  for (char c : presidentS) {
    presidentV.push_back(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentV));
}

TEST(FrenchConstant, French_President_List){
  std::list<std::string> president{"Alexandre", " ", "Millerand"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Alexandre ", "Millerand"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Alexandre", " Millerand"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Alexandre ", " Millerand"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Alexandre", "Millerand"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Alexandre Millerand";
  std::list<std::string> presidentL;
  for (char c : presidentS) {
    presidentL.push_back(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentL));
}

/**
 * A lot of test with set doesn't work because the set is sorted and the order is not the same as the string
 * so ' ' is before 'A' and 'M'
*/
TEST(FrenchConstant, French_President_Set){
  std::set<std::string> president{"Alexandre", " ", "Millerand"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Alexandre ", "Millerand"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Alexandre", " Millerand"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Alexandre ", " Millerand"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Alexandre", "Millerand"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Alexandre Millerand";
  std::set<std::string> presidentSet;
  for (char c : presidentS) {
    presidentSet.insert(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentSet));
}

TEST(FrenchConstant, French_President_Multiset){
  std::multiset<std::string> president{"Alexandre", " ", "Millerand"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Alexandre ", "Millerand"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Alexandre", " Millerand"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Alexandre ", " Millerand"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Alexandre", "Millerand"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Alexandre Millerand";
  std::multiset<std::string> presidentSet;
  for (char c : presidentS) {
    presidentSet.insert(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentSet));
}

TEST(FrenchConstant, French_President_Map){
  std::map<std::string, std::string> president{{"Alexandre", " "}, {"Millerand", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Alexandre ", "Millerand"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Alexandre", " Millerand"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Alexandre ", " Millerand"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Alexandre", "Millerand"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Alexandre Millerand";
  std::map<std::string, std::string> presidentMap;
  for (char c : presidentS) {
    presidentMap.insert(std::make_pair(std::string(1, c), " "));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentMap));
}

TEST(FrenchConstant, French_President_Multimap){
  std::multimap<std::string, std::string> president{{"Alexandre", " "}, {"Millerand", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Alexandre ", "Millerand"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Alexandre", " Millerand"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Alexandre ", " Millerand"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Alexandre", "Millerand"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Alexandre Millerand";
  std::multimap<std::string, std::string> presidentMap;
  for (char c : presidentS) {
    presidentMap.insert(std::make_pair(std::string(1, c), " "));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentMap));
}

TEST(FrenchConstant, French_President_Queue){
  std::queue<std::string> president({"Alexandre", " ", "Millerand"});
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Alexandre ", "Millerand"});
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Alexandre", " Millerand"});
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Alexandre ", " Millerand"});
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Alexandre", "Millerand"});
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Alexandre Millerand";
  std::queue<std::string> presidentQueue;
  for (char c : presidentS) {
    presidentQueue.push(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentQueue));
}

TEST(FrenchConstant, French_President_ProrityQueue){
  std::vector<std::string> presidentV{"Alexandre", " ", "Millerand"};
  std::priority_queue<std::string> president(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Alexandre ", "Millerand"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Alexandre", " Millerand"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_TRUE(is::Twelve::twelve(president));
  presidentV = {"Alexandre ", " Millerand"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Alexandre", "Millerand"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Alexandre Millerand";
  std::priority_queue<std::string> presidentQueue;
  for (char c : presidentS) {
    presidentQueue.push(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentQueue));
}

TEST(FrenchConstant, French_President_Stack){
  std::stack<std::string> president;
  president.push("Alexandre");
  president.push(" ");
  president.push("Millerand");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Alexandre ");
  president.push("Millerand");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Alexandre");
  president.push(" Millerand");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Alexandre ");
  president.push(" Millerand");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Alexandre");
  president.push("Millerand");
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Alexandre Millerand";
  std::stack<std::string> presidentStack;
  for (char c : presidentS) {
    presidentStack.push(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentStack));
  presidentS = "dnarelliM erdnaxelA";
  presidentStack = std::stack<std::string>();
  for (char c : presidentS) {
    presidentStack.push(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentStack));
}

TEST(FrenchConstant, French_President_Array){
  std::array<std::string, 3> president{"Alexandre", " ", "Millerand"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Alexandre ", "Millerand"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Alexandre", " Millerand"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Alexandre ", " Millerand"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Alexandre", "Millerand"};
    EXPECT_FALSE(is::Twelve::twelve(president));
    std::string presidentS = "Alexandre Millerand";
    std::array<std::string, 100> presidentArray;
    std::size_t index = 0;
    for (char c : presidentS) {
      presidentArray[index++] = std::string(1, c);
    }
    EXPECT_TRUE(is::Twelve::twelve(presidentArray));
  }

  TEST(FrenchConstant, French_President_Pair){
    std::pair<std::string, std::string> pair{"Alexandre ", "Millerand"};
    EXPECT_TRUE(is::Twelve::twelve(pair));
    pair = std::make_pair("Alexandre", "Millerand");
    EXPECT_FALSE(is::Twelve::twelve(pair));
    pair = std::make_pair("Alexandre", " Millerand");
    EXPECT_TRUE(is::Twelve::twelve(pair));
    pair = std::make_pair("Alexandre ", " Millerand");
    EXPECT_FALSE(is::Twelve::twelve(pair));
  }


/**
 * The First Republic is not included in this list because none of its three successive administrations
 * provided for a presidency: the National Convention and the Directory were entirely parliamentary regimes, 
 * and the Consulate was based on a triumvirate. The presidential status would only emerge in 1848 during the 
 * drafting of the constitution of the Second Republic under the provisional government, despite lengthy debates 
 * between Félix Pyat and Alphonse de Lamartine in the Assembly regarding the relevance of the president's role 
 * within a republic
*/
TEST(FrenchConstant, French_President_Count_First_Republic){
  std::string president = "Paul Deschanel", presidentU = "PAUL DESCHANEL";
  EXPECT_FALSE(is::Twelve::twelve(president));
  EXPECT_FALSE(is::Twelve::twelve(presidentU));
}

TEST(FrenchConstant, French_President_Count_First_Republic_Vector){
  std::vector<std::string> president{"Paul", " ", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul ", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul", " Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul ", " Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Paul Deschanel";
  std::vector<std::string> presidentV;
  for (char c : presidentS) {
    presidentV.push_back(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentV));
}

TEST(FrenchConstant, French_President_Count_First_Republic_List){
  std::list<std::string> president{"Paul", " ", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul ", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul", " Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul ", " Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Paul Deschanel";
  std::list<std::string> presidentL;
  for (char c : presidentS) {
    presidentL.push_back(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentL));
}

TEST(FrenchConstant, French_President_Count_First_Republic_Set){
  std::set<std::string> president{"Paul", " ", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul ", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul", " Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul ", " Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Paul Deschanel";
  std::set<std::string> presidentSet;
  for (char c : presidentS) {
    presidentSet.insert(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentSet));
}

TEST(FrenchConstant, French_President_Count_First_Republic_Multiset){
  std::multiset<std::string> president{"Paul", " ", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul ", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul", " Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul ", " Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Paul", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Paul Deschanel";
  std::multiset<std::string> presidentSet;
  for (char c : presidentS) {
    presidentSet.insert(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentSet));
}

TEST(FrenchConstant, French_President_Count_First_Republic_Map){
  std::map<std::string, std::string> president{{"Paul", " "}, {"Deschanel", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Paul ", "Deschanel"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Paul", " Deschanel"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Paul ", " Deschanel"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Paul", "Deschanel"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Paul Deschanel";
  std::map<std::string, std::string> presidentMap;
  for (char c : presidentS) {
    presidentMap.insert(std::make_pair(std::string(1, c), " "));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentMap));
}

TEST(FrenchConstant, French_President_Count_First_Republic_Multimap){
  std::multimap<std::string, std::string> president{{"Paul", " "}, {"Deschanel", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Paul ", "Deschanel"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Paul", " Deschanel"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Paul ", " Deschanel"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Paul", "Deschanel"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Paul Deschanel";
  std::multimap<std::string, std::string> presidentMap;
  for (char c : presidentS) {
    presidentMap.insert(std::make_pair(std::string(1, c), " "));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentMap));
}

TEST(FrenchConstant, French_President_Count_First_Republic_Queue){
  std::queue<std::string> president({"Paul", " ", "Deschanel"});
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Paul ", "Deschanel"});
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Paul", " Deschanel"});
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Paul ", " Deschanel"});
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Paul", "Deschanel"});
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Paul Deschanel";
  std::queue<std::string> presidentQueue;
  for (char c : presidentS) {
    presidentQueue.push(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentQueue));
}

TEST(FrenchConstant, French_President_Count_First_Republic_ProrityQueue){
  std::vector<std::string> presidentV{"Paul", " ", "Deschanel"};
  std::priority_queue<std::string> president(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Paul ", "Deschanel"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Paul", " Deschanel"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Paul ", " Deschanel"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Paul", "Deschanel"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Paul Deschanel";
  std::priority_queue<std::string> presidentQueue;
  for (char c : presidentS) {
    presidentQueue.push(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentQueue));
}

TEST(FrenchConstant, French_President_Count_First_Republic_Stack){
  std::stack<std::string> president;
  president.push("Paul");
  president.push(" ");
  president.push("Deschanel");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Paul ");
  president.push("Deschanel");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Paul");
  president.push(" Deschanel");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Paul ");
  president.push(" Deschanel");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Paul");
  president.push("Deschanel");
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Paul Deschanel";
  std::stack<std::string> presidentStack;
  for (char c : presidentS) {
    presidentStack.push(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentStack));
  presidentS = "lenahcseD luaP";
  presidentStack = std::stack<std::string>();
  for (char c : presidentS) {
    presidentStack.push(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentStack));
}

TEST(FrenchConstant, French_President_Count_First_Republic_Array){
  std::array<std::string, 3> president{"Paul", " ", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Paul ", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Paul", " Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Paul ", " Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Paul", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Paul Deschanel";
  std::array<std::string, 100> presidentArray;
  std::size_t index = 0;
  for (char c : presidentS) {
    presidentArray[index++] = std::string(1, c);
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentArray));
}

TEST(FrenchConstant, French_President_Count_First_Republic_Pair){
  std::pair<std::string, std::string> pair{"Paul ", "Deschanel"};
  EXPECT_FALSE(is::Twelve::twelve(pair));
  pair = std::make_pair("Paul", "Deschanel");
  EXPECT_FALSE(is::Twelve::twelve(pair));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
