// C++ program to solve N Queen Problem using backtracking

#include <iostream>    // To handle input-output operations
#include <vector>      // To use the vector container

using namespace std;

// A utility function to print the solution
void printSolution(const vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {  // Loop through each row
        for (int j = 0; j < N; j++) {  // Loop through each column in the row
            if (board[i][j])  // If a queen is placed at this position (1)
                cout << "Q ";  // Print 'Q' for the queen
            else
                cout << ". ";  // Print '.' for an empty space
        }
        cout << "\n";  // Move to the next line after printing a row
    }
}

// A utility function to check if a queen can be placed at board[row][col]
// It checks for conflicts in the row, upper diagonal, and lower diagonal
bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    int i, j;

    // Check this row on left side for any queens
    for (i = 0; i < col; i++)  // Only check the columns to the left of 'col'
        if (board[row][i])  // If there's a queen in the same row
            return false;  // Return false, meaning it's not safe

    // Check the upper diagonal on the left side for any queens
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)  // Traverse the upper diagonal
        if (board[i][j])  // If a queen is found in the upper diagonal
            return false;  // It's not safe to place the queen here

    // Check the lower diagonal on the left side for any queens
    for (i = row, j = col; j >= 0 && i < N; i++, j--)  // Traverse the lower diagonal
        if (board[i][j])  // If a queen is found in the lower diagonal
            return false;  // It's not safe to place the queen here

    return true;  // If no conflicts are found, it's safe to place the queen
}

// A recursive utility function to solve the N-Queen problem using backtracking
bool solveNQUtil(vector<vector<int>>& board, int col, int N) {
    // Base case: If all queens are placed (i.e., we reached beyond the last column)
    if (col >= N)
        return true;  // Solution found

    // Try placing a queen in each row of the current column
    for (int i = 0; i < N; i++) {  // Loop through all rows in the current column
        // Check if the queen can be safely placed at board[i][col]
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;  // Place the queen (mark with 1)

            // Recur to place the next queens
            if (solveNQUtil(board, col + 1, N))  // Move to the next column
                return true;  // If placing the queen leads to a solution, return true

            // If placing the queen does not lead to a solution, backtrack
            board[i][col] = 0;  // Remove the queen (mark back to 0)
        }
    }

    // If no queen can be placed in any row in the current column, return false
    return false;
}

// Function to solve the N-Queen problem using backtracking
bool solveNQ(int N) {
    // Create a 2D board initialized with all 0s (no queens placed)
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Try solving the N-Queen problem starting from the first column (column 0)
    if (solveNQUtil(board, 0, N) == false) {
        cout << "Solution does not exist\n";  // If no solution is found
        return false;  // Return false, indicating no solution exists
    }

    // Print the solution if found
    printSolution(board, N);
    return true;  // Return true, indicating a solution was found
}

// Main driver function
int main() {
    int N;

    // Ask the user to enter the number of queens (N)
    cout << "Enter the number of queens: ";
    cin >> N;

    // Special cases: For N = 2 or N = 3, no solution exists for the N-Queen problem
    if (N == 2 || N == 3) {
        cout << "No solution exists for N = " << N << endl;
    } else {
        // Solve the N-Queen problem and print the solution if exists
        solveNQ(N);
    }

    return 0;  // Return 0, indicating successful program termination
}


