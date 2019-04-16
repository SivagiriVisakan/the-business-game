#include "Player.h"
#include <exception>
#include <string.h>

int Player::TOTAL_ID = 0;
Player::Player()
{
    strcpy(name, "\0");
    id = TOTAL_ID++;
}

Player::Player(char *n)
{
    if(strlen(n) <= 20)
        strcpy(name, n);
    else {
        throw "Player name too long";
    }

    moneyOwned = 10000;
    id = TOTAL_ID++;
}

void Player::changeMoneyOwned(int change)
{
    moneyOwned += change;
    if(moneyOwned <= 0)
    {
        throw 2; // Two is for bankruptcy
    }
}
