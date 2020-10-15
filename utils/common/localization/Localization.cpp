#include "Localization.h"

#include <QDebug>

Localization* Localization::mInstance = nullptr;

Localization::Localization(QQmlEngine* engine)
    : mEngine(engine)
{
    QMap<QString, QString> ruLocalization;
    ruLocalization.insert("InputFolders_addFolderButton", "Добавить");
    ruLocalization.insert("InputFolders_removeFolderButton", "Удалить");
    ruLocalization.insert("InputFolders_fileDialogTitle", "Выберите папку");
    ruLocalization.insert("ScanningControls_toggleScanningButton_startScanning", "Начать");
    ruLocalization.insert("ScanningControls_toggleScanningButton_stopScanning", "Остановить");

    mLocalizations.insert("ru", ruLocalization);

    mCurrentLanguageCode = "ru";
}

Localization* Localization::createAndGet(QQmlEngine* engine) {
    if (!mInstance) {
        mInstance = new Localization(engine);
    }

    return mInstance;
}

Localization* Localization::get() {
    return mInstance;
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
