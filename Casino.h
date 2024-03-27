#ifndef CASINO_H
#define CASINO_H

#include "CasinoGameInterface.cpp" // Include necessary header for CasinoInterface
#include "CasinoGameInterface.h" // Include necessary header for CasinoGameInterface

// Forward declaration of Player class to avoid circular dependency
class Player;

class Casino : public CasinoInterface {
private:
    CasinoGameInterface* currentGame;
    Player* player;

public:
    Casino();
    ~Casino();
    void switchGame(CasinoGameInterface* game);
    void playRound(bool prediction, int bet);
    void payout(int bet, double multiplier);
    void update(int bet, bool prediction);
    void registerPlayer(Player* newPlayer);
};

#endif // CASINO_H
