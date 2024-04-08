#include "battle.h"
#include <iostream>
#include <random>

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
    while(1){
        int choice;
        std::cout << "What would you like to do: \n1 Attack \n2 Power Attack \n3 Heal\n";
        std::cin >> choice;
        if (choice == 1){
            std::cout << player.getName() << " attacks!" << std::endl;
            ai.receiveDamage(player.getAttackPower());
            player.decrementCooldown();
            break;
        }else if (choice == 2){
            // add Power Attack
        }else if (choice == 3){
            if (player.canHeal()){
                heal(player);
                std::cout << player.getName() << " heals!" << std::endl;
                break;
            }else{
                std::cout << player.getName() << " can heal in " << player.getCooldown() << " turns." << std::endl;
            } 
        }
    }
    displayStatus();
}

//where ai deals damage to the player
void Battle::aiTurn(Player &ai, Player &player) {
    std::random_device rd;
    std::mt19937 gen(rd());
    int min = 1, max = 2;
    std::uniform_int_distribution<> distr(min, max); 
    int choice;
    if (ai.canHeal()){
        choice = distr(gen);
    }else{
        choice = 1;
    }
    if(choice == 1){
        std::cout << ai.getName() << " attacks!" << std::endl;
        player.receiveDamage(ai.getAttackPower());
        ai.decrementCooldown();
    }else{
        heal(ai);
        std::cout << ai.getName() << " heals!" << std::endl;
    }
    displayStatus();
}

void Battle::heal(Player &player){
    std::random_device rd;
    std::mt19937 gen(rd());
    int min = 2, max = 20;
    std::uniform_int_distribution<> distr(min, max); 
    player.heal(distr(gen));
}

void Battle::testTurn(Player &test1, Player &test2){
    test2.receiveDamage(test1.getAttackPower());
}

void Battle::testHeal(Player &player){
    std::random_device rd;
    std::mt19937 gen(rd());
    int min = 2, max = 20;
    std::uniform_int_distribution<> distr(min, max); 
    player.heal(distr(gen));
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
