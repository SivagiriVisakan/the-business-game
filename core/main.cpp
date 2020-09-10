#include "Company.h"
#include "Board.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    char name[243] = "dsf";
    Company c(name, 100);
    std::cout << c.getCurrentLevel();
    std::cout << c.getRent();
    c.upgradeCompany();
    std::cout << std::endl<<c.getCurrentLevel();
    std::cout << c.getRent();
    std::cout << std::endl<<c.getCost();

    Board b;
    std::cout << "\n\n\n";

    c = b[0];
    char* n = c.getName();
    std::cout << "Ds";
    std::cout << "\n\nCompany: " << c.getName();
    std::cout << "\t Cost: " << c.getCost()<<std::endl;
    std::cout << "\nLevel: " << c.getCurrentLevel();
    std::cout << std::endl << "Rent: "<< c.getRent();
    c.upgradeCompany();
    std::cout << "\nLevel: " <<c.getCurrentLevel();
    std::cout <<  "\nRent: " << c.getRent();

    std::cout << std::endl<<c.getCost();

    
    return 0;
}
