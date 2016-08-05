/*
 * @file    Utility.h
 * @author  Piotr Gregor <piotrek.gregor gmail com>
 * @brief   Helper methods.
 */

#ifndef UTILITY_H
#define UTILITY_H


#include <iostream>
#include <string>
#include <sstream>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>


namespace Utility {
    bool mountSingle(std::string& s, const std::string& value, const std::string& logMark, const std::string& paramMark);
    std::string mountAll(std::string logText, std::string params, const std::string& logMark, const std::string& paramMark);
    /* trim from start (in place) */
    static inline void ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                    std::not1(std::ptr_fun<int, int>(std::isspace))));
    }
    /* trim from end (in place) */
    static inline void rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(),
                    std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    }
}

#endif /* UTILITY_H */
