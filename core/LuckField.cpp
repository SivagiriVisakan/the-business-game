
#include "LuckField.h"
#include <ctime>
#include <cstdlib>

/**
 * Initializes the LuckField with the given name
 */ 
LuckField::LuckField(char *name, int rent): NonBuyableField(name, rent)
{
    // Nothing to do here
}

void LuckField::calculateRent()
{
    srand(time(0));
    int num = rand() % 2;
    if(num == 0)
    {
        rent = 100; // Rent will be deducted from the player. Player is in bad luck.
        helpText =  std::string(name) + " charges you " + std::to_string(rent) ;
    }
    else
    {
        rent = -100; // Rent will be added to the player. Player is in good luck.
        helpText =  std::string(name) + " rewards you with " + std::to_string(100) ;

    }
}

const char* LuckField::getHelpText()
{
    return helpText.c_str();
}