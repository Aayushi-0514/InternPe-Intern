#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];

// Function to initialize the board with numbers
void initializeBoard() {
    char num = '1';
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = num++;
        }
    }
}

// Function to print the board
void printBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--|---|--" << endl;
    }
}

// Function to make a move
bool makeMove(char player, int move) {
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
        return true;
    }
    return false;
}

// Function to check if a player has won
bool checkWin(char player) {
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full
bool isBoardFull() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    initializeBoard();
    char currentPlayer = 'X';
    bool gameWon = false;
    
    while (!isBoardFull() && !gameWon) {
        printBoard();
        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || !makeMove(currentPlayer, move)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        gameWon = checkWin(currentPlayer);
        if (gameWon) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
    
    if (!gameWon) {
        printBoard();
        cout << "The game is a draw!" << endl;
    }

    return 0;
}

