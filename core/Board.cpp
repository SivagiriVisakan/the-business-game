#include "Board.h"

Board::Board()
{
    char c[20] = "Google";
    addCompany(c, 200, TECH_INDUSTRY);
    addCompany("Facebook", 175, TECH_INDUSTRY);
    addCompany("Gucci", 175, TECH_INDUSTRY);
}

void Board::addCompany(char* name, int cost, CompanyCategory category)
{
    Company *c = new Company(name, cost, category);
    allCompanies.push_back(c);
}

void Board::setPlayerPosition(int playerIndex, int companyPositionIndex)
{
    playerPositions[playerIndex] = companyPositionIndex;
}

Company& Board::getPlayerCurrentCompany(int playerId)
{
    int index = playerPositions[playerId];
    Company *c = dynamic_cast<Company*> (allCompanies[index]);;
    return *c;
}

Field* Board::updatePlayerPosition(const int player, int diceMoves)
{
    int totalLength = allCompanies.size();
    int currentPosition = playerPositions[player];
    int positionToUpdate = currentPosition + diceMoves;

    // if(positionToUpdate <= totalLength)
    // {
    //     setPlayerPosition(player, positionToUpdate);
    //     return allCompanies[positionToUpdate];
    // }
    // else
    {
        int exactPositionToUpdate = positionToUpdate % totalLength;
        setPlayerPosition(player, exactPositionToUpdate);
        return allCompanies[exactPositionToUpdate];
    }
}
