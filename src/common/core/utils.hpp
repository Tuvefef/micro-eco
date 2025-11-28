#ifndef UTIL_COMMONS
#define UTIL_COMMONS

#include <variant>

constexpr int WIDTH = 14;
constexpr int HEIGHT = 14;
inline bool ROCKMAP[WIDTH][HEIGHT] = {false};

constexpr unsigned int TICKS = 500;
constexpr unsigned int PLAYERENERG = 50;

const int gprey0 = 5;

using incvar = std::variant<int, char>;

inline double gpowx2(double g)
{
    return g * g; 
}

inline bool areNear(int x1, int y1, int x2, int y2, int rad)
{
    int rx = x1 - x2;
    int ry = y1 - y2;
    int f = (gpowx2(rx) + gpowx2(ry)) <= (gpowx2(rad));
    return f;
}

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