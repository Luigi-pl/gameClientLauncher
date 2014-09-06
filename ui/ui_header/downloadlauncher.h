#ifndef DOWNLOADLAUNCHER_H
#define DOWNLOADLAUNCHER_H

#include "mytcpsocket.h"
#include "ui_downloadlauncher.h"

class MainWindow;

namespace Ui
{
class downloadLauncher;
}

class DownloadLauncher : public QWidget
{
    Q_OBJECT

public:
    explicit DownloadLauncher(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent = 0);
    void updateProcedure();
    void setProgressBar(int i);
    ~DownloadLauncher();

private slots:
    void on_exit_clicked();

    void on_play_clicked();

private:
    Ui::downloadLauncher *ui;
    MainWindow *mainWindow;
    MyTCPSocket *internetConnection;
};

#endif // DOWNLOADLAUNCHER_H
