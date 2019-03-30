/**
 * Test program for checking the correctness and as well as demonstrate the usage
 * of the classes

 * ------------------------------------------------------------------------------------------
 * Compile with command: g++ test.cpp Company.cpp Field.cpp Board.cpp GameManager.cpp player.cpp
 * ------------------------------------------------------------------------------------------------
 */

#include "Company.h"
#include "Board.h"
#include "GameManager.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    GameManager game; // Create an instance of this class.
    game.addPlayer("John");
    game.addPlayer("Markd"); // Add required players
    game.initializeGame(); // Call this method to reset the game.

    std::cout << "----\nCurrent Player: " << game.getCurrentPlayer().getName() << "\n----" << std::endl;
    std::cout << "Current Position: "<< game.getCurrentPlayerCompany().getName() << std::endl;
    int dice = game.rollDice();

    std::cout << "Rolling dice... " << dice << std::endl;
    std::cout << "Updating player position...\n" ;
    game.updateCurrentPlayerPosition(dice);
    
    std::cout << "Player position : " << game.getCurrentPlayerCompany().getName() << std::endl;
    std::cout << "Player position : " << game.updateCurrentPlayerPosition(dice).getName() << std::endl;
    std::cout << "Player position : " << game.updateCurrentPlayerPosition(dice).getName() << std::endl;

    game.buyCompany(0, game.getCurrentPlayerCompany());
    std::cout <<" Owner ID: " << game.getCurrentPlayerCompany().getOwnerId() << std::endl;
    std::cout<< game.getCurrentPlayer().moneyOwned;

    std::cout << "\n\nChanging Turns: " << std::endl;
    game.changeTurn();

    std::cout << "\n----\nCurrent Player: " << game.getCurrentPlayer().getName() << "\n----" << std::endl;
    std::cout << "Current Position: "<< game.getCurrentPlayerCompany().getName() << std::endl;
    std::cout <<" Owner ID of "<< game.getCurrentPlayerCompany().getName() << game.getCurrentPlayerCompany().getOwnerId() << std::endl;


    /*Test code*/
    std::cout<< game.getCurrentPlayer().moneyOwned << std::endl;
    game.changeTurn();
    std::cout<< game.getCurrentPlayer().moneyOwned << std::endl;
    game.changeTurn();
    std::cout<< game.getCurrentPlayer().moneyOwned << std::endl;

    return 0;
}

