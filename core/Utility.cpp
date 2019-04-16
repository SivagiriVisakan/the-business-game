
#include "Utility.h"


Utility::Utility(char *name, int cost): BuyableField(name)
{
    setCost(cost);
    calculateRent();
}
Utility::~Utility()
{
    //Nothing to do 
}

void Utility::setCost(int c)
{
    this->cost = c;
}

void Utility::calculateRent()
{
        rent = cost * 0.5; // TODO: As above. Check this ratio.    
}
