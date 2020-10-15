#include "Error.h"

Error::Error() {

}

Error::Error(const int code, const QString& description)
    : mCode(code),
      mDescription(description)
{

}

Error::Error(const Error& other)
    : mCode(other.mCode),
      mDescription(other.mDescription)
{

}

int Error::code() const {
    return mCode;
}

QString Error::description() const {
    return mDescription;
}
