#ifndef STATEPROP_H
#define STATEPROP_H

#include "common/libs/redux/prop/StatePropLike.h"

template <class T> class StateProp : public StatePropLike
{
public:
    StateProp() {

    }

    StateProp(T val) {
        mVal = val;
    }

    void set(T val) {
        setUpdated(true);
        mVal = val;
    }

    T get() const {
        return mVal;
    }

private:
    T mVal;
};
#endif // STATEPROP_H
