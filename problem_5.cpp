
/*

Design an arr class with the following features:
a) arr object may be declared for a specific len and a value for initializing all the elements. If
this it is to be assumed as a 0.
b) An arr object may be declared and initialized with another object.
c) An arr object may be declared and initialized with another arr (not the object, standard
arr as in C language).
Let a and b are two objects:
i. a+b will add corresponding elements.
ii. a=b will do the assignment.
iii. a[I] will return the ith element of the object.
iv. a*5 or 5*a will multiply the element with 5.

Soulib Ghosh
BCSE - 2
roll - 47




*/


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

template <class Type>

class arr
{
	Type *a;	
	int len;
	
	int get_len()
	{
		return len;
	} 
	
	public:			
	
	arr(int len1){
		len=len1;
		
		a= new Type[len];		
		for(int i=0;i<len;i++)
			a[i]=0;
	}
	
	
	void operator = (arr b)
	{
		int c=b.get_len();
		
		if(c>len)
			c=len;			
			
		for(int i=0;i<c;i++)
			a[i]=b.a[i];
	}
	
	void operator = (Type *f)
	{
		for(int i=0;i<len;i++)
			a[i]=*(f+i);		
	}	
	
	int operator [] (int i)			
	{
		if(i>len)
			cout<<"\n\t Wrong access point";
			
		else
			return a[i];
	}
	
	arr operator * (int m)		
	{
		arr x(len);
		for(int i=0;i<len;i++)
			x.a[i]=a[i]*m;
			
		return x;
	} 
	
	
	
	
	
	friend arr operator * (int x, arr y)	
	{
		return y*x;
	}
	
	arr operator + (arr x)		
	{
		arr y(len);
		
		for(int i=0;i<len;i++)
			y.a[i]=a[i]+x.a[i];
		
		return y;	
	}
	
	void print(void)			
	{
		for(int i=0;i<len;i++)
			cout<<a[i]<< " ";
	}
};




int main()
{
	int tem;
	
	cout<<"Number of element: ";
	cin>>tem;
	
	int choice,num,index,mu;
	int *i1;
	arr<int> a(tem),b(tem),c(tem);
	
	cout<<"first arr: ";       
	i1=new int[tem];
	
	for(int i=0;i<tem;i++)
		cin>>i1[i];
	a=i1;
	
	cout<<"second arr: ";
		
	for(int i=0;i<tem;i++)
		cin>>i1[i];
	
	b=i1;

	cout << "\n\n***********Welcome to new array***********";
	while(1)
	{
				cout << "\n\n1.Assign by another arr\n";
		cout << "2.Return an arr element\n";
		cout << "3.Multiply with any const(5*a i.e. form 2)\n";		
		cout << "4.Print the arr\n";
		cout << "5.Multiply with any const(a*5 i.e. form 1)\n";
		cout << "6.Addition\n";		
		cout << "7.Exit\n\n";
	
		
		cin>>choice;
		
		switch(choice)
		{
			
			case 1:
				cout<<"please mention the arr: ";
				cin>>num;
				if(num==1)
					c=a;		
				else
					c=b;
					
				cout<<"new arr: "<<endl;
				c.print();
				cout<<endl;
				break;
			
			
				
			case 2:
				cout<<"\nplease mention the  arr:  ";
				cin>>num;
				cout<<"\nplease mention the index:";
				cin>>index;
				if(num==1)
					cout<<"\nelement is: "<<a[index]<<endl;
				else 
					cout<<"\nelement is: "<<b[index]<<endl;
				break;
				
			case 3:
				cout<<"\nplease mention the arr: ";
				cin>>num;
				cout<<"\nplease mention the  multiplier: ";
				cin>>mu;
				
				if(num==1)
					c=mu*a;
				else if(num==2)  
					c=mu*b;
				else cout << "Invalid Input\n";
				break;
				
				
			case 4:
				cout<<"arr is: ";
				c.print();
				cout<<endl;
				break;
				
			case 5:
				cout<<"\nplease mention the  arr: ";
				cin>>num;
				cout<<"\nplease mention the  multiplier:  ";
				cin>>mu;
				
				if(num==1)
					c=a*mu;
				else if(num==2) 
					c=b*mu;
				else cout << "Invalid Input\n";
			
				break;
			case 6:
				c=a+b;
				break;
				
			
				
			
				
			case 7:
				cout<<"\n************Thank you**************\n";
				exit(0);
				
			default:
				cout<<"\nWrong Entry\n";
				break;
		}			
	
	}
	
	return 0;
}


	
