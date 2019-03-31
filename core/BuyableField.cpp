
#include "BuyableField.h"
#include <string.h>

BuyableField::BuyableField(char *name): Field(name)
{
    ownerId = -1;

}

BuyableField::BuyableField(const BuyableField& bf): Field(bf)
{
    level  = bf.level;
    cost = bf.cost;
    rent = bf.rent;
    ownerId = bf.ownerId;
}

BuyableField::~BuyableField()
{
}