#ifndef COMPANY_H
#define COMPANY_H
#include "Field.h"

class Company : public Field
{
public:
    Company(char *name, int cost);
    void setCost(int c);
    void calculateRent();

    /**
     * Expanding a company will upgrade it after checking if it can be upgraded and
     * changes the currentLevel
    */
    void upgradeCompany();
};

#endif // COMPANY_H
