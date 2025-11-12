#ifndef GRANDH
#define GRANDH

#include <stdint.h>

#define LCG0 1664525u
#define LCG1 1013904223u
#define LIMG 0xff

#define MIX8(g) ((uint8_t)(((g) >> 24) ^ ((g) >> 16) ^ ((g) >> 8) ^ (g)))
#define XORBLEND(g) (((g) ^ ((g) >> 8)) ^ (((g) ^ ((g) >> 8)) >> 16))

static uint32_t gseed = 1u;

static inline uint32_t glcgforml(uint32_t *m)
{
    *m = (uint32_t)(LCG0 * (*m) + LCG1);
    return *m;
}

static inline uint8_t grand(void)
{
    uint32_t g = glcgforml(&gseed);
    return MIX8(g);
}

static inline void gsrand(uint32_t g)
{
    gseed = g ? g : 1u;
}

static inline uint8_t grmod(uint32_t m)
{
    if(!m) return 0u;
    uint8_t g = grand();

    //  g ^= g >> 8;
    //  g ^= g >> 16;

    return g % m;
}

static inline float grandf(void)
{
    return (float)grand() / (float)LIMG;
}

static inline double grandd(void)
{
    return (double)grand() / (double)LIMG;
}

#endif
