#ifndef INPUTPATH_H
#define INPUTPATH_H

#include <QString>

class InputPath
{
public:
    InputPath();
    InputPath(const QString& path, const bool includeSubpath = true);
    InputPath(const InputPath& other);

    QString path() const;
    bool includeSubpath() const;

private:
    QString mPath;
    bool mIncludeSubpaths;
};

#endif // INPUTPATH_H
