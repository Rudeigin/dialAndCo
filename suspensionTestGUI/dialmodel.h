#ifndef DIALMODEL_H
#define DIALMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "dialitem.h"

class DialModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit DialModel(QObject * parent = nullptr);

    enum Roles {
        IMAGE = Qt::UserRole + 1,
        LOADER
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE QList<DialItem> model();
    void addItem(const QString &imgSource, const QString &loaderSource);

private:
    QList<DialItem> _model;
};

#endif // DIALMODEL_H
