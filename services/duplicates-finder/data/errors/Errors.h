#ifndef ERRORS_H
#define ERRORS_H

#include "common/data/error/Error.h"

class Errors
{
public:
    static constexpr int UNKNOWN = 1;

    static Error get(const int type);
};

#endif // ERRORS_H
