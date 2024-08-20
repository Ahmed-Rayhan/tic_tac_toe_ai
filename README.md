# Tic-Tac-Toe Game

This is a simple command-line Tic-Tac-Toe game implemented in C++. You can play against the computer (AI). The AI uses basic strategies to make its moves, making the game more challenging.

## Table of Contents
- [How to Play](#how-to-play)
- [Features](#features)
- [Game Rules](#game-rules)
- [AI Strategy](#ai-strategy)
- [How to Run](#how-to-run)
- [Code Explanation](#code-explanation)
- [Future Improvements](#future-improvements)
- [Contributing](#contributing)
- [License](#license)

## How to Play

1. **Player Symbols**: You (the human player) play as **'X'**, and the AI plays as **'O'**.
2. **Board Layout**: The game is played on a 3x3 grid. The board is displayed in the terminal with rows and columns indexed from 0 to 2.
3. **Making a Move**: On your turn, enter the row and column numbers where you want to place your 'X'. The AI will automatically make its move after yours.
4. **Winning the Game**: The first player to get three of their symbols in a row, column, or diagonal wins the game.
5. **Ending in a Draw**: If all nine squares are filled and neither player has won, the game ends in a draw.

## Features

- **Human vs AI**: Play against an AI opponent.
- **Interactive Console**: Simple and intuitive console interface.
- **Input Validation**: Prevents invalid moves and handles incorrect input.
- **AI Strategy**: The AI makes decisions based on a basic strategy to either win, block, or choose the best available move.

## Game Rules

- The game is played on a 3x3 grid.
- Players take turns placing their symbol ('X' or 'O') in an empty square.
- The first player to get three of their symbols in a row (horizontally, vertically, or diagonally) wins.
- If all squares are filled and no player has three in a row, the game ends in a draw.

## AI Strategy

The AI uses a simple strategy to determine its moves:
1. **Win if possible**: If the AI can win in its current move, it will do so.
2. **Block the opponent**: If the human player is about to win in the next move, the AI will block that move.
3. **Take the center**: If the center square is available, the AI will choose it.
4. **Take a corner**: If the center is taken, the AI will prioritize taking one of the corners.
5. **Choose any available spot**: If none of the above options are available, the AI will choose any remaining open spot.

## How to Run

1. **Clone the Repository**:
```bash
    git clone https://github.com/ahmed-rayhan/tic_tac_toe_ai.git
    cd tic_tac_toe_ai
    ```

2. **Compile the Program**:
    ```bash
    g++ -o tic_tac_toe tic_tac_toe.cpp
    ```

3. **Run the Game**:
    ```bash
    ./tic_tac_toe
    ```

4. **Play**:
   - Follow the on-screen instructions to play the game.
   - Enter the row and column numbers (0-2) when prompted to make your move.

## Code Explanation

The code is structured into several key functions that handle different aspects of the game. Here's an explanation of each part:

### 1. **Initializing the Board**
   ```cpp
   void initializeBoard(char board[3][3]);
 ```
This function initializes the 3x3 game board by filling it with spaces (' '), indicating that all positions are empty at the start of the game.

### 2. **Displaying the Board**
   ```cpp
void displayBoard(const char board[3][3]);
 ```
This function prints the current state of the board to the console, showing the layout of the game. It uses loops to go through each row and column, displaying the content within the grid.

### 3. **Checking for a Win**
   ```cpp
bool hasWon(const char board[3][3], char player);
 ```
This function checks if the specified player ('X' or 'O') has won the game. It does so by checking all rows, columns, and both diagonals to see if there are three matching symbols in a line.
### 4. **Checking if the Board is Full**
   ```cpp
bool isBoardFull(const char board[3][3]);
 ```
This function checks if the board is completely filled. If there are no empty spaces left and no player has won, the game ends in a draw.
### 5. **Getting the Player's Move**
   ```cpp
void getPlayerMove(char board[3][3], char player);
 ```
This function handles the human player's input. It prompts the player to enter the row and column where they want to place their symbol. It also validates the input to ensure the move is within bounds and the chosen spot is empty.
### 6. **Finding the Best Move for the AI**
   ```cpp
bool findBestMove(char board[3][3], char player, int &bestRow, int &bestCol);
 ```
This function checks the board to find the best possible move for the AI. It simulates moves and checks if they would result in a win for the AI or if they need to block the human player from winning.

### 7. **Making the AI's Move**
   ```cpp
void makeAIMove(char board[3][3], char aiPlayer, char humanPlayer);
 ```
This function is where the AI decides its move based on the strategies mentioned above. It checks for winning moves, blocks the human player if necessary, or chooses the best available spot based on the priorities.
### 8. **Switching the Player**
   ```cpp
char switchPlayer(char currentPlayer);

 ```
This function switches the current player from 'X' to 'O' or vice versa, alternating turns between the human player and the AI.

### 9. **Main Game Loop**
   ```cpp
int main();
 ```
The main function runs the game loop. It initializes the board, alternates turns between the human player and the AI, and checks after each move if someone has won or if the game has ended in a draw.



## License

This project is licensed under the MIT License.









