#include "core.h"
#include <QNetworkDatagram>
#include <QString>

Core::Core(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket();
    socket->bind(QHostAddress::Any, 6001);//я так понимаю, мы что-то слушаем, как там данные придут - херак readyRead
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

QVariantMap Core::data() {
    return _data;
}

void Core::setData(QVariantMap data) {
    if(_data == data)
        return;

    _data = data;

    emit dataChanged(_data);
}

void Core::sendData(double lf, double rf, double lc, double rc, double lb, double rb)
{
    QJsonObject objValue;
    QJsonObject obj;
    objValue["LF"] = lf;
    objValue["RF"] = rf;
    objValue["LC"] = lc;
    objValue["RC"] = rc;
    objValue["LB"] = lb;
    objValue["RB"] = rb;

    obj["mode"] = "custom";
    obj["value"] = objValue;

    QByteArray arr;
    QJsonDocument jsonDoc(obj);
    qDebug() << jsonDoc.toJson(QJsonDocument::Compact);
    qDebug() << socket->writeDatagram(jsonDoc.toJson(QJsonDocument::Compact), QHostAddress("127.0.0.1"), 6002);
}

void Core::onReadyRead() {
    while(socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = socket->receiveDatagram();
        QString str = QString::fromUtf8(datagram.data().data());
        QJsonDocument jsonDoc = QJsonDocument::fromJson(datagram.data());
        setData(jsonDoc.object()["value"].toVariant().toMap());
        qDebug() << _data["LF"].toDouble();
    }
}
