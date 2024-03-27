#include "CoinGame.h"
#include <iostream>

bool CoinGame::tossCoin() {
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    double random_number = distribution(rng);

    if (random_number > 0.5) {
        std::cout << "COIN FLIPPED: HEADS" << " TRUE " << std::endl;
    } else {
        std::cout << "COIN FLIPPED: TAILS" << " FALSE " << std::endl;
    }
    return random_number > 0.5;
}

bool CoinGame::checkWinner(bool prediction, bool outcome) {
    if (prediction == outcome) {
        std::cout << "You Win!" << std::endl;
        return true;
    } else {
        std::cout << "You Lose!" << std::endl;
        return false;
    }
}

double CoinGame::executeRound(bool prediction) {
    bool predict = getPrediction();
    bool outcome = tossCoin();
    if (checkWinner(predict, outcome)) {
        return 2.0;
    }
    return 0.0;
}

bool CoinGame::getPrediction() {
    char prediction;
    std::cout << "Select Heads or Tails: (ENTER 'H' OR 'T')" << std::endl;
    std::cin >> prediction;
    return (prediction == 'H');
}
