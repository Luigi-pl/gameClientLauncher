#include "ui/ui_header/downloadlauncher.h"
#include "ui/ui_header/mainwindow.h"

DownloadLauncher::DownloadLauncher(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downloadLauncher)
{
    this->internetConnection=internetConnection;
    this->mainWindow=mainWindow;
    ui->setupUi(this);
    ui->label1->setText(QCoreApplication::applicationName());
}

DownloadLauncher::~DownloadLauncher()
{
    delete ui;
}
void DownloadLauncher::updateProcedure()    //metoda wykonujaca update gry
{
    ui->play->setEnabled(false);
    internetConnection->requestUpdateInfo();
    internetConnection->requestUpdateFile();
    ui->play->setEnabled(true);
}

void DownloadLauncher::on_exit_clicked() //obsluga przycisku exit, wyjscie z programu i zamkniecie polaczenia z serwerem
{
    internetConnection->closeConnection();
    mainWindow->close();
}

void DownloadLauncher::on_play_clicked() //do zrobienia - uruchomienie gry
{
    mainWindow->startGame();
}
void DownloadLauncher::setProgressBar(int i)
{
    ui->progressBar->setValue(i);
}
