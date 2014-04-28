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
    socket->connectToHost("89.229.5.219", 2400);
    socket->waitForConnected(3000);
}
void MyTCPSocket::sendCommand(const char *command) //metoda wysylajaca info do serwera co zostanie wyslane do niego
{
    socket->write(command);
    socket->write("\n");
}
bool MyTCPSocket::sendLogin(std::string login, std::string password) //metoda wysyla dane sluzace do logowania z loginLaunchera (K: SLN) i
//zwraca czy logowanie sie powiodlo
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
    return getLoginStatus();
}
bool MyTCPSocket::getLoginStatus()  //metoda sprawdzajaca czy logowanie sie powiodlo
{
    char *data = new char[1];
    socket->read(data, 1);
    if(data[0]=='T')
    {
        delete data;
        return true;
    }
    else
    {
        delete data;
        return false;
    }
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
