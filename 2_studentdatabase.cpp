#include <iostream>
#include <string.h>     //constructor(default,parametrized),static member func,friend class,this pointer ,inline code,dynamic memory operation,exception handling 
#include <iomanip>
using namespace std;

class Student
{
	public:
    	string name ,cls, bldgrp, add, drvlic,dob;
	int rno;
	long tele,tempS;

    
    	static int count; // Static member variable
    	static void incrementCount()
		 {
        	count++;
        	cout<<"Student "<<count<<" data succesfully added."<<endl;
    	}
    
        Student() //Default Constructor
        {
            name=""; cls="";bldgrp="";add="";drvlic="";dob="";
            rno=0; tele=0;
        }

        Student(string name, string cls, string bldgrp, string add, string drvlic, string dob, int rno, int tele, int aadhaar) //paremeterised constructor
        {
        	this->name = name;
        	this->cls = cls;
        	this->bldgrp = bldgrp;
        	this->add = add;
        	this->drvlic = drvlic;
        	this->dob = dob;
        	this->rno = rno;
        	this->tele = rno;
        	
        }

	    Student( Student &s1) //Copy Constructor created
	    {
	        name = s1.name;
	        cls = s1.cls;
	        bldgrp = s1.bldgrp;
	        add = s1.add;
	        drvlic = s1.drvlic;
	        dob = s1.dob;
	        rno = s1.rno;
	        tele = s1.tele;
	    }

	
	    void input()
	    {
	        	cout<<"Enter Name of Student: ";
			cin>>name;
			cout<<"\nEnter Class: ";
			cin>>cls;
			cout<<"\nEnter Blood Group: ";
			cin>>bldgrp;
			cout<<"\nEnter Address: ";
			cin>>add;
			cout<<"\nEnter Driving licence no: ";
			cin>>drvlic;
			cout<<"\nEnter Date of birth: ";
			cin>>dob;
			cout<<"\nEnter roll no: ";
			cin>>rno;
					//contact number with exception handling
		while(true)
	{
		cout << "Enter your contact number = ";
		try
		{
			cin >> tempS;
			string numString = to_string(tempS);
    		int length = numString.length();
			if (length!=10){
				throw "Phone number must be 10 digit!";
			}
		 	tele = tempS;
			break;
		}
		catch (const char *msg){
			cout << msg << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}
			cout<<"\n\n\n\n";
			 incrementCount();                 //calling the static member function
	    }

	
		inline void display()			//inline function
		{
			cout<<left<<setw(30)<<name<<setw(30)<<cls<<setw(30)<<bldgrp<<setw(30)<<add<<setw(30)<<drvlic<<setw(30)<<dob<<setw(30)<<rno<<setw(30)<<tele<<endl;
		}

		~ Student() //Destructor
		{
			cout<<"Destructor Invoked"<<endl;
		}

    friend class Hello;
};

class Hello  //use of friend class
{
    public:
        void display_name(Student &s)
        {	
		cout<<"Hello"<<s.name<<endl;
       	}
};

int Student::count=0;  //by syntax
int main()
{
	Student s1,s2,s3,s4;
	Hello h1,h2,h3,h4,h5;
	s1.input();
	s2.input();
 	s3.input();
 	s4.input();
 	Student s5(s4);                        //copy conctructor    called
	
	cout<<left<<setw(30)<<"NAME"<<setw(30)<<"CLASS"<<setw(30)<<"BLOOD GROUP"<<setw(30)<<"ADDRESS"<<setw(30)<<"DRIVING LIC NO"<<setw(30)<<"DATE OF BIRTH"<<setw(30)<<"ROLL NO"<<setw(30)<<"TELEPHONE"<<"\n============================================================================================="<<endl;
	
	s1.display();
	s2.display();
	s3.display();
	s4.display();
	cout<<"copying the details of the 4th student "<<endl;
	s5.display();
	cout<<"--------------------------------------------------------------------"<<endl;
	
	h1.display_name(s1);
	h2.display_name(s2);
	h3.display_name(s3);
	h4.display_name(s4);
	h5.display_name(s5);
	
	Hello *h = new Hello[3];
	delete [] h;
}
