#ifndef BATTLE_H
#define BATTLE_H

#include "player.h"

class Battle {
public:
    Battle();
    Battle(Player player1, Player player2);
    ~Battle();

    void startBattle();

private:
    Player m_player1;
    Player m_player2;

    void playerTurn(Player &player, Player &ai);
    void aiTurn(Player &ai, Player &player);
    void displayStatus();
    bool isBattleOver();
};

#endif
