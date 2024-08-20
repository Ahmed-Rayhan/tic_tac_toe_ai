#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 3;

// Function to initialize the Tic-Tac-Toe board
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the Tic-Tac-Toe board
void displayBoard(const char board[SIZE][SIZE]) {
    cout << "-------------\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "| ";
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check if a player has won
bool hasWon(const char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full
bool isBoardFull(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to get the human player's move
void getPlayerMove(char board[SIZE][SIZE], char player) {
    int row, col;
    while (true) {
        cout << "Player " << player << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        // Validate input
        if (cin.fail() || row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid move. Please try again.\n";
        } else {
            break;
        }
    }
    board[row][col] = player;
}

// Function to check if there's a winning move or a blocking move
bool findBestMove(char board[SIZE][SIZE], char player, int &bestRow, int &bestCol) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                if (hasWon(board, player)) {
                    bestRow = i;
                    bestCol = j;
                    board[i][j] = ' ';
                    return true;
                }
                board[i][j] = ' ';
            }
        }
    }
    return false;
}

// Function for the AI to make its move
void makeAIMove(char board[SIZE][SIZE], char aiPlayer, char humanPlayer) {
    int row, col;

    // 1. Check if AI can win in the next move
    if (findBestMove(board, aiPlayer, row, col)) {
        board[row][col] = aiPlayer;
        return;
    }

    // 2. Check if the AI needs to block the opponent
    if (findBestMove(board, humanPlayer, row, col)) {
        board[row][col] = aiPlayer;
        return;
    }

    // 3. Take the center if available
    if (board[1][1] == ' ') {
        board[1][1] = aiPlayer;
        return;
    }

    // 4. Take a corner if available
    int corners[4][2] = { {0, 0}, {0, 2}, {2, 0}, {2, 2} };
    for (int i = 0; i < 4; ++i) {
        if (board[corners[i][0]][corners[i][1]] == ' ') {
            board[corners[i][0]][corners[i][1]] = aiPlayer;
            return;
        }
    }

    // 5. Take any available spot
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                board[i][j] = aiPlayer;
                return;
            }
        }
    }
}

// Function to switch the player
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    char humanPlayer = 'X';  // Human plays 'X'
    char aiPlayer = 'O';      // AI plays 'O'
    char currentPlayer = humanPlayer;
    
    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "You are 'X'. AI is 'O'.\n";

    // Main game loop
    while (true) {
        displayBoard(board);

        if (currentPlayer == humanPlayer) {
            getPlayerMove(board, currentPlayer);
        } else {
            makeAIMove(board, aiPlayer, humanPlayer);
        }

        // Check for a win
        if (hasWon(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check for a draw
        if (isBoardFull(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Switch to the other player
        currentPlayer = switchPlayer(currentPlayer);
    }

    return 0;
}
