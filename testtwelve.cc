#include "gtest/gtest.h"

#include "Twelve.h"
#include <numeric>
#include <cmath>

void caesarCodeShift(std::string& code, int shift){
  std::string codeShift = "";
  shift %= 26;
  for(const char& c : code){
    if(c < 'A' || c > 'z' || (c > 'Z' && c < 'a')){
      codeShift.push_back(c);
      continue;
    }
    unsigned char n = c + shift;
    if(n > 'z' && c >= 'a' && c <= 'z'){
      n = (n % ('z' + 1)) + 'a';
    }else if(n > 'Z' && c >= 'A' && c <= 'Z'){
      n = (n % ('Z' + 1)) + 'A';
    }
    codeShift.push_back(n);
  }
  code = codeShift;
}

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

TEST(Math, Wee2){
  std::vector<int> numbers = {1, 13, 6, 9, 12};

  // Calcul des différences adjacentes
  std::vector<int> differences(numbers.size());
  std::adjacent_difference(numbers.begin(), numbers.end(), differences.begin());
  EXPECT_TRUE(is::Twelve::twelve(differences));
}

TEST(Math, square_of_root){
  EXPECT_TRUE(is::Twelve::twelve(std::sqrt(144)));
}

/**
 * Caesar code already work with string which use latin alphabet
*/
TEST(CaesarCode, Twelve){
  std::string twelve = "twelve";
  caesarCodeShift(twelve, 12);
  EXPECT_TRUE(is::Twelve::twelve(twelve));
  std::cout << twelve << std::endl;
  twelve = "twelve";
  caesarCodeShift(twelve, 13);
  EXPECT_FALSE(is::Twelve::twelve(twelve));
  twelve = "fiqxhq";
  caesarCodeShift(twelve, 14);
  EXPECT_TRUE(is::Twelve::twelve(twelve));
}

TEST(CaesarCode, Douze){
  std::string twelve = "douze";
  caesarCodeShift(twelve, 12);
  std::cout << twelve << std::endl;
  EXPECT_TRUE(is::Twelve::twelve(twelve));
  twelve = "douze";
  caesarCodeShift(twelve, 13);
  EXPECT_FALSE(is::Twelve::twelve(twelve));
  twelve = "paglq";
  caesarCodeShift(twelve, 14);
  EXPECT_TRUE(is::Twelve::twelve(twelve));
}

TEST(CaesarCode, Doce){
  std::string twelve = "doce";
  caesarCodeShift(twelve, 12);
  std::cout << twelve << std::endl;
  EXPECT_TRUE(is::Twelve::twelve(twelve));
  twelve = "doce";
  caesarCodeShift(twelve, 13);
  EXPECT_FALSE(is::Twelve::twelve(twelve));
  twelve = "paoq";
  caesarCodeShift(twelve, 14);
  EXPECT_TRUE(is::Twelve::twelve(twelve));
}

TEST(CaesarCode, XII_Uppercase){
  std::string twelve = "XII";
  caesarCodeShift(twelve, 12);
  std::cout << twelve << std::endl;
  EXPECT_TRUE(is::Twelve::twelve(twelve));
  twelve = "XII";
  caesarCodeShift(twelve, 13);
  EXPECT_FALSE(is::Twelve::twelve(twelve));
  twelve = "JUU";
  caesarCodeShift(twelve, 14);
  EXPECT_TRUE(is::Twelve::twelve(twelve));
}

TEST(CaesarCode, XII_Lowercase){
  std::string twelve = "xii";
  caesarCodeShift(twelve, 12);
  std::cout << twelve << std::endl;
  EXPECT_TRUE(is::Twelve::twelve(twelve));
  twelve = "xii";
  caesarCodeShift(twelve, 13);
  EXPECT_FALSE(is::Twelve::twelve(twelve));
  twelve = "juu";
  caesarCodeShift(twelve, 14);
  EXPECT_TRUE(is::Twelve::twelve(twelve));
}

TEST(CaesarCode, Tunka_paya){
  std::string twelve = "tunka paya";
  caesarCodeShift(twelve, 12);
  std::cout << twelve << std::endl;
  EXPECT_TRUE(is::Twelve::twelve(twelve));
  twelve = "tunka paya";
  caesarCodeShift(twelve, 13);
  EXPECT_FALSE(is::Twelve::twelve(twelve));
  twelve = "fgzwm bmkm";
  caesarCodeShift(twelve, 14);
  EXPECT_TRUE(is::Twelve::twelve(twelve));
}

TEST(CaesarCode, On_iki){
  std::string twelve = "on iki";
  caesarCodeShift(twelve, 12);
  std::cout << twelve << std::endl;
  EXPECT_TRUE(is::Twelve::twelve(twelve));
  twelve = "on iki";
  caesarCodeShift(twelve, 13);
  EXPECT_FALSE(is::Twelve::twelve(twelve));
  twelve = "az uwu";
  caesarCodeShift(twelve, 14);
  EXPECT_TRUE(is::Twelve::twelve(twelve));
}

TEST(CaesarCode, Tannifilan){
  std::string twelve = "tannifilan";
  caesarCodeShift(twelve, 12);
  std::cout << twelve << std::endl;
  EXPECT_TRUE(is::Twelve::twelve(twelve));
  twelve = "tannifilan";
  caesarCodeShift(twelve, 13);
  EXPECT_FALSE(is::Twelve::twelve(twelve));
  twelve = "fmzzuruxmz";
  caesarCodeShift(twelve, 14);
  EXPECT_TRUE(is::Twelve::twelve(twelve));
}

TEST(CaesarCode, Hamabi){
  std::string twelve = "hamabi";
  caesarCodeShift(twelve, 12);
  std::cout << twelve << std::endl;
  EXPECT_TRUE(is::Twelve::twelve(twelve));
  twelve = "hamabi";
  caesarCodeShift(twelve, 13);
  EXPECT_FALSE(is::Twelve::twelve(twelve));
  twelve = "tmymnu", 
  caesarCodeShift(twelve, 14);
  EXPECT_TRUE(is::Twelve::twelve(twelve));
}

/**
 * Representation of twelve in unary
*/
TEST(Random, Unary){
  std::string twelve = "IIIIIIIIIIII";
  EXPECT_TRUE(is::Twelve::twelve(twelve));
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

TEST(EnglishConstant, American_President){
  std::string president = "Zachary Taylor", presidentU = "ZACHARY TAYLOR";
  EXPECT_TRUE(is::Twelve::twelve(president));
  EXPECT_FALSE(is::Twelve::twelve(presidentU));
}

TEST(EnglishConstant, American_President_Vector){
  std::vector<std::string> president{"Zachary", " ", "Taylor"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Zachary ", "Taylor"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Zachary", " Taylor"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Zachary ", " Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Zachary", "Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Zachary Taylor";
  std::vector<std::string> presidentV;
  for (char c : presidentS) {
    presidentV.push_back(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentV));
}

TEST(EnglishConstant, American_President_List){
  std::list<std::string> president{"Zachary", " ", "Taylor"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Zachary ", "Taylor"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Zachary", " Taylor"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Zachary ", " Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Zachary", "Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Zachary Taylor";
  std::list<std::string> presidentL;
  for (char c : presidentS) {
    presidentL.push_back(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentL));
}

TEST(EnglishConstant, American_President_Set){
  std::set<std::string> president{"Zachary", " ", "Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Zachary ", "Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Zachary", " Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Zachary ", " Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Zachary", "Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Zachary Taylor";
  std::set<std::string> presidentSet;
  for (char c : presidentS) {
    presidentSet.insert(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentSet));
}

TEST(EnglishConstant, American_President_Multiset){
  std::multiset<std::string> president{"Zachary", " ", "Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Zachary ", "Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Zachary", " Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Zachary ", " Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Zachary", "Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Zachary Taylor";
  std::multiset<std::string> presidentSet;
  for (char c : presidentS) {
    presidentSet.insert(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentSet));
}

TEST(EnglishConstant, American_President_Map){
  std::map<std::string, std::string> president{{"Zachary", " "}, {"Taylor", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Zachary ", "Taylor"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Zachary", " Taylor"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Zachary ", " Taylor"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Zachary", "Taylor"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Zachary Taylor";
  std::map<std::string, std::string> presidentMap;
  for (char c : presidentS) {
    presidentMap.insert(std::make_pair(std::string(1, c), " "));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentMap));
}

TEST(EnglishConstant, American_President_Multimap){
  std::multimap<std::string, std::string> president{{"Zachary", " "}, {"Taylor", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Zachary ", "Taylor"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Zachary", " Taylor"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Zachary ", " Taylor"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Zachary", "Taylor"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Zachary Taylor";
  std::multimap<std::string, std::string> presidentMap;
  for (char c : presidentS) {
    presidentMap.insert(std::make_pair(std::string(1, c), " "));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentMap));
}

TEST(EnglishConstant, American_President_Queue){
  std::queue<std::string> president({"Zachary", " ", "Taylor"});
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Zachary ", "Taylor"});
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Zachary", " Taylor"});
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Zachary ", " Taylor"});
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Zachary", "Taylor"});
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Zachary Taylor";
  std::queue<std::string> presidentQueue;
  for (char c : presidentS) {
    presidentQueue.push(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentQueue));
}

TEST(EnglishConstant, American_President_ProrityQueue){
  std::vector<std::string> presidentV{"Zachary", " ", "Taylor"};
  std::priority_queue<std::string> president(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Zachary ", "Taylor"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_TRUE(is::Twelve::twelve(president));
  presidentV = {"Zachary", " Taylor"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_TRUE(is::Twelve::twelve(president));
  presidentV = {"Zachary ", " Taylor"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Zachary", "Taylor"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Zachary Taylor";
  std::priority_queue<std::string> presidentQueue;
  for (char c : presidentS) {
    presidentQueue.push(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentQueue));
}

TEST(EnglishConstant, American_President_Stack){
  std::stack<std::string> president;
  president.push("Zachary");
  president.push(" ");
  president.push("Taylor");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Zachary ");
  president.push("Taylor");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Zachary");
  president.push(" Taylor");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Zachary ");
  president.push(" Taylor");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Zachary");
  president.push("Taylor");
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Zachary Taylor";
  std::stack<std::string> presidentStack;
  for (char c : presidentS) {
    presidentStack.push(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentStack));
  presidentS = "rolyaT yrahcaZ";
  presidentStack = std::stack<std::string>();
  for (char c : presidentS) {
    presidentStack.push(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentStack));
}

TEST(EnglishConstant, American_President_Array){
  std::array<std::string, 3> president{"Zachary", " ", "Taylor"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Zachary ", "Taylor"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Zachary", " Taylor"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Zachary ", " Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Zachary", "Taylor"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Zachary Taylor";
  std::array<std::string, 100> presidentArray;
  std::size_t index = 0;
  for (char c : presidentS) {
    presidentArray[index++] = std::string(1, c);
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentArray));
}

TEST(EnglishConstant, American_President_Pair){
  std::pair<std::string, std::string> pair{"Zachary ", "Taylor"};
  EXPECT_TRUE(is::Twelve::twelve(pair));
  pair = std::make_pair("Zachary", "Taylor");
  EXPECT_FALSE(is::Twelve::twelve(pair));
}

TEST(RomanConstant, XII_Uppercase){
  EXPECT_TRUE(is::Twelve::twelve("XII"));
}

TEST(RomanConstant, XII_Uppercase_Vector){
  std::vector<std::string> XII = {"X", "I", "I"};
  EXPECT_TRUE(is::Twelve::twelve(XII));
}

TEST(RomanConstant, XII_Uppercase_List){
  std::list<std::string> XII = {"X", "I", "I"};
  EXPECT_TRUE(is::Twelve::twelve(XII));
}

TEST(RomanConstant, XII_Uppercase_Set){
  std::set<std::string> XII = {"X", "I"};
  EXPECT_FALSE(is::Twelve::twelve(XII));
}

// TEST(RomanConstant, XII_UpperCase_MultiSet){
//   std::multiset<std::string> XII = {"X", "I", "I"};
//   EXPECT_TRUE(is::Twelve::twelve(XII));
// }

// TEST(RomanConstant, XII_Uppercase_Map){
//   std::map<std::string, std::string> XII = {"X": "", "I": "", "I": ""};
//   EXPECT_TRUE(is::Twelve::twelve(XII));
// }

TEST(RomanConstant, XII_Uppercase_Array){
  std::array<std::string, 3> XII = {"X", "I", "I"};
  EXPECT_TRUE(is::Twelve::twelve(XII));
}

TEST(RomanConstant, XII_Lowercase){
  EXPECT_TRUE(is::Twelve::twelve("xii"));
}

TEST(RomanConstant, XII_Lowercase_Vector){
  std::vector<std::string> XII = {"x", "i", "i"};
  EXPECT_TRUE(is::Twelve::twelve(XII));
}

TEST(RomanConstant, XII_Lowercase_List){
  std::list<std::string> XII = {"x", "i", "i"};
  EXPECT_TRUE(is::Twelve::twelve(XII));
}

TEST(RomanConstant, XII_Lowercase_Set){
  std::set<std::string> XII = {"x", "i"};
  EXPECT_FALSE(is::Twelve::twelve(XII));
}

// TEST(RomanConstant, XII_Lowercase_MultiSet){
//   std::multiset<std::string> XII = {"x", "i", "i"};
//   EXPECT_TRUE(is::Twelve::twelve(XII));
// }

// TEST(RomanConstant, XII_Lowercase_Map){
//   std::map<std::string, std::string> XII = {"x": "", "i": "", "i": ""};
//   EXPECT_TRUE(is::Twelve::twelve(XII));
// }

TEST(RomanConstant, XII_Lowercase_Array){
  std::array<std::string, 3> XII = {"x", "i", "i"};
  EXPECT_TRUE(is::Twelve::twelve(XII));
}

TEST(BrazilianConstant, Brazilian_President){
  std::string president = "Artur Bernardes", presidentU = "ARTUR BERNARDES";
  EXPECT_TRUE(is::Twelve::twelve(president));
  EXPECT_FALSE(is::Twelve::twelve(presidentU));
}

TEST(BrazilianConstant, Brazilian_President_Vector){
  std::vector<std::string> president{"Artur", " ", "Bernardes"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Artur ", "Bernardes"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Artur", " Bernardes"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Artur ", " Bernardes"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Artur", "Bernardes"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Artur Bernardes";
  std::vector<std::string> presidentV;
  for (char c : presidentS) {
    presidentV.push_back(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentV));
}

TEST(BrazilianConstant, Brazilian_President_List){
  std::list<std::string> president{"Artur", " ", "Bernardes"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Artur ", "Bernardes"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Artur", " Bernardes"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Artur ", " Bernardes"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Artur", "Bernardes"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Artur Bernardes";
  std::list<std::string> presidentL;
  for (char c : presidentS) {
    presidentL.push_back(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentL));
}

TEST(BrazilianConstant, Brazilian_President_Set){
  std::set<std::string> president{"Artur", " ", "Bernardes"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Artur ", "Bernardes"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Artur", " Bernardes"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Artur ", " Bernardes"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Artur", "Bernardes"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Artur Bernardes";
  std::set<std::string> presidentSet;
  for (char c : presidentS) {
    presidentSet.insert(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentSet));
}

TEST(BrazilianConstant, Brazilian_President_Multiset){
  std::multiset<std::string> president{"Artur", " ", "Bernardes"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Artur ", "Bernardes"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Artur", " Bernardes"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Artur ", " Bernardes"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Artur", "Bernardes"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Artur Bernardes";
  std::multiset<std::string> presidentSet;
  for (char c : presidentS) {
    presidentSet.insert(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentSet));
}

TEST(BrazilianConstant, Brazilian_President_Map){
  std::map<std::string, std::string> president{{"Artur", " "}, {"Bernardes", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Artur ", "Bernardes"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Artur", " Bernardes"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Artur ", " Bernardes"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Artur", "Bernardes"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Artur Bernardes";
  std::map<std::string, std::string> presidentMap;
  for (char c : presidentS) {
    presidentMap.insert(std::make_pair(std::string(1, c), " "));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentMap));
}

TEST(BrazilianConstant, Brazilian_President_Multimap){
  std::multimap<std::string, std::string> president{{"Artur", " "}, {"Bernardes", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Artur ", "Bernardes"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Artur", " Bernardes"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Artur ", " Bernardes"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Artur", "Bernardes"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Artur Bernardes";
  std::multimap<std::string, std::string> presidentMap;
  for (char c : presidentS) {
    presidentMap.insert(std::make_pair(std::string(1, c), " "));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentMap));
}

TEST(BrazilianConstant, Brazilian_President_Queue){
  std::queue<std::string> president({"Artur", " ", "Bernardes"});
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Artur ", "Bernardes"});
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Artur", " Bernardes"});
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Artur ", " Bernardes"});
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Artur", "Bernardes"});
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Artur Bernardes";
  std::queue<std::string> presidentQueue;
  for (char c : presidentS) {
    presidentQueue.push(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentQueue));
}

TEST(BrazilianConstant, Brazilian_President_ProrityQueue){
  std::vector<std::string> presidentV{"Artur", " ", "Bernardes"};
  std::priority_queue<std::string> president(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Artur ", "Bernardes"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Artur", " Bernardes"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_TRUE(is::Twelve::twelve(president));
  presidentV = {"Artur ", " Bernardes"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Artur", "Bernardes"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Artur Bernardes";
  std::priority_queue<std::string> presidentQueue;
  for (char c : presidentS) {
    presidentQueue.push(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentQueue));
}

TEST(BrazilianConstant, Brazilian_President_Stack){
  std::stack<std::string> president;
  president.push("Artur");
  president.push(" ");
  president.push("Bernardes");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Artur ");
  president.push("Bernardes");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Artur");
  president.push(" Bernardes");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Artur ");
  president.push(" Bernardes");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Artur");
  president.push("Bernardes");
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Artur Bernardes";
  std::stack<std::string> presidentStack;
  for (char c : presidentS) {
    presidentStack.push(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentStack));
  presidentS = "sedranreB rutrA";
  presidentStack = std::stack<std::string>();
  for (char c : presidentS) {
    presidentStack.push(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentStack));
}

TEST(BrazilianConstant, Brazilian_President_Array){
  std::array<std::string, 3> president{"Artur", " ", "Bernardes"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Artur ", "Bernardes"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Artur", " Bernardes"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Artur ", " Bernardes"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::array<std::string, 3>{"Artur", "Bernardes"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Artur Bernardes";
  std::array<std::string, 100> presidentArray;
  std::size_t index = 0;
  for (char c : presidentS) {
    presidentArray[index++] = std::string(1, c);
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentArray));
}

TEST(BrazilianConstant, Brazilian_President_Pair){
  std::pair<std::string, std::string> pair{"Artur ", "Bernardes"};
  EXPECT_TRUE(is::Twelve::twelve(pair));
  pair = std::make_pair("Artur", "Bernardes");
  EXPECT_FALSE(is::Twelve::twelve(pair));
}

TEST(ArgentinaConstant, Argentina_President){
  std::string president = "Luis Sáenz Peña", presidentU = "LUIS SÁENZ PEÑA";
  EXPECT_TRUE(is::Twelve::twelve(president));
  EXPECT_FALSE(is::Twelve::twelve(presidentU));
}

TEST(ArgentinaConstant, Argentina_President_Vector){
  std::vector<std::string> president{"Luis", " ", "Sáenz", " ", "Peña"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Luis ", "Sáenz", " ", "Peña"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Luis", " ", "Sáenz ", "Peña"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Luis ", "Sáenz ", "Peña"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Luis", "Sáenz", "Peña"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Luis Sáenz Peña";
  std::vector<std::string> presidentV;
  for (char c : presidentS) {
    presidentV.push_back(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentV));
}

TEST(ArgentinaConstant, Argentina_President_List){
  std::list<std::string> president{"Luis", " ", "Sáenz", " ", "Peña"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Luis ", "Sáenz", " ", "Peña"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Luis", " ", "Sáenz ", "Peña"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Luis ", "Sáenz ", "Peña"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Luis", "Sáenz", "Peña"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Luis Sáenz Peña";
  std::list<std::string> presidentL;
  for (char c : presidentS) {
    presidentL.push_back(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentL));
}

TEST(ArgentinaConstant, Argentina_President_Set){
  std::set<std::string> president{"Luis", " ", "Sáenz", " ", "Peña"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Luis ", "Sáenz", " ", "Peña"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Luis", " ", "Sáenz ", "Peña"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Luis ", "Sáenz ", "Peña"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Luis", "Sáenz", "Peña"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Luis Sáenz Peña";
  std::set<std::string> presidentSet;
  for (char c : presidentS) {
    presidentSet.insert(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentSet));
}

TEST(ArgentinaConstant, Argentina_President_Multiset){
  std::multiset<std::string> president{"Luis", " ", "Sáenz", " ", "Peña"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Luis ", "Sáenz", " ", "Peña"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Luis", " ", "Sáenz ", "Peña"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Luis ", "Sáenz ", "Peña"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Luis", "Sáenz", "Peña"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Luis Sáenz Peña";
  std::multiset<std::string> presidentSet;
  for (char c : presidentS) {
    presidentSet.insert(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentSet));
}

TEST(ArgentinaConstant, Argentina_President_Map){
  std::map<std::string, std::string> president{{"Luis", " "}, {"Sáenz", " "}, {"Peña", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Luis ", "Sáenz"}, {"Peña", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Luis", " "}, {"Sáenz ", "Peña"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Luis ", "Sáenz "}, {"Peña", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Luis", "Sáenz"}, {"Peña", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Luis Sáenz Peña";
  std::map<std::string, std::string> presidentMap;
  for (char c : presidentS) {
    presidentMap.insert(std::make_pair(std::string(1, c), " "));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentMap));
}

TEST(ArgentinaConstant, Argentina_President_Multimap){
  std::multimap<std::string, std::string> president{{"Luis", " "}, {"Sáenz", " "}, {"Peña", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Luis ", "Sáenz"}, {"Peña", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Luis", " "}, {"Sáenz ", "Peña"}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Luis ", "Sáenz "}, {"Peña", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {{"Luis", "Sáenz"}, {"Peña", " "}};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Luis Sáenz Peña";
  std::multimap<std::string, std::string> presidentMap;
  for (char c : presidentS) {
    presidentMap.insert(std::make_pair(std::string(1, c), " "));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentMap));
}

TEST(ArgentinaConstant, Argentina_President_Queue){
  std::queue<std::string> president({"Luis", " ", "Sáenz", " ", "Peña"});
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Luis ", "Sáenz", " ", "Peña"});
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Luis", " ", "Sáenz ", "Peña"});
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Luis ", "Sáenz ", "Peña"});
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::queue<std::string>({"Luis", "Sáenz", "Peña"});
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Luis Sáenz Peña";
  std::queue<std::string> presidentQueue;
  for (char c : presidentS) {
    presidentQueue.push(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentQueue));
}

TEST(ArgentinaConstant, Argentina_President_ProrityQueue){
  std::vector<std::string> presidentV{"Luis", " ", "Sáenz", " ", "Peña"};
  std::priority_queue<std::string> president(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Luis ", "Sáenz", " ", "Peña"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Luis", " ", "Sáenz ", "Peña"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Luis ", "Sáenz ", "Peña"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  presidentV = {"Luis", "Sáenz", "Peña"};
  president = std::priority_queue<std::string>(presidentV.begin(), presidentV.end());
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Luis Sáenz Peña";
  std::priority_queue<std::string> presidentQueue;
  for (char c : presidentS) {
    presidentQueue.push(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentQueue));
}

TEST(ArgentinaConstant, Argentina_President_Stack){
  std::stack<std::string> president;
  president.push("Luis");
  president.push(" ");
  president.push("Sáenz");
  president.push(" ");
  president.push("Peña");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Luis ");
  president.push("Sáenz");
  president.push(" ");
  president.push("Peña");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Luis");
  president.push(" ");
  president.push("Sáenz ");
  president.push("Peña");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Luis ");
  president.push("Sáenz ");
  president.push("Peña");
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = std::stack<std::string>();
  president.push("Luis");
  president.push("Sáenz");
  president.push("Peña");
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Luis Sáenz Peña";
  std::stack<std::string> presidentStack;
  for (char c : presidentS) {
    presidentStack.push(std::string(1, c));
  }
  EXPECT_FALSE(is::Twelve::twelve(presidentStack));
  presidentS = "añeP zneáS siuL";
  presidentStack = std::stack<std::string>();
  for (char c : presidentS) {
    presidentStack.push(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentStack));
}

TEST(ArgentinaConstant, Argentina_President_Array){
  std::array<std::string, 5> president{"Luis", " ", "Sáenz", " ", "Peña"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::array<std::string, 5>{"Luis ", "Sáenz", " ", "Peña"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::array<std::string, 5>{"Luis", " ", "Sáenz ", "Peña"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::array<std::string, 5>{"Luis ", "Sáenz ", "Peña"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::array<std::string, 5>{"Luis", "Sáenz", "Peña"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Luis Sáenz Peña";
  std::array<std::string, 100> presidentArray;
  std::size_t index = 0;
  for (char c : presidentS) {
    presidentArray[index++] = std::string(1, c);
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentArray));
}

TEST(ArgentinaConstant, Argentina_President_Pair){
  std::pair<std::string, std::string> pair{"Luis ", "Sáenz Peña"};
  EXPECT_TRUE(is::Twelve::twelve(pair));
  pair = std::make_pair("Luis", "Sáenz");
  EXPECT_FALSE(is::Twelve::twelve(pair));
}

TEST(SouthAfricaConstant, SouthAfrica_President){
  std::string president = "Cyril Ramaphosa", presidentU = "CYRIL RAMAPHOSA";
  EXPECT_TRUE(is::Twelve::twelve(president));
  EXPECT_FALSE(is::Twelve::twelve(presidentU));
}

TEST(SouthAfricaConstant, SouthAfrica_President_Vector){
  std::vector<std::string> president = {"Cyril", " ", "Ramaphosa"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Cyril", " Ramaphosa"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Cyril ", "Ramaphosa"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Cyril", "Ramaphosa"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Cyril ", " Ramaphosa"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Cyril Ramaphosa";
  std::vector<std::string> presidentV;
  for(char c : presidentS){
    presidentV.push_back(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentV));
}

TEST(SouthAfricaConstant, SouthAfrica_President_List){
  std::list<std::string> president = {"Cyril", " ", "Ramaphosa"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Cyril", " Ramaphosa"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Cyril ", "Ramaphosa"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = {"Cyril", "Ramaphosa"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  president = {"Cyril ", " Ramaphosa"};
  EXPECT_FALSE(is::Twelve::twelve(president));
  std::string presidentS = "Cyril Ramaphosa";
  std::list<std::string> presidentL;
  for(char c : presidentS){
    presidentL.push_back(std::string(1, c));
  }
  EXPECT_TRUE(is::Twelve::twelve(presidentL));
}

TEST(SouthAfricaConstant, SouthAfrica_President_Pair){
  std::pair<std::string, std::string> president = {"Cyril", " Ramaphosa"};
  EXPECT_TRUE(is::Twelve::twelve(president));
  president = std::make_pair("Cyril", "Ramaphosa");
  EXPECT_FALSE(is::Twelve::twelve(president));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
