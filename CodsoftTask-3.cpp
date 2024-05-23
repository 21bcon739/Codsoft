#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<vector<char>>& board) {
    cout << "Current board state:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}

bool isMoveValid(const vector<vector<char>>& board, int row, int col) {
    return board[row][col] == ' ';
}

void makeMove(vector<vector<char>>& board, int row, int col, char player) {
    board[row][col] = player;
}

bool checkWin(const vector<vector<char>>& board, char player) {
  
    for (int i = 0; i < 3; ++i) {
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

bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char& player) {
    player = (player == 'X') ? 'O' : 'X';
}

void resetBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameOngoing = true;
    char playAgain;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    do {
        resetBoard(board);
        currentPlayer = 'X';
        gameOngoing = true;

        while (gameOngoing) {
            displayBoard(board);

            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            while (!isMoveValid(board, row, col)) {
                cout << "Invalid move. Try again." << endl;
                cout << "Player " << currentPlayer << ", enter your move (row and column): ";
                cin >> row >> col;
            }

            makeMove(board, row, col, currentPlayer);

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOngoing = false;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "The game is a draw!" << endl;
                gameOngoing = false;
            } else {
                switchPlayer(currentPlayer);
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing Tic-Tac-Toe!" << endl;

    return 0;
}
