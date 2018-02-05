
/*

Design a class TIME which stores hour, minute and second. The class should have the methods to
support the following:
 User may give the time value in 24-hour format.
 User may give the time value in AM/PM format
 Display the time in 24-hour format.
 Display the time in AM/PM format.
 User may like to add minute with a time value.


Soulib Ghosh
BCSE - 2
Roll - 47




*/

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class time1{

// declaring the private variables

	int hour, min, sec;
	int hour_mem, min_mem;
	
	string in;

public:

// taking the input

void input(){
	cout << "write the time\n" ;
	cin >> in ;
}


// displaying the input

void display(){
	cout << "your input is " << in << endl << endl << endl ;
}


// function for assigning the hour minite second value
void assign(){
 
	if( in[8] == '\0'){
		hour = 10* (in[0] - 48) + (in[1] - 48);
		min = 10* (in[3] - 48) + (in[4] - 48);
		sec = 10* (in[6] - 48 )  + (in[7] - 48);	
	}

// assigning value for AM format

	if(in[8] == 'a' || in[8] == 'A'){
		min = 10* (in[3] - 48) + (in[4] - 48);
		sec = 10* (in[6] - 48 )  + (in[7] - 48);
		hour = 10* (in[0] - 48) + (in[1] - 48);
	}

// assigning value for PM format

	if(in[8] == 'p' || in[8] == 'P'){
		min = 10* (int(in[3]) - 48) + (int(in[4]) - 48);
		sec = 10* (int(in[6]) - 48 )  + (int(in[7]) - 48);
		hour = 12 + 10* (int(in[0]) - 48) + (int(in[1]) - 48);
	}

	
}

// function to add minute

void add(int x){

	hour_mem = hour;
	min_mem = min;
	
	min = min + x;
	if(min > 59 ) {
		hour = hour + (min)/60;
		min = min%60;
	}
	if(hour > 23) hour = hour % 24;
	//cout << " hour has exceed 24 so you cannot display the time \n ";
	cout << "\nminute is added successfully\n";

}


// displaying the time in 24 hour

void display_24hour(){
	
	int x = check_global();
	if(x == 0) cout << "invalid input \n" ;	
	if(x == 1) {
		cout <<"output in 24 hour format \n\n " << " " << hour << " : " << " " << min << " : " << " " << sec << endl;

	
 
		}

	}

// displaying in 12 hour format

void display_12hour(){

	int x = check_global();
	if(x == 0) cout << "invalid input \n" ;	
	if(x == 1) {
		
	
		cout << "displaying in AM / PM format \n\n"; 
		if ( hour >= 12 ) cout << (hour - 12) <<" : " << min << " : " << sec << " PM \n\n" ;

		else  cout << hour   <<" : " << min << " : " << sec  << " AM \n\n" ;
 
		}

	}



// checking the input , it is correct or not

int check_global(){
	
	if(min > 60 || sec > 60) return 0;
	if((in[8] == 'a'||in[8] == 'p'||in[8] == 'A'||in[8]=='P')&&10* (in[0] - 48) + (in[1] - 48) > 11 ) return 0;
	if(hour > 23 ) return 0;
	
	else return 1;
}

// function to go in previous stage 

void prev(){
	hour = hour_mem;
	min = min_mem;
	cout << "you are in the previous condition\n";
}

};

// class time ends

int main(){

	class time1 t;
          int ad;
	t.input();
	t.display();
	t.assign();

	int ch;
	cout << "\n\n**************welcome to our time format***************";
	while(1){
	
	
		cout << "\n\n1. display in 24 hour\n";
	cout << "2. display in 12 hour\n";
	cout << "3. add minutes\n";
	cout << "4. Exit from the process\n";
	cout << "5. return to initial stage\n";
	cout << "6. Previous stage\n";
	
	
	
		cin >> ch;
		switch(ch){
			case 1: 
			t.display_24hour();
			break;
			
			case 2:
			t.display_12hour();
			break;

			case 3:
			cout << "minutes you want to add " ;
			cin >> ad;
			t.add(ad);
			break;

			case 4:
			cout << "***************Thank you**********\n\n";
			return 0;
			break;
			
			case 5:
			t.assign();
			cout << "you are in the initial stage\n";
			break;
			
			case 6:
			t.prev();
			break;

			default:
			cout << "wrong input";
			break;

		}

	}

				

	return 0;
}


