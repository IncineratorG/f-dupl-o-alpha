#include "SelectorIdsGenerator.h"

int SelectorIdsGenerator::mNextId = 0;

int SelectorIdsGenerator::nextId() {
    return ++mNextId;
}
