#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include "includeFile.h"

//klasa odpowiedzialna za polaczenie internetowe z serwerem
//dziala na linuxie i na wingrozie ;)

class MyTCPSocket : public QObject
{
Q_OBJECT
public:
    explicit MyTCPSocket(QObject *parent = 0);
    ~MyTCPSocket();
    enum QAbstractSocket::SocketState getStatus();
    void connectToHost();
    void sendCommand(const char *command);
    bool sendLogin(std::string login, std::string password);
    void requestUpdateInfo();
    void closeConnection();

signals:

public slots:

private:
    QTcpSocket *socket;
    bool getLoginStatus();
    char readChar();
    QString readQString();
    std::string readStdString();

};

#endif // MYTCPSOCKET_H
