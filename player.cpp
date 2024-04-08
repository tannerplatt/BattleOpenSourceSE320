#include "player.h"
#include <string>
#include <iostream>

Player::Player(){
}

Player::Player(std::string name, int health, int attackPower){
    m_name = name;
    m_health = health;
    m_attackPower = attackPower;
}

Player::~Player(){
}

std::string Player::getName(){
    return m_name;
}

int Player::getHealth(){
    return m_health;
}

int Player::getAttackPower(){
    return m_attackPower;
}

void Player::heal(int amount){
    m_health += amount;
    if (m_health > 100){
        m_health = 100;
    }
}

//player recieves damage and if their health goes below 0 it is set to 0
void Player::receiveDamage(int amount){
    m_health -= amount;
    if (m_health < 0){
        m_health = 0;
    }
}

//checks if player is alive
bool Player::isAlive(){
    if (m_health > 0){
        return true;
    }
    return false;
}
