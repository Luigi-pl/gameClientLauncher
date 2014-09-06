
#include "gamerresearch.h"

GamerResearch::GamerResearch(qint8 shipSize,
                             qint8 missile, qint8 ionCannon, qint8 plasmaGun,
                             qint8 armor, qint8 shield,
                             qint8 ecm, qint8 eccm,
                             qint8 fleetSize,
                             qint8 upperLimitForMissile, qint8 upperLimitForIonCannon, qint8 upperLimitForPlasmaGun,
                             qint8 upperLimitForArmor, qint8 upperLimitForShield,
                             qint8 upperLimitForEcm, qint8 upperLimitForEccm)
{
    this->shipSize=shipSize;

    this->missile=missile;
    this->ionCannon=ionCannon;
    this->plasmaGun=plasmaGun;

    this->armor=armor;
    this->shield=shield;

    this->ecm=ecm;
    this->eccm=eccm;

    this->fleetSize=fleetSize;

    this->upperLimitForMissile=upperLimitForMissile;
    this->upperLimitForIonCannon=upperLimitForIonCannon;
    this->upperLimitForPlasmaGun=upperLimitForPlasmaGun;

    this->upperLimitForArmor=upperLimitForArmor;
    this->upperLimitForShield=upperLimitForShield;

    this->upperLimitForEcm=upperLimitForEcm;
    this->upperLimitForEccm=upperLimitForEccm;
}
bool GamerResearch::checkIsResearched(QString researchType, qint8 researchToCheck)
{
    if(researchType[0]=='A')
    {
        if(researchToCheck<upperLimitForMissile && researchToCheck<=missile)
        {
            return true;
        }
        else if(upperLimitForMissile<=researchToCheck &&
                researchToCheck<upperLimitForIonCannon && researchToCheck<=ionCannon)
        {
            return true;
        }
        else if(upperLimitForIonCannon<=researchToCheck &&
                researchToCheck<upperLimitForPlasmaGun && researchToCheck<=plasmaGun)
        {
            return true;
        }
        else if(upperLimitForPlasmaGun<=researchToCheck &&
                researchToCheck<upperLimitForArmor && researchToCheck<=armor)
        {
            return true;
        }
        else if(upperLimitForArmor<=researchToCheck &&
                researchToCheck<upperLimitForShield && researchToCheck<=shield)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(researchType[0]=='B')
    {
        if(researchToCheck<upperLimitForEcm && researchToCheck<=ecm)
        {
            return true;
        }
        else if(upperLimitForEcm<=researchToCheck &&
                researchToCheck<upperLimitForEccm && researchToCheck<=eccm)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(researchType[0]=='C')
    {
        if(researchToCheck<=shipSize)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(researchType[0]=='-')
    {
        if(researchToCheck<=fleetSize)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
