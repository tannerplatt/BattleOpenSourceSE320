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
    int getCooldown();
    void decrementCooldown();
    void receiveDamage(int amount);
    void heal(int amount);
    bool isAlive();
    bool canHeal();

private:
    std::string m_name;
    bool m_heal;
    int m_cooldown;
    int m_health;
    int m_attackPower;
};

#endif 
