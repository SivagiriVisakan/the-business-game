#include "Player.h"
#include <exception>
#include <string>

int Player::TOTAL_ID = 0;
Player::Player()
{
    id = TOTAL_ID++;
}

Player::Player(std::string n)
{
    name=n;
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
