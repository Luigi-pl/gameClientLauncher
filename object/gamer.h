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
private:
    GamerResearch *gamerResearch;
};

#endif // GAMER_H
