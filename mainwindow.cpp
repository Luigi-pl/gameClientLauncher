#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) //Konstrkutor okna glownego
{
    ui->setupUi(this);

    //stworzenie polaczenia z serwerem
    internetConnection = new MyTCPSocket();
    internetConnection->connectToHost();

    //obsluga kilku widgetow
    qStackedWidget = new QStackedWidget;

    //tworzenie widgetow Launchera
    widgetLoginLauncher = new loginLauncher(internetConnection, this);
    widgetDownloadLauncher = new downloadLauncher(internetConnection, this);


    //wrzucenie widegtow na stos
    qStackedWidget->addWidget(widgetLoginLauncher);
    qStackedWidget->addWidget(widgetDownloadLauncher);

    //pokazanie najwyzszego widgetu
    ui->layout->addWidget(qStackedWidget);

}

MainWindow::~MainWindow() //destruktor okna glownego
{
    delete ui;
    delete widgetLoginLauncher;
    delete qStackedWidget;
}

void MainWindow::setWidget(int nWidget)
{
    qStackedWidget->setCurrentIndex(nWidget);
}
