#include "server.h"
#include <QDebug>
#include <QNetworkDatagram>

Server::Server(QObject *parent) : QObject(parent) {
    socket = new QUdpSocket();
    socket->bind(QHostAddress::Any, 6002);
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyReadServer()));
    sendData(1.2, 1.2, 1.2, 1.2, 1.2, 1.2);
}
//на порт 6001
void Server::sendData(double lf, double rf, double lc, double rc, double lb, double rb) {
    QJsonObject objValue;
    QJsonObject obj;
    objValue["LF"] = lf;
    objValue["RF"] = rf;
    objValue["LC"] = lc;
    objValue["RC"] = rc;
    objValue["LB"] = lb;
    objValue["RB"] = rb;

    obj["mode"] = "auto";
    obj["value"] = objValue;

    QByteArray arr;
    QJsonDocument jsonDoc(obj);
    qDebug() << jsonDoc.toJson(QJsonDocument::Compact);
    qDebug() << socket->writeDatagram(jsonDoc.toJson(QJsonDocument::Compact), QHostAddress("127.0.0.1"), 6001);
}

void Server::onReadyReadServer() {
    while(socket->hasPendingDatagrams()) {
           QNetworkDatagram datagram = socket->receiveDatagram();
           QString str = QString::fromUtf8(datagram.data().data());
           QJsonDocument jsonDoc = QJsonDocument::fromJson(datagram.data());
           QJsonObject obj = jsonDoc.object();
           qDebug() << obj["value"] << "приняли в плюсах";
    }
}
