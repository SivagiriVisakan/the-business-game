#include "GameManager.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
GameManager::GameManager(): board()
{
    // TODO: Change this for the Go! place.
}

void GameManager::addPlayer(char *name)
{
    Player *p = new Player(name);
    players.push_back(p);
}


void GameManager::initializeGame()
{
    currentPlayerTurnIndex = 0;
    board.setPlayerPosition(0, 0); // Initially at the first position
    board.setPlayerPosition(1, 0); // Initially at the first position

}

void GameManager::changeTurn()
{
    int index = (currentPlayerTurnIndex + 1) % players.size() ;
    currentPlayerTurnIndex = index;

}

int GameManager::rollDice()
{
    int num;
    int min = 1, max = 6;
    srand(time(0));
    num = (min + (rand() % (int)(max - min + 1)));
    return num;
}

Company GameManager::updateCurrentPlayerPosition(int dice)
{
    return *(Company*)board.updatePlayerPosition(currentPlayerTurnIndex, dice);
}

Company& GameManager::getCurrentPlayerCompany()
{
    return board.getPlayerCurrentCompany(currentPlayerTurnIndex);
}

/**
 * Returns a pointer to the Field that the current player is positioned in.
 * The client-side code should make checks and convert it to appropriate objects of Company, Utility etc.
 * 
 * Example usage:
 * ```cpp
 * 
 * Field* f = gm.getFieldOfCurrentPlayer();
 * 
 * if(dynamic_cast<Company*> (f))
 * {
 *      Company *c = dynamic_cast<Company*> (f);
 *      // Do things for Company type 
 * }
 *      // Similarly perform else-if checks and handle the Field appropriately.
 * 
 * ```
 */ 
Field* GameManager::getFieldOfCurrentPlayer()
{
    return board.getCurrentFieldOfPlayer(currentPlayerTurnIndex);
}

/**
 * Get the Player with the specified ID.
 * Else throws an exception
 */ 
Player GameManager::getPlayerFromId(int id)
{
    if(id < players.size()-1)
    {
        return *players[id];
    } 
    else
    {
        throw "Player index out of range";
    }
    
}
/**
 * Buys the given BuyableField i.e checks if the current player
 */ 
void GameManager::buyCompany(int playerId, BuyableField& company)
{
    Player *player = players[playerId];
    if(company.getOwnerId() != -1)
    {
        throw "Field not for sale.";
    }
    if(player->moneyOwned >= company.getCost())
    {
        company.setOwner(playerId);
        player->changeMoneyOwned(-company.getCost());
    }
    else
    {
        throw "Not enough money to buy";
    }
    
}


/**
 * Sells the given BuyableField i.e check if the player is the owner, if yes then add money into his account
 * and set the owner to none.
 * ```cpp
 * gm.sellField(gm.getCurrentPlayerId, gm.board[2])
 * ``` 
 */
void GameManager::sellField(int playerId, BuyableField& company)
{
    Player *player = players[playerId];
    if(company.getOwnerId() == playerId)
    {
        company.setOwner(-1);
        player->changeMoneyOwned(company.getCost()*0.8*company.getCurrentLevel()); // Adds the 80% of original cost on selling
    }
    else
    {
        throw "Not owned by player";
    }

}
