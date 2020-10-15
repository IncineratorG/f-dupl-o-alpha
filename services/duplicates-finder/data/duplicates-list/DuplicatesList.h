#ifndef DUPLICATESLIST_H
#define DUPLICATESLIST_H

#include "services/duplicates-finder/data/file-info/FileInfo.h"

#include <QMap>
#include <QList>

class DuplicatesList
{
public:
    DuplicatesList();
    DuplicatesList(const DuplicatesList& other);

    void clear();

    void addDuplicate(const FileInfo& file, const FileInfo& duplicate);
    void addDuplicates(const FileInfo& file, const QList<FileInfo>& duplicates);

    QList<FileInfo> files() const;
    int filesSize() const;

    QList<FileInfo> duplicates(const FileInfo& file) const;
    int duplicateSize(const FileInfo& file) const;

private:
    QMap<FileInfo, QList<FileInfo>> mDuplicates;
};

#endif // DUPLICATESLIST_H
