#ifndef PLANTSH
#define PLANTSH

#include <cstdlib>

#include "core/utils.hpp"
#include "core/structs.hpp"
#include "core/grand.h"

class Plants
{
    public:
        virtual void spawnPlants() = 0;
        virtual void consumePlant()= 0;
        virtual ~Plants() = default;
};

#endif