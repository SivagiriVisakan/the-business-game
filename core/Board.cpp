#include "Board.h"
#include <string.h>
Board::Board()
{


    //GO
    NonBuyableField *nbf = new NonBuyableField("Start", -50);
    allCompanies.push_back(nbf);
    //chance
    LuckField *lf = new LuckField("Chance", 100);
    allCompanies.push_back(lf);

    addUtility("Airport", 300);
    addUtility("Railway", 250);
    addCompany("Rolls Royce", 290, AUTOMOTIVES);
    addCompany("Samsung", 270, ELECTRONICS);
    addCompany("Cadbury", 250, FOOD);
    addCompany("H & M", 150 , FASHION);
    addCompany("Amazon", 275,SOFTWARE);
    addCompany("Tesla", 175, AUTOMOTIVES);
    
    //community chest
    lf = new LuckField("CommunityChest", 100);
    allCompanies.push_back(lf);

    addCompany("Google",300,SOFTWARE);
    //prison
    nbf = new NonBuyableField("Prison", 1000);
    allCompanies.push_back(nbf);
    addCompany("Apple", 280, ELECTRONICS);
    addCompany("Adidas",250, FASHION);
    addCompany("Facebook",150, SOFTWARE);
    addCompany("Microsoft", 250, SOFTWARE);
    addCompany("Domino's", 175, FOOD);
    addCompany("Intel", 300 , ELECTRONICS);
    
    //community chest
    lf = new LuckField("CommunityChest", 100);
    allCompanies.push_back(lf);

    //water tax
    nbf = new NonBuyableField("WaterTax", 50);
    allCompanies.push_back(nbf);
    addCompany("Benz",250, AUTOMOTIVES);
    addCompany("McDonalds",190, FOOD);
    addUtility("Transports", 250);
    addCompany("KFC", 120, FOOD);
    addCompany("Nike",120, FASHION);
    addCompany("Xiaomi",250, ELECTRONICS);
    addCompany("Audi", 300, AUTOMOTIVES);
    addCompany("Gucci", 280, FASHION);

    //chance
    lf = new LuckField("Chance", 100);
    allCompanies.push_back(lf);

    addUtility("Power Plant", 190);

    //income tax
    nbf = new NonBuyableField("IncomeTax", 50);
    allCompanies.push_back(nbf);
    addUtility("Stadium", 200);
    addUtility("Space station", 400);
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

        int exactPositionToUpdate = positionToUpdate % totalLength;
        setPlayerPosition(player, exactPositionToUpdate);
        return allCompanies[exactPositionToUpdate];
}
