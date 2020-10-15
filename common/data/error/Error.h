#ifndef ERROR_H
#define ERROR_H

#include <QString>

class Error
{
public:
    Error();
    Error(const int code, const QString& description);
    Error(const Error& other);

    int code() const;
    QString description() const;

private:
    int mCode;
    QString mDescription;
};

#endif // ERROR_H
