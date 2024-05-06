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

// creates a random chance of missing
bool randomChance(float probability) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(probability);
    return d(gen);
}

void Battle::playerTurn(Player &player, Player &ai) {
    if (randomChance(0.8)) {  // 80% chance to hit
        int damage = player.getAttackPower();
        ai.receiveDamage(damage);
        std::cout << player.getName() << " hits " << ai.getName() << " for " << damage << " damage!" << std::endl;
    } else {
        std::cout << player.getName() << " misses the attack!" << std::endl;
    }
    displayStatus();
}

void Battle::aiTurn(Player &ai, Player &player) {
    if (randomChance(0.8)) {  // 80% chance to hit
        int damage = ai.getAttackPower();
        player.receiveDamage(damage);
        std::cout << ai.getName() << " hits " << player.getName() << " for " << damage << " damage!" << std::endl;
    } else {
        std::cout << ai.getName() << " misses the attack!" << std::endl;
    }
    displayStatus();
}


void Battle::testHeal(Player &player) {
    std::random_device rd;
    std::mt19937 gen(rd());
    int min = 2, max = 20;
    std::uniform_int_distribution<> distr(min, max); 
    player.heal(distr(gen));
}

void Battle::testTurn(Player &test1, Player &test2) {
    // Example implementation, adjust according to actual test needs
    std::cout << "Testing turn between " << test1.getName() << " and " << test2.getName() << std::endl;
    test1.receiveDamage(test2.getAttackPower());
    test2.receiveDamage(test1.getAttackPower());
    std::cout << test1.getName() << " Health: " << test1.getHealth() << std::endl;
    std::cout << test2.getName() << " Health: " << test2.getHealth() << std::endl;
}

void Battle::displayStatus() {
    std::cout << m_player1.getName() << ": " << GREEN << m_player1.getHealth() << RESET << " HP" << std::endl;
    std::cout << m_player2.getName() << ": " << GREEN << m_player2.getHealth() << RESET << " HP" << std::endl;
    std::cout << WHITE << "-----------" << RESET << std::endl;
}

bool Battle::isBattleOver() {
    return !m_player1.isAlive() || !m_player2.isAlive();
}

void Battle::startBattle() {
    while (!isBattleOver()) {
        playerTurn(m_player1, m_player2);
        if (isBattleOver()) {
            std::cout << m_player2.getName() << " has been defeated!" << std::endl;
            break;
        }
        aiTurn(m_player2, m_player1);
        if (isBattleOver()) {
            std::cout << m_player1.getName() << " has been defeated!" << std::endl;
            break;
        }
    }
}