#include "downloadlauncher.h"


downloadLauncher::downloadLauncher(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent) :
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

void downloadLauncher::on_exit_clicked()
{
    internetConnection->close();
    mainWindow->close();

}

void downloadLauncher::on_play_clicked()
{

}
