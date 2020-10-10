#ifndef INPUTFOLDERSLISTMODEL_H
#define INPUTFOLDERSLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <QString>

class InputFoldersListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        IDRole = Qt::UserRole + 1,
        FolderNameRole
    };

    InputFoldersListModel();

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

private:
    QList<QString> folderNames;
};

#endif // INPUTFOLDERSLISTMODEL_H
