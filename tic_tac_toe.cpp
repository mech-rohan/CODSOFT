#include <iostream>

using namespace std;

const int BOARD_SIZE = 3;
char board[BOARD_SIZE][BOARD_SIZE];
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j];
            if (j < BOARD_SIZE - 1) cout << " | ";
        }
        cout << "\n";
        if (i < BOARD_SIZE - 1) cout << "--|---|--\n";
    }
    cout << "\n";
}

bool isMoveValid(int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ');
}

void makeMove(int row, int col) {
    if (isMoveValid(row, col)) {
        board[row][col] = currentPlayer;
    }
}

bool checkWin() {
    // to check rows and columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // to check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    char playAgain;

    do {
        initializeBoard();
        currentPlayer = 'X';
        bool gameEnded = false;

        while (!gameEnded) {
            displayBoard();
            int row, col;
            cout << "Player " << currentPlayer << ", enter your row and column number : ";
            cin >> row >> col;

            if (isMoveValid(row - 1, col - 1)) {
                makeMove(row - 1, col - 1);

                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    gameEnded = true;
                } else if (checkDraw()) {
                    displayBoard();
                    cout << "The game is a draw!\n";
                    gameEnded = true;
                } else {
                    switchPlayer();
                }
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
