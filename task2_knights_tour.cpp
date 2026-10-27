#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;

// Possible row and column changes for the knight's eight moves
int rowMove[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int colMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// Check whether a square is inside the board and unvisited
bool isSafe(int board[MAX][MAX], int n, int row, int col)
{
    return row >= 0 && row < n &&
           col >= 0 && col < n &&
           board[row][col] == -1;
}

// Solve the Knight's Tour using backtracking
bool solveTour(int board[MAX][MAX], int n,
               int row, int col, int moveNumber)
{
    // All squares have been visited
    if (moveNumber == n * n)
        return true;

    // Try all eight possible knight moves
    for (int i = 0; i < 8; i++)
    {
        int nextRow = row + rowMove[i];
        int nextCol = col + colMove[i];

        if (isSafe(board, n, nextRow, nextCol))
        {
            board[nextRow][nextCol] = moveNumber;

            if (solveTour(board, n, nextRow, nextCol, moveNumber + 1))
                return true;

            // Undo the move if this path fails
            board[nextRow][nextCol] = -1;
        }
    }

    return false;
}

int main()
{
    int n, startRow, startCol;
    int board[MAX][MAX];

    cout << "Enter board size (1-" << MAX << "): ";
    cin >> n;

    if (n < 1 || n > MAX)
    {
        cout << "Invalid board size\n";
        return 0;
    }

    cout << "Enter starting row and column (0-based): ";
    cin >> startRow >> startCol;

    if (startRow < 0 || startRow >= n ||
        startCol < 0 || startCol >= n)
    {
        cout << "Invalid starting position\n";
        return 0;
    }

    // Initialize every square as unvisited
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            board[i][j] = -1;
    }

    // Number the starting square as move zero
    board[startRow][startCol] = 0;

    if (solveTour(board, n, startRow, startCol, 1))
    {
        cout << "\nKnight's Tour:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << setw(4) << board[i][j];

            cout << '\n';
        }
    }
    else
    {
        cout << "No Knight's Tour found for this board and starting position.\n";
    }

    return 0;
}