#include <iostream>
#include<windows.h>
using namespace std;

int main() {
    int h,m,s;
    cout <<"Enter the Houres ";
    cin>>h;
    cout <<"Enter the Min ";
    cin>>m;
    cout <<"Enter the Second ";
    cin>>s;
    while (1)
    {
        system("cls");// to clear the screen (clear screen)
        if(s>59){
            m++;
            s=0;
        }
        if(m>59){
            h++;
            m=0;
        }
        if(h>23){
            h=0;
        }
        cout << h<<":" << m << ":" << s << ":" << endl;
        s++;//to increase sec each once
        Sleep(900);//to print the clock every 900msec
    }
    




    return 0;
}