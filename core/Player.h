#ifndef PLAYER_H
#define PLAYER_H

#include<string>

class Player
{
public:
    Player();
    Player(std::string n);

    /**
    * The amount of money currently owned by a player at any given time.
    * This is `int` because we use all the prices as whole numbers.
    */
    int moneyOwned;

    /**
    * This function suld be called all the time whenever the moneyOwned is to be
    * increased or decreased.
    * Specify a negative amount to decrement the balance.
    * 
    * @param change - the amount to change
    */
    void changeMoneyOwned(int change);

    std::string getName() { return name;}

    int getId() { return id; }
    int getMoney() { return moneyOwned; }
    
private:
    std::string name;
    static int TOTAL_ID;
    int id;
};

#endif // PLAYER_H
