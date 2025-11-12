#ifndef MUSHROOMH
#define MUSHROOMH

#include <vector>
#include <algorithm>
#include <vector>

#include "core/structs.hpp"
#include "core/utils.hpp"
#include "core/grand.h"

class Mushroom
{
    public:
        virtual void spawnMush() = 0;
        virtual void consumeMush() = 0;
        virtual ~Mushroom() = default;
};

#endif