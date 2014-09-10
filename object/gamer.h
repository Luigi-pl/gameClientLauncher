#ifndef GAMER_H
#define GAMER_H
#include "includeFile.h"


class GamerResearch;

class Gamer
{
public:
    Gamer();
    ~Gamer();
    GamerResearch *getResearch();

    void setResearch(GamerResearch *gamerResearch);
    void setCurrentResearch(QString currentResearch);
    bool canBeResearched(QString researchCategory, qint8 researchToCheck);
private:
    GamerResearch *gamerResearch;
};

#endif // GAMER_H
