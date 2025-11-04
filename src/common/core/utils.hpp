#ifndef UTIL_COMMONS
#define UTIL_COMMONS

#include <variant>

#define ESHFT8CC(x) ((x) >> (8))
#define ESHFT16CC(x) ((x) >> (16))
#define EBLENDXORCC(x) ((ESHFT8CC(x)) ^ (ESHFT16CC(x))) 

constexpr int WIDTH = 12;
constexpr int HEIGHT = 12;

constexpr unsigned int TICKS = 500;
constexpr unsigned int PLAYERENERG = 50;

const int gprey0 = 5;

using incvar = std::variant<int, char>;

template <typename T>
T minn(T x, T y)
{
    return ((x) < (y)) ? (x) : (y);
}

template <typename T>
T maxn(T x, T y)
{
    return ((x) > (y)) ? (x) : (y);
}

#endif