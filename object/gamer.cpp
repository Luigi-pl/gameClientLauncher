#include "gamer.h"
#include "gamerresearch.h"

Gamer::Gamer()
{

}
GamerResearch *Gamer::getResearch()
{
    return this->gamerResearch;
}
Gamer::~Gamer()
{
    delete this->gamerResearch;
}
void Gamer::setResearch(GamerResearch *gamerResearch)
{
    this->gamerResearch=gamerResearch;
}
void Gamer::setCurrentResearch(QString currentResearch)
{
    if(currentResearch.compare("NONE")==0)
    {
        gamerResearch->setCurrentResearch(false);
    }
    else
    {
        QString category=currentResearch.left(1);
        currentResearch.remove(0,1);

        QString id=currentResearch.left(2);
        currentResearch.remove(0,2);

        QString timeLeft=currentResearch;

        gamerResearch->setCurrentResearchData(category, id.toInt(), timeLeft.toInt());
    }
}

bool Gamer::canBeResearched(QString researchCategory, qint8 researchToCheck)
{
    return this->gamerResearch->checkIsResearchable(researchCategory, researchToCheck);
}
