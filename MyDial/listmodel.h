#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "listitem.h"

class ListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ListModel(QObject * parent = nullptr);

    enum Roles {
        IMAGE = Qt::UserRole + 1,
        LOADER
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE QList<ListItem> model();
    Q_INVOKABLE void addItem(const QString &imgSource, const QString &loaderSource);

private:
    QList<ListItem> _model;
};

#endif // LISTMODEL_H
