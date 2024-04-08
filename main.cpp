#include <iostream>
#include <string>
#include "battle.h"


void unitTests(){
    Player test("test_player", 100, 15);
    test.receiveDamage(105);
    if (test.getHealth() != 0){

    }else{
        std::cout << "Test 1 Complete!" << std::endl;
    }
    Player test2("test_player2", 100, 15);
    Player test3("test_player3", 100, 15);
    Battle battle(test2, test3);
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
