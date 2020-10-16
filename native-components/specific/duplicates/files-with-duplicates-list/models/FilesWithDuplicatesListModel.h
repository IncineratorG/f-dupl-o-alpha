#ifndef FILESWITHDUPLICATESLISTMODEL_H
#define FILESWITHDUPLICATESLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <QString>

class FilesWithDuplicatesListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        IDRole = Qt::UserRole + 1,
        FileNameRole,
    };

    FilesWithDuplicatesListModel();

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
};

#endif // FILESWITHDUPLICATESLISTMODEL_H
