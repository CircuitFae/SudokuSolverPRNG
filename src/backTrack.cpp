
#include "backTrack.h"

bool backTrack(Board &grid)
{   
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            // skip non-empty cell
            if (grid[row][col] != 0) {
                continue;
            }
            for (int num = 1; num <= 9; ++num) {
                if (isValid(grid, row, col, num)) {
                    grid[row][col] = num;
                    if (backTrack(grid)) {
                        return true;
                    }
                    grid[row][col] = 0;
                }
            }
            // no number between 1-9 fits the cell
            return false;
        }
    }
    return true;
}