#ifndef COMPANY_H
#define COMPANY_H
#include "BuyableField.h"

enum CompanyCategory{
    SOCIAL_MEDIA = 1,
    TECH_INDUSTRY = 2,
    AUTOMOTIVE_INDUSTRY = 3,
    GAMING = 4,
    RETAIL_INDUSTRY = 5
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
     * main()
     * ```
    */
    void upgradeCompany();
    CompanyCategory getCategory(){ return category; }
private:
    CompanyCategory category;
};

#endif // COMPANY_H
