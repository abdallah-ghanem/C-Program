#include <iostream>
using namespace std;
#include <fstream>

class temp
{
    // string id,name,auther;
    string searchId, searchName, searchAuther, id, name, auther;
    fstream file;

public:
    void addBook();
    void showAll();
    void extractBook();
} obj;

int main()
{
    char choice;
    cout << "----------------------------";
    cout << "\n1-Showw all Books\n";
    cout << "\n2-Extract Books\n";
    cout << "\n3-Add Books(ADMIN)\n";
    cout << "\n4-Exit\n";
    cout << "\n---------------------------\n";
    cout << "\nEnter your Choice\n";
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.showAll();
        break;
    case '2':
        cin.ignore();
        obj.extractBook();
    case '3':
        cin.ignore();
        obj.addBook();
    case '4':
        return 0;
    default:
        cout << "Invalid Choice";
        break;
    }
    return 0;
}

void temp ::addBook()
{
    cout << "\nEnter Book ID:";
    getline(cin, id);
    cout << "\nEnter Book Name:";
    getline(cin, name);
    cout << "\nEnter Book Auther:";
    getline(cin, auther);

    file.open("LibraryData.txt", ios ::out | ios ::app); // to open file and store data at file name login data.txt
    file << id << " " << name << " " << auther << endl;  // to store at next forme abdallah*abdo21@gmail.com*abdo2161
    file.close();
    
}

void temp ::showAll()
{
    file.open("LibraryData.txt", ios ::in);
    getline(file, id, ' ');
    getline(file, name, ' ');
    getline(file, auther, '\n');
    cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's Name"<<endl;
    while (!file.eof())
    {
        cout<<"\t\t " <<id <<" \t\t\t\t "<< name <<" \t\t\t\t " <<auther <<endl;
        getline(file, id, ' ');
    getline(file, name, ' ');
    getline(file, auther, '\n');
    }
    file.close();
}
void temp ::extractBook()
{

    showAll();
    cout << "\nEnter Book ID";
    getline(cin, searchId);

    file.open("LibraryData.txt", ios ::in);
    getline(file, id, ' ');
    getline(file, name, ' ');
    getline(file, auther, '\n');
    while (!file.eof())
    {
        if (searchId == id)
        {
            cout << "Extract Book Successfuly...";
            cout<<"This book for auther :"<<auther <<" and name book is "<<name<<endl;
        }else {
            cout<<"you are add wrong ID!!"<<endl;
            cout<<"please try again"<<endl;
        }
        getline(file, id, ' ');
        getline(file, name, ' ');
        getline(file, auther, '\n');
    }
    file.close();
}