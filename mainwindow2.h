#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include "mytcpsocket.h"

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(MyTCPSocket *iC, QWidget *parent = 0);
    ~MainWindow2();

private:
    Ui::MainWindow2 *ui;
    MyTCPSocket *internetConnection;
};

#endif // MAINWINDOW2_H
