#ifndef SERVER_H
#define SERVER_H
#include <QObject>
#include <QUdpSocket>
#include <QJsonObject>
#include <QJsonDocument>

class Server : public QObject {
    Q_OBJECT
public:
    explicit Server(QObject * parent = nullptr);
    void sendData(double lf, double rf, double lc, double rc, double lb, double rb);
public slots:
    void onReadyReadServer();
private:
    QUdpSocket *socket;
};

#endif // SERVER_H
