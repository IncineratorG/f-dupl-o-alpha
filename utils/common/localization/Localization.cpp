#include "Localization.h"

#include <QDebug>

Localization::Localization(QQmlEngine* engine)
    : mEngine(engine)
{
    QMap<QString, QString> ruLocalization;
    ruLocalization.insert("InputFolders_addFolderButton", "Добавить");
    ruLocalization.insert("InputFolders_removeFolderButton", "Удалить");
    ruLocalization.insert("InputFolders_fileDialogTitle", "Выберите папку");

    mLocalizations.insert("ru", ruLocalization);

    mCurrentLanguageCode = "ru";
}

QString Localization::t(const QString& pattern) {
    return mLocalizations.value(mCurrentLanguageCode).value(pattern);
}

void Localization::change() {
//    if (mCurrentLanguageCode == "ru") {
//        mCurrentLanguageCode = "en";
//    } else {
//        mCurrentLanguageCode = "ru";
//    }

    mEngine->retranslate();
}
