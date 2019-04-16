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
    * This function should be called all the time whenever the moneyOwned is to be
    * increased or decreased.
    * Specify a negative amount to decrement the balance.
    * 
    * @param change - the amount to change
    */
    /* TODO: Write the implementation. It should also check for the case of moneyOwned going below zero
       i.e the player has gone bankrupt and the game should end.
       Still have to figure out how to specify the game ending from here.
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
