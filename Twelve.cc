#include "Twelve.h"

namespace is {
    static bool twelve(bool n){
        return n;
    }
    static bool twelve(char n){
        return n == 12;
    }
    static bool twelve(signed char n){
        return n == 12;
    }
    static bool twelve(unsigned char n){
        return n == 12;
    }
    static bool twelve(short n){
        return n == 12;
    }
    static bool twelve(unsigned short n){
        return n == 12;
    }
    static bool twelve(int n){
        return n == 12;
    }
    static bool twelve(unsigned int n){
        return n == 12;
    }
    static bool twelve(long n){
        return n == 12;
    }
    static bool twelve(unsigned long n){
        return n == 12;
    }
    static bool twelve(long long n){
        return n == 12;
    }
    static bool twelve(unsigned long long n){
        return n == 12;
    }


    static bool twelve(wchar_t n){
        return n == 12;
    }
    static bool twelve(char16_t n){
        return n == 12;
    }
    static bool twelve(char32_t n){
        return n == 12;
    }

    static bool twelve(float n){
        return n == 12;
    }
    static bool twelve(double n){
        return n == 12;
    }
    static bool twelve(long double n){
        return n == 12;
    }

    static bool twelve(std::string n){
        return n == "12";
    }
    static bool twelve(std::wstring n){
        return n == L"12";
    }
    static bool twelve(std::u16string n){
        return n == u"12";
    }
    static bool twelve(std::u32string n){
        return n == U"12";
    }

    template<typename T>
    static bool twelve(std::vector<T> n){
        return n.size() == 12;
    }

    template<typename T>
    static bool twelve(std::list<T> n){
        return n.size() == 12;
    }

    template<typename T>
    static bool twelve(std::set<T> n){
        return n.size() == 12;
    }

    template<typename T>
    static bool twelve(std::multiset<T> n){
        return n.size() == 12;
    }

    template<typename K, typename T>
    static bool twelve(std::map<K, T> n){
        return n.size() == 12;
    }

    template<typename K, typename T>
    static bool twelve(std::multimap<K, T> n){
        return n.size() == 12;
    }

    template<typename T>
    static bool twelve(std::queue<T> n){
        return n.size() == 12;
    }

    template<typename T>
    static bool twelve(std::priority_queue<T> n){
        return n.size() == 12;
    }

    template<typename T>
    static bool twelve(std::stack<T> n){
        return n.size() == 12;
    }

    template<typename T, std::size_t N>
    static bool twelve(std::array<T, N> n){
        return n.size() == 12;
    }

    template<typename T>
    static bool twelve(std::tuple<T> n){
        return n.size() == 12;
    }

    template<typename T1, typename T2>
    static bool twelve(std::pair<T1, T2> n){
        return n.size() == 12;
    }
}