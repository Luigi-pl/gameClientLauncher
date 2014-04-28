#ifndef DOWNLOADLAUNCHER_H
#define DOWNLOADLAUNCHER_H

#include "mytcpsocket.h"
#include "ui_downloadlauncher.h"


namespace Ui {
class downloadLauncher;
}

class downloadLauncher : public QWidget
{
    Q_OBJECT

public:
    explicit downloadLauncher(MyTCPSocket *internetConnection, QMainWindow *mainWindow, QWidget *parent = 0);
    ~downloadLauncher();

private slots:
    void on_exit_clicked();

    void on_play_clicked();

private:
    Ui::downloadLauncher *ui;
    QMainWindow *mainWindow;
    MyTCPSocket *internetConnection;
};

#endif // DOWNLOADLAUNCHER_H
