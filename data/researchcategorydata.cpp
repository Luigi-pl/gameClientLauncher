#include "researchcategorydata.h"

ResearchCategoryData::ResearchCategoryData(QString listID, QString categoryName)
{
    this->listID=listID;
    this->categoryName=categoryName;
}
void ResearchCategoryData::addResearch(ResearchData researchData)
{
    this->arrayOfResearchData.append(researchData);
}
QString ResearchCategoryData::getCategoryID()
{
    return this->listID;
}
QString ResearchCategoryData::getCategoryName()
{
    return this->categoryName;
}
qint8 ResearchCategoryData::getSizeOfArrayOfResearchData()
{
    return this->arrayOfResearchData.size();
}
QString ResearchCategoryData::getResearchNameFromArrayOfResearchData(qint8 i)
{
    return this->arrayOfResearchData[i].getResearchName();
}
qint8 ResearchCategoryData::getFirstElementFromArrayOfResearchData(qint8 i)
{
    return this->arrayOfResearchData[i].getFirstElement();
}
qint8 ResearchCategoryData::getLastElementFromArrayOfResearchData(qint8 i)
{
    return this->arrayOfResearchData[i].getLastElement();
}
