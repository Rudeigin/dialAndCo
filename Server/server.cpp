#include "server.h"
#include <QDebug>
#include <QNetworkDatagram>
#include <QRandomGenerator>

Server::Server(QObject *parent) : QObject(parent) {
    socket = new QUdpSocket();
    socket->bind(QHostAddress::Any, 6002);
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyReadServer()));

    timer = new QTimer();
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->start();
}

void Server::onTimeout() {
    sendData(QRandomGenerator::global()->bounded(5.1), QRandomGenerator::global()->bounded(5.1),
             QRandomGenerator::global()->bounded(5.1), QRandomGenerator::global()->bounded(5.1),
             QRandomGenerator::global()->bounded(5.1), QRandomGenerator::global()->bounded(5.1));
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

    obj["mode"] = "real";
    obj["value"] = objValue;

    QByteArray arr;
    QJsonDocument jsonDoc(obj);
    socket->writeDatagram(jsonDoc.toJson(QJsonDocument::Compact), QHostAddress("127.0.0.1"), 6001);
}

void Server::onReadyReadServer() {
    while(socket->hasPendingDatagrams()) {
           QNetworkDatagram datagram = socket->receiveDatagram();
           QString str = QString::fromUtf8(datagram.data().data());
           QJsonDocument jsonDoc = QJsonDocument::fromJson(datagram.data());
           QJsonObject obj = jsonDoc.object();
           QVariantMap map = obj["value"].toVariant().toMap();
           foreach(QString key, map.keys()) {
               qDebug() << key << " : " << map.value(key).toDouble();
           }
           qDebug() << "";
    }
}
