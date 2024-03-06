#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player();
    Player(std::string name, int health, int attackPower);
    ~Player();
    std::string getName();
    int getHealth();
    int getAttackPower();
    void receiveDamage(int amount);
    bool isAlive();

private:
    std::string m_name;
    int m_health;
    int m_attackPower;
};

#endif 
