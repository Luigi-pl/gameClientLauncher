#include "fleet.h"
#include "ship.h"

Fleet::Fleet(QString admiralName, QString fleetName, qint32 admiralLevel, qint32 admiralExperience,
             float admiralAttackBonus, float admiralDefendBonus, qint32 fleetSizeMaximum)
{
    this->admiralName=admiralName;
    this->admiralLevel=admiralLevel;
    this->admiralExperience=admiralExperience;

    this->admiralAttackBonus=admiralAttackBonus;
    this->admiralDefendBonus=admiralDefendBonus;

    this->fleetName=fleetName;
    this->fleetSizeMaximum=fleetSizeMaximum;
}

void Fleet::addShip(Ship shipToAdd)
{
    if(arrayOfShips.size()<fleetSizeMaximum+1)
    {
        arrayOfShips.append(shipToAdd);
    }
}
