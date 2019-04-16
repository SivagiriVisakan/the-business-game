#ifndef COMPANY_H
#define COMPANY_H
#include "BuyableField.h"

enum CompanyCategory{
    ELECTRONICS = 1,
    SOFTWARE = 2,
    AUTOMOTIVES = 3,
    FASHION = 4,
    FOOD = 5
};

class Company : public BuyableField
{
public:
    Company(char *name, int cost, CompanyCategory category);
    ~Company();
    void setCost(int c);
    void calculateRent();

    /**
     * Expanding a company will upgrade it after checking if it can be upgraded and
     * changes the currentLevel
     * ```
     * 
     * ```
    */
    void upgradeCompany();
    CompanyCategory getCategory(){ return category; }
private:
    CompanyCategory category;
};

#endif // COMPANY_H
