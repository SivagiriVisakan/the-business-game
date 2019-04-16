
#include "NonBuyableField.h"
#include <string.h>


/**
 * Initializes the NonBuyableField with the given name
 */ 
NonBuyableField::NonBuyableField(char *name, int rent): Field(name)
{
    this->rent = rent;
    helpText = "You are charged " + std::to_string(rent) + "for landing in " +  std::string(name);
}


NonBuyableField::NonBuyableField(const NonBuyableField& nbf): Field(nbf)
{
    rent = nbf.rent;
}

NonBuyableField::~NonBuyableField()
{
}

void NonBuyableField::calculateRent()
{
    rent = rent;
}
const char* NonBuyableField::getHelpText()
{
    return helpText.c_str(); 
}