#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 10;

// Possible row and column changes for the knight's eight moves
int rowMove[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int colMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// Structure to store candidate moves and their onward degree
struct Move {
    int row;
    int col;
    int degree;
};

// Check whether a square is inside the board and unvisited
bool isSafe(int board[MAX][MAX], int n, int row, int col) {
    return row >= 0 && row < n &&
           col >= 0 && col < n &&
           board[row][col] == -1;
}

// Count remaining valid unvisited moves from (row, col)
int getDegree(int board[MAX][MAX], int n, int row, int col) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nextRow = row + rowMove[i];
        int nextCol = col + colMove[i];
        if (isSafe(board, n, nextRow, nextCol)) {
            count++;
        }
    }
    return count;
}

// Solve Knight's Tour using Warnsdorff's Heuristic for O(N^2) complexity
bool solveTour(int board[MAX][MAX], int n, int row, int col, int moveNumber) {
    if (moveNumber == n * n)
        return true;

    Move neighbors[8];
    int count = 0;

    // Evaluate all 8 moves and calculate their degrees
    for (int i = 0; i < 8; i++) {
        int nextRow = row + rowMove[i];
        int nextCol = col + colMove[i];
        if (isSafe(board, n, nextRow, nextCol)) {
            neighbors[count].row = nextRow;
            neighbors[count].col = nextCol;
            neighbors[count].degree = getDegree(board, n, nextRow, nextCol);
            count++;
        }
    }

    // Sort valid moves by degree ascending using insertion sort (Warnsdorff's Rule)
    for (int i = 1; i < count; i++) {
        Move key = neighbors[i];
        int j = i - 1;
        while (j >= 0 && neighbors[j].degree > key.degree) {
            neighbors[j + 1] = neighbors[j];
            j--;
        }
        neighbors[j + 1] = key;
    }

    // Try moves with the lowest onward degree first
    for (int i = 0; i < count; i++) {
        int nextRow = neighbors[i].row;
        int nextCol = neighbors[i].col;

        board[nextRow][nextCol] = moveNumber;
        if (solveTour(board, n, nextRow, nextCol, moveNumber + 1))
            return true;
        
        // Undo move if this path fails (backtrack)
        board[nextRow][nextCol] = -1;
    }

    return false;
}

int main() {
    int n, startRow, startCol;
    int board[MAX][MAX];

    cout << "Enter board size (1-" << MAX << "): ";
    cin >> n;
    if (n < 1 || n > MAX) {
        cout << "Invalid board size\n";
        return 0;
    }

    cout << "Enter starting row and column (0-based): ";
    cin >> startRow >> startCol;
    if (startRow < 0 || startRow >= n || startCol < 0 || startCol >= n) {
        cout << "Invalid starting position\n";
        return 0;
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = -1;

    board[startRow][startCol] = 0;

    if (solveTour(board, n, startRow, startCol, 1)) {
        cout << "\nKnight's Tour:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << setw(4) << board[i][j];
            cout << '\n';
        }
    } else {
        cout << "No Knight's Tour found for this board and starting position.\n";
    }
    return 0;
}