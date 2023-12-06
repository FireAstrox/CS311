/* hsscount.cpp
Rylan Clavell
10/10/2023
For CS 311 Fall 2023
Source File for Assignment 4 functions
*/

#include "hsscount.hpp"
#include <vector>

// Helper function to recursively calculate the number of valid paths
int hssCount_recurse(std::vector<std::vector<int>>& board, int finish_x, int finish_y, int dim_x, int dim_y, int curr_x, int curr_y, int squaresLeft) {
    // If we reached the finish position and used all available squares
    if (curr_x == finish_x && curr_y == finish_y && squaresLeft == 0) {
        return 1;
    }

    int count = 0;

    // Possible move directions
                        // N  NE E  SE S   SW  W  NW
    std::vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
    std::vector<int> dy = {1, 1, 0, -1, -1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
        int new_x = curr_x + dx[i];
        int new_y = curr_y + dy[i];

        // Check if the new position is within the board boundaries and not visited
        if (new_x >= 0 && new_x < dim_x && new_y >= 0 && new_y < dim_y && board[new_x][new_y] == 0) {
            board[new_x][new_y] = 1;    // Mark the square as visited
            squaresLeft -= 1;           // Decrement available squares
            count += hssCount_recurse(board, finish_x, finish_y, dim_x, dim_y, new_x, new_y, squaresLeft);
            board[new_x][new_y] = 0;    // Backtrack: Mark the square as unvisited
            squaresLeft += 1;           // Backtrack: Restore available squares
        }
    }

    return count;
}

// Main function to calculate the number of valid paths
int hssCount(int dim_x, int dim_y, int hole_x, int hole_y, int start_x, int start_y, int finish_x, int finish_y) {
    // If the start and finish positions are the same, no valid paths
    if (start_x == finish_x && start_y == finish_y) {
        return 0;
    }

    // Create the board and initialize it
    std::vector<std::vector<int>> board(dim_x, std::vector<int>(dim_y, 0));
    board[hole_x][hole_y] = 1;   // Mark the hole
    board[start_x][start_y] = 1; // Mark the start

    // Calculate the total number of squares minus the hole and start squares
    int squaresLeft = (dim_x * dim_y) - 2;

    // Start the recursive calculation
    return hssCount_recurse(board, finish_x, finish_y, dim_x, dim_y, start_x, start_y, squaresLeft);
}
