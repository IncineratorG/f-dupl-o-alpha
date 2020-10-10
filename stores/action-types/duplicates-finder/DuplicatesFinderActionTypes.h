#ifndef DUPLICATESFINDERACTIONTYPES_H
#define DUPLICATESFINDERACTIONTYPES_H

#include <QString>

class DuplicatesFinderActionTypes
{
public:
    static const QString STORE_MARK;

    static constexpr int FIND_DUPLICATES = 1;
    static constexpr int FIND_DUPLICATES_BEGIN = 2;
    static constexpr int FIND_DUPLICATES_FINISHED = 3;
    static constexpr int FIND_DUPLICATES_ERROR = 4;
};

#endif // DUPLICATESFINDERACTIONTYPES_H
