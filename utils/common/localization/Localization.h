#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QMap>

class Localization : public QObject
{
    Q_OBJECT

public:
    Localization(QQmlEngine* engine);

    Q_INVOKABLE QString t(const QString& pattern);
    Q_INVOKABLE void change();

private:
    QQmlEngine* mEngine;
    QString mCurrentLanguageCode;
    QMap<QString, QMap<QString, QString>> mLocalizations;
};

#endif // LOCALIZATION_H
