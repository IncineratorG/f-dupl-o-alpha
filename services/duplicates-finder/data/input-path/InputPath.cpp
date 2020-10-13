#include "InputPath.h"

InputPath::InputPath() {

}

InputPath::InputPath(const QString& path, const bool includeSubpath)
    : mPath(path),
      mIncludeSubpaths(includeSubpath)
{

}

InputPath::InputPath(const InputPath& other)
    : mPath(other.mPath),
      mIncludeSubpaths(other.mIncludeSubpaths)
{

}

QString InputPath::path() const {
    return mPath;
}

bool InputPath::includeSubpath() const {
    return mIncludeSubpaths;
}
