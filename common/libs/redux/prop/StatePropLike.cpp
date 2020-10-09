#include "StatePropLike.h"

StatePropLike::StatePropLike()
    : mPropId(-1),
      mUpdated(false)
{

}

StatePropLike::~StatePropLike() {

}

void StatePropLike::setPropId(const int id) {
    mPropId = id;
}

void StatePropLike::setUpdated(const bool updated) {
    mUpdated = updated;
}

int StatePropLike::propId() const {
    return mPropId;
}

bool StatePropLike::updated() const {
    return mUpdated;
}
