#include "battle.h"
#include <iostream>
#include <random>

// Define some ANSI escape codes for text color. This will allows us to have colored output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PINK    "\033[38;2;255;192;203m"
#define WHITE   "\033[37m"
#define PURPLE      "\033[38;2;148;0;211m"
#define ORANGE      "\033[38;2;255;165;0m"

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
        std::cout << m_player1.getName() << YELLOW << " wins!" << RESET << std::endl;
    } else {
        std::cout << m_player2.getName() << YELLOW <<  " wins!" << RESET << std::endl;
    }
}

//where player deals damage to ai
void Battle::playerTurn(Player &player, Player &ai) {
    while(1){
        int choice;
        std::cout << "What would you like to do? " << std::endl;
        std::cout << PURPLE << "1 Attack" << RESET << std::endl;
        std::cout << ORANGE << "2 Power Attack " << RESET << RED << "(In Development)" << RESET << std::endl;
        std::cout << BLUE << "3 Heal" << RESET << std::endl;
        std::cin >> choice;
        if (choice == 1){
            std::cout << std::endl;
            ai.receiveDamage(player.getAttackPower());
            player.decrementCooldown();
            std::cout << player.getName() << " attacks and deals " << RED << player.getAttackPower() << RESET << " damage!" << std::endl;
            std::cout << WHITE << "-----------" << RESET << std::endl; // Adding some lines to distinguish the output so it's cleaner - Jaden J.
            break;
        }else if (choice == 2){
            // add Power Attack
        }else if (choice == 3){
            if (player.canHeal()){
                heal(player);
                std::cout << player.getName() << PINK << " heals!" << RESET << std::endl;
                std::cout << WHITE << "-----------" << RESET << std::endl; // Adding some lines to distinguish the output so it's cleaner - Jaden J.
                break;
            }else{
                std::cout << player.getName() << " can heal in " << player.getCooldown() << " turns." << std::endl;
                std::cout << WHITE << "-----------" << RESET << std::endl; // Adding some lines to distinguish the output so it's cleaner - Jaden J.
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
        player.receiveDamage(ai.getAttackPower()); // moving these lines before the actual cout so that we can tell how much damage is done. May potentially need to be changed if we adjust how damage is calculated
        ai.decrementCooldown();
        std::cout << ai.getName() << " attacks and deals " << RED << ai.getAttackPower() << RESET << " damage!" << std::endl;
        std::cout << WHITE << "-----------" << RESET << std::endl; // Adding some lines to distinguish the output so it's cleaner - Jaden J.
    }else{
        heal(ai);
        std::cout << ai.getName() << PINK << " heals!" << RESET << std::endl;
        std::cout << WHITE << "-----------" << RESET << std::endl; // Adding some lines to distinguish the output so it's cleaner - Jaden J.
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
    std::cout << m_player1.getName() << ": " << GREEN << m_player1.getHealth() << RESET << " HP" << std::endl;
    std::cout << m_player2.getName() << ": " << GREEN << m_player2.getHealth() << RESET << " HP" << std::endl;
    std::cout << WHITE << "-----------" << RESET << std::endl; // Adding some lines to distinguish the output so it's cleaner - Jaden J.
}

//checks if a player has died
bool Battle::isBattleOver(){
    return !m_player1.isAlive() || !m_player2.isAlive();
}
