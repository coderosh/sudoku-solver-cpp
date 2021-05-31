#include <iostream>

using namespace std;

void print(int[9][9]);
bool solveBoard(int[9][9]);
bool isValid(int[9][9], int, int, int);
bool getEmptyPosition(int[9][9], int &, int &);

const string vLine = "┃";
const string thinVline = "│";

const string borders[6] = {
    "┏━━━┯━━━┯━━━┳━━━┯━━━┯━━━┳━━━┯━━━┯━━━┓",
    "┣━━━┿━━━┿━━━╋━━━┿━━━┿━━━╋━━━┿━━━┿━━━┫",
    "┠───┼───┼───╂───┼───┼───╂───┼───┼───┨",
    "┗━━━┷━━━┷━━━┻━━━┷━━━┷━━━┻━━━┷━━━┷━━━┛",
};

int board[9][9] = {
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
    cout << "\nOriginal Board: \n";
    print(board);

    cout << "\nSolved Board \n";

    if (solveBoard(board))
        print(board);
    else
        cout << "Couln't solve the board\n";

    return 0;
}

// solves the board
bool solveBoard(int board[][9])
{
    int row, col;

    if (!getEmptyPosition(board, row, col))
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

// gets first row and column in board where the value is 0
bool getEmptyPosition(int board[][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (board[row][col] == 0)
                return true;

    return false;
}

// checks if the board remains valid if board[row][col] is replaced by num
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
    int r = row - row % 3;
    int c = col - col % 3;
    for (int i = r; i < r + 3; i++)
        for (int j = c; j < c + 3; j++)
            if (board[i][j] == num)
                return false;

    return true;
}

// prints the board
void print(int board[][9])
{
    for (int i = 0; i < 9; i++)
    {
        if (i == 0)
            cout << borders[0] << endl;
        else if (i == 3 || i == 6)
            cout << borders[1] << endl;
        else
            cout << borders[2] << endl;

        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0)
                cout << vLine << " ";

            if (board[i][j] != 0)
                cout << board[i][j];
            else
                cout << " ";

            if ((j + 1) % 3 != 0)
                cout << " " << thinVline;

            if (j == 8)
                cout << " " << vLine
                     << " " << endl;
            else
                cout << " ";
        }

        if (i == 8)
            cout << borders[3] << endl;
    }
}

/*
const string vLine = "║";
const string thinVline = "│";

const string borders[6] = {
    "╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗",
    "╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣",
    "╟───┼───┼───╫───┼───┼───╫───┼───┼───╢",
    "╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝",
};

const string vLine = "|";
const string thinVline = "|";

const string borders[6] = {
    "+---+---+---+---+---+---+---+---+---+",
    "|---+---+---+---+---+---+---+---+---|",
    "| -   -   - | -   -   - | -   -   - |",
    "+---+---+---+---+---+---+---+---+---+",
};

const string vLine = "┃";
const string thinVline = "│";

const string borders[6] = {
    "┏━━━┯━━━┯━━━┳━━━┯━━━┯━━━┳━━━┯━━━┯━━━┓",
    "┣━━━┿━━━┿━━━╋━━━┿━━━┿━━━╋━━━┿━━━┿━━━┫",
    "┠───┼───┼───╂───┼───┼───╂───┼───┼───┨",
    "┗━━━┷━━━┷━━━┻━━━┷━━━┷━━━┻━━━┷━━━┷━━━┛",
};


const string vLine = "┇";
const string thinVline = "╎";

const string borders[6] = {
    "┏╍╍╍┯╍╍╍┯╍╍╍┳╍╍╍┯╍╍╍┯╍╍╍┳╍╍╍┯╍╍╍┯╍╍╍┓",
    "┇╍╍╍┿╍╍╍┿╍╍╍┇╍╍╍┿╍╍╍┿╍╍╍┇╍╍╍┿╍╍╍┿╍╍╍┇",
    "┇╌╌╌┼╌╌╌┼╌╌╌┇╌╌╌┼╌╌╌┼╌╌╌┇╌╌╌┼╌╌╌┼╌╌╌┇",
    "┗╍╍╍┷╍╍╍┷╍╍╍┻╍╍╍┷╍╍╍┷╍╍╍┻╍╍╍┷╍╍╍┷╍╍╍┛",
};


const string vLine = "┃";
const string thinVline = "|";

const string borders[6] = {
    "┏━━━━━━━━━━━┳━━━━━━━━━━━┳━━━━━━━━━━━┓",
    "┣━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┫",
    "┃-----------┃-----------┃-----------┃",
    "┗━━━━━━━━━━━┻━━━━━━━━━━━┻━━━━━━━━━━━┛",
};
*/