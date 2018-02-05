/*
In a bank two types of accounts are there savings and current. For savings account a minimum deposit
of Rs. 500 are to be kept. In current account overdraft up to Rs. 20,000 is allowed. Each transaction is
noted. Design and implement the necessary classes.


Soulib Ghosh
BCSE - 2
roll - 47


*/



#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#define MAX_lok 100
#define MAX_T 100
using namespace std;

class sav;
class cur;
class acc {
	protected:
	int acc_no;
	float amount;
	public:
	acc(int temp_acc_no=0, float amt=0.0) {acc_no=temp_acc_no; amount=amt;} 
	virtual void withdraw(float)=0;
	virtual void deposit(float)=0;
	friend int sav_acc_no(sav*,int,int);
	friend int cur_acc_no(cur*,int,int);
};
class transaction {
	int trans_id;
	char mode;
	float amount;
	public:
	transaction() {trans_id=0; amount=0.0;}
	transaction(int id, char typ, float amt) {
		trans_id=id;
		mode=typ;
		amount=amt;
	}
	friend class sav;
	friend class cur;
};

class sav:public acc {
	int no_trans;
	transaction trans[MAX_T];
	public:
	sav():acc(0,0) {}
	sav(int temp_acc_no, float amt):acc(temp_acc_no,amt) {no_trans=0;}
	
	


void deposit(float amt) {
	amount+=amt;
	trans[no_trans++]=transaction(no_trans,'D',amt);
	cout << "Rs. " << amt << " your deposit is successfully done" << endl;
	cout << "balance: Rs. " << amount << endl;
	
}
void withdraw(float amt) {
	if ((amount-amt)<500) {
		cout << " Rs. 500 must" << endl;
	}
	else {
		amount-=amt;
		trans[no_trans++]=transaction(no_trans,'W',amt);
		cout << "Rs. " << amt << " withdrawn successfully" << endl;
		cout << " balance: Rs. " << amount << endl;
		
	}
}
void tran_last5() const {
	cout << "Account Number: " << acc_no << endl;
	cout << "Available Balance: Rs. " << amount << endl;
	cout << "Serial.NO		amount		mode" << endl;
	for (int i=0; i<no_trans  && i<5; i++) {
		cout << i+1 << "\t\t" << trans[no_trans-1-i].amount << "\t\t" << trans[no_trans-1-i].mode << endl; 
	}
}

};


class cur : public acc{
	transaction trans[MAX_T];
	int no_trans;
	float over_amt;
	public:
	cur():acc(0,0) {}
	cur(int temp_acc_no, float amt):acc(temp_acc_no, amt) {
		no_trans=0;
		over_amt=0.0;
	}


void deposit(float amt) {
	amount+=amt;
	over_amt=(amount<0.0)?-amount:0.0;
	trans[no_trans++]=transaction(no_trans,'D',amt);
	cout << "Rs. " << amt << " deposited successfully" << endl;
	if (amount<0) {
		cout << "Available Overdraft Limit: Rs. " << (20000-over_amt) << endl;
	}
	else {
		cout << "Available balance: Rs. " << amount << endl;
	}
}
void withdraw(float amt) {
	if ((amount-amt)<-20000) {
		cout << "Maximum overdraft is Rs. 20000" << endl;
	}
	else {
		amount-=amt;
		over_amt=(amount<0.0)?-amount:0.0;
		trans[no_trans++]=transaction(no_trans,'W',amt);
		cout << "Rs. " << amt << "your withdrawn was successfully done" << endl;
		if (amount<0) {
		cout << "Available Overdraft Limit: Rs. " << (20000-over_amt) << endl;
		}
		else {
			cout << "Available balance: Rs. " << amount << endl;
		}
	}
}
void tran_last5() const {
	cout << "your Account Number: " << acc_no << endl;
	if (amount<0) {
		cout << "you can take loan Rs. " << (20000-over_amt) << endl;
	}
	else {
		cout << "your amount Rs. " << amount << endl;
	}
	cout << "\nSerial.NO		amount	     mode" << endl;
	for (int i=0; i<no_trans  && i<5; i++) {
		cout << i+1 << "\t\t" << trans[no_trans-1-i].amount << "\t\t" << trans[no_trans-1-i].mode << endl; 
	}
	
	cout << "\n\n";
}

};


int sav_acc_no(sav* temporary, int len, int temp_acc_no) {
	int pos=-1; 
	for(int i=0; i<len; i++) {
		if(temp_acc_no==temporary[i].acc_no) { 
			pos=i; 
			break;
		}
	}
	return pos;
}
int cur_acc_no(cur* temporary, int len, int temp_acc_no) {
	int pos=-1; 
	for(int i=0; i<len; i++) {
		if(temp_acc_no==temporary[i].acc_no) { 
			pos=i; 
			break;
		}
	}
	return pos;
}

int main() {

	sav sav_acc[MAX_lok];
	cur cur_acc[MAX_lok];
	int temp_acc_no;
	int index_sav=0, index_cur=0 ,choice, position_s, position_c, temp;
	float amount;
	
	cout << "\n***********Welcome to our Bank****************";
		
	while (1) {
		
			cout << "\n\n1. Create an account\n";
		cout << "2. Withdraw from account\n";
		cout << "3. View last 5 transactions\n";
		cout << "4. Deposit in the account\n";		
		cout << "5. Exit from the process\n\n";
		
		cin >> choice;
		switch(choice) {
			case 1:  
				cout << "\nwhat type of accoumt do you want\n";
			         cout << "\t1. Savings Account\n";
			         cout << "\t2. Current Account\n";
			        
			       
				cin >> temp;
				cout << "please write account number: " ;
				cin >> temp_acc_no;
				cout << "please write starting balance: " ;
				cin >> amount;
				if (temp==1 && amount<500) {
					cout << "sorry Rs. 500 must\n";
				}
				else {
					if (temp==1) sav_acc[index_sav++]=sav(temp_acc_no,amount);
					else if (temp==2) cur_acc[index_cur++]=cur(temp_acc_no,amount);
				}
				break;
					
					
			case 2: cout << "please write account number: ";
					cin >> temp_acc_no;
					position_s=sav_acc_no(sav_acc,index_sav,temp_acc_no);
					position_c=cur_acc_no(cur_acc,index_cur,temp_acc_no);
					if (position_s==-1 && position_c==-1) {
						cout << "sorry no account" << endl;
						break;
					}
					cout << "please write the amount: " ;
					cin >> amount;
					if (position_s>=0) {
						sav_acc[position_s].withdraw(amount);
					}
					else if (position_c>=0) {
						cur_acc[position_c].withdraw(amount);
					}
					break;
					
					
			case 3: cout << "please write account number: ";
					cin >> temp_acc_no;
					position_s=sav_acc_no(sav_acc,index_sav,temp_acc_no);
					position_c=cur_acc_no(cur_acc,index_cur,temp_acc_no);
					if (position_s==-1 && position_c==-1) {
						cout << "sorry no account" << endl;
						break;
					}
					if (position_s>=0) {
						sav_acc[position_s].tran_last5();
					}
					else if (position_c>=0) {
						cur_acc[position_c].tran_last5();
					}
					break;
					
			case 4: cout << "please write account number: ";
					cin >> temp_acc_no;
					position_s=sav_acc_no(sav_acc,index_sav,temp_acc_no);
					position_c=cur_acc_no(cur_acc,index_cur,temp_acc_no);
					if (position_s==-1 && position_c==-1) {
						cout << "sorry No account\n";
						break;
					}
					cout << "please write amount: " ;
					cin >> amount;
					if (position_s>=0) {
						sav_acc[position_s].deposit(amount);
					}
					else if (position_c>=0) {
						cur_acc[position_c].deposit(amount);
					}
					break;
			
			
			case 5: cout << "****************Thank You***************\n" ;
					return 0;
			default: cout << "Invalid input" << endl;
		}
	}
	
	
	return 0;
}
