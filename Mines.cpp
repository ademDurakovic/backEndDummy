//
// Created by Adem Durakovic on 3/24/24.
//
#include "Mines.h"
#include <iostream>
#include <cstdlib> // for rand()

Mines::Mines(int mines) : totalMines(mines) {
    // Calculate the multiplier based on the total number of mines
    multiplier = 1;
    totalSquares = 25 - totalMines;
    generateMineLocations();
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            grid[i][j] = 0;
            bombGrid[i][j] = 0;
        }
    }
}


Mines::~Mines() {}


void Mines::generateMineLocations() {
    int bombsPlaced = 0;
    while (bombsPlaced != totalMines) {
        int x = rand() % 5;
        int y = rand() % 5;
        if (bombGrid[x][y] != 1) {
            bombGrid[x][y] = 1;
            bombsPlaced += 1;
        }
    }
}

double Mines::executeRound(bool prediction) {
    bool playingFlag = true;
    std::cout << "Welcome to mines! 0 INDEXED." << std::endl << "To quit enter 100" << std::endl;

    std::cout << std::endl;
    reset();
    while (playingFlag) {
        displayGrid();
        int x;
        int y;
        std::cout << "Please select a row then column." << std::endl;
        std::cin >> x;
        if (x == 100) { return multiplier; }
        std::cin >> y;
        if (checkForBomb(x, y) == false) {
            flipSquare(x, y);
            totalSquares -= 1;
            if (totalSquares == 0) { return multiplier; }
            multiplier += 0.05;
        }
        else {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "BOMB HIT!" << std::endl;
            displayBombGrid();
            return 0;
        }

    }
    return 0;
}

bool Mines::checkForBomb(int x, int y) {
    if (bombGrid[x][y] == 1) {
        return true;
    }
    return false;
}

void Mines::flipSquare(int x, int y) {
    grid[x][y] = 1;
}

void Mines::displayGrid() {
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            std::cout << grid[i][k] << " ";
        }
        std::cout << std::endl; // Print newline after each row
    }
}

void Mines::displayBombGrid() {
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            std::cout << bombGrid[i][k] << " ";
        }
        std::cout << std::endl; // Print newline after each row
    }
}

void Mines::reset() {
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < 5; k++) {
            grid[i][k] = 0;
            bombGrid[i][k] = 0;
        }
    }
    multiplier = 1;
    generateMineLocations();
}

