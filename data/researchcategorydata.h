#ifndef RESEARCHCATEGORYDATA_H
#define RESEARCHCATEGORYDATA_H
#include "includeFile.h"
#include "researchdata.h"

class ResearchCategoryData
{
public:
    ResearchCategoryData() {}
    ResearchCategoryData(QString listID, QString categoryName);
    void addResearch(ResearchData researchData);
    QString getCategoryID();
    QString getCategoryName();
    qint8 getSizeOfArrayOfResearchData();

    QString getResearchNameFromArrayOfResearchData(qint8 i);
    qint8 getFirstElementFromArrayOfResearchData(qint8 i);
    qint8 getLastElementFromArrayOfResearchData(qint8 i);
private:
    QString listID;
    QString categoryName;
    QVector <ResearchData> arrayOfResearchData;
};

#endif // RESEARCHCATEGORYDATA_H
