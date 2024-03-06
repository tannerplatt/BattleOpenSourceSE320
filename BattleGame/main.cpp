#include <iostream>
#include "battle.h"

int main() {
    std::string playerName;
    std::cout << "Enter your character's name: ";
    std::getline(std::cin, playerName);

    //creating the player and a basic AI opponent
    Player player(playerName, 100, 15); //player with 100 health and 15 attack power
    Player ai("AI_Opponent", 100, 13); //AI opponent with 100 health and 13 attack power

    //starting the battle
    Battle battle(player, ai);
    battle.startBattle();

    return 0;
}
