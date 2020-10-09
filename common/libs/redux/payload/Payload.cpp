#include "Payload.h"

Payload::Payload() {

}

Payload::Payload(std::any defaultValue)
    : mDefaultValue(defaultValue)
{

}

Payload::Payload(const Payload& other)
    : mValues(other.mValues),
      mDefaultValue(other.mDefaultValue)
{

}

void Payload::set(const QString& key, std::any value) {
    mValues.insert(key, value);
}

std::any Payload::get(const QString& key) const {
    return mValues.value(key);
}

std::any Payload::getDefault() const {
    return mDefaultValue;
}
