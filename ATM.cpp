#include <iostream>
using namespace std;

void ShowMenu()
{
    cout << "1. See the Balance : \n";
    cout << "2. Deposit : \n";
    cout << "3. Withdrawal : \n";
    cout << "4. Exit : \n";
}

int main()
{
    int ch, balance = 2000, add, mins;
    int four=4;
    while ( ch!=4 )
    {
        ShowMenu();
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "The Balance is : " <<balance << endl;
            break;
        case 2:
            cout << "Deposit : " << endl;
            cin >> add;
            balance+=add;
            cout << "The New Balance is : " <<balance << endl;
            break;
        case 3:
            cout << "Whithdraw : " << endl;
            cin >> mins;
            if (mins > balance)
            {
                cout << "refuse the operation" << endl;
            }
            else
            {
                balance-=mins;
                cout << "The New Balance is : " <<balance << endl;
            }
            break;
        default:
            break;
        }
    }
    cout << "I'm a dragon";

    return 0;
}
