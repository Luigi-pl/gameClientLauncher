#include "ui/ui_header/researchanddevelopment.h"
#include "ui/ui_header/mainwindow.h"
#include "data/datastorage.h"
#include "object/gamerresearch.h"


ResearchAndDevelopment::ResearchAndDevelopment(MyTCPSocket *internetConnection, MainWindow *mainWindow, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResearchAndDevelopment)
{
    ui->setupUi(this);

    this->mainWindow = mainWindow;
    this->internetConnection = internetConnection;
    DataStorage *dataStorage = mainWindow->getDataStorage();
    GamerResearch *gamerResearch = mainWindow->getGamerResearch();


    QVector <ResearchCategoryData> researchCategoryData = dataStorage->getArrayOfResearchCategoryData();

    QListView *listView[5][3];
    listView[0][0]=ui->listViewAInTabA;
    listView[0][1]=ui->listViewBInTabA;
    listView[0][2]=ui->listViewCInTabA;
    listView[1][0]=ui->listViewAInTabB;
    listView[1][1]=ui->listViewBInTabB;
    listView[2][0]=ui->listViewAInTabC;
    listView[2][1]=ui->listViewBInTabC;
    listView[3][0]=ui->listViewAInTabD;
    listView[4][0]=ui->listViewAInTabE;


    QStandardItemModel *model;
    QStandardItem *colorItem;


    for(qint8 i=0; i<researchCategoryData.size(); i++)
    {
        ui->tabWidget->setTabText(i, researchCategoryData[i].getCategoryName());
        for(qint8 j=0; j<researchCategoryData[i].getSizeOfArrayOfResearchData(); j++)
        {
            model = new QStandardItemModel();
            listToDeleteA.append(model);

            colorItem = new QStandardItem(researchCategoryData[i].getResearchNameFromArrayOfResearchData(j));
            listToDeleteB.append(colorItem);

            colorItem->setData(QBrush(QColor(Qt::black)),
                               Qt::ForegroundRole);
            model->appendRow(colorItem);

            for(qint8 k=researchCategoryData[i].getFirstElementFromArrayOfResearchData(j);
                k<=researchCategoryData[i].getLastElementFromArrayOfResearchData(j);k++)
            {
                colorItem = new QStandardItem(dataStorage->getResearchNameAndCode(
                                                  researchCategoryData[i].getCategoryID(),
                                                  k));
                listToDeleteB.append(colorItem);

                if(gamerResearch->checkIsResearched(researchCategoryData[i].getCategoryID(),
                                                    k))
                {
                    colorItem->setData(QColor("green"), Qt::DecorationRole);
                }
                else
                {
                    colorItem->setData(QColor("red"), Qt::DecorationRole);
                }

                colorItem->setData(QBrush(QColor(Qt::black)),
                                   Qt::ForegroundRole);
                model->appendRow(colorItem);
            }
            listView[i][j]->setModel(model);
        }
    }
}

ResearchAndDevelopment::~ResearchAndDevelopment()
{

    qDeleteAll(listToDeleteB.begin(), listToDeleteB.end());
    listToDeleteB.clear();

    qDeleteAll(listToDeleteA.begin(), listToDeleteA.end());
    listToDeleteA.clear();
    delete ui;
}

void ResearchAndDevelopment::on_pushButton_clicked()
{
    mainWindow->setWidgetMainMenu();
}
