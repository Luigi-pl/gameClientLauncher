#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mytcpsocket.h"

#include "ui_mainwindow.h"

#include "loginlauncher.h"
#include "downloadlauncher.h"



namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setWidget(int nWidget);

private:
    Ui::MainWindow *ui;
    MyTCPSocket *internetConnection;
    loginLauncher *widgetLoginLauncher;
    downloadLauncher *widgetDownloadLauncher;
    QStackedWidget *qStackedWidget;
};

#endif // MAINWINDOW_H
