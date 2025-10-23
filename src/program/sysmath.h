#ifndef SYSMATHH
#define SYSMATHH

template <typename T>
T gmax(T x, T y)
{
    return (x > y) ? x : y;
}

template <typename T>
T gmin(T x, T y)
{
    return (x < y) ? x : y;
}

#define gclamp(x, min, max) (gmax(min, gmin(max, x)))

#endif