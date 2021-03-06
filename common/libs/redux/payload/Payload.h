#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <QMap>

#include <memory>
#include <any>

class Payload
{
public:
    Payload();
    Payload(std::any defaultValue);
    Payload(const Payload& other);

    void set(const QString& key, std::any value);

    std::any get(const QString& key) const;
    std::any getDefault() const;

private:
    QMap<QString, std::any> mValues;
    std::any mDefaultValue;
};

#endif // PAYLOAD_H
