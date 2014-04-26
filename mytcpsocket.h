#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QCryptographicHash>
#include <iostream>

class MyTCPSocket : public QObject
{
Q_OBJECT
public:
    explicit MyTCPSocket(QObject *parent = 0);
    ~MyTCPSocket();
    enum QAbstractSocket::SocketState getStatus();
    void connectToHost();
    void login(std::string login, std::string password);
    void close();

signals:

public slots:

private:
    QTcpSocket *socket;

};

#endif // MYTCPSOCKET_H
