#ifndef GAMERRESEARCH_H
#define GAMERRESEARCH_H
#include "includeFile.h"

class GamerResearch
{
public:
    GamerResearch(qint8 shipSize,
                  qint8 missile, qint8 ionCannon, qint8 plasmaGun,
                  qint8 armor, qint8 shield,
                  qint8 ecm, qint8 eccm,
                  qint8 fleetSize,
                  qint8 upperLimitForMissile, qint8 upperLimitForIonCannon, qint8 upperLimitForPlasmaGun,
                  qint8 upperLimitForArmor, qint8 upperLimitForShield,
                  qint8 upperLimitForEcm, qint8 upperLimitForEccm);
    bool checkIsResearched(QString researchType, qint8 researchToCheck);
    bool checkIsResearchable(QString researchType, qint8 researchToCheck);
    bool isCurrentResearch();
    void clearCurrentResearch();
    void setCurrentResearch(bool state);
    void setCurrentResearchData(QString category, qint8 id, qint32 researchTime);
    QString getCurrentResearchTimeEnd();
    bool isResearchFinished();
    QString getCurrentResearchCategory();
    qint8 getCurrentResearchID();
    QString getCurrentResearchDataToSendToServer(QString type);
    qint8 setResearchAdvancer();
private:
    qint8 shipSize;

    qint8 missile;
    qint8 ionCannon;
    qint8 plasmaGun;

    qint8 armor;
    qint8 shield;

    qint8 ecm;
    qint8 eccm;

    qint8 fleetSize;


    qint8 upperLimitForMissile;
    qint8 upperLimitForIonCannon;
    qint8 upperLimitForPlasmaGun;
    qint8 upperLimitForArmor;
    qint8 upperLimitForShield;

    qint8 upperLimitForEcm;
    qint8 upperLimitForEccm;

    bool currentResearched;

    qint8 currentResearchedID;
    QString currentResearchedCategory;

    QDateTime currentResearchEndTime;

};

#endif // GAMERRESEARCH_H
