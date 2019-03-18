#include "Board.h"

Board::Board()
{
    char c[20] = "Google";
    addCompany(c, 200);
}

void Board::addCompany(char* name, int cost)
{
    Company c(name, cost);
    allCompanies.push_back(c);
}