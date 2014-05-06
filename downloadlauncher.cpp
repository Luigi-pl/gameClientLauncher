#include "downloadlauncher.h"


downloadLauncher::downloadLauncher(MyTCPSocket *internetConnection, QMainWindow *mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downloadLauncher)
{
    this->internetConnection=internetConnection;
    this->mainWindow=mainWindow;
    ui->setupUi(this);
    ui->label1->setText(QCoreApplication::applicationName());
}

downloadLauncher::~downloadLauncher()
{
    delete ui;
}
void downloadLauncher::updateProcedure()    //metoda wykonujaca update gry
{
    ui->play->setEnabled(false);
    internetConnection->requestUpdateInfo();
    internetConnection->requestUpdateFile();

}

void downloadLauncher::on_exit_clicked() //obsluga przycisku exit, wyjscie z programu i zamkniecie polaczenia z serwerem
{
    internetConnection->closeConnection();
    mainWindow->close();
}

void downloadLauncher::on_play_clicked() //do zrobienia - uruchomienie gry
{

}
