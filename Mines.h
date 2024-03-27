//
// Created by Adem Durakovic on 3/24/24.
//

#ifndef UNTITLED1_MINES_H
#define UNTITLED1_MINES_H
//
// Created by Adem Durakovic on 3/23/24.
//


class Mines{
private:
    int totalMines;
    int totalSquares;
    double multiplier;
    int grid[5][5];  // initializes all to 0
    int bombGrid[5][5];  // initializes all to 0

public:
    Mines(int mines);
    ~Mines();

    void generateMineLocations();
    double executeRound(bool prediction);
    bool checkForBomb(int x, int y);
    void flipSquare(int x, int y);
    void displayGrid();
    void displayBombGrid();
    void reset();
};

#endif //UNTITLED1_MINES_H
