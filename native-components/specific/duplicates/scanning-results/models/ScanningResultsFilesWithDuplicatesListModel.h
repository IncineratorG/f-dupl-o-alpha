#ifndef SCANNINGRESULTSFILESWITHDUPLICATESLISTMODEL_H
#define SCANNINGRESULTSFILESWITHDUPLICATESLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <QString>

class ScanningResultsFilesWithDuplicatesListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        IDRole = Qt::UserRole + 1,
        FileNameRole,
    };

    ScanningResultsFilesWithDuplicatesListModel();

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
};

#endif // SCANNINGRESULTSFILESWITHDUPLICATESLISTMODEL_H
