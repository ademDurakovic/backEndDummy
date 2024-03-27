#include <iostream>
#include "Mines.h"
#include "Casino.h"
int main() {
    Mines* mines = new Mines(2);
    Casino* casino = new Casino();

    //mines->executeRound(true);

    std::cout << "Hello, World!, "  <<std::endl;
    delete mines;
    delete casino;
    return 0;
}
