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
#include "player.h"


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

    const Field* operator [](int i)
    {
        return allCompanies[i];
    }

    void setPlayerPosition(int playerIndex, int companyPositionIndex);
    Company& getPlayerCurrentCompany(int playerId);

private:
    std::vector<Field*> allCompanies;

    int playerPositions[2]; // Hold the current company to hold the position of the players

    /**
     * Utitlity method for initially adding companies into the vector about the companies
     */
    void addCompany(char *name, int cost, CompanyCategory category);
};

#endif // BOARD_H
