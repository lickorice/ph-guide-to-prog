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

// Checks if a move/entry is valid, given the position and number
bool is_valid(int board[9][9], int row, int col, int number) {
    // Check rows
    bool number_check_row[10]; 
    memset(number_check_row, true, sizeof(number_check_row)); // Make all true
    for (int i = 0; i < 9; ++i) {
        if (i == col) continue; // Skip the target cell
        if (board[row][i] && !number_check_row[board[row][i]]) return false; // Double number
        number_check_row[board[row][i]] = false;
    }
    if (!number_check_row[number]) return false; // Has same # in row

    // Check cols
    bool number_check_col[10]; 
    memset(number_check_col, true, sizeof(number_check_col)); // Make all true
    for (int i = 0; i < 9; ++i) {
        if (i == row) continue; // Skip the target cell
        if (board[i][col] &&!number_check_col[board[i][col]]) return false; // Double number
        number_check_col[board[i][col]] = false;
    }
    if (!number_check_col[number]) return false; // Has same # in row   

    // Check square
    int square_start_row = 0;
    if (row >= 3) square_start_row = 3;
    if (row >= 6) square_start_row = 6;
    int square_start_col = 0;
    if (col >= 3) square_start_col = 3;
    if (col >= 6) square_start_col = 6;

    bool number_check_square[10]; 
    memset(number_check_square, true, sizeof(number_check_square)); // Make all true
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int sq_row = square_start_row+i;
            int sq_col = square_start_col+j;
            if (sq_row == row && sq_col == col) continue; // Skip target cell
            if (board[sq_row][sq_col] && !number_check_square[board[sq_row][sq_col]]) 
                return false; // Double number
            number_check_square[board[sq_row][sq_col]] = false;
        }
    }
    if (!number_check_square[number]) return false;

    return true;
}

// Checks if the board is solved
bool is_solved(int board[9][9]) {
    // Check if there are no blanks
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!board[i][j]) return false; // Board has a blank!
        }
    }
    // Check if each number is valid
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!is_valid(board, i, j, board[i][j])) return false; // Board has a blank!
        }
    }

    return true;
}

// Solve the sudoku board recursively, then print it
bool solve(int board[9][9]) {
    // Base case 1: if board is solved, then return true
    if (is_solved(board)) {
        return true;
    }

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
    
    if (r < 0) return false;

    for (int n = 1; n <= 9; ++n) {
        if (is_valid(board, r, c, n)) {
            int new_board[9][9];
            copy_board(board, new_board);
            new_board[r][c] = n;
            bool result = solve(new_board);
            if (result) {
                copy_board(new_board, board);
                return true;
            }
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

    bool is_solved = solve(input_board);
    if (is_solved) {
        cout << "Solution found!\n";
        print_board(input_board);
    } else {
        cout << "No solution found.\n";
    }

}