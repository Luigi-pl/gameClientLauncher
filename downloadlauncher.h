#ifndef DOWNLOADLAUNCHER_H
#define DOWNLOADLAUNCHER_H

#include "mytcpsocket.h"
#include "ui_downloadlauncher.h"
class MainWindow;

namespace Ui {
class downloadLauncher;
}

class downloadLauncher : public QWidget
{
    Q_OBJECT

public:
    explicit downloadLauncher(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent = 0);
    ~downloadLauncher();

private slots:
    void on_exit_clicked();

    void on_play_clicked();

private:
    Ui::downloadLauncher *ui;
    MainWindow *mainWindow;
    MyTCPSocket *internetConnection;
};

#endif // DOWNLOADLAUNCHER_H
