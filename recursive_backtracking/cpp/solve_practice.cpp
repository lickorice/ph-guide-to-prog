#include <iostream>
#include <cstring>
#include <string> // For input purposes

using namespace std;

void print_board(int board[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!board[i][j]) cout << "- ";
            else cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void copy_board(int copy_from[9][9], int copy_to[9][9]) {
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            copy_to[i][j] = copy_from[i][j];
}

// Solve the sudoku board recursively, then print it
bool solve(int board[9][9]) {
    return false;
}

int main() {
    int input_board[9][9];

    // Put the input to a 9x9 int array,
    // empty squares are marked with 0
    for (int i = 0; i < 9; ++i) {
        string row; cin >> row;
        for (int j = 0; j < 9; ++j) {
            if (row[j] == '-') {
                input_board[i][j] = 0;
            } else {
                input_board[i][j] = row[j] - '0';
            }
        }
    }
    cout << "Input board:\n";
    print_board(input_board);

    // Solve the board:
    cout << "Solution\n";
    bool is_solved = solve(input_board);
    if (is_solved) {
        cout << "Solution found!\n";
        print_board(input_board);
    } else {
        cout << "No solution found.\n";
    }

}