// This file may include some code that will confuse you
// (particularly the bitwise operators), but treat it as a 
// practice on getting used to being out of your comfort zone
// and learning new, dangerous things!

// Some notes:
// Integers are basically size 32 boolean arrays!
// Since an integer can be represented as 32 bits,
// we can utilize this and make integers small boolean arrays!

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

// [Optimization #3]
// We modify is_valid to get_valid_numbers, to instead return a
// bool array (bitwise operation) of valid numbers (true if valid, else false), so that
// we only check a square once, instead of 9 times in the previous
// implementation.
// Checks if a move/entry is valid, given the position and number
int get_valid_numbers(int board[9][9], int row, int col) {
    int valid_numbers = 1023; // 0b11 1111 1111 <- all true boolean array with 10 elements

    // Check rows
    for (int i = 0; i < 9; ++i) {
        valid_numbers &= ~(1UL << board[row][i]); // Clear a bit at position n
    }

    // Check cols
    for (int i = 0; i < 9; ++i) {
        valid_numbers &= ~(1UL << board[i][col]); // Clear a bit at position n
    }

    // Check square
    int sq_row = (row >= 3) ? ((row >= 6) ? 6 : 3) : 0;
    int sq_col = (col >= 3) ? ((col >= 6) ? 6 : 3) : 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            valid_numbers &= ~(1UL << board[sq_row+i][sq_col+j]); // Clear a bit at position n
        }
    }

    return valid_numbers;
}

// [Optimization #1]
// Checks if the board is already solved
int is_already_solved(int board[9][9]) {
    // Check if there are no blanks
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!board[i][j]) return 1; // Board has a blank!
        }
    }
    // Check if each row and column is valid
    for (int i = 0; i < 9; ++i) {
        int row_nums = 1023, col_nums = 1023;
        for (int j = 0; j < 9; ++j) {
            row_nums &= ~(1UL << board[i][j]);
            col_nums &= ~(1UL << board[j][i]);
        }
        if (row_nums >> 1 || col_nums >> 1) return 2; // Board is full and invalid!
    }
    // Check each square
    int sq_row[9] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
    int sq_col[9] = {0, 3, 6, 0, 3, 6, 0, 3, 6};
    for (int d = 0; d < 3; ++d) {
        int sq_nums = 1023;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                sq_nums &= ~(1UL << board[sq_row[d]+i][sq_col[d]+j]);
            }
        }
        if (sq_nums >> 1) return 2; // Board is full and invalid!
    }

    return 0; // Board is fully solved and correct!
}

// Solve the sudoku board recursively, then print it
bool solve(int board[9][9]) {
    // [Optimization #1]
    // We don't need to call is_solve always, if we're trying to solve a
    // board with blank spaces anyway.

    // Find a blank
    int r = -1, c = -1; // Blank coordinates
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!board[i][j]) { // if zero
                r = i; c = j; break;
            }
        }
        if (r >= 0) break;
    }
    
    // [Optimization #1]
    // Logically, if the board has no more blanks,
    // then it is solved. (Base case 1)
    if (r < 0) return true;

    // [Optimization #3]
    // Here we just get the bool array (bitwise operations) of the valid numbers
    int valid_numbers = get_valid_numbers(board, r, c);
    for (int n = 1; n <= 9; ++n) {
        // [Optimization #3]
        // If our number at n is valid:
        if ((valid_numbers >> n) & 1) {
            // [Optimization #2]
            // We don't need to copy a board, let's just modify
            // our current board:
            board[r][c] = n;
            bool result = solve(board);
            // Leave the board modified if a solution is found:
            if (result) return true;
            // If not, return it to a blank if our modification
            // did not lead to a solution:
            board[r][c] = 0; // Return to blank state
        }
    }

    // Base case 2: if unsolvable return false
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

    // If board is already solved:
    int res = is_already_solved(input_board);
    if (!res) {
        cout << "Board is already solved!\n";
        return 0;
    } else if (res == 2) {
        cout << "Board is unsolvable.\n";
        return 0;
    }

    // Else:
    bool is_solved = solve(input_board);
    if (is_solved) {
        cout << "Solution found!\n";
        print_board(input_board);
    } else {
        cout << "No solution found.\n";
    }

}