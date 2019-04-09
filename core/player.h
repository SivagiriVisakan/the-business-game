#ifndef PLAYER_H
#define PLAYER_H


//#include "Field.h"


class Player
{
public:
    Player();
    Player(char *n);

    /**
    * This array will hold both the Company and Utility
    * owned by the given Player
    * TODO: Try and make this dynamic
    */
    // Field fieldsOwned[20];


    /**
    * The count of cards owned by the player.
    */
    int fieldsOwnedCount;

    /**
    * The amount of money currently owned by a player at any given time.
    * This is `int` because we use all the prices as whole numbers.
    */
    int moneyOwned;

    /**
    * This will buy the given Field , under the condition that a player is able to
    * afford the given place.
    * TODO: Write implementation of this. It should check for the money and modify the `field` to set owner
    *       and add the `field` to the players collection of fields and modify the money
    */
    // void buyField(Field &field);

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

    char* getName() { return name;}
    /**
    * Checks if the given field is in the possession of the player
    * TODO: Implement this. (Search for the given field in the fieldsOwned array)
    */
    // bool hasField(const Field &field);

    
private:
    char name[20];
};

#endif // PLAYER_H
