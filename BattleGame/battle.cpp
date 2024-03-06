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
        playerTurn(m_player2, m_player1);
    }

    std::cout << "Battle Over!" << std::endl;

    if (m_player1.isAlive()) {
        std::cout << m_player1.getName() << " wins!" << std::endl;
    } else {
        std::cout << m_player2.getName() << " wins!" << std::endl;
    }
}

//where player deals damage to other player
void Battle::playerTurn(Player &attacker, Player &defender) {
    std::cout << attacker.getName() << " attacks!" << std::endl;
    defender.receiveDamage(attacker.getAttackPower());
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
