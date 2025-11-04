#ifndef RAND168B
#define RAND168B

#include <stdint.h>

#define GRANDVAL8 0xff
#define GRANDVAL16 0xffff

#define ESHFT8(x) ((x) >> (8))
#define ESHFT16(x) ((x) >> (16))
#define EBLENDXOR(x) ((ESHFT8(x)) ^ (ESHFT16(x)))

const unsigned int lcga = 1664525;
const unsigned int lcgc = 1013904223;

static uint32_t gseed32 = 1;
static uint32_t gLCGForml(void);

uint16_t gSrand16(uint16_t g);
uint8_t gSrand8(uint8_t g);

uint16_t gRand16(void);
uint8_t gRand8(void);

uint16_t grandmod16(uint16_t n);
uint8_t grandmod8(uint8_t n);

#endif