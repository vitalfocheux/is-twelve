#include "Twelve.h"

#include <iostream>
#include <locale>
#include <string>
#include <codecvt>

namespace is {
    bool Twelve::twelve(bool n){
        return n;
    }
    bool Twelve::twelve(char n){
        return n == constant::twelve_c;
    }
    bool Twelve::twelve(signed char n){
        return n == constant::twelve_c;
    }
    bool Twelve::twelve(unsigned char n){
        return n == constant::twelve_c;
    }
    bool Twelve::twelve(short n){
        return n == constant::TWELVE;
    }
    bool Twelve::twelve(unsigned short n){
        return n == constant::TWELVE;
    }
    bool Twelve::twelve(int n){
        return n == constant::TWELVE;
    }
    bool Twelve::twelve(unsigned int n){
        return n == constant::TWELVE;
    }
    bool Twelve::twelve(long n){
        return n == constant::TWELVE;
    }
    bool Twelve::twelve(unsigned long n){
        return n == constant::TWELVE;
    }
    bool Twelve::twelve(long long n){
        return n == constant::TWELVE;
    }
    bool Twelve::twelve(unsigned long long n){
        return n == constant::TWELVE;
    }


    bool Twelve::twelve(wchar_t n){
        return n == constant::TWELVE;
    }
    bool Twelve::twelve(char16_t n){
        return n == constant::TWELVE;
    }
    bool Twelve::twelve(char32_t n){
        return n == constant::TWELVE;
    }

    bool Twelve::twelve(float n){
        return n == constant::TWELVE;
    }
    bool Twelve::twelve(double n){
        return n == constant::TWELVE;
    }
    bool Twelve::twelve(long double n){
        return n == constant::TWELVE;
    }

    bool Twelve::twelve(std::string n){
        return n == "12" || constant::twelve_s.find(n) != constant::twelve_s.end();
    }

    bool Twelve::twelve(std::wstring n){
        if(n == L"12"){
            return true;
        }
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        std::string str = converter.to_bytes(n);
        return constant::twelve_s.find(str) != constant::twelve_s.end();
    }

    bool Twelve::twelve(std::u16string n){
        if(n == u"12"){
            return true;
        }
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
        std::string str = converter.to_bytes(n);
        return constant::twelve_s.find(str) != constant::twelve_s.end();
    }

    bool Twelve::twelve(std::u32string n){
        if(n == U"12"){
            return true;
        }
        std::wstring_convert<std::codecvt_utf8_utf16<char32_t>, char32_t> converter;
        std::string str = converter.to_bytes(n);
        return constant::twelve_s.find(str) != constant::twelve_s.end();
    }

    
}