#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUdpSocket>
#include <QTimer>

class Core : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantMap data READ data WRITE setData NOTIFY dataChanged)
    Q_PROPERTY(bool connected READ connected WRITE setConnected NOTIFY connectedChanged)
    Q_PROPERTY(QString ip READ ip WRITE setIp NOTIFY ipChanged)
public:
    explicit Core(QObject *parent = nullptr);

    QVariantMap data();
    bool connected();
    QString ip();

    void setData(QVariantMap data);
    void setConnected(bool connected);
    Q_INVOKABLE void setIp(QString ip);

signals:
    void dataChanged(QVariantMap data);
    void connectedChanged(bool connected);
    void ipChanged(QString ip);

public slots:
    void sendData(double lf, double rf, double lc, double rc, double lb, double rb);
    void onTimeout();
    void onReadyRead();

private:
    QUdpSocket *socket;
    QTimer * timer;

    QVariantMap _data;
    bool _connected;
    QString _ip;
};

#endif // CORE_H
