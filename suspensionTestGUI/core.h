#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUdpSocket>

class Core : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantMap data READ data WRITE setData NOTIFY dataChanged)
public:
    explicit Core(QObject *parent = nullptr);
    QVariantMap data();
    void setData(QVariantMap data);

signals:
    void dataChanged(QVariantMap data);

public slots:
    void sendData(double lf, double rf, double lc, double rc, double lb, double rb);
    void onReadyRead();
private:
    QVariantMap _data;
    QUdpSocket *socket;
};

#endif // CORE_H
