#ifndef UTILITY_H
#define UTILITY_H
#include "BuyableField.h"

class Utility : public BuyableField
{
public:
    Utility(char *name, int cost);
    ~Utility();
    void setCost(int c);
    void calculateRent();
};

#endif // UTILITY_H
