#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include "includeFile.h"
class MainWindow;

//klasa odpowiedzialna za polaczenie internetowe z serwerem
//dziala na linuxie i na wingrozie ;)
class DownloadLauncher;

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
    QString requestResearchInfo();
    QString requestCurrentResearchInfo();
    bool sendCurrentResearch(QString currentResearch, QString *error);
    QString requestFleetInformation();
    void closeConnection();

signals:

public slots:

private:
    MainWindow *mainWindow;

    QByteArray downloadFile();
    void saveFile(std::string fileAndPath, QByteArray qByteArray);
    QTcpSocket *socket;
    bool checkIsSuccessful();
    char readChar();
    int readInt();
    QString readQString();
    std::string readStdString();


};

#endif // MYTCPSOCKET_H
