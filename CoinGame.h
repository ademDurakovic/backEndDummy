//
// Created by Adem Durakovic on 3/23/24.
//

#ifndef BACK_END_COINGAME_H
#define BACK_END_COINGAME_H


#include "CasinoGameInterface.h"
#include <random>
#include <chrono>

class CoinGame : public CasinoGameInterface {
private:
    bool tossCoin();
    bool checkWinner(bool prediction, bool outcome);
    bool getPrediction();

public:
    double executeRound(bool prediction);
};


#endif //BACK_END_COINGAME_H
