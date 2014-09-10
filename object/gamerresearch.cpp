
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
    /////////////////
    this->currentResearched=false;
    this->currentResearchedID=-1;
    this->currentResearchedCategory="";

}
bool GamerResearch::isCurrentResearch()
{
    return this->currentResearched;
}
void GamerResearch::setCurrentResearch(bool state)
{
    this->currentResearched=state;
}
void GamerResearch::setCurrentResearchData(QString category, qint8 id, qint32 researchTime)
{
    setCurrentResearch(true);
    this->currentResearchedID=id;
    this->currentResearchedCategory=category;
    this->currentResearchEndTime=QDateTime::currentDateTime();
    this->currentResearchEndTime = this->currentResearchEndTime.addSecs(researchTime*60);
}
qint8 GamerResearch::setResearchAdvancer()
{
    int tittleShift=0;
    if(currentResearchedCategory[0]=='A')
    {
        if(this->currentResearchedID<upperLimitForMissile)
        {
            this->missile++;
            tittleShift=1;
        }
        else if(this->currentResearchedID<upperLimitForIonCannon)
        {
            this->ionCannon++;
            tittleShift=2;
        }
        else if(this->currentResearchedID<upperLimitForPlasmaGun)
        {
            this->plasmaGun++;
            tittleShift=3;
        }
        else if(this->currentResearchedID<upperLimitForArmor)
        {
            this->armor++;
            tittleShift=4;
        }
        else if(this->currentResearchedID<upperLimitForShield)
        {
            this->shield++;
            tittleShift=5;
        }
        return this->currentResearchedID+tittleShift;
    }
    else if(currentResearchedCategory[0]=='B')
    {
        if(this->currentResearchedID<upperLimitForEcm)
        {
            this->ecm++;
            tittleShift=6;
        }
        else if(this->currentResearchedID<upperLimitForEccm)
        {
            this->eccm++;
            tittleShift=7;
        }
        return this->currentResearchedID+36+tittleShift;
    }
    else if(currentResearchedCategory[0]=='C')
    {
        if(this->currentResearchedID<10)
        {
            this->shipSize++;
            tittleShift=8;
        }
        return this->currentResearchedID+36+16+tittleShift;
    }
    else if(currentResearchedCategory[0]=='-')
    {
        if(this->currentResearchedID<10)
        {
            this->fleetSize++;
            tittleShift=9;
        }
        return this->currentResearchedID+36+16+10+tittleShift;
    }

    return 0;
}
QString GamerResearch::getCurrentResearchTimeEnd()
{
    return this->currentResearchEndTime.toString("dd.MM.yyyy HH:mm");
}
QString GamerResearch::getCurrentResearchCategory()
{
    return this->currentResearchedCategory;
}
void GamerResearch::clearCurrentResearch()
{
    setCurrentResearch(false);
    this->currentResearchedID=-1;
    this->currentResearchedCategory="D";
}

qint8 GamerResearch::getCurrentResearchID()
{
    return this->currentResearchedID;
}
bool GamerResearch::isResearchFinished()
{
    return (this->currentResearchEndTime<=QDateTime::currentDateTime());
}
QString GamerResearch::getCurrentResearchDataToSendToServer(QString type)
{
    return type+currentResearchedCategory+QString::number(currentResearchedID);
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
bool GamerResearch::checkIsResearchable(QString researchType, qint8 researchToCheck)
{
    if(researchToCheck<1)
    {
        return false;
    }

    if(researchType[0]=='A')
    {
        if(1<=researchToCheck &&
                researchToCheck<=upperLimitForMissile &&
                researchToCheck==missile+2)
        {
            return true;
        }
        else if(upperLimitForMissile<researchToCheck &&
                researchToCheck<=upperLimitForIonCannon &&
                researchToCheck==ionCannon+2)
        {
            return true;
        }
        else if(upperLimitForIonCannon<researchToCheck &&
                researchToCheck<=upperLimitForPlasmaGun &&
                researchToCheck==plasmaGun+2)
        {
            return true;
        }
        else if(upperLimitForPlasmaGun<researchToCheck &&
                researchToCheck<=upperLimitForArmor &&
                researchToCheck==armor+2)
        {
            return true;
        }
        else if(upperLimitForArmor<researchToCheck &&
                researchToCheck<=upperLimitForShield &&
                researchToCheck==shield+2)
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
        if(1<=researchToCheck &&
                researchToCheck<=upperLimitForEcm &&
                researchToCheck==ecm+2)
        {
            return true;
        }
        else if(upperLimitForEcm<researchToCheck &&
                researchToCheck<=upperLimitForEccm &&
                researchToCheck==eccm+2)
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
        if(1<=researchToCheck &&
                researchToCheck<=10 &&
                researchToCheck==shipSize+2)
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
        if(1<=researchToCheck &&
                researchToCheck<=10 &&
                researchToCheck==fleetSize+2)
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
