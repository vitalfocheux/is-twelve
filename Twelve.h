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
#include <type_traits>

namespace is {

    class Twelve {
        public:
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
                if(n.empty()){
                    return false;
                }
                std::vector<T> value_c;
                T value = T();
                for(const auto& v : n){
                    if(twelve(v)){
                        return true;
                    }
                    if constexpr (is_one_of<T>::value) {
                        value += v;
                    } else if constexpr (is_std_vector<T>::value){
                        continue;
                    }else{
                        value_c.push_back(v);
                    }
                }
                return twelve(value) || twelve(value_c);
            }

            template<typename T>
            static bool twelve(std::list<T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                if(n.empty()){
                    return false;
                }
                std::vector<T> value;
                for(const auto& v : n){
                    if(twelve(v)){
                        return true;
                    }
                    value.push_back(v);
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
                std::vector<T> value;
                for(const auto& v : n){
                    if(twelve(v)){
                        return true;
                    }
                    value.push_back(v);
                }
                return twelve(value);
            }

            template<typename T>
            static bool twelve(std::multiset<T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                if(n.empty()){
                    return false;
                }
                std::vector<T> value;
                for(const auto& v : n){
                    if(twelve(v)){
                        return true;
                    }
                    value.push_back(v);
                }
                return twelve(value);
            }

            template<typename K, typename T>
            static bool twelve(std::map<K, T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                if(n.empty()){
                    return false;
                }
                std::vector<K> key;
                std::vector<T> value;
                for(const auto& v : n){
                    if(twelve(v.first) || twelve(v.second)){
                        return true;
                    }
                    key.push_back(v.first);
                    value.push_back(v.second);
                }
                return twelve(key) || twelve(value);
            }

            template<typename K, typename T>
            static bool twelve(std::multimap<K, T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                if(n.empty()){
                    return false;
                }
                std::vector<K> key;
                std::vector<T> value;
                for(const auto& v : n){
                    if(twelve(v.first) || twelve(v.second)){
                        return true;
                    }
                    key.push_back(v.first);
                    value.push_back(v.second);
                }
                return twelve(key) || twelve(value);
            }

            template<typename T>
            static bool twelve(std::queue<T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                if(n.empty()){
                    return false;
                }
                std::vector<T> value;
                while(!n.empty()){
                    if(twelve(n.front())){
                        return true;
                    }
                    value.push_back(n.front());
                    n.pop();
                }
                return twelve(value);
            }

            template<typename T>
            static bool twelve(std::priority_queue<T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                if(n.empty()){
                    return false;
                }
                std::vector<T> value;
                while(!n.empty()){
                    if(twelve(n.top())){
                        return true;
                    }
                    value.push_back(n.top());
                    n.pop();
                }
                return twelve(value);
            }

            template<typename T>
            static bool twelve(std::stack<T> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                if(n.empty()){
                    return false;
                }
                std::vector<T> value;
                while(!n.empty()){
                    if(twelve(n.top())){
                        return true;
                    }
                    value.push_back(n.top());
                    n.pop();
                }
                return twelve(value);
            }

            template<typename T, std::size_t N>
            static bool twelve(std::array<T, N> n){
                if(n.size() == constant::TWELVE){
                    return true;
                }
                if(n.empty()){
                    return false;
                }
                std::vector<T> value;
                for(const auto& v : n){
                    if(twelve(v)){
                        return true;
                    }
                    value.push_back(v);
                }
                return twelve(value);
            }            

            template<typename T1, typename T2>
            static bool twelve(std::pair<T1, T2> n){
                return twelve(n.first) || twelve(n.second) || twelve(n.first + n.second);
            }
        private:
            template <typename T>
            struct is_one_of : std::disjunction<
                std::is_same<T, char>,
                std::is_same<T, signed char>,
                std::is_same<T, unsigned char>,
                std::is_same<T, short>,
                std::is_same<T, unsigned short>,
                std::is_same<T, int>,
                std::is_same<T, unsigned int>,
                std::is_same<T, long>,
                std::is_same<T, unsigned long>,
                std::is_same<T, long long>,
                std::is_same<T, unsigned long long>,
                std::is_same<T, wchar_t>,
                std::is_same<T, char16_t>,
                std::is_same<T, char32_t>,
                std::is_same<T, float>,
                std::is_same<T, double>,
                std::is_same<T, long double>,
                std::is_same<T, std::string>,
                std::is_same<T, std::wstring>,
                std::is_same<T, std::u16string>,
                std::is_same<T, std::u32string>
            > {};

            // Spécialisation de modèle pour vérifier si un type T est un std::vector
            template <typename T>
            struct is_std_vector : std::false_type {};

            template <typename T, typename Alloc>
            struct is_std_vector<std::vector<T, Alloc>> : std::true_type {};

            template<typename T>
            struct is_std_list : std::false_type {};

            template <typename T, typename Alloc>
            struct is_std_list<std::list<T, Alloc>> : std::true_type {};

            template<typename T>
            struct is_std_set : std::false_type {};

            template<typename T, typename Alloc>
            struct is_std_set<std::set<T, Alloc>> : std::true_type {};

            template<typename T>
            struct is_std_multiset : std::false_type {};
            
            template<typename T, typename Alloc>
            struct is_std_multiset<std::multiset<T, Alloc>> : std::true_type {};

            template<typename T>
            struct is_std_map : std::false_type {};

            template<typename K, typename T, typename Alloc>
            struct is_std_map<std::map<K, T, Alloc>> : std::true_type {};

            template<typename T>
            struct is_std_multimap : std::false_type {};

            template<typename K, typename T, typename Alloc>
            struct is_std_multimap<std::multimap<K, T, Alloc>> : std::true_type {};

            template<typename T>
            struct is_std_queue : std::false_type {};

            template<typename T, typename Alloc>
            struct is_std_queue<std::queue<T, Alloc>> : std::true_type {};

            template<typename T>
            struct is_std_priority_queue : std::false_type {};

            template<typename T, typename Alloc>
            struct is_std_priority_queue<std::priority_queue<T, Alloc>> : std::true_type {};

            template<typename T>
            struct is_std_stack : std::false_type {};

            template<typename T, typename Alloc>
            struct is_std_stack<std::stack<T, Alloc>> : std::true_type {};

            template<typename T>
            struct is_std_array : std::false_type {};

            template<typename T, std::size_t N>
            struct is_std_array<std::array<T, N>> : std::true_type {};
    };
}

#endif // TWELVE_H
