/**
 * GameManager.h
 *
 * This class is the overall manager of everything that happens in the game of Monopoly.
 * Most, if not all of the client-side calls are made to and from only this class.
 */
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <vector>
#include "Company.h"
#include "player.h"
#include "Board.h"


class GameManager
{
public:
    GameManager();

    void initializeGame();
    int rollDice();
    void addPlayer(char* name);
    void changeTurn();
    Company updateCurrentPlayerPosition(int dice);
    Company& getCurrentPlayerCompany();

    Field* getFieldOfCurrentPlayer();
    Player getPlayerFromId(int playerId);
    Player& getCurrentPlayer() { return *players[currentPlayerTurnIndex];}
    void buyCompany(int playerId, Company& company);
private:
    Board board;
    std::vector<Player*> players;
    int currentPlayerTurnIndex;
};

#endif // GAME_MANAGER_H
