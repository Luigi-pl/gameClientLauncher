#include "downloadlauncher.h"


downloadLauncher::downloadLauncher(MyTCPSocket *internetConnection, QMainWindow *mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downloadLauncher)
{
    this->internetConnection=internetConnection;
    this->mainWindow=mainWindow;
    ui->setupUi(this);
}

downloadLauncher::~downloadLauncher()
{
    delete ui;
}

void downloadLauncher::on_exit_clicked() //obsluga przycisku exit, wyjscie z programu i zamkniecie polaczenia z serwerem
{
    internetConnection->closeConnection();
    mainWindow->close();
}

void downloadLauncher::on_play_clicked() //do zrobienia - uruchomienie gry
{

}
