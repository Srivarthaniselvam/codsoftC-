# task 3

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl << "---------" << endl;
    }
}

bool checkWinner(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        if (row[0] == row[1] && row[1] == row[2] && row[0] != ' ') {
            return true;
        }
    }

    for (int col = 0; col < 3; ++col) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != ' ') {
            return true;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }

    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

pair<int, int> getHumanMove(char currentPlayer) {
    int move;
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move in game (1-9): ";
        cin >> move;

        if (move >= 1 && move <= 9) {
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            return {row, col};
        } else {
            cout << "Invalid move. Please enter a number between 1 and 9." << endl;
        }
    }
}

pair<int, int> getComputerMove() {
    return {rand() % 3, rand() % 3};
}

void playTicTacToe() {
    while (true) {
        vector<vector<char>> board(3, vector<char>(3, ' '));

        cout << "Welcome to Tic Tac Toe!" << endl;
        cout << "---------------------START THE GAME--------------------------" << endl;

        vector<char> playerTypes = {'X', 'O'};
        random_shuffle(playerTypes.begin(), playerTypes.end());

        for (int i = 0; i < 9; ++i) {
            printBoard(board);

            char currentPlayer = playerTypes[i % 2];

            pair<int, int> move;
            if (currentPlayer == 'X') {
                move = getHumanMove(currentPlayer);
            } else {
                move = getComputerMove();
            }

            if (board[move.first][move.second] == ' ') {
                board[move.first][move.second] = currentPlayer;

                if (checkWinner(board)) {
                    printBoard(board);
                    if (currentPlayer == 'X') {
                        cout << "Player X wins! Congratulations, you win!" << endl;
                    } else {
                        cout << "Player O wins!" << endl;
                    }
                    break;
                } else if (isBoardFull(board)) {
                    printBoard(board);
                    cout << "It's a tie!" << endl;
                    break;
                }
            } else {
                cout << "Cell already occupied. Try again." << endl;
                --i; 
            }
        }

        char playAgain;
        cout << "Do you want to play again? (yes/no): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    }

    cout << "Thanks for playing Tic Tac Toe!" << endl;
}

int main() {
    srand(time(nullptr)); 
    playTicTacToe();
    return 0;
}
