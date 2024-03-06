#include "battle.h"
#include <iostream>

Battle::Battle(){
}

Battle::Battle(Player player1, Player player2){
    m_player1 = player1;
    m_player2 = player2;
}

Battle::~Battle(){
}

void Battle::startBattle() {
    //battle takes place within while loop
    while (!isBattleOver()) {
        playerTurn(m_player1, m_player2);
        if (isBattleOver()) break;
        aiTurn(m_player2, m_player1);
    }

    std::cout << "Battle Over!" << std::endl;

    if (m_player1.isAlive()) {
        std::cout << m_player1.getName() << " wins!" << std::endl;
    } else {
        std::cout << m_player2.getName() << " wins!" << std::endl;
    }
}

//where player deals damage to ai
void Battle::playerTurn(Player &player, Player &ai) {
    int choice;
    std::cout << "What would you like to do: \n1 Attack \n2 Power Attack \n3 Heal";
    std::cin >> choice;
    if (choice == 1){
        std::cout << player.getName() << " attacks!" << std::endl;
        ai.receiveDamage(player.getAttackPower());
    }else if (choice == 2){
        // add Power Attack
    }else if (choice == 3){
        // add heal
    }
    displayStatus();
}

//where ai deals damage to the player
void Battle::aiTurn(Player &ai, Player &player) {
    std::cout << ai.getName() << " attacks!" << std::endl;
    player.receiveDamage(ai.getAttackPower());
    displayStatus();
}

//displays both players current HP
void Battle::displayStatus(){
    std::cout << m_player1.getName() << ": " << m_player1.getHealth() << " HP" << std::endl;
    std::cout << m_player2.getName() << ": " << m_player2.getHealth() << " HP" << std::endl;
}

//checks if a player has died
bool Battle::isBattleOver(){
    return !m_player1.isAlive() || !m_player2.isAlive();
}
