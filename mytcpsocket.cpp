#include "mytcpsocket.h"


MyTCPSocket::MyTCPSocket(QObject *parent) : QObject(parent) //konstruktor tworzacy nowy socket
{
    socket = new QTcpSocket();
}
MyTCPSocket::~MyTCPSocket() //destruktor zamykajacy polaczenie i usuwajacy socket
{
    socket->close();
    delete socket;
}
void MyTCPSocket::connectToHost() //metoda laczy z scisle okreslonym server
{
    socket->connectToHost("localhost", 2340);
    socket->waitForConnected(30000);
}
void MyTCPSocket::login(std::string login, std::string password) //metoda wysyla dane sluzace do logowania z pierwszego formularza
{

    QString pass;
    pass.fromStdString(password);
    QByteArray hash = QCryptographicHash::hash(pass.toUtf8(), QCryptographicHash::Sha3_512);
    hash=hash.toHex();


    socket->write(login.c_str());
    socket->write("\n");
    password=hash.data();
    socket->write(password.c_str());
    socket->write("\n");
}
enum QAbstractSocket::SocketState MyTCPSocket::getStatus() //uzyskiwanie statusu polaczenie
{
    return socket->state();
}
void MyTCPSocket::close() //zamykanie polaczenia
{
    socket->close();
    //status = rozlaczony;
}
