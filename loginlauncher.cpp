#include "loginlauncher.h"
#include "mainwindow.h"

loginLauncher::loginLauncher(MyTCPSocket *internetConnection, MainWindow *mWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginLauncher)
{
    this->internetConnection=internetConnection;
    this->mainWindow=mWindow;
    ui->setupUi(this);
    if(this->internetConnection->getStatus()==(QAbstractSocket::ConnectingState))
    {
        ui->label4->setText("Laczenie");
    }
    else if(this->internetConnection->getStatus()==(QAbstractSocket::ConnectedState))
    {
        ui->label4->setText("Polaczony");
    }
    else if(this->internetConnection->getStatus()==(QAbstractSocket::BoundState))
    {
        ui->label4->setText("Polaczony2");
    }
    else
    {
        ui->label4->setText("Brak polaczenia, zresetuj klienta");
    }
}

loginLauncher::~loginLauncher()
{
    delete ui;
}

void loginLauncher::on_play_clicked()  //obsluga przycisku play, wyslanie danych do logowania - do zrobienia
{
    std::string com="SLN";
    internetConnection->sendCommand(com.c_str());
    if(!internetConnection->sendLogin(ui->login->text().toStdString(), ui->password->text().toStdString()))
    {
        mainWindow->setWidget(1);
    }
    else
    {
        ui->label5->setText("Bledne haslo albo login");
        ui->password->clear();
    }
}

void loginLauncher::on_exit_clicked() //obsluga przycisku exit, wyjscie z programu i zamkniecie polaczenia z serwerem
{
    internetConnection->close();
    mainWindow->close();
}
