#include "ship.h"

Ship::Ship(QString shipTypeID, QString shipType, qint32 attackModifierFromShipType, qint32 maxSquadronSize, qint32 minShipSize,
           qint32 actShipSize, qint32 maxShipSize, qint32 ownAccuracyModifier, qint32 enemyAccuracyModifier,
           qint32 HPTakenPerAttackPerShip, qint32 APTakenPerAttackPerShip, qint32 SPTakenPerAttackPerShip,
           qint32 maxShipHP, qint32 maxShipAP, qint32 maxShipSP)
{
    this->shipTypeID=shipTypeID;
    this->shipType=shipType;
    this->attackModifierFromShipType=attackModifierFromShipType;
    this->maxSquadronSize=maxSquadronSize;
    this->minShipSize=minShipSize;
    this->actShipSize=actShipSize;
    this->maxShipSize=maxShipSize;
    this->ownAccuracyModifier=ownAccuracyModifier;
    this->enemyAccuracyModifier=enemyAccuracyModifier;
    this->HPTakenPerAttackPerShip=HPTakenPerAttackPerShip;
    this->APTakenPerAttackPerShip=APTakenPerAttackPerShip;
    this->SPTakenPerAttackPerShip=SPTakenPerAttackPerShip;
    this->maxShipHP=maxShipHP;
    this->maxShipAP=maxShipAP;
    this->maxShipSP=maxShipSP;
    this->curShipHP=maxShipHP;
    this->curShipAP=maxShipAP;
    this->curShipSP=maxShipSP;
}
qint32 Ship::getSquadronHPAttackPoints()
{
    return qFloor(curShipHP/actShipSize/100) * HPTakenPerAttackPerShip * attackModifierFromShipType;
}
qint32 Ship::getSquadronAPAttackPoints()
{
    return qFloor(curShipHP/actShipSize/100) * APTakenPerAttackPerShip * attackModifierFromShipType;
}
qint32 Ship::getSquadronSPAttackPoints()
{
    return qFloor(curShipHP/actShipSize/100) * SPTakenPerAttackPerShip * attackModifierFromShipType;
}
void Ship::recalculateAfterEnemyAttack(qint32 HPTaken, qint32 APTaken, qint32 SPTaken)
{
    if(curShipSP>=SPTaken)
    {
        curShipSP-=SPTaken;
    }
    else
    {
        curShipSP=0;
    }
    if(curShipSP==0)
    {
        if(curShipAP>=APTaken)
        {
            curShipAP-=APTaken;
        }
        else
        {
            curShipAP=0;
        }
    }
    if(curShipSP==0 && curShipAP==0)
    {
        if(curShipHP>=HPTaken)
        {
            curShipHP-=HPTaken;
        }
        else
        {
            curShipHP=0;
        }
    }
}
void Ship::resetAfterBattler()
{
    this->curShipHP=maxShipHP;
    this->curShipAP=maxShipAP;
    this->curShipSP=maxShipSP;
}

bool Ship::canStillFight()
{
    if(curShipHP==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
QString Ship::getShipTypeID()
{
    return shipTypeID;
}
QString Ship::getShipType()
{
    return shipType;
}
qint32 Ship::getOwnAccuracyModifier(qint32 enemyECMModifier)
{
    return 74+ownAccuracyModifier+enemyECMModifier;
}

qint32 Ship::getECMModifier()
{
    return enemyAccuracyModifier;
}
