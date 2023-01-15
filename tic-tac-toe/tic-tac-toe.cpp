// tic-tac-toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;

char board[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
char player = 'X';

void drawBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void playerMove() {
    int move;
    cout << "Player " << player << ", enter your move: ";
    cin >> move;

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    board[row][col] = player;
}

char checkForWin() {
    // check for horizontal win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }

    // check for vertical win
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // check for diagonal win
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }

    return ' ';
}

int main() {
    drawBoard();
    while (true) {
        playerMove();
        drawBoard();
        if (checkForWin() != ' ') {
            cout << "Player " << checkForWin() << " wins!" << endl;
            break;
        }
        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
