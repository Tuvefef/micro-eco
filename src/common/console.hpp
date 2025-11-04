#pragma once

#include <string>

namespace console
{
    std::string green = "\033[32m";
    std::string greenb = "\033[1;32m";
    std::string reset = "\033[39m";
    std::string grey = "\033[37m";
    std::string red = "\033[31m";
    std::string redb = "\033[1;31m";
    std::string cyan = "\033[36m";
    std::string yellow = "\033[33m";
    std::string yellowb = "\033[33m\033[6m";

    std::string consoleClean = "\033[2J\033[H";
};// namespace console