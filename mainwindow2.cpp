#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(MyTCPSocket *iC, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    this->internetConnection=iC;
    ui->setupUi(this);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}
