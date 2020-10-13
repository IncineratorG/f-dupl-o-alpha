#ifndef INPUTFOLDERSLISTACTIONTYPES_H
#define INPUTFOLDERSLISTACTIONTYPES_H

#include <QString>

class InputFoldersListActionTypes
{
public:
    static const QString STORE_MARK;

    static constexpr int ADD_FOLDER = 1;
    static constexpr int REMOVE_FOLDER = 2;
    static constexpr int UPDATE_FOLDER = 3;
};

#endif // INPUTFOLDERSLISTACTIONTYPES_H
