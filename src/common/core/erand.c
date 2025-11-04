#include "erand.h"

uint32_t gLCGForml(void)
{
    gseed32 = lcga * gseed32 + lcgc;
    return gseed32;
}

uint16_t gSrand16(uint16_t g)
{
    gseed32 = (uint32_t)g;
    return (uint16_t)gseed32;
}

uint8_t gSrand8(uint8_t g)
{
    gseed32 = (uint32_t)g;
    return (uint8_t)gseed32;
}

uint16_t gRand16(void)
{
    return (uint16_t)(ESHFT8(gLCGForml()) & GRANDVAL16);
}

uint8_t gRand8(void)
{
    return (uint8_t)(EBLENDXOR(gLCGForml()) & GRANDVAL8);
}

uint16_t grandmod16(uint16_t n)
{
    return gRand16() % n;
}

uint8_t grandmod8(uint8_t n)
{
    return gRand8() % n;
}