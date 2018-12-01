#include "listmodel.h"
#include <QDebug>

ListModel::ListModel(QObject *parent) : QAbstractListModel(parent)
{
    addItem("icons/off", "");
    addItem("icons/auto", "SpinBoxComponent.qml");
    addItem("icons/dynamic", "SliderComponent.qml");
}

QList<ListItem> ListModel::model() {
    return _model;
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _model.count();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const ListItem &item = _model[index.row()];
    switch (role) {
    case IMAGE:
        return item.imgSource();
    case LOADER:
        return item.loaderSource();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IMAGE] = "barIcon";
    roles[LOADER] = "loaderSource";
    return roles;
}

void ListModel::addItem(const QString &imgSource, const QString &loaderSource) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    ListItem item;
    item.setImgSource(imgSource);
    item.setLoaderSource(loaderSource);
    _model.append(item);
    endInsertRows();
}

