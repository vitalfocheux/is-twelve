#ifndef TWELVE_H
#define TWELVE_H

#include "Constant_Twelve.h"
#include <string>
#include <vector>
#include <list>
#include <map>
#include <tuple>
#include <set>
#include <array>
#include <queue>
#include <stack>
#include <iostream>

namespace is {

    class Twelve {
        public:
            static bool twelve(bool n);
            static bool twelve(char n);
            static bool twelve(signed char n);
            static bool twelve(unsigned char n);
            static bool twelve(short n);
            static bool twelve(unsigned short n);
            static bool twelve(int n);
            static bool twelve(unsigned int n);
            static bool twelve(long n);
            static bool twelve(unsigned long n);
            static bool twelve(long long n);
            static bool twelve(unsigned long long n);


            static bool twelve(wchar_t n);
            static bool twelve(char16_t n);
            static bool twelve(char32_t n);

            static bool twelve(float n);
            static bool twelve(double n);
            static bool twelve(long double n);

            static bool twelve(std::string n);
            static bool twelve(std::wstring n);
            static bool twelve(std::u16string n);
            static bool twelve(std::u32string n);

            template<typename T>
            static bool twelve(std::vector<T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                T value;
                for(const auto& v : n){
                    twelve(v);
                }
                return false;
            }

            template<typename T>
            static bool twelve(std::list<T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                T value;
                for(auto v : n){
                    twelve(v);
                    value += v;
                }
                return twelve(value);
            }

            template<typename T>
            static bool twelve(std::set<T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                if(n.empty()){
                    return false;
                }
                T value;
                for(auto v : n){
                    twelve(v);
                    value += v;
                }
                return twelve(value);
            }

            template<typename T>
            static bool twelve(std::multiset<T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                T value;
                for(auto v : n){
                    twelve(v);
                    value += v;
                }
                return twelve(value);
            }

            /**
             * TODO
            */
            template<typename K, typename T>
            static bool twelve(std::map<K, T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                T value;
                for(const auto& v : n){

                }
                return twelve(value);
            }

            template<typename K, typename T>
            static bool twelve(std::multimap<K, T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                std::size_t value = 0;
                for(auto v : n){
                    twelve(v);
                    value += v;
                }
                return value == constant::TWELVE;
            }

            template<typename T>
            static bool twelve(std::queue<T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                std::size_t value = 0;
                for(auto v : n){
                    twelve(v);
                    value += v;
                }
                return value == constant::TWELVE;
            }

            template<typename T>
            static bool twelve(std::priority_queue<T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                std::size_t value = 0;
                for(auto v : n){
                    twelve(v);
                    value += v;
                }
                return value == constant::TWELVE;
            }

            template<typename T>
            static bool twelve(std::stack<T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                std::size_t value = 0;
                for(auto v : n){
                    twelve(v);
                    value += v;
                }
                return value == constant::TWELVE;
            }

            template<typename T, std::size_t N>
            static bool twelve(std::array<T, N> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                std::size_t value = 0;
                for(auto v : n){
                    twelve(v);
                    value += v;
                }
                return value == constant::TWELVE;
            }

            template<typename T>
            static bool twelve(std::tuple<T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                std::size_t value = 0;
                for(auto v : n){
                    twelve(v);
                    value += v;
                }
                return value == constant::TWELVE;
            }

            template<typename T1, typename T2>
            static bool twelve(std::pair<T1, T2> n){
                return twelve(n.first) || twelve(n.second) || twelve(n.first + n.second);
            }
            
    };
}

#endif // TWELVE_H
