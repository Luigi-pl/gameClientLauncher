#include "mytcpsocket.h"
#include <cstdlib>


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
    socket->connectToHost("localhost", 2400);
    socket->waitForConnected(3000);
}
void MyTCPSocket::sendCommand(const char *command) //metoda wysylajaca info do serwera co zostanie wyslane do niego
{
    //lista komend
    // SLN - wyslanie loginu i hasla do sprawdzenia
    // LGT - wylogowanie sie i zakonczenie polaczenia
    // RUI - wyslanie informacji o wersji plikow w kliencie i prosba o dostarczenie informacji jakie pliki wymagaja update'u
    // RUF - pobieranie kolejnych plikow
    socket->write(command);
    socket->write("\n");
}
void MyTCPSocket::sendOS(const char *command)
{
    //WIN
    //LIN
    socket->write(command);
    socket->write("\n");
}
enum QAbstractSocket::SocketState MyTCPSocket::getStatus() //uzyskiwanie statusu polaczenie
{
    return socket->state();
}
char MyTCPSocket::readChar()    //pobieranie danych z socketu w postaci char
{
    socket->waitForReadyRead(250);
    char data[1];
    socket->read(data,1);
    return data[0];
}
int MyTCPSocket::readInt()
{
    int size;
    std::string readStdString="";
    char data[9];
    socket->read(data,9);
    for(int i=0; i<9; i++)
    {
        readStdString=readStdString+data[i];
    }
    size = atoi(readStdString.c_str());
    return size;
}
std::string MyTCPSocket::readStdString() //pobranie danych z socketu w postaci std::string
{
    int size;
    std::string readStdString="";
    qint64 qintSize;
    socket->waitForReadyRead(2000);
    socket->waitForReadyRead(50);


    size=readInt();

    qintSize=static_cast<qint64>(size);

    char *data2= new char[size];

    socket->read(data2,qintSize);
    for(qint64 i=0; i<size; i++)
    {
        readStdString=readStdString+data2[i];
    }

    delete data2;
    return readStdString;
}
QString MyTCPSocket::readQString()  //pobranie z socketu danych w postaci QString
{
    QString readQString;
    readQString=QString(readStdString().c_str());
    return readQString;
}
void MyTCPSocket::closeConnection() //zamykanie polaczenia
{
    sendCommand("LGT");
    socket->close();
}

bool MyTCPSocket::sendLogin(std::string login, std::string password) //metoda wysyla dane sluzace do logowania z loginLaunchera (K: SLN) i
//zwraca czy logowanie sie powiodlo
{
    sendCommand("SLN");   //wyslanie info o przyszlej komendzie

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
    char data=readChar();
    if(data=='T')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MyTCPSocket::requestUpdateInfo()   //pobiera informacje na temat ktore pliki maja byc zupdate'owane
{
    sendCommand("RUI");

    QSettings settings;
    socket->write((settings.value("version").toString().toStdString()+"\n").c_str());

    std::string update=readStdString();
    QString qupdate = QString(update.c_str());
    settings.setValue("update", qupdate);
    QString version = settings.value("version").toString();
    for(int i=0; i<(qupdate.length() - version.length()); i++)
    {
        version=version+"0";
    }
    settings.setValue("version", version);
}

QByteArray MyTCPSocket::downloadFile()  //pobiera dane z Socketu i przetwarza je do postaci QByteArray, ulatwiajac dalsza obrobke
{
    int fileSize;
    QByteArray qByteArray;

    fileSize=readInt();
    qByteArray.clear();
    if(fileSize<=16358)
    {
        qByteArray = socket->read(fileSize);
    }
    else
    {
        QByteArray read;
        while(fileSize>0)
        {
            if(fileSize>=16358)
            {
                read = socket->read(16358);
            }
            else
            {
                read = socket->read(fileSize);
            }
            fileSize=fileSize-read.length();
            qByteArray = qByteArray + read;
        }
    }
    return qByteArray;
}

void MyTCPSocket::saveFile(std::string fileAndPath, QByteArray qByteArray)
//Zapisuje do pliku znajdujacego sie
// na linuksie: "/../folder_w_ktorym_uruchomiono_launcher/"+fileAndPath
// na windowsie: "x:/../folder_w_ktorym_uruchomiono_launcher/"+fileAndPath
//dane z qByteArray
{
    QFile file;
    QString filePath="";

    filePath = QString::fromStdString(fileAndPath);
    #ifdef _WIN32
        filePath.replace("win/", "/");
    #elif __linux__
        filePath.replace("lin/", "/");
    #endif
    filePath = QDir::fromNativeSeparators(filePath);
    filePath= QApplication::applicationDirPath() + filePath;

    file.setFileName(filePath);
    file.open(QIODevice::WriteOnly);

    file.write(qByteArray);
    file.close();

}
void MyTCPSocket::requestUpdateFile()
{
    sendCommand("RUF");

    QSettings settings;
    QString update = settings.value("update").toString();
    std::string version = settings.value("version").toString().toStdString();
    char *str = new char[10];
    std::string fileAndPath;

    #ifdef _WIN32
        sendOS("WIN");
    #elif __linux__
        sendOS("LIN");
    #endif
    for(int i=0; i<update.length(); i++)
    {
        if(update[i]=='1')
        {
            //wyslanie informacji ktory plik chcemy dostac
            sprintf(str, "%d", i);
            socket->write(str);
            socket->write("\n");

            //pobranie sciezki od serwera do ktorej plik ma byc zapisany
            fileAndPath = readStdString();
            saveFile(fileAndPath,downloadFile());

            update[i]='0';
            version[i]=version[i]+1;
            std::cout << static_cast<int>(version[i])-1 << " " << static_cast<int>(version[i]) << std::endl;
        }
    }
    settings.setValue("update", update);
    settings.setValue("version", QString::fromStdString(version));
    socket->write("X");
    socket->write("\n");
}
