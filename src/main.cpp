/*
* @file main.cpp : Main entry point for the program
* @author Anushka Thakur
* @date 04-07-2025
* @brief A Sudoku Puzzle Solver with unique PRNG abilities (Pseudo Random 
* Number Generation). 
*/
#include "backTrack.h"
#include "printBoard.h"
#include "stdafx.h"

/* 
" The Mersenne Twister is a general-purpose pseudorandom number 
generator (PRNG) developed in 1997 by Makoto Matsumoto (松本 眞) 
and Takuji Nishimura (西村 拓士).
Its name derives from the choice of a Mersenne prime 
as its period length." - Wikipedia
We use the PRNG mt19937 along with std::shuffle to generate 9 by 9 sets 
of random integers.
*/


int main()
{
    /* Creates a RNG Board */
    Board board{};
    if (fillBoard(board)) {
        removeCells(board, 40);  // You can vary this number (20-60)
        std::cout << "Sudoku Puzzle:\n";
        printBoard(board);
    } else {
        std::cout << "Failed to generate Sudoku board.\n";
    }

    std::cout << "Following is the Solution of the above " << std::endl;
    backTrack(board);
    printBoard(board);

    getchar();

    return 0;
}





