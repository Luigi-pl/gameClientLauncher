#ifndef FLEET_H
#define FLEET_H

#include "includeFile.h"

class Ship;


class Fleet
{
public:
    Fleet(QString admiralName, QString fleetName, qint32 admiralLevel=1, qint32 admiralExperience=0,
          float admiralAttackBonus=1.0, float admiralDefendBonus=1.0, qint32 fleetSizeMaximum=0);
    void addShip(Ship shipToAdd);
private:
    QString admiralName;
    qint32 admiralLevel;
    qint32 admiralExperience;
    float admiralAttackBonus;
    float admiralDefendBonus;

    QString fleetName;
    qint32 fleetSizeMaximum;

    QVector<Ship> arrayOfShips;
};

#endif // FLEET_H
