#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string userName,Email,PassWord;
    string searchName,searchPass,searchEmail;
    fstream file;//to make file to store data in it
    public:
    void login();
    void signUp();
    void forgot();
}obj;

int main(){
    char choice;
    cout << "1- login\n";
    cout << "2- Sign-Up\n";
    cout << "3- Forget Password\n";
    cout << "4- Exit\n";
    cout << "Enter Your Choice\n";
    cin >>choice;

    switch (choice)
    {
    case '1':
        cin.ignore();//we add this code line to make it cin many thimes
        obj.login();
        break;
    case '2':
        cin.ignore();
        obj.signUp();
        break;
    case '3':
        obj.forgot();
        break;
    case '4':
        return 0;
        break;
    default:
    cout<<"Invalid selection...!";
        break;
    }

    return 0;
}

void temp :: signUp(){
    cout<<"Enter Your User Name :: "<<endl;
    getline(cin,userName);
    cout<<"Enter Your Email Adress :: "<<endl;
    getline(cin,Email);
    cout<<"Enter Your Password :: "<<endl;
    getline(cin,PassWord);
    file.open("loginData.txt",ios :: out | ios :: app);//to open file and store data at file name login data.txt
    file<<userName<<"*"<<Email<<"*"<<PassWord<<endl;//to store at next forme abdallah*abdo21@gmail.com*abdo2161
    file.close();
}

void temp :: login(){
    //string searchName,searchPass;
    cout<<"---------LOGIN--------"<<endl;
    cout<<"Enter Your User Name ::"<<endl;
    getline(cin,searchName);
    cout<<"Enter Your Password :: "<<endl;
    getline(cin,searchPass);
    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');//to get info from file(login data.txt) and ignore *
    getline(file,Email,'*');
    getline(file,PassWord,'\n');
    while (!file.eof())//while the file end to search about all data in file
    {
        if (userName == searchName)
        {
            if (PassWord == searchPass)
            {
                cout<<"\nAccount Login Successful"<<endl;
                cout<<"\nUsername :: "<<userName<<endl;
                cout<<"\nEmail :: "<<Email<<endl;
            }else{
                cout<<"Password is In coreect\n";
            }
        }
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,PassWord,'\n');
    }
    //file<<searchName<<"*"<<searchPass<<endl;
    file.close();
}

void temp :: forgot(){
    cout<<"\nEnter Your UserName :: "<<endl;
    getline(cin,searchName);
    cout<<"\nEnter Your Email Adress :: "<<endl;
    getline(cin,searchEmail);
    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,PassWord,'\n');
    while (!file.eof())
    {
        if (userName == searchName)
        {
            if (Email == searchEmail)
            {
                cout<<"\nAccount Found "<<endl;
                cout<<"\nYour Password ::"<<PassWord<<endl;
                cout<<"\nEmail ::"<<Email<<endl;
            }else{
                cout<<"Account Not Found\n"<<endl;
            }
        }else{
            cout<<"Account Not Found\n";
        } 
    }
    file.close();
}