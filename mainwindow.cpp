#include "mainwindow.h"
#include "mainwindow2.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    internetConnection = new MyTCPSocket();
    internetConnection->connectToHost();
    if(internetConnection->getStatus()==3)
    {
        ui->label4->setText("Polaczony");
    }
    else
    {
        ui->label4->setText("Brak polaczenia, zresetuj klienta");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_play_clicked()
{
    internetConnection->login(ui->login->text().toStdString(), ui->password->text().toStdString());
    MainWindow2 *w = new MainWindow2(internetConnection);
    w->show();
    this->close();
}

void MainWindow::on_exit_clicked()
{
    internetConnection->close();
}
