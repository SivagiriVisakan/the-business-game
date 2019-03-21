#include "Board.h"

Board::Board()
{
    char c[20] = "Google";
    addCompany(c, 200, TECH_INDUSTRY);
    addCompany("Facebook", 175, TECH_INDUSTRY);
}

void Board::addCompany(char* name, int cost, CompanyCategory category)
{
    Company c(name, cost, TECH_INDUSTRY);
    allCompanies.push_back(c);
}

void Board::setPlayerPosition(int playerIndex, int companyPositionIndex)
{
    playerPositions[playerIndex] = companyPositionIndex;
}

Company Board::getPlayerCurrentPosition(int playerId)
{
    int index = playerPositions[playerId];
    Company c = allCompanies[index];
    return c;
}