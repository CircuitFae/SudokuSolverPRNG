#include "printBoard.h"
#include "stdafx.h"


void printBoard(const Board &grid)
{
    for (int i = 0; i < SIZE; i++) {
        if (i == 3 || i == 6) {
            std::cout << "\n";
            std::cout << "---------------------";
            std::cout << "\n";
        } else {
            std::cout << "\n";
        }
        for (int j = 0; j < SIZE; j++) {
            if (j == 3 || j == 6) {
                std::cout << "| ";
            }
            std::cout << grid[i][j];
            std::cout << " ";
        }
    }
    std::cout << '\n';
}

bool isSafe(const Board& board, int row, int col, int num) {
    for (int x = 0; x < SIZE; ++x) {
        if (board[row][x] == num || board[x][col] == num ||
            board[(row / 3) * 3 + x / 3][(col / 3) * 3 + x % 3] == num)
            return false;
    }
    return true;
}


bool fillBoard(Board& board) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (board[row][col] == 0) {
                std::array<int, SIZE> numbers = {1,2,3,4,5,6,7,8,9};
                std::shuffle(numbers.begin(), numbers.end(), std::mt19937{std::random_device{}()});

                for (int num : numbers) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (fillBoard(board)) return true;
                        board[row][col] = 0; // backtrack
                    }
                }
                return false; // backtrack
            }
        }
    }
    return true;
}

void removeCells(Board& board, int blanks) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, SIZE - 1);

    int removed = 0;
    while (removed < blanks) {
        int row = dist(gen);
        int col = dist(gen);
        if (board[row][col] != 0) {
            board[row][col] = 0;
            ++removed;
        }
    }   
}

