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
