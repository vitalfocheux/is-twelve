/**
 * All the constants related to twelve.
 * All the constants in different languages but essentially in English and French
*/

#ifndef CONSTANT_TWELVE_H
#define CONSTANT_TWELVE_H

#include <set>
#include <string>

std::string caesarCode(std::string code, int shift){
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
    return codeShift;
}

namespace constant {

    constexpr int TWELVE = 12;
    constexpr char twelve_c = '0' + 12;

    const std::set<std::string> twelve_s = {
        /**
         * Twelve in different languages.
        */
        "xii", // Roman numeral lowercase
        "XII", // Roman numeral uppercase
        "douze", // French
        "douzième", // French (ordinal)
        "twelve", // English
        "doce", // Spanish
        "اثني عشر", // Arabic
        "dymbëdhjetë", // Albanian
        "zwölf", // German
        "አስራ ሁለት", // Amharic
        "տասներկու", // Armenian
        "বাৰ", // Assamese
        "tunka paya", // Aymara
        "on iki", // Azerbaijani
        "tannifilan", // Bambara
        "hamabi", // Basque
        "বারো", // Bengali
        "बारह", // Hindi
        "дванаццаць", // Belarusian
        "ဆယ့်နှစ်", // Birman
        "dvanaest", // Bosnian
        "дванадесет", // Bulgarian

        /**
         * Twelve in different language with caesar code
        */
        "fiqxhq", // Twelve
        "paglq", // Douze
        "paoq", // Doce
        "JUU", // XII
        "juu", // xii
        "fgzwm bmkm", // tunka_paya
        "az uwu", // On iki
        "fmzzuruxmz", // Tannifilan
        "tmymnu", // Hamabi

        /**
         * French
        */

        /**
         * Presidents
        */
        "Alexandre Millerand", // 12th President of France
        "Zachary Taylor", // 12th President of the United States
        "Artur Bernardes", // 12th President of Brazil
        "Luis Sáenz Peña", // 12th President of Argentina
        "Cyril Ramaphosa", // 12th President of South Africa 
        "Ilir Meta", // 12th President of Albania
        "Alexander Van der Bellen", // 12th President of Austria
        "Badrudozza Chowdhury", // 12th President of Bangladesh
        "Jorge Córdova", // 12th President of Bolivia
        "José Manuel Balmaceda Fernández", // 12th President of Chile
        "Liborio Mejía Gutiérrez de Lara", // 12th President of Colombia
        "Moon Jae-in", // 12th President of South Korea
        "Sauli Niinistö", // 12th President of Finland
        "Pierre Théoma Boisrond-Canal", // 12th President of Haiti
        "Pratibha Patil", // 12th President of India
        "Sergio Mattarella", // 12th President of Italy
        "Keikō Tennō", // 12th Emperor of Japan
        "景行天皇", // 12th Emperor of Japan (in Japanese)
    };
}

#endif // CONSTANT_TWELVE_H
