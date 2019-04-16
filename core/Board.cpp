#include "Board.h"
#include <string.h>
Board::Board()
{
    //chance
    addUtility("Airport", 300);
    addUtility("Railway", 250);
    addCompany("Amazon", 275,SOFTWARE);
    addCompany("Rolls Royce", 290, AUTOMOTIVES);
    addCompany("H & M", 150 , FASHION);
    addCompany("Samsung", 270, ELECTRONICS);
    addCompany("Cadbury", 250, FOOD);
    //prison
    addCompany("Google",300,SOFTWARE);
    //community chest
    addCompany("Tesla", 175, AUTOMOTIVES);
    addCompany("Facebook",150, SOFTWARE);
    addCompany("Adidas",250, FASHION);
    addCompany("Apple", 280, ELECTRONICS);
    addUtility("Transports", 250);
    addCompany("McDonalds",190, FOOD);
    addCompany("KFC", 120, FOOD);
    addCompany("Benz",250, AUTOMOTIVES);
    addCompany("Nike",120, FASHION);
    //water tax
    addCompany("Xiaomi",250, ELECTRONICS);
    //community chest
    addCompany("Audi", 300, AUTOMOTIVES);
    addCompany("Intel", 300 , ELECTRONICS);
    addCompany("Gucci", 280, FASHION);
    addCompany("Domino's", 175, FOOD);
    //chance
    addCompany("Microsoft", 250, SOFTWARE);
    addUtility("Space station", 400);
    addUtility("Stadium", 200);
    addUtility("Power Plant", 190);
    //income tax
}

void Board::addCompany(char* name, int cost, CompanyCategory category)
{
    Company *c = new Company(name, cost, category);
    allCompanies.push_back(c);
}

void Board::addUtility(char* name, int cost)
{
    Utility *u = new Utility(name, cost);
    allCompanies.push_back(u);
}

int Board::getIndexOfField(Field *f)
{
    int i;
    for( i = 0; i < allCompanies.size(); i++)
    {
        if(strcmp(f->getName(), allCompanies[i]->getName()) == 0)
            return i;
    }

    return -1;
    
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

Field* Board::getCurrentFieldOfPlayer(int playerId)
{
    int index = playerPositions[playerId];
    Field *f = allCompanies[index];
    return f;
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
