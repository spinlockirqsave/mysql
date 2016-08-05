/*
 * @file    Utility.cpp
 * @author  Piotr Gregor <piotrek.gregor gmail com>
 * @brief   Helper methods.
 */


#include "Utility.h"


bool Utility::mountSingle(std::string& s, const std::string& value, const std::string& logMark, const std::string& paramMark)
{
    std::string::size_type begin = s.find(logMark), logMarkLen = logMark.size();
    if (begin == std::string::npos)
    {
        return false;
    }
    std::string::size_type end = s.find(logMark, begin + logMarkLen);
    if (end == std::string::npos)
    {
        return false;
    }
    s.replace(begin, end - begin + logMarkLen, value);
    return true;
}

std::string Utility::mountAll(std::string logText, std::string params, const std::string& logMark, const std::string& paramMark)
{
    std::string paramValue;
    std::string::size_type begin, end = 0, paramMarkLen = paramMark.size();
    while ((begin = params.find(paramMark, end)) != std::string::npos)
    {
        end = params.find(paramMark, paramMarkLen + begin);
        if (end == std::string::npos)
        {
            return logText;
        }
        paramValue = params.substr(begin + paramMarkLen, end - begin - paramMarkLen);
        mountSingle(logText, paramValue, logMark, paramMark);
    }

    return logText;
}
