#ifndef SERVICES_H
#define SERVICES_H

#include "services/duplicates-finder/DuplicatesFinderService.h"

#include <QList>

#include <memory>

class Services
{
public:
    std::shared_ptr<DuplicatesFinderService> duplicatesFinderService;

    static Services* get();

private:
    Services();

    static Services* mInstance;

    QList<std::shared_ptr<Service>> mServices;
};

#endif // SERVICES_H
