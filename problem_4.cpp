
/*
Design a STUDENT class to store roll, name, course, admission date and marks in 5 subjects. Provide
methods corresponding to admission date and receiving marks, preparing mark sheet. Support must
be there to show the number of students who have taken admission.


Soulib Ghosh
BCSE 2
roll - 47






*/
#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<string.h>
#include <ctime>

using namespace std;


class Student
{
     
    char name[50];
   
    int subject1, subject2, subject3, subject4, subject5;
   
    char course[50];
    char * date;
    
    public:

        int roll;


	// function to calculate CGPA
        char cgpa(int marks)      
        {
            if(marks>=90)
                return 'S';
            if(marks>=80)
                return 'A';
            if(marks>=70)
                return 'B';
            if(marks>=60)
                return 'C';
            if(marks>=50)
                return 'D';
            if(marks>=40)
                return 'E';
            return 'X';
        }
        
        
        		
        	
             
        void input()      
        {
           
            cout<<"please write the name of the student: ";
	cin>>name;
	
	
               
             time_t now = time(0);
   
   
    date = ctime(&now);
   
   }
   
   void get_marks(){
   
            cout<<"Marks in the subjects:- \n";
            cout<<"\tSubject 1 : ";
            cin>>subject1;
            cout<<"\tSubject 2 : ";
            cin>>subject2;
            cout<<"\tSubject 3 : ";
            cin>>subject3;
            cout<<"\tSubject 4 : ";
            cin>>subject4;
            cout<<"\tSubject 5 : ";
            cin>>subject5;
        }     

        void marks_sheet()        
        {
        
            int temp = subject1 + subject2 + subject3 + subject4 + subject5 ;
      	  
            cout<<"\n\nName of the student: "<<name<<"\n";
            cout<<"Roll of the student: "<<roll<<"\n";
            
           
           
           cout << "The date and time of admission is : " << date << endl;
            cout<<"Subject 1 : "<<subject1<<"\t\tcgpa : "<<cgpa(subject1)<< "\n";
            cout<<"Subject 2 : "<<subject2<<"\t\tcgpa : "<<cgpa(subject2)<<"\n";
            cout<<"Subject 3 : "<<subject3<<"\t\tcgpa : "<<cgpa(subject3)<<"\n";
            cout<<"Subject 4 : "<<subject4<<"\t\tcgpa : "<<cgpa(subject4)<<"\n";
            cout<<"Subject 5 : "<<subject5<<"\t\tcgpa : "<<cgpa(subject5)<<"\n";
            
            
             cout << "total marks is : " << subject1 + subject2 + subject3 + subject4 + subject5  << endl;
             cout << "percentage of the student is: " << temp*0.2 << endl;  

        }
};      


int main()
{
	Student *list[100];
	int choice;
	int flag=0;
	int i;
	int tag=0;
	int newRoll;

	cout << "\n******WELCOME TO THE STUDENT ADMISSION PORTAL************";
    
	while(1)       
	{
	
	   
    cout<<"\n\n1.Add new Student\n";
    cout<<"2.Get Marksheet of student\n";
    cout<<"3.Number of student\n";
    cout << "4.Exit from the system\n";
    cout << "5.Get marks of the student\n\n";
       
		cin>>choice;
		switch(choice)
			{
              

	      case 1:    
		list[tag]=new Student;
                  
                    list[tag]->roll = tag + 1;
                    cout << "student roll is: " << tag + 1 << endl;
		flag=0;
		for(i=0;i<tag;i++)
			{
			if((list[i]->roll==list[tag]->roll))
			{
				flag=1;
				break;
			}
		}
			if(!flag)
			{
			    list[i]->input();
				    tag++;
				   
			}
			else
			cout<<"Student Already Present\n";
			   break;

		case 2:     
		cout<<"please write the Student roll: ";
                      cin>>newRoll;
                       flag=0;
                        for(i=0;i<tag;i++)
                        {
                            if((list[i]->roll==newRoll))
                            {
                                flag=1;
                                break;
                            }
                        }
                        if(flag)
                            list[i]->marks_sheet();
                        else
                            cout<<"This roll number does not exist\n";
		break;

		case 3:    
                    cout<<"\nNumber of student taken admission is:"<<tag<<endl;
                    break;
                    
                    case 4:
                    cout << "*************Thank you********************\n";
                    return 0;
                    
                    case 5:     
		cout<<"please write the Student roll: ";
                      cin>>newRoll;
                       flag=0;
                        for(i=0;i<tag;i++)
                        {
                            if((list[i]->roll==newRoll))
                            {
                                flag=1;
                                break;
                            }
                        }
                        if(flag)
                            list[i]-> get_marks();
                        else
                            cout<<"This roll number does not exist\n";
		break;
                    
                    

                default:
                        cout<<"Invalid Input\n";

			}      
		}     

	return 0;
}       
