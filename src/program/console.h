#ifndef CONSOLESYSH
#define CONSOLESYSH

#include <string>

class Consoleformat
{
    public:
        std::string green();
        std::string blue();
        std::string reset();
        std::string cyan();
        std::string purple();
        std::string yellow();
        std::string red();
        std::string grey();
        std::string consoleclear();
};

#endif