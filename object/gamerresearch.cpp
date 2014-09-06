
#include "gamerresearch.h"

GamerResearch::GamerResearch(qint8 shipSize,
                             qint8 missile, qint8 ionCannon, qint8 plasmaGun,
                             qint8 armor, qint8 shield,
                             qint8 ecm, qint8 eccm,
                             qint8 fleetSize)
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
}
bool GamerResearch::checkIsResearched(QString researchType, qint8 researchToCheck)
{
    if(researchType[0]=='A')
    {
        if(researchToCheck<8 && researchToCheck<=missile)
        {
            return true;
        }
        else if(8<=researchToCheck && researchToCheck<16 && researchToCheck<=ionCannon)
        {
            return true;
        }
        else if(16<=researchToCheck && researchToCheck<24 && researchToCheck<=plasmaGun)
        {
            return true;
        }
        else if(24<=researchToCheck && researchToCheck<30 && researchToCheck<=armor)
        {
            return true;
        }
        else if(30<=researchToCheck && researchToCheck<36 && researchToCheck<=shield)
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
        if(researchToCheck<8 && researchToCheck<=ecm)
        {
            return true;
        }
        else if(8<=researchToCheck && researchToCheck<16 && researchToCheck<=eccm)
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
