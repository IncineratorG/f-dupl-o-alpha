#include "Services.h"

Services* Services::mInstance = nullptr;

Services::Services() {
    duplicatesFinderService = std::make_shared<DuplicatesFinderService>();

    mServices.append(duplicatesFinderService);

    for (int i = 0; i < mServices.length(); ++i) {
        mServices.at(i)->init();
    }
}

Services* Services::get() {
    if (!mInstance) {
        mInstance = new Services();
    }

    return mInstance;
}
