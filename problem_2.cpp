/*

Design a COMPLEX class, which will behave like normal integer with respect to
addition,
subtraction,
accepting the value and
displaying the value

Soulib Ghosh
BCSE - 2
roll - 47





*/

#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<string.h>

using namespace std;

class complex{

	int re;
	int im;
	
	
public:

// assigning a initial value zero to both using constructor
	complex(){
		re = 0;
		im = 0;
	}
	
	
// taking the input starts

void input_new(){
	cout << "Write the complex number in a + ib format\n";
	//string in;
	//getline(cin, in);
	char in[100];
	cin >> in;
	
	
	int pos = 0;
	int j;
	int len;
	len = strlen(in);
	
	// calculating the position of the sign before 'i'
	
	for(j=0;j<len;j++){
		
		if( in[j] == 'i') break;
		pos = j;
	}
	
	
	// calculating real part
	
	if(pos == 0 && len != 1) re = 0; // if the number starts with i real is zero
	
	else if(pos == len -1 && in[0] != '+' && in[0] != '-'){
		for(j=0;j<len;j++){
			re = re + (int(in[j]) - 48)*pow(10,len-j-1);
		}
	} // no i so imaginary part is zero and starst with no sign
	
	
	else if((pos == len-1) && ( in[0] == '+' || in[0] == '-')){
		for(j=1;j<len;j++){
			re = re + (int(in[j]) - 48)*pow(10,len-j-1);
		}
	} // imaginary part zero and start with a sign 
	
	
	
	
	else if((in[0] == '+' || in[0] == '-') && in[1] != 'i'){
		
		for(j=1;j<=pos-1;j++){
			re = re + (int(in[j]) - 48)*pow(10,pos-j-1);
		}
	} // start with sign and second element is not i that means have some real part
	
	else if(in[0] != '+' && in[0] != '-' && in[1] != 'i'){
		
		for(j=0;j<=pos-1;j++){
			re = re + (int(in[j]) - 48)*pow(10,pos-j-1);
		}
	} // start with no sign and have real part
	
	
	
	if(in[0] == '-') re = re * -1; // if initial sign is negative the make the real part negeative
	
	
	
	
	// calculating real ends
	
	
	
	
	// calculating imaginary part
	
	if(in [0] == 'i') {
		for(j=1;j<len;j++){
			im = im + (int(in[j]) - 48)*pow(10,len - j - 1); 
		}
	
	} // if starts with i 
	
	else 
	{
	
	for(j=pos+2;j<len;j++){
		im = im + (int(in[j]) - 48)*pow(10,len - j - 1); 
	} // if it do not start with 'i' 
	
	
	if(in[pos] == '-') im = im * -1; // if the sign before is negeative then make 
				   // imaginary part negeative
	
	
	}
	
	
	// end of calculating imaginary part

}




	

// displaying a complex number
	
void display(){		
	
	if(re!=0 && im>0)
		printf("complex number is : %d+i%d\n",re,im);
			
	else if(re!=0 && im<0)
		printf("complex number is : %d-i%d\n",re,im*(-1));
			
	else if (re==0 && im>0)
		printf("complex number is : i%d\n",im);
			
	else if (re==0 && im<0)
		printf("complex number is : -i%d\n",im*(-1));
			
	else if(re!=0 && im==0)
		printf("complex number is : %d\n",re);
			
	else if(re==0 && im==0)
		printf("complex number is : %d\n",re);
}


// operator overloading for addition

complex operator + (complex a){
	complex b;
	b.re = re + a.re;
	b.im = im + a.im;
	return b;
}

// operator overloading for subtraction

complex operator - (complex a){
	complex b;
	b.re = re - a.re;
	b.im = im - a.im;
	return b;
}

// operator overloading for multiplication

complex operator * (complex a){
	complex b;
	b.re = re*a.re - im*a.im;
	b.im = re*a.im + im*a.re;
	return b;
}

// calculating modulous of a complex number

float mod(){
	float a;
	a = re*re + im*im;
	return sqrt(a);
}



/*	

// old input.........
void input(){

	cout << "Write the real and imaginary part of the number\n";
	cout << "write real part\n";
	cin >> re;
	cout << "write imaginary part \n";
	cin >> im;
	
}



complex add(complex a){
	complex c;
	c.re = re + a.re;
	c.im = im + a.im;
	return c;
	
}


complex substract(complex a){
	complex c;
	c.re = re - a.re;
	c.im = im - a.im;
	return c;
	
}

*/





};  // end of the class


// main function begins

int main(){

	class complex num1,num2,num3,temp,temp1;
	num1.input_new();
	num3 = num1;
	
	
	

	cout << "\n**********welcome**************";
	
	int ch;
	

	
	
	while(1){
	
		cout<<"\n\n1. display  number \n";
	cout<<"2. Modulous\n"; 
	cout<<"3. addition\n";
	cout<<"4. subtraction\n";
	cout<<"5. exit\n";
	//cout<<"6. Multiplication\n";
	
	
		cin >> ch;
		switch(ch){
		case 1: 
		num1.display();
		break;
		

		
		case 3:
		
		temp.input_new();
		num1 = num1 + temp;
		num1.display();
		break;
		
		case 4:
		temp1.input_new();
		num1 = num1 - temp1;
		num1.display();
		
		break;
		
		case 5:
		cout << "****************THANK YOU*******************\n";
		return 0;
		break;
		/*
		case 6:
		temp.input_new();
		num1 = num1 * temp;
		num1.display();
		
		break;
		*/
		case 2:
		
		
		
		cout << "the mod is: " << num1.mod() << endl;
		
		break;
		
		default:
		cout << "WRONG INPUT !!!" << endl;
		
	}
}	
		
		
	
	return 0;
}
	
	






	
