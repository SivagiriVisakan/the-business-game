#include "GameManager.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

GameManager::GameManager(): board()
{
    // TODO: Change this for the Go! place.
}

void GameManager::addPlayer(std::string name)
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

void GameManager::updateCurrentPlayerPosition(int dice)
{
    board.updatePlayerPosition(currentPlayerTurnIndex, dice);
    Field *f = getFieldOfCurrentPlayer();
    if(dynamic_cast<BuyableField*> (f))
    {
     BuyableField *bf = dynamic_cast<BuyableField*> (f);
     if(bf->getOwnerId() != -1 && bf->getOwnerId() != getCurrentPlayer().getId())
     {
         // The player doesn't own the field, so reduce his money.
         getCurrentPlayer().changeMoneyOwned(-(bf->getRent()));
         // Add the rent into the owner's account.
         getPlayerFromId(bf->getOwnerId()).changeMoneyOwned(bf->getRent());
     }
    }
    else if(dynamic_cast<NonBuyableField*> (f))
    {
        // It is not a BuyAble Field, so we try if it is a NonBuyableField.
        // If it is so, then reduce the money based.
        NonBuyableField *nbf = dynamic_cast<NonBuyableField*> (f);
        nbf->calculateRent();
        getCurrentPlayer().changeMoneyOwned(-(nbf->getRent()));
    }
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
Player& GameManager::getPlayerFromId(int id)
{
    if(id < players.size())
    {
        return *players[id];
    } 
    else
    {
        throw 1;
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
        throw 1;
    }
    if(player->moneyOwned >= company.getCost())
    {
        company.setOwner(playerId);
        player->changeMoneyOwned(-company.getCost());
    }
    else
    {
        throw 2;
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

/**
 * Returns the fields which have been bought by the player with the given ID.
 */
vector<BuyableField*> GameManager::getFieldsOwnedByPlayer(int id)
{
    std::vector<Field*> all = board.getAllFields();
    std::vector<BuyableField*> owned;

    for(int i = 0; i < all.size(); i++)
    {
        Field *f = all[i];
        if(dynamic_cast<BuyableField*> (f))
        {
            BuyableField *bf = dynamic_cast<BuyableField*> (f);
            if(bf->getOwnerId() == id)
            {
                owned.push_back(bf);
            }
        }
    }
    return owned;
}
