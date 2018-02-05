/*

Design a TOLLTAX class to store the number of cars that crossed the bridge and total
amount collected. It must support the following activities.
 Receiving toll.
 Display number of cars that crossed the bridge.
Display the amount of toll collected

Soulib Ghosh
BCSE - 2
roll - 47



*/





#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<cmath>

using namespace std;

class toll_tax{
	
	int tw,fw,sw;
	int twf,fwf,swf;
	int car; // number of cars
	int amount; // amount collected
	int prev;
	int flag;
	
public:
	
	
	// initializong the value using constructor
	
	toll_tax(){
		
		car = tw = fw = sw = 0;
		twf = 20;
		fwf = 40;
		swf = 60;
		amount = 0;
		prev = 0;
		flag = 0;
	}
	
	
	// reciving a toll
	
	void recieve(){
		

		
		cout << "Which type of car: " << endl;
		int x;
		cout << "\t1 for two wheller\n\t2 for four wheller\n\t3 for six wheller\n";
		cin >> x;
		if(x==1) {
			tw = tw + 1;
			car = car + 1;
			amount = amount + twf;
			cout << "\nWe have recieved your toll please visit again\n";
		}
		
		else if(x==2) {
			fw = fw + 1;
			car = car + 1;
			amount = amount + fwf;
			cout << "\nWe have recieved your toll please visit again\n";
		}
		
		else if(x==3) {
			sw = sw + 1;
			car = car + 1;
			amount = amount + swf;
			cout << "\nWe have recieved your toll please visit again\n";
		}
		
		else cout << "wrong input \n";
		
		
		
		
		
	}
	
	// displaying number of cars
	
	void display_car(){
		
		cout << "the number of car is : " << car << endl;
	}
	
	// displaying the amount
	
	void display_amount(){
		
		cout << "the amount collected till now is : " << amount << endl;
	}
	
	
	// ending the process
	
	
	int end_process(){
	
		cout << "Do you want to end the process ?\n";
		cout << "Press 'y' to end the process or press anything to cancel\n";
		char c;
		cin >> c;
		if(c == 'y'){
			cout << "   ****  YOU HAVE FINISHED THE PROCESS  **** \n"; 
			cout << "\ttwo wheller : " << tw;
			cout << "\n\tfour wheller : " << fw;
			cout << "\n\tsix wheller : " << sw;   
			cout << "\n               Total number of car for the day is : " << car << endl;
			
		
			cout << "               Total amount collected is : " << amount << endl;
			cout << "         **********THANK YOU***********	\n";
			return 1;
		}
		
		if(c != 'y') return 2;
	}
	
	// undo the last operation only
	
	
	
	
void update_tax(){


	int x;
	cout << "Which type of vehicle\n";
	cout << "\t1 for two wheller\n\t2 for four wheller\n\t3 for six wheller\n";
	cin >> x;
	if(x == 1) {
		cout << "Enter the new amount : ";
		cin >> twf;
	}
	
	
	else if(x == 2) {
		cout << "Enter the new amount : ";
		cin >> fwf;
	}
	
	else if(x == 3) {
		cout << "Enter the new amount : ";
		cin >> swf;
	}
	
	else cout<< "Wrong Input\n";

	
}
	
	
	
	
	
			
}; // end of the class


// main function begins

int main(){
	
	class toll_tax t;
	int ch;
	
	cout << "\n\n************Welcome to toll tax*****************";

	
	while(1){
	
		cout << "\n\n1. Recieve toll\n";
	cout << "2. Show the number of car till now\n";
	cout << "3. Show the amount collected till now\n";
	cout << "4. update the toll\n";
	cout << "5. End process for the day\n\n";
	
	
		cin >> ch;
		switch(ch){
			case 1: 
			t.recieve();
			break;
			
			case 2:
			t.display_car();
			break;
			
			case 3:
			t.display_amount();
			break;
			
			case 4:
			t.update_tax();
			break;
			
			case 5:
			int x;
			x = t.end_process();
			if(x == 1) return 0;
			cout << "The process is on \n";
			break;
			
			//case 6:
			//t.undo();
			
			//break;
			
			
			default:
			cout << "Wrong input\n";
			
		}
		
	}
	
	return 0;

}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	 
