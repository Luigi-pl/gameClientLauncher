#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mytcpsocket.h"
#include "ui_mainwindow.h"

class LoginLauncher;
class DownloadLauncher;
class MainMenu;

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
    void setProgressBar(int i);
    void startGame();

private:
    void setSizeAndPosition(int width, int height);


    Ui::MainWindow *ui;

    MyTCPSocket *internetConnection;
    LoginLauncher *widgetLoginLauncher;
    DownloadLauncher *widgetDownloadLauncher;
    MainMenu *widgetMainMenu;
    QStackedWidget *qStackedWidget;
};

#endif // MAINWINDOW_H
