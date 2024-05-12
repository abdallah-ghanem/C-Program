#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>

int main()
{
    int guesses = 5, guess, answer;//number of railrs
    srand(time(0));
    answer = rand() % 20; // if range from 5 to 20 add 5 to equ. like rand()%20+5
    cout << "Welcom to Guessing Game. \n";
    cout << "A number between 0 and 20 in 5 guesses \n";
    for (int i = 0; i < guesses; i++)//for loop to make user guess 5 times only
    {
        cout << "Guess # " << i + 1 << ":";
        cin >> guess;
        if (guess != answer)//To help user get corret answer
        {
            if (i != 4)//I'm make it to print the answer when end the five guess
            {
                if (guess > answer)
                {
                    cout << "your guess is big than answer\n";
                }
                else
                {
                    cout << "your guess is small than answer\n";
                }
            }
            else
            {
                cout << "Oh No! The Answer is: " << answer;
            }
        }
        else
        {
            cout << "The Answer is correct Congratulations! : " << answer;
            break;
        }
    }
    return 0;
}