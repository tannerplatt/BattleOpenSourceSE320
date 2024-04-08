#include <iostream>
#include <string>
#include <stdexcept>
#include "battle.h"


void unitTests(){
    Player test("test_player", 100, 15);
    test.receiveDamage(105);
    if (test.getHealth() != 0){
        throw std::runtime_error("Player health cannot go below 0.");
    }else{
        std::cout << "Test 1 Complete!" << std::endl;
    }
    Player test2("test_player2", 100, 12);
    Player test3("test_player3", 100, 18);
    Battle testBattle;
    testBattle.testTurn(test2,test3);
    testBattle.testTurn(test3,test2);
    if (test2.getHealth() != 82){
        throw std::runtime_error("Error with Ai Turn.");
    }else{
        std::cout << "Test 2 Complete!" << std::endl;
    }
    if (test3.getHealth() != 88){
        throw std::runtime_error("Error with Player turn.");
    }else{
        std::cout << "Test 3 Complete!" << std::endl;
    }
    Player test4("test_player4", 100, 18);
    testBattle.testHeal(test4);
    if (test4.getHealth() > 100){
        throw std::runtime_error("Error with player healing.");
    }else{
        std::cout << "Test 4 Complete!" << std::endl;
    }
}

int main(int argc, char **argv) {
    bool unitTestFlag = false;
    for (int i = 1; i < argc; i++){
        if(std::string(argv[i]) == "-test"){
            unitTestFlag = true;
            break;
        }
    }

    if (unitTestFlag){
        unitTests();
    } else {
        std::string playerName;
        std::cout << "Enter your character's name: ";
        std::getline(std::cin, playerName);

        //creating the player and a basic AI opponent
        Player player(playerName, 100, 15); //player with 100 health and 15 attack power
        Player ai("AI_Opponent", 100, 13); //AI opponent with 100 health and 13 attack power

        //starting the battle
        Battle battle(player, ai);
        battle.startBattle();
    }
    return 0;
}
