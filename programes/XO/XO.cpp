#include <iostream>
using namespace std;

char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';

void draw()
{
    system("cls");//to clear screen
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            cout << matrix[r][c] << " "; // print spae after each colume
        }
        cout << endl; // to print new line (1,0) ,(1,1), (1,2) and so on
    }
}

void replace()
{
    char pos;//can't you make it integer must be the same type of matrix
    cout << "Enter you position("   << player <<    ")\n";
    cin >> pos;
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (matrix[r][c] == pos)
            {
                matrix[r][c] = player;
            }
        }
        if (player == 'X')
        {
            player = 'O'; // if user play as x revrse turn to player play as O
        }
        else
        {
            player = 'X'; // if player play as O reverse it and make player play as X
        }
    }
}

char checkWinner()
{
    int x = 0, o = 0, counter = 0; // make counter to count the number of x and o in each colume
    for (int r = 0; r < 3; r++)    // part of count the colume
    {
        for (int c = 0; c < 3; c++)
        {
            if (matrix[r][c] == 'X')
            {
                x++;
            }
            else if (matrix[r][c] == 'O')
            {
                o++;
            }
            if (x == 3)
            {
                return 'X';
            }
            if (o == 3)
            {
                return 'O';
            }
            x = 0, o = 0; // return the value of x and o to zero to check each colme only
        }
    }

    for (int c = 0; c < 3; c++) // part to count the row
    {
        for (int r = 0; r < 3; r++)
        {
            if (matrix[r][c] == 'X')
            {
                x++;
            }
            else if (matrix[r][c] == 'O')
            {
                o++;
            }
            if (x == 3)//when number of x reach to 3 return to main function X to player who play with X win
            {
                return 'X';
            }
            if (o == 3)
            {
                return 'O';
            }
            x = 0, o = 0; // return the value of x and o to zero to check each colme only
        }
    }
    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') // the diagonla of matrixs
    {
        return 'X';
    }
    if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
    {
        return 'O';
    }
    if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X') // the revesr of diagonal
    {
        return 'X';
    }
    if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O')
    {
        return 'O';
    }

    for (int r = 0; r < 3; r++) // in the draw
    {
        for (int c = 0; c < 3; c++)
        {
            if (matrix[r][c] != 'X' && matrix[r][c] != 'O') // to check if exist empty position at game
            {
                counter++;
            }
        }
    }
        if (counter == 0)
        {
            return '=';
        }
    
    return '*'; // in main function that make the game is play on because not return x or o
    
}

int main()
{
    while (checkWinner() == '*')
    {
        draw();
        replace();
        checkWinner();
    }
    draw();
    if (checkWinner() == 'X')
    {
        cout << "the Winner is player X\n";
    }
    if (checkWinner() == 'O')
    {
        cout << "the Winner is player O\n";
    }
    if (checkWinner() == '=')
    {
        cout << "No One is win\n";
    }
    return 0;
}