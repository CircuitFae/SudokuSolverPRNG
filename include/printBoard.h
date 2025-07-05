#ifndef PRINTGRID_H
#define PRINTGRID_H

#include "stdafx.h"


void printBoard(const Board &grid);
bool isSafe(const Board& board, int row, int col, int num);
bool fillBoard(Board& board);
void removeCells(Board& board, int blanks = 40);

#endif