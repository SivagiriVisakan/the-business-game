
#include "Company.h"


Company::Company(char *name, int cost): Field(name)
{
    setCost(cost);
    level = LevelOne;
    calculateRent();
}

void Company::setCost(int c)
{
    this->cost = c;
}

void Company::calculateRent()
{
    if(level != NotUpgradable)
    {
        rent = level * cost*0.9; // TODO:Check this for a better ratio
    }
    else
    {
        rent = cost * 0.8; // TODO: As above. Check this ratio.
    }
    
}

