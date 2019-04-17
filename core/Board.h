/**
 * Board.h
 *
 * The Board class is similar to a Monopoly-like board.
 * This class holds the reference of the positions of the various companies and
 * other utilities. It also tracks the position of the players.
 *
 * Ideally, the constructor should construct all the Company objects and not modify its features at all.
 *
 */
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Company.h"
#include "Player.h"
#include "Utility.h"
#include "NonBuyableField.h"
#include "LuckField.h"
class Board
{
public:
    Board();

    /**
     * Update the current position of the player to that many dice moves.
     * Automatically handles the case where the diceMoves goes over all the places(starts from the first again)
     */
    Company updatePlayerPosition(const Player& player, int diceMoves);
    Field* updatePlayerPosition(const int player, int diceMoves);

    Field* operator [](int i)
    {
        return allCompanies[i];
    }

    void setPlayerPosition(int playerIndex, int companyPositionIndex);
    Company& getPlayerCurrentCompany(int playerId);

    Field* getCurrentFieldOfPlayer(int playerId);

    /**
     * Returns the index (starting from zero) of the given field in the arrangement of the board.
     * 
     * ```
     * Field *f = getCurrentFieldOfPlayer(0);
     * int index = board.getIndexOfField(f);
     * cout << index;
     * ```
     */
    int getIndexOfField(Field *f);
    std::vector<Field*> getAllFields(){ return allCompanies;}
private:
    std::vector<Field*> allCompanies;

    int playerPositions[2]; // Hold the current company to hold the position of the players

    /**
     * Utitlity method for initially adding companies into the vector about the companies
     */
    void addCompany(char *name, int cost, CompanyCategory category);

    /**
     * Utitlity method for initially adding `Utilities` into the vector about the companies
     */
    void addUtility(char *name, int cost);

    /**
     * Utitlity method for initially adding `NonBuyableField` into the vector about the companies
     */
    void addNonBuyableField(char *name, int rent);

};

#endif // BOARD_H
