#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include "includeFile.h"
class MainWindow;

//klasa odpowiedzialna za polaczenie internetowe z serwerem
//dziala na linuxie i na wingrozie ;)
class downloadLauncher;

class MyTCPSocket : public QObject
{
Q_OBJECT
public:
    explicit MyTCPSocket(MainWindow *mWindow, QObject *parent = 0);
    ~MyTCPSocket();
    enum QAbstractSocket::SocketState getStatus();
    void connectToHost();
    void sendCommand(const char *command);
    void sendOS(const char *command);
    bool sendLogin(std::string login, std::string password);
    void requestUpdateInfo();
    void requestUpdateFile();
    void closeConnection();

signals:

public slots:

private:
    MainWindow *mainWindow;

    QByteArray downloadFile();
    void saveFile(std::string fileAndPath, QByteArray qByteArray);
    QTcpSocket *socket;
    bool getLoginStatus();
    char readChar();
    int readInt();
    QString readQString();
    std::string readStdString();


};

#endif // MYTCPSOCKET_H
