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
                  qint8 fleetSize);
    bool checkIsResearched(QString researchType, qint8 researchToCheck);
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
};

#endif // GAMERRESEARCH_H
