
#include "BuyableField.h"
#include <string.h>


/**
 * Initializes the BuyableField with the given name
 */ 
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