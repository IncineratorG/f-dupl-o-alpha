#ifndef DUPLICATESSCREEN_H
#define DUPLICATESSCREEN_H

#include "common/libs/native-screen/NativeScreen.h"
#include "native-components/specific/duplicates/input-folders/InputFoldersComponent.h"
#include "native-components/specific/duplicates/scanning-controls/ScanningControlsComponent.h"
#include "native-components/specific/duplicates/scanning-results/ScanningResultsComponent.h"

#include <QList>

class DuplicatesScreen : public NativeScreen
{
public:
    DuplicatesScreen(QQmlContext* ctxt);

protected:
    void registerScreen(QQmlContext* ctxt);
    void registerComponents(QQmlContext* ctxt);

private:
    InputFoldersComponent* mInputFoldersComponent;
    ScanningControlsComponent* mScanningControlsComponent;
    ScanningResultsComponent* mScanningResultsComponent;
};

#endif // DUPLICATESSCREEN_H
