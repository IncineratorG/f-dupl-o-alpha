#include "StatePropIdsGenerator.h"

int StatePropIdsGenerator::mNextId = 0;

int StatePropIdsGenerator::nextId() {
    return ++mNextId;
}

