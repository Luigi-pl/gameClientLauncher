#ifndef SHIP_H
#define SHIP_H

#include "includeFile.h"

class Ship
{
public:
    Ship() {}
    Ship(QString bdObjectInformation,  QString shipTypeID, QString shipType, qint32 attackModifierFromShipType, qint32 maxSquadronSize,
    qint32 minShipSize, qint32 actShipSize, qint32 maxShipSize,
    qint32 ownAccuracyModifier, qint32 enemyAccuracyModifier,
    qint32 HPTakenPerAttackPerShip, qint32 APTakenPerAttackPerShip, qint32 SPTakenPerAttackPerShip,
    qint32 maxShipHP, qint32 maxShipAP, qint32 maxShipSP);

    QString getShipTypeID();
    QString getShipType();
    qint32 getSquadronHPAttackPoints();
    qint32 getSquadronSPAttackPoints();
    qint32 getSquadronAPAttackPoints();
    qint32 getOwnAccuracyModifier(qint32 enemyECMModifier);
    qint32 getECMModifier();


    void recalculateAfterEnemyAttack(qint32 HPTaken, qint32 APTaken, qint32 SPTaken);
    void resetAfterBattler();
    bool canStillFight();
    QString getBDObjectInformation();
    void setBDObjectInformation(QString BDObjectInformation);

private:
    QString bdObjectInformation;

    QString shipTypeID;
    QString shipType;
    qint32 attackModifierFromShipType;

    qint32 maxSquadronSize;

    qint32 minShipSize;
    qint32 actShipSize;
    qint32 maxShipSize;

    qint32 ownAccuracyModifier;
    qint32 enemyAccuracyModifier;

    qint32 HPTakenPerAttackPerShip;
    qint32 APTakenPerAttackPerShip;
    qint32 SPTakenPerAttackPerShip;

    qint32 maxShipHP;
    qint32 maxShipAP;
    qint32 maxShipSP;
    qint32 curShipHP;
    qint32 curShipAP;
    qint32 curShipSP;
};

#endif // SHIP_H
