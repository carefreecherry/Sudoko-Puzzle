# Sudoku Console C++ Application
This project is a comprehensive Sudoku game implemented in C++ for console environments. It includes a variety of functions to enhance gameplay, allowing players to enjoy a smooth and interactive Sudoku experience.

# Features
Gameplay Functions

void playSudoku(): Start a new game of Sudoku.
void checkGame(): Validate the current game state for correctness.
void setNumberKey(string value): Set a number in the Sudoku grid based on user input.
void pauseGame(): Pause the game.
void helpSudoku(string located): Provide hints or help for the current game state.
void showProgressHardMode(double final_progress): Display progress for hard mode puzzles.
# Navigation Functions

void upkey(): Move the cursor up.
void downKey(): Move the cursor down.
void leftKey(): Move the cursor left.
void rightKey(): Move the cursor right.
Puzzle Management

void setPuzzle(int level): Initialize a new puzzle based on the selected difficulty level.
void makePuzzle(string target, string puzzle): Generate a new puzzle and set the target solution.
User Interface

void hideCursor(bool condition): Hide or show the cursor based on the game state.
void gotoMenu(char choice): Navigate to different menu options.
void colorSet(int tint): Change the color scheme of the game interface.
void gamePart(string part): Load and display different parts of the game.
# Utility Functions

void exitMenu(): Exit from the game menu.
void mainGame(): The main function to start and manage the game loop.
# How to Play
Start the Game: Use playSudoku() to begin a new game.
Navigate: Use arrow keys (up, down, left, right) to move the cursor.
Set Numbers: Enter numbers into the grid using the setNumberKey(value) function.
Check Progress: Validate your game at any point using checkGame().
Pause and Help: Pause the game or get hints using pauseGame() and helpSudoku(located) respectively.
Customize and Manage: Adjust game settings and interface colors with colorSet(tint) and gotoMenu(choice).
# Getting Started
To get started with the Sudoku Console C++ app, clone the repository and compile the source code using a C++ compiler.


git clone https://github.com/yourusername/sudoku-console-cpp.git
cd sudoku-console-cpp
g++ -o sudoku main.cpp
./sudoku
# Contributions
Feel free to fork this repository, make improvements, and submit pull requests. All contributions are welcome!
