
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
    if(level != NotUpgradable) // TODO: This might be an unneccessary check. All companies are upgrade-able(utilities aren't)
    {
        rent = level * cost*0.9; // TODO:Check this for a better ratio
    }
    else
    {
        rent = cost * 0.8; // TODO: As above. Check this ratio.
    }
    
}

void Company::upgradeCompany()
{
    if(level < LevelThree)
    {
        level = FieldLevel(level + 1); // Upgrade the level by 1
        calculateRent(); // Recalculate the rent for this level.
    }
    else
    {
        throw "Can't upgrade company"; // TODO: Check if this is needed or any better way.
    }
}
