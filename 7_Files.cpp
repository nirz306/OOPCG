#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void createFile()
{
    fstream f1;
    f1.open("example.txt", ios::out);              //ios::out means that file is opened in output mode allowing to write and edit in the file

    if (!f1)                                      //is a condition checking the state of the file stream object f1.
    {
        cout<<"Error while opening file "<<endl;
    }
    else
    {
        cout<<"\n File created \n ";
        f1<<"Name"<<"      "<<"City"<<endl;       // "<<" used for writing the contents in the file 
        f1.close();

    }
}

void writeFile()
{
    fstream f2;
    int length;
    f2.open("example.txt", ios::in | ios::out);

    if (!f2)
    {
        cout<<"Error "<<endl;
    }
    else
    {
        cout<<"\n----Writing data into the file----\n ";
        string name, city;

        cout<<"\nEnter Name : \n";
        cin>>name;

        cout<<"\nEnter City : \n";
        cin>>city;

        f2<<endl;

        f2<<name<<"      "<<city<<endl;

        length = name.length();

        cout<<"\n----Data written into the file----\n ";

        f2.close();

    }
}

void readFile()
{
    fstream f3;
    f3.open("example.txt", ios::in);

    if (!f3)
    {
        cout<<"Error  "<<endl;
    }
    else
    {
        cout<<"\n---Reading data from the file---\n ";
        char x;
        while(1)                 //infinite loop until break occurs and break will occur when eof is reached
        {
            x = f3.get();
            cout<<x;
            if (f3.eof())
            {
                break;
            }

        }
        f3.close();

    }
}


int main()
{
    char ch = 'y';
    while( ch!= 'n')
    {
    int choice;
    cout<<"\n 1] Create File "<<endl;
    cout<<"\n 2] Write to File "<<endl;
    cout<<"\n 3] Read File "<<endl;
    cout<<"\n Enter a choice : "<<endl;
    cin>>choice;

    
        if (choice == 1)
        {
            createFile();
            cout<<"\n Do you want to continue ? (y/n)"<<endl;
            cin>>ch;
        }

        else if (choice == 2)
        {
            writeFile();
            cout<<"\n Do you want to continue ? (y/n)"<<endl;
            cin>>ch;
        }

        else if (choice == 3)
        {
            readFile();
            cout<<"\n Do you want to continue ? (y/n)"<<endl;
            cin>>ch;
        }

	}
    cout<<"\n ---Exitting the system--- \n";
    return 0;
}file
