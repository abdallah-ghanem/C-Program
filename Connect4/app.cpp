#include <iostream>
using namespace std;

int board[6][7];
int input, player = 1;
int row_index = 5;//to make boarder 6 input in each colume
bool game_end = false;
void handelInput(int input)
{
    if (input>7){
        cout<<"Erorr in input please enter number from 1 to 7 only \n";
        row_index = 5;                // to make index 5 again because the input may be add more than 5 wrong input
        player = player == 1 ? 2 : 1; // to no change toplayer to to give new chance for player one
    }else{
    if (row_index >= 0)
    {

        if (board[row_index][input] != 0)
        {
            row_index--;
            handelInput(input);
        }
        else
        {
            board[row_index][input] = player;
            row_index = 5;
        }
    }
    else
    {
        cout << "Wrong Input! \n";
        row_index = 5;                // to make index 5 again because the input may be add more than 5 wrong input
        player = player == 1 ? 2 : 1; // to no change toplayer to to give new chance for player one
    }
}
}

void checkWinner()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] == player && board[i][j - 1] == player && board[i][j - 2] == player && board[i][j - 3] == player) // check columes
            {
                game_end = true;
                cout << "\nplayer " << player << " win!";
            }
            else if (board[i][j] == player && board[i - 1][j] == player && board[i - 2][j] == player && board[i - 3][j] == player) // check rows
            {
                game_end = true;
                cout << "\nplayer " << player << " win!";
            }
            else if (board[i][j] == player && board[i - 1][j - 1] == player && board[i - 2][j - 2] == player && board[i - 3][j - 3] == player) // check diagonal and the number of colume behaind
            {
                game_end = true;
                cout << "\nplayer " << player << " win!";
            }
            else if (board[i][j] == player && board[i - 1][j + 1] == player && board[i - 2][j + 2] == player && board[i - 3][j + 3] == player) // check anather diagonal
            {
                game_end = true; // to end game
                cout << "\nplayer " << player << " win!";
            }
        }
    }
}

void draw()
{
    // to make this code clean and organize i print number of columes
    for (int j = 0; j < 7; j++)
    {
        cout << "--" << j + 1 << "--";
    }
    cout << endl;
    // the main code is print columes and rows
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << "| " << board[i][j] << " |"; // print line after and before array
            /*else*//* if (board[i][j]==1){
                            cout<<"| X |";
                        }else if (board[i][j]==2){
                            cout<<"| O |";
                        } */
        }
        cout << endl;
    }
    // to make code clean and organize
    for (int j = 0; j < 7; j++)
    {
        cout << "=====";
    }
    cout << endl;
}

int main()
{
    draw();
    while (!game_end)
    {
        cout << "Player" << player << ": ";
        cin >> input;
        handelInput(input - 1); // to make code begain from one no zero
        draw();
        checkWinner();
        player = player == 1 ? 2 : 1;//condetion to switch if player ==1 switch to 2 else if player ==1
    }
    return 0;
}