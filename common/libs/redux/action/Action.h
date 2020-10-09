#ifndef ACTION_H
#define ACTION_H

#include "common/libs/redux/payload/Payload.h"

#include <QString>

class Action
{
public:
    Action(const QString& storeMark, const int type);
    Action(const QString& storeMark, const int type, const Payload& payload);
    Action(const Action& other);

    QString storeMark() const;
    int type() const;
    Payload payload() const;

private:
    QString mStoreMark;
    int mType;
    Payload mPayload;
};

#endif // ACTION_H
