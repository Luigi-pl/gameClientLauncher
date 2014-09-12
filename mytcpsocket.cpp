#include "mytcpsocket.h"
#include <QCryptographicHash>
#include "sha512.h"
#include "ui/ui_header/mainwindow.h"

MyTCPSocket::MyTCPSocket(MainWindow *mWindow, QObject *parent) : QObject(parent) //konstruktor tworzacy nowy socket
{
    socket = new QTcpSocket();
    this->mainWindow = mWindow;

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

    // RRS - pobranie danych na temat stanu badan
    // CRS - pobranie danych na temat stanu aktualnego badania
    // SCR - wysłanie danych na temat stanu aktualnego badania

    // RFI - pobranie ogolnych danych na temat floty
    // RSI - pobranie informacji na temat określonego okrętu
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
QString MyTCPSocket::requestFleetInformation()
{
    sendCommand("RFI");
    return readQString();
}
QString MyTCPSocket::requestShipInformation(int i)
{
    sendCommand("RSI");
    socket->write(QString::number(i).toStdString().c_str());
    socket->write("\n");
    return readQString();
}

enum QAbstractSocket::SocketState MyTCPSocket::getStatus() //uzyskiwanie statusu polaczenie
{
    return socket->state();
}
char MyTCPSocket::readChar()    //pobieranie danych z socketu w postaci char
{
    socket->waitForReadyRead(250);
    char data[1];
    while(socket->bytesAvailable()<1)
    {
        socket->waitForReadyRead(250);
    }
    socket->read(data,1);
    return data[0];
}
int MyTCPSocket::readInt()
{
    socket->waitForReadyRead(250);
    int size=0;
    std::string readStdString="";
    char data[9];

    while(socket->bytesAvailable()<9)
    {
        socket->waitForReadyRead(250);
    }
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
    int size=0;
    std::string readStdString="";
    qint64 qintSize;
    socket->waitForReadyRead(250);

    size=readInt();

    qintSize=static_cast<qint64>(size);

    char *data2= new char[size];


    while(socket->bytesAvailable()<qintSize)
    {
        socket->waitForReadyRead(250);
    }
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
QString MyTCPSocket::requestResearchInfo()
{
    sendCommand("RRS");
    return readQString();
}
QString MyTCPSocket::requestCurrentResearchInfo()
{
    sendCommand("CRS");
    return readQString();
}
bool MyTCPSocket::sendCurrentResearch(QString currentResearch, QString *error)
{
    sendCommand("SCR");
    socket->write(currentResearch.toStdString().c_str());
    socket->write("\n");
    QString answerFromServer = readQString();

    if(answerFromServer.length()==1)
    {
        return true;
    }
    else
    {
        error->clear();
        if(QString::compare(answerFromServer, "SS"))
        {
            error->append("You didn't finish \nprevious research!");
        }
        else if(QString::compare(answerFromServer, "ES"))
        {
            error->append("You didn't finish \nprevious research!");
        }
        else if(QString::compare(answerFromServer, "DE"))
        {
            error->append("There is no \nresearch to end!");
        }
        else if(QString::compare(answerFromServer, "SE"))
        {
            error->append("You cant't finish \nthis research!");
        }
        else if(QString::compare(answerFromServer, "EE"))
        {
            error->append("You didn't finish \nprevious research!");
        }
        return false;
    }
}
bool MyTCPSocket::sendLogin(std::string login, std::string password) //metoda wysyla dane sluzace do logowania z loginLaunchera (K: SLN) i
//zwraca czy logowanie sie powiodlo
{
    sendCommand("SLN");   //wyslanie info o przyszlej komendzie

    socket->write(login.c_str());
    socket->write("\n");

    password=sha512(password);

    socket->write(password.c_str());
    socket->write("\n");
    return checkIsSuccessful();
}
bool MyTCPSocket::checkIsSuccessful()  //metoda sprawdzajaca czy logowanie sie powiodlo
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
        socket->bytesWritten(fileSize);
        qByteArray = socket->read(fileSize);
    }
    else
    {
        QByteArray read;
        while(fileSize>0)
        {
            if(fileSize>=16358)
            {
                socket->bytesWritten(16358);
                read = socket->read(16358);
            }
            else
            {
                socket->bytesWritten(fileSize);
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
        filePath.replace("\\\\", "\\");
    #elif __linux__
        filePath.replace("//", "/");
    #endif


    filePath = QDir::fromNativeSeparators(filePath);
    filePath = QApplication::applicationDirPath() + QDir::separator() + filePath;

    std::cout << fileAndPath << " " <<  filePath.toStdString() << std::endl;

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
        }
        mainWindow->setProgressBar((i+1) * 100/update.length());
    }
    settings.setValue("update", update);
    settings.setValue("version", QString::fromStdString(version));
    socket->write("X");
    socket->write("\n");
}
