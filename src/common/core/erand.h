#ifndef RAND168B
#define RAND168B

#include <stdint.h>

#define RAND8
#define MAXGRAND8

#define ESHFT8(x) ((x) >> 8)
#define EBLENDXOR(x) (((x) >> 8) ^ ((x) >> 16))

static const uint32_t lcga = 1664525u;
static const uint32_t lcgc = 1013904223u;
static uint32_t gseed32u = 1u;

static inline uint32_t gLGCrand(uint32_t *gseed)
{
    *gseed = lcga * *gseed + lcgc;
    return *gseed;
}

static inline void gSrand(uint32_t g)
{
    gseed32u = g;
}

#if defined(MAXGRAND32)
    #define GLIMR 0xffffffff
#elif defined(MAXGRAND16)
    #define GLIMR 0xffff
#elif defined(MAXGRAND8) || (!defined(MAXGRAND8) && !defined(MAXGRAND16) && !defined(MAXGRAND32))
    #if !defined(MAXGRAND8) && !defined(MAXGRAND16) && !defined(MAXGRAND32)
        #pragma message("no RANDMAX mode defined!... defaulting to 8bit")
    #endif
    #define GLIMR 0xff
#endif
#if defined(RAND32)
    typedef uint32_t uintg_t;

    #define seedptr (&gseed32u)
    #define GEXP_CASTR(x) ((uint32_t)(x) & GLIMR)
#elif defined(RAND16)
    typedef uint16_t uintg_t;

    #define seedptr (&gseed32u)
    #define GEXP_CASTR(x) ((uint16_t)(ESHFT8(x) & GLIMR))
#elif defined(RAND8) || (!defined(RAND8) && !defined(RAND16) && !defined(RAND32))
    #if !defined(RAND8) && !defined(RAND16) && !defined(RAND32)
        #pragma message("rand type undef!... defaulting to 8bit")
    #endif

    typedef uint8_t uintg_t;

    #define seedptr (&gseed32u)
    #define GEXP_CASTR(x) ((uint8_t)(EBLENDXOR(x) & GLIMR))
#endif

static inline uintg_t grand(void)
{
    return GEXP_CASTR(gLGCrand(seedptr));
}

static inline uintg_t grmod(uintg_t n)
{
    return grand() % n;
}

#endif