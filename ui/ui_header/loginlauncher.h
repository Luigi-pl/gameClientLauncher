#ifndef LOGINLAUNCHER_H
#define LOGINLAUNCHER_H

#include "mytcpsocket.h"
#include "ui_loginlauncher.h"

class MainWindow;

namespace Ui
{
class loginLauncher;
}

class LoginLauncher : public QWidget
{
    Q_OBJECT

public:
    explicit LoginLauncher(MyTCPSocket *internetConnection, MainWindow *mWindow, QWidget *parent = 0);
    ~LoginLauncher();

private slots:
    void on_play_clicked();
    void on_exit_clicked();

private:
    Ui::loginLauncher *ui;
    MainWindow *mainWindow;
    MyTCPSocket *internetConnection;
};

#endif // LOGINLAUNCHER_H
