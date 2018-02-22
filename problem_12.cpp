#include<iostream>
#include<cstdio>
using namespace std;

class pascal_triangle{
	
	
	public:
	
	int fact(int a){
	if(a==0) return 1;
	else return a*fact(a-1);
	}
	
	int comb(int n,int r){
		return fact(n) /(fact(r) * fact(n-r));
	}
	
	
	void pascal_com(int size){
		int i;
		int j;
		for(i=1;i<=size;i++){
			space(size - i +1);
			for(j=0;j<=i;j++){
				cout << "  " << comb(i,j) ;
			}
			
			cout << endl<<endl;
		}
	}
	
	
	void pascal_arr(int size){
	
		int i,j;
		int arr[size][size];
		
		for(i=1;i<=size;i++){
			for(j=0;j<=i;j++){
				if(j==0 || j==i) arr[i][j] = 1;
				else arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
			}
		}
		
	
		for(i=1;i<=size;i++){
			space(size - i);
			for(j=0;j<=i;j++){
				cout << "  " << arr[i][j] ;
			}
			
			cout << endl<<endl;
		}
	}
		
	void find(int size,int rows,int coloumn){
		
		int i,j;
		int arr[size][size];
		
		for(i=1;i<=size;i++){
			for(j=0;j<=i;j++){
				if(j==0 || j==i) arr[i][j] = 1;
				else arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
			}
		}
		
		cout << "\nThe number you want is : " << arr[rows][coloumn-1];
		cout << endl;
		
	}
	
	
	void space(int n){
		int i;
		for(i=0;i<n;i++) cout << "  ";
	}
	
		
		
	
	
	
	
	
};

int main(){
	class pascal_triangle p;
	
	cout << "\n\n**********WELCOME*************\n";
	
	
	int ch;
	
	
	while(1){
	
		cout << "\n1. Pascal triangle using combinational\n";
		cout << "2. Pascal triangle using dynamic programming\n";
		cout << "3. Find an element in pascal triangle\n";
		cout << "4. Exit from the process\n";
		
		
		cout << "\n\tEnter Choice\n";
		
		
		cin >> ch;
		switch(ch){
		
		case 1: 
		cout << "\nWrite the number of rows: ";
		int rows;
		cin >> rows;
		p.pascal_com(rows);
		
		break;
		
		case 2: 
		cout << "\nWrite the number of rows: ";
		int rows1;
		cin >> rows1;
		p.pascal_arr(rows1);
		break;
		
		case 3: 
		cout << "enter the number of rows of the triangle : ";
		int size;
		cin >> size;
		cout << "enter the row and coloumn : ";
		int r,c;
		cin >> r >> c;
		if(c>r+1 || r > size ) 	cout << "\nThe dimention you entered is wrong\n";
		else p.find(size,r,c);
		
		
		break;
		
		case 4:
		cout << "\n****************Thank you**********\n";
		return 0;
		
		default:
		cout << "\nsorry wrong input\n";
		
		
		
		}
	}
	
	
	
	
	return 0;
}

