#include "Action.h"

Action::Action(const QString& storeMark, const int type)
    : mStoreMark(storeMark),
      mType(type)
{

}

Action::Action(const QString& storeMark, const int type, const Payload& payload)
    : mStoreMark(storeMark),
      mType(type),
      mPayload(payload)
{

}

Action::Action(const Action& other)
    : mStoreMark(other.mStoreMark),
      mType(other.mType),
      mPayload(other.mPayload)
{

}

QString Action::storeMark() const {
    return mStoreMark;
}

int Action::type() const {
    return mType;
}

Payload Action::payload() const {
    return mPayload;
}
