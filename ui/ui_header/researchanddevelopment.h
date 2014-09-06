#ifndef RESEARCHANDDEVELOPMENT_H
#define RESEARCHANDDEVELOPMENT_H

#include "mytcpsocket.h"
#include "ui_researchanddevelopment.h"


namespace Ui {
class ResearchAndDevelopment;
}

class ResearchAndDevelopment : public QWidget
{
    Q_OBJECT

public:
    explicit ResearchAndDevelopment(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent = 0);
    ~ResearchAndDevelopment();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ResearchAndDevelopment *ui;
    MainWindow *mainWindow;
    MyTCPSocket *internetConnection;
    QVector <QStandardItemModel *> listToDeleteA;
    QVector <QStandardItem *> listToDeleteB;

};

#endif // RESEARCHANDDEVELOPMENT_H
