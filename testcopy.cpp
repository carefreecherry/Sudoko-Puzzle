#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 9; // Size of the Sudoku grid
const int Empty = 0;

// Function to print the Sudoku grid
extern "C" void printGrid(vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

// Function to check if it's safe to place num at (row, col)
bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
    // Check if num is present in the current row or column
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
  
    // Check if num is present in the current 3x3 grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Function to solve the Sudoku grid using backtracking
bool solveSudoku(vector<vector<int>>& grid) {
    int row, col;
  
    // Find the first empty cell
    bool isEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == Empty) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
            break;
    }
  
    // If no empty cell is found, the Sudoku is solved
    if (!isEmpty)
        return true;
  
    // Try placing numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = Empty; // Undo the assignment if it leads to a dead end
        }
    }
  
    return false;
}

// Function to generate a Sudoku puzzle
extern "C" void generateSudoku(vector<vector<int>>& puzzle, int numToRemove) {
    // Initialize a solved Sudoku grid
    vector<vector<int>> grid(N, vector<int>(N, 0));
    solveSudoku(grid);

    // Copy the solved grid to the puzzle
    puzzle = grid;

    // Remove a specified number of cells
    srand(time(0)); // Seed for randomness
    for (int i = 0; i < numToRemove; i++) {
        int row = rand() % N;
        int col = rand() % N;
        puzzle[row][col] = Empty;
    }
}

int main() {
    vector<vector<int>> puzzle(N, vector<int>(N, 0));
    // Generate a Sudoku puzzle with 30 empty cells
    generateSudoku(puzzle, 0);

    // Print the generated puzzle
    printGrid(puzzle);
    
    generateSudoku(puzzle, 30);
    
    // Print the generated puzzle
    printGrid(puzzle);

    return 0;
}