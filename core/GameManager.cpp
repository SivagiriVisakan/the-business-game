#include "GameManager.h"
#include <iostream>
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
    int dice= 1; // Randomize this
    return dice;

}

Company GameManager::updateCurrentPlayerPosition(int dice)
{
    return *(Company*)board.updatePlayerPosition(0, dice);
}

Company& GameManager::getCurrentPlayerCompany()
{
    return board.getPlayerCurrentCompany(0);
}

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

void GameManager::buyCompany(int playerId, Company& company)
{
    Player *player = players[playerId];
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