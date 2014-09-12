#ifndef GAMER_H
#define GAMER_H
#include "includeFile.h"


class GamerResearch;
class Fleet;
class Ship;

class Gamer
{
public:
    Gamer();
    ~Gamer();
    GamerResearch *getResearch();

    void setResearch(GamerResearch *gamerResearch);
    void setFleet(Fleet *fleet);
    void addShip(Ship ship);
    void setCurrentResearch(QString currentResearch);
    bool canBeResearched(QString researchCategory, qint8 researchToCheck);


private:
    GamerResearch *gamerResearch;
    Fleet *gamerFleet;
};

#endif // GAMER_H
