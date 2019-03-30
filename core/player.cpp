#include "player.h"
#include <exception>
#include <string.h>
Player::Player()
{
    strcpy(name, "\0");
}

Player::Player(char *n)
{
    if(strlen(n) <= 20)
        strcpy(name, n);
    else {
        throw "Player name too long";
    }

    moneyOwned = 10000;
}

void Player::changeMoneyOwned(int change)
{
    moneyOwned += change;
}
