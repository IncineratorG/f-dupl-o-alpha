#ifndef FILEINFO_H
#define FILEINFO_H

#include <QString>
#include <QFileInfo>

class FileInfo
{
public:
    FileInfo();
    FileInfo(const QString& filePath);
    FileInfo(const QFileInfo& fileInfo);
    FileInfo(const FileInfo& other);

    QString filePath() const;
    QString completeBaseName() const;
    QString suffix() const;
    qint64 bytesSize() const;

    inline bool operator<(const FileInfo& other) const {
        return this->filePath() < other.filePath();
    }

    inline bool operator==(const FileInfo& other) const {
        return this->filePath() == other.filePath();
    }

private:
    QFileInfo mFileInfo;
};

inline uint qHash(const FileInfo& fileInfo) {
    return ::qHash(fileInfo.filePath());
}

#endif // FILEINFO_H
