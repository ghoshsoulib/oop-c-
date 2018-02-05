/*


Design a class for the following scenario:
An item list contains item code, name, rate, and quantity for several items.
Whenever a new item is added in the list uniqueness of item code is to be checked.
Time to time rate of the items may change.
Whenever an item is issued or received existence of the item is checked and quantity is
updated.
In case of issue, availability of quantity is also to be checked.
User may also like to know price/quantity available for an item


Soulib Ghosh
BCSE - 2
roll-47



*/



#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<string.h>

using namespace std;

class product{

	char name[31]; 			
	int price;
	int quantity;
	char code[31];


public:




char * gc() 
	{
		return code;
	}


void add_new_item(){
		
		cout<<"\nplease write the Item name: ";
		cin>>name;
			
		cout<<"\nplease write the Item code: ";
		cin>>code;
			
		cout<<"\nplease write the Item Price: ";
		cin>>price;

		update_quantity();
		
		cout << "\nYou Have Entered The Item Successfully\n";
			
}


void update_quantity(){
		
		int temp_quan;
			
		cout<<"\nplease write the Item Quantity: ";
		cin>>temp_quan;
			
		quantity+=temp_quan;
		cout << "\nquantity successfully updated\n";
		
}


void update_price(){
		cout<<"\nplease write the Item Price: ";
		cin>>price;
		cout << "\nprice successfully updated\n";
		
}	


void sold(){
	int temp_quan;
			
	
			
	
		cout<<"\nplease write the Item Quantity: ";
		cin>>temp_quan;
				
	if(temp_quan > quantity) cout<< "There is not enough item.\n";
	else {
	quantity = quantity - temp_quan;
	cout << "\n successfully updated\n";
	
	}
	
	 
	
	
}


void show_data(void){
			
	printf("the price of item is: %d 	Quantity is: %d\n",price,quantity);
			
}  

};




int main(){
	
		
	int index=0;
	int flag;
	char *code1;
	int i;
	product *list[100];
	
	
	
	
	cout << "\n\n**************Welcome to our shop**********************";
	
	
	
	
	int ch;
	while(1){
	
	
	cout << "\n\n1. Recieve New Item";
	cout << "\n2. Update Price";
	cout << "\n3. Update Quantity";
	cout << "\n4. Buy an Item";
	cout << "\n5. Check availablity of Item";
	cout << "\n6. Return from the process\n\n";
	
	
	
		cin >> ch;
		switch(ch){
			case 1: 
									
						
			list[index]=new product;
					
			
			
			
			cout<<"plese write Item Code: ";		
					cin>>code1;
					
					flag=0;
					for(i=0;i<index;i++)
					{
						if(strcmp(list[i]->gc(),code1)==0)
						{
							flag=1;
							break;
						}
					}
					if(!flag){
						
						list[i]->add_new_item(); 
					}		
					else
			
						cout<<"Item already exist\n";
					
			index++;
			
			
			
			break;
			
			case 2:
			
			cout<<"\nplease write the Item Code: ";		
					
					cin >> code1;
					
					
					flag=0;
					for(i=0;i<index;i++)
					{
						if(strcmp(list[i]->gc(),code1)==0)
						{
							flag=1;
							break;
						}
					}
					if(flag)
						list[i]->update_price(); 		
					else
						cout<<"\nitem does not exist\n";
	
			break;
			
			case 3:
			
			cout<<"\nplease write the Item Code: ";	
					cin>>code1;
					flag=0;
					for(i=0;i<index;i++)
					{
						if(strcmp(list[i]->gc(),code1)==0)
						{
							flag=1;
							break;
						}
					}
					if(flag==1)
						list[i]->update_quantity(); 		
					else
						cout<<"\nitem does not exist";
			
			break;
			
			case 4:
			
			cout<<"\nplease write the Item Code: ";	
					cin>>code1;
					flag=0;
					for(i=0;i<index;i++)
					{
						if(strcmp(list[i]->gc(),code1)==0)
						{
							flag=1;
							break;
						}
					}
					
					if(flag)
						list[i]->sold(); 		
					else
						cout<<"\nitem does not exist";
	                    break;
			
			case 5:
			
			cout<<"\nplease write the Item Code: ";		
					cin>>code1;
					flag=0;
					
					for(i=0;i<index;i++)
					{
						if(strcmp(list[i]->gc(),code1)==0)
						{
							flag=1;
							break;
						}
					}
					
					
					
					if(flag)
						list[i] -> show_data(); 		
					else
						cout<<"\nitem does not exist";
		
			
			
			break;
			
			case 6:
			cout << "\n ***********THANK YOU***************\n";
			return 0;
			break;
			
			
			default:
			cout << "Wrong input\n";
			
		}
		
	}
	
	return 0;

}
