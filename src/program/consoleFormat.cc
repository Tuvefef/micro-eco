#include "consoleFormat.h"

std::string Consoleformat::green()
{
    return "\033[32m\033[1m";
}

std::string Consoleformat::blue()
{
    return "\033[34m";
}

std::string Consoleformat::reset()
{
    return "\033[0m";
}

std::string Consoleformat::cyan()
{
    return "\033[36m\033[1m";
}

std::string Consoleformat::purple()
{
    return "\033[35m\033[1m";
}

std::string Consoleformat::yellow()
{
    return "\033[33m\033[6m";
}

std::string Consoleformat::red()
{
    return "\033[31m\033[1m";
}

std::string Consoleformat::consoleclear()
{
    return "\033[2J\033[H";
}