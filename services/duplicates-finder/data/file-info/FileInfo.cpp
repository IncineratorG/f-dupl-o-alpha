#include "FileInfo.h"

FileInfo::FileInfo() {

}

FileInfo::FileInfo(const QString& filePath)
    : mFileInfo(filePath)
{

}

FileInfo::FileInfo(const QFileInfo& fileInfo)
    : mFileInfo(fileInfo)
{

}

FileInfo::FileInfo(const FileInfo& other)
    : mFileInfo(other.mFileInfo)
{

}

QString FileInfo::filePath() const {
    return mFileInfo.absoluteFilePath();
}

QString FileInfo::completeBaseName() const {
    return mFileInfo.completeBaseName();
}

QString FileInfo::suffix() const {
    return mFileInfo.suffix();
}

qint64 FileInfo::bytesSize() const {
    return mFileInfo.size();
}
