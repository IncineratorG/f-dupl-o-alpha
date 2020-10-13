#ifndef INPUTFOLDERSWITHSUBPATHSLISTMODEL_H
#define INPUTFOLDERSWITHSUBPATHSLISTMODEL_H

#include "services/duplicates-finder/data/input-path/InputPath.h"

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <QString>

class InputFoldersWithSubpathsListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        IDRole = Qt::UserRole + 1,
        FolderNameRole,
        IncludeSubpathRole
    };

    InputFoldersWithSubpathsListModel();

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;

private:
    QList<InputPath> mPaths;
};

#endif // INPUTFOLDERSWITHSUBPATHSLISTMODEL_H
