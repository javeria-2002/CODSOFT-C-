#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    void playGame() {
        bool gameWon = false;
        bool gameDraw = false;
        int moves = 0;

        while (!gameWon && !gameDraw) {
            displayBoard();
            playerMove();
            moves++;
            gameWon = checkWin();
            gameDraw = checkDraw(moves);
            if (!gameWon && !gameDraw) {
                switchPlayer();
            }
        }

        displayBoard();

        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (gameDraw) {
            cout << "The game is a draw!" << endl;
        }
    }

private:
    vector<vector<char>> board;
    char currentPlayer;

    void displayBoard() {
        cout << "Current board:" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "--+---+--" << endl;
        }
    }

    void playerMove() {
        int row, col;
        bool validMove = false;

        while (!validMove) {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
                board[row - 1][col - 1] = currentPlayer;
                validMove = true;
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool checkWin() {
        // Check rows
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true;
            }
        }

        // Check columns
        for (int i = 0; i < 3; ++i) {
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true;
        }

        return false;
    }

    bool checkDraw(int moves) {
        return moves == 9;
    }
};

int main() {
    char playAgain;
    do {
        TicTacToe game;
        game.playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
