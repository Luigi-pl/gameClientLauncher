#include "mytcpsocket.h"

MyTCPSocket::MyTCPSocket(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket();
}

MyTCPSocket::~MyTCPSocket()
{
    socket->close();
    delete socket;
}

void MyTCPSocket::connectToHost()
{
    socket->connectToHost("ultra60.mat.pl", 2350);
}
void MyTCPSocket::login(std::string login, std::string password)
{
    QCryptographicHash *hash;
    hash = new QCryptographicHash(QCryptographicHash::Sha512);
    hash->addData(password.c_str(), password.length());

    socket->write(login.c_str());
    socket->write(hash->result().data());
}
enum QAbstractSocket::SocketState MyTCPSocket::getStatus()
{
    return socket->state();
}
void MyTCPSocket::close()
{
    socket->close();
    //status = rozlaczony;
}
