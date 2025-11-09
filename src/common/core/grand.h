#ifndef GRANDH
#define GRANDH

#include <stdint.h>

#define LCG0 1664525u
#define LCG1 1013904223u
#define LIMR 0xffu
#define gblend8(g) ((uint8_t)((((g) ^ ((g) >> 8)) ^ (((g) ^ ((g) >> 8)) >> 16))))

static uint32_t gseed = 1u;

static inline uint32_t glcgforml(uint32_t *m)
{
    *m = LCG0 * (*m) + LCG1;
    return *m;
}

static inline uint8_t grand(void)
{
    uint32_t g = glcgforml(&gseed);
    return gblend8(g);
}

static inline void gsrand(uint32_t g)
{
    gseed = g ? g : 1u;
}

static inline uint32_t grmod(uint32_t m)
{
    return m ? (grand() % m) : 0u;
}

static inline float grandf(void)
{
    return (float)grand() / (float)(LIMR);
}

#endif