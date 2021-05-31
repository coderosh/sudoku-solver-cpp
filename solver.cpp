#include <iostream>

void print(int[9][9]);
bool solveBoard(int board[9][9]);
bool findZeroPosition(int board[9][9], int &, int &);
bool isValid(int[9][9], int, int, int);

int board[][9] = {
    {0, 5, 0, 0, 0, 7, 0, 0, 8},
    {0, 0, 2, 0, 0, 0, 6, 7, 0},
    {7, 4, 1, 3, 0, 6, 2, 0, 0},
    {2, 7, 0, 0, 5, 1, 0, 0, 6},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {5, 0, 0, 7, 9, 0, 0, 8, 1},
    {0, 0, 8, 4, 0, 9, 3, 5, 2},
    {0, 3, 5, 0, 0, 0, 7, 0, 0},
    {4, 0, 0, 5, 0, 0, 0, 1, 0},
};

int main()
{
    std::cout << "\nOriginal Board: \n";
    print(board);

    std::cout << "\nSolved Board \n";

    if (solveBoard(board))
        print(board);
    else
        std::cout << "Couln't solve the board\n";

    return 0;
}

bool solveBoard(int board[][9])
{
    int row, col;

    if (findZeroPosition(board, row, col))
        return true;

    for (int i = 1; i <= 9; i++)
    {
        if (isValid(board, row, col, i))
        {
            board[row][col] = i;

            if (solveBoard(board))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

bool findZeroPosition(int board[][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (board[row][col] == 0)
                return false;

    return true;
}

bool isValid(int board[][9], int row, int col, int num)
{
    // Check if row already has the number
    for (int i = 0; i < 9; i++)
        if (board[i][col] == num)
            return false;

    // Check if column already has the number
    for (int i = 0; i < 9; i++)
        if (board[row][i] == num)
            return false;

    // Check if the 3 x 3 box already has the number
    int rowStart = row - row % 3;
    int colStart = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + rowStart][j + colStart] == num)
                return false;

    return true;
}

void print(int board[][9])
{
    const std::string line = "───────";

    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
            if (i != 0)
                std::cout << "├" << line
                          << "┼" << line
                          << "┼" << line
                          << "┤\n";
            else
                std::cout << "┌" << line
                          << "┬" << line
                          << "┬" << line
                          << "┐\n";

        for (int j = 0; j < 9; j++)
        {
            std::cout << (j % 3 == 0 ? "│ " : "");

            if (board[i][j] == 0)
                std::cout << " ";
            else
                std::cout << board[i][j];

            std::cout << (j == 8 ? " │ \n" : " ");
        }

        if (i == 8)
            std::cout << "└" << line
                      << "┴" << line
                      << "┴" << line
                      << "┘\n";
    }
}