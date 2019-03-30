/**
 * GameManager.h
 *
 * The Board class is similar to a Monopoly-like board.
 * This class holds the reference of the positions of the various companies and
 * other utilities. It also tracks the position of the players.
 *
 * Ideally, the constructor should construct all the Company objects and not modify its features at all.
 *
 */
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <vector>
#include "Company.h"
#include "player.h"
#include "Board.h"



/**
 * GameManager - start with two player names.
 * That should set the initial amount for players and do all sorts of reset game stuff
 *   - Set initial amount of money
 *   - Set starting position to be Start for both the players
 *   - Player 1 is given the turn and UI will provide the options for Rolling dice, viewing map etc.

*/
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

    Player getPlayerFromId(int playerId);
    Player& getCurrentPlayer() { return *players[currentPlayerTurnIndex];}
    void buyCompany(int playerId, Company& company);
private:
    Board board;
    std::vector<Player*> players;
    int currentPlayerTurnIndex;
};

#endif // GAME_MANAGER_H
