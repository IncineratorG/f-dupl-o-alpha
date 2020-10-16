#ifndef FILESWITHDUPLICATESLISTCOMPONENT_H
#define FILESWITHDUPLICATESLISTCOMPONENT_H

#include "common/libs/native-component/NativeComponent.h"

class FilesWithDuplicatesListComponent : public NativeComponent
{
public:
    FilesWithDuplicatesListComponent(QQmlContext* ctxt);

    void registerComponent(QQmlContext* ctxt);
};

#endif // FILESWITHDUPLICATESLISTCOMPONENT_H
