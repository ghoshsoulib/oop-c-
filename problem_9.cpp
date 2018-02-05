/*

Design a BALANCE class with account number, balance and date of last update. Consider a
TRANSACTION class with account number, date of transaction, amount and transaction type. If it is
a withdrawal check whether the amount is available or not. Transaction object will make necessary
update in the BALANCE class.

Soulib Ghosh
BCSE - 2
roll - 47





*/
#include <ctime>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;


class BALLANCE{

	int ballance;
	
	char * date;
	
	public:
	
	int acc_no;
	BALLANCE(){
		ballance = 0;
		//acc_no = 'NULL';
	}
	
	
	void input(){
		//cout << "\nWrite the account number: ";
		//cin >> acc_no;
		cout << "Write the ballance: ";
		cin >> ballance;
		
		             time_t now = time(0);
   
   // convert now to string form
    date = ctime(&now);
    
		cout << "Your account is created\n";
	}
	
	void deposit(){
	
		//cout << "yooooo";
		int temp;
		int temp1 = ballance;
		
		
		             time_t now = time(0);
   
   // convert now to string form
    date = ctime(&now);
    
    
		cout << "Write the amount: ";
		cin >> temp;
		ballance = ballance + temp;
		cout << "your ballance is updated successfully:";
		cout << "\nDATE: "<< date << "   Previous Ballance: " << temp1 << "   Updated Ballance: " << ballance << endl; 
	}
	
	
		
	void withdraw(){
	
		//cout << "yooooo";
		int temp;
		int temp1 = ballance;
		cout << "\nWrite the amount: ";
		cin >> temp;
		if(temp > ballance) cout << "sorry you donot have that much amount\n";
		else {
			ballance = ballance - temp;
			
			cout << "Your ballance is updated successfully:";
			
			             time_t now = time(0);
   
   // convert now to string form
    date = ctime(&now);
    
    
		}
		cout << "\nDATE: "<< date << "   Previous Ballance: " << temp1 << "   Updated Ballance: " << ballance << endl; 
	}
	
	void show_data(){
		
		//cout << "yooooo";
		cout << "\nYour accoumt number is: " << acc_no;
		cout << "\nYour ballance is: " << ballance;
		cout << "\nLast updated date is: " << date << endl;;
	}
	
};



int main(){
	//class BALLANCE t;
	
	int index=0;
	int flag = 0;
	int temp;
	int i;
	class BALLANCE *list[100];



	int ch;
	
	cout << "\n\n*******************Welcome to our bank****************\n";
	
	
	while(1){
	
	
		cout << "\n\n1.Create a new account";
	cout << "\n2.Deposit";
	cout << "\n3.Withdraww";
	cout << "\n4.Show data";
	cout << "\n5.Exit\n\n";
	
	
		cin >> ch;
		switch(ch){
			case 1:
			
		list[index]=new BALLANCE;
		    
                    cout<<"Enter account number: ";
                    
                    cin>>list[index]->acc_no;
		flag=0;
		for(i=0;i<index;i++)
			{
			if((list[i]->acc_no==list[index]->acc_no))
			{
				flag=1;
				break;
			}
		}
			if(!flag)
			{
			    list[i]->input();
				    index++;
				   
			}
			else
			cout<<"account Already Present\n";
			   break;	
			   
		
		
		
		case 2:
		
		cout<<"Enter account number : ";
                      cin>>temp;
                       flag=0;
                        for(i=0;i<index;i++)
                        {
                            if((list[i]->acc_no==temp))
                            {
                                flag=1;
                                break;
                            }
                        }
                        if(flag)
                            list[i]->deposit();
                        else
                            cout<<"account does not exist\n";
		break;
		
		
		case 3:
		
		cout<<"Enter account number : ";
                      cin>>temp;
                       flag=0;
                        for(i=0;i<index;i++)
                        {
                            if((list[i]->acc_no==temp))
                            {
                                flag=1;
                                break;
                            }
                        }
                        if(flag)
                            list[i]->withdraw();
                        else
                            cout<<"account does not exist\n";
		break;	
		
		
		case 4:
		
		cout<<"Enter account number : ";
                      cin>>temp;
                       flag=0;
                        for(i=0;i<index;i++)
                        {
                            if((list[i]->acc_no==temp))
                            {
                                flag=1;
                                break;
                            }
                        }
                        if(flag)
                            list[i]->show_data();
                        else
                            cout<<"account does not exist\n";
		break;
			   
		
		
		case 5: 
		cout << "***************THANK YOU****************\n";
		return 0;
	      
	
		}
	}
	
	return 0;
	
}

	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
