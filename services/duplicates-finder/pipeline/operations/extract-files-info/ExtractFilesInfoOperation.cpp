#include "ExtractFilesInfoOperation.h"

#include <QDebug>

ExtractFilesInfoOperation::ExtractFilesInfoOperation() {

}

void ExtractFilesInfoOperation::run() {
    for (int i = 0; i < mInput.length(); ++i) {
        qDebug() << __PRETTY_FUNCTION__ << mInput.at(i).path() << ' - ' << mInput.at(i).includeSubpath();
    }
}
