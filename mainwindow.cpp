#include "mainwindow.h"
#include "mainwindow2.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) //Konstrkutor okna launchera1
{
    ui->setupUi(this);
    internetConnection = new MyTCPSocket();
    internetConnection->connectToHost();
    if(internetConnection->getStatus()==(QAbstractSocket::ConnectingState))
    {
        ui->label4->setText("Laczenie");
    }
    else if(internetConnection->getStatus()==(QAbstractSocket::ConnectedState))
    {
        ui->label4->setText("Polaczony");
    }
    else if(internetConnection->getStatus()==(QAbstractSocket::BoundState))
    {
        ui->label4->setText("Polaczony2");
    }
    else
    {
        ui->label4->setText("Brak polaczenia, zresetuj klienta");
    }
}

MainWindow::~MainWindow() //destruktor okna launchera1
{
    delete ui;
}


void MainWindow::on_play_clicked()  //obsluga przycisku play, wyslanie danych do logowania - do zrobienia
{
    internetConnection->login(ui->login->text().toStdString(), ui->password->text().toStdString());


    MainWindow2 *w = new MainWindow2(internetConnection);
    w->show();
    this->close();
}

void MainWindow::on_exit_clicked() //obsluga przycisku exit, wyjscie z programu i zamkniecie polaczenia z serwerem
{
    internetConnection->close();
}
