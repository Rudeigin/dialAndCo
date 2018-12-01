#include "dialmodel.h"
#include <QDebug>

DialModel::DialModel(QObject *parent) : QAbstractListModel(parent)
{
    addItem("icons/off", "");
    addItem("icons/auto", "SpinBoxComponent.qml");
    addItem("icons/dynamic", "SliderComponent.qml");
}

QList<DialItem> DialModel::model() {
    return _model;
}

int DialModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _model.count();
}

QVariant DialModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const DialItem &item = _model[index.row()];
    switch (role) {
    case IMAGE:
        return item.barIcon();
    case LOADER:
        return item.loaderSource();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> DialModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IMAGE] = "barIcon";
    roles[LOADER] = "loaderSource";
    return roles;
}

void DialModel::addItem(const QString &imgSource, const QString &loaderSource) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    DialItem item;
    item.setBarIcon(imgSource);
    item.setLoaderSource(loaderSource);
    _model.append(item);
    endInsertRows();
}

