#include "loginlauncher.h"
#include "mainwindow.h"

LoginLauncher::LoginLauncher(MyTCPSocket *internetConnection, MainWindow *mWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginLauncher)
{
    this->internetConnection=internetConnection;
    this->mainWindow=mWindow;
    ui->setupUi(this);
    ui->label1->setText(QCoreApplication::applicationName());
    //sprawdzanie statusu polaczanie
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
        ui->label4->setText("Polaczony");
    }
    else
    {
        ui->label4->setText("Brak polaczenia, zresetuj klienta");
    }
}

LoginLauncher::~LoginLauncher()
{
    delete ui;
}

void LoginLauncher::on_play_clicked()  //obsluga przycisku play, wyslanie danych do logowania
{
    if(ui->login->text().length()!=0 &&
            ui->password->text().length()!=0 &&
            internetConnection->sendLogin(ui->login->text().toStdString(), ui->password->text().toStdString()))  //logowanie i sprawdzanie czy logowanie sie powiodlo
    {
        mainWindow->setWidget(1);
    }
    else
    {
        ui->label5->setText("Bledne haslo albo login");
        ui->password->clear();
    }
}

void LoginLauncher::on_exit_clicked() //obsluga przycisku exit, wyjscie z programu i zamkniecie polaczenia z serwerem
{
    internetConnection->closeConnection();
    mainWindow->close();
}
