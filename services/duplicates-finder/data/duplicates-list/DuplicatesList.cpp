#include "DuplicatesList.h"

DuplicatesList::DuplicatesList() {

}

DuplicatesList::DuplicatesList(const DuplicatesList& other)
    : mDuplicates(other.mDuplicates)
{

}

void DuplicatesList::clear() {
    mDuplicates.clear();
}

void DuplicatesList::addDuplicate(const FileInfo& file, const FileInfo& duplicate) {
    QList<FileInfo> currentFileDuplicates = mDuplicates.value(file);
    currentFileDuplicates.append(duplicate);

    mDuplicates.insert(file, currentFileDuplicates);
}

void DuplicatesList::addDuplicates(const FileInfo& file, const QList<FileInfo>& duplicates) {
    QList<FileInfo> currentFileDuplicates = mDuplicates.value(file);
    currentFileDuplicates.append(duplicates);

    mDuplicates.insert(file, currentFileDuplicates);
}

QList<FileInfo> DuplicatesList::files() const {
    return mDuplicates.keys();
}

int DuplicatesList::filesSize() const {
    return mDuplicates.keys().length();
}

QList<FileInfo> DuplicatesList::duplicates(const FileInfo& file) const {
    return mDuplicates.value(file);
}

int DuplicatesList::duplicateSize(const FileInfo& file) const {
    return mDuplicates.value(file).length();
}
