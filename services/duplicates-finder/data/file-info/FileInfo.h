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

private:
    QFileInfo mFileInfo;
};

#endif // FILEINFO_H
