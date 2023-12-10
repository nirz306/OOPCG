#include<iostream>
#include<string.h>
using namespace std;
class Publication {
    private:
        string title;
        float price;
    public:
         void get_data()
        {
            cout<<"Enter the title:"<<endl;
            cin.get();
            getline(cin,title);
            cout<<"Enter the price:"<<endl;
            cin>>price;
        }
        void show_data()
        {
            cout<<"Title: "<<title<<endl;
            cout<<"Price: "<<price<<endl;
        }

};
class book:public Publication{
    private:
        int page_count;
    public:
         void getdata()
         {
            cout<<"Enter the pages of book:"<<endl;
            cin>>page_count;
            cout<<"--------------------------------------------------------------------------"<<endl;
         }
         void showdata()
         {
            cout<<"Pages:"<<page_count<<endl;
            cout<<"--------------------------------------------------------------------------"<<endl;
         }
};
class tape:public Publication{
    private:
        float playing_time;
     public:
         void getdata()
         {
            cout<<"Enter playing time of tape:"<<endl;
            cin>>playing_time;
            cout<<"--------------------------------------------------------------------------"<<endl;
         }
         void showdata()
         {
            cout<<"Playing time:"<<playing_time<<endl;
            cout<<"--------------------------------------------------------------------------"<<endl;
         }
};
int main()
{
    book b1[100];
    tape t1[100];
    string answer;
    int n,num;
    while(answer!="N" || answer!="n")
    {
         cout<<"Enter the operation you wanna perform:\n1)Enter Book Data \n2)Enter Tape Data \n3)Display book data \n4)Display tape data"<<endl;
        cin>>n;
    switch(n){
        case 1:
        {
           
            cout<<"How many books? ";
            cin>>num;
            for(int i = 0; i < num; i++)
            {
                b1[i].get_data();
                b1[i].getdata();
            }
           
            break;
        }
        case 2:
        {  
            cout<<"How many tapes? ";
            cin>>num;
            for(int i = 0; i < num; i++)
            {
                t1[i].get_data();
                t1[i].getdata();
            }
           
            break;
        }
        case 3:
        {   for(int i = 0; i < num; i++)
            {
                b1[i].show_data();
                b1[i].showdata();
            }
           
            break;
        }
        case 4:
        {  
            for(int i = 0; i < num; i++)
            {
                t1[i].show_data();
                t1[i].showdata();
            }
            break;
        }
        }
    cout<<"Wanna continue: N-To exit  Press any other key-continue?"<<endl;
    cin>>answer;
    }
   
} 
