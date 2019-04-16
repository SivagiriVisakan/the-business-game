/**
 * GameManager.h
 *
 * This class is the overall manager of everything that happens in the game of Monopoly.
 * Most, if not all of the client-side calls are made to and from only this class.
 */
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <vector>
#include "BuyableField.h"
#include "Company.h"
#include "Player.h"
#include "Board.h"


class GameManager
{
public:
    GameManager();

    void initializeGame();
    int rollDice();
    void addPlayer(char* name);
    void changeTurn();
    void updateCurrentPlayerPosition(int dice);
    Company& getCurrentPlayerCompany();

    Field* getFieldOfCurrentPlayer();
    Player getPlayerFromId(int playerId);
    Player& getCurrentPlayer() { return *players[currentPlayerTurnIndex];}
    void buyCompany(int playerId, BuyableField& company);
    void sellField(int playerId, BuyableField& company);
    Board& getBoard(){return board;}
private:
    Board board;
    std::vector<Player*> players;
    int currentPlayerTurnIndex;
};

#endif // GAME_MANAGER_H
