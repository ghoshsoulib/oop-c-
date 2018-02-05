
/*

Design a STRING class, which will have the initialization facility similar to array class. Provide
support for
 Assigning one object for another,
 Two string can be concatenated using + operator,
 Two strings can be compared using the relational operators.

Soulib Ghosh
BCSE - 2
roll - 47



*/




#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class my_str {
	char *str=NULL;
	int size;
	public:
	my_str(int);
	my_str(const my_str&);
	my_str(const char*);
	~my_str();
	int length() const {return size;}
	char &operator[](int);
	void operator=(my_str);
	my_str operator+(my_str&);
	bool operator>=(my_str&);	
	bool operator!=(my_str&);
	bool operator>(my_str&);	
	bool operator==(my_str&);
	bool operator<(my_str&);
	bool operator<=(my_str&);
	
	friend ostream& operator<<(ostream&,my_str&);
};
my_str::my_str(int len=0) {
	//cout << "1" << endl;
	size=0;
	if (str) {
		delete str;
		size=0;
	}
	if (len==0) {
		str=NULL;
		size=0;
	}
	else if(len<0) {
		cout << " memory allocation error" << endl;
	}
	else if(len>0) {
		size=len;
		str=new char[size+1];
		for (int i=0; i<len; i++)
		str[i]='\0';
		str[size]='\0';
	}	
	//cout << "Array created with size: " << len << endl;
}
my_str::my_str(const my_str& instr) {
	//cout << "2" << endl;
	if (str) {
		delete str;
		size=0;
	}
	if((size=instr.length())) { // allocate space equal to array
		//cout << "copying" << endl;
		str=new char[size+1];
		for (int i=0; i<size; i++)
		str[i]=instr.str[i];
		str[size]='\0';
	}
}
my_str::my_str(const char *instr) {
	//cout << "3" << endl;
	int len=strlen(instr);
	
	if (str) {// already space allocated
		delete str;
		size=0;
	}
	size=0;
	if (len==0) {
		str=NULL;
		size=0;
	}
	else if (len<0) {
		cout << "memory allocation error" << endl;
	}
	else if(len>0) {
		size=len;
		str=new char[len+1];
		for (int i=0; i<len; i++)
		str[i]=instr[i];
		str[len]='\0';
	}
}
my_str::~my_str() {
	if (str) {
		size=0;
		delete str;
	}
}
void my_str::operator=(my_str mstr) {
	if (str) {// already space allocated
		delete str;
		size=0;
	}
	if((size=mstr.length())) { // allocate space equal to array
		str=new char[size+1];
		for (int i=0; i<size; i++)
		str[i]=mstr[i];
		str[size]='\0';
	}
	
}

ostream& operator<<(ostream& out, my_str& mstr) {
	
	out << mstr.str;
	return out;
}


bool my_str::operator>(my_str& mstr) {
	if (strcmp(str,mstr.str)>0) return true;
	return false; 
}



bool my_str::operator!=(my_str& mstr) {
	if (strcmp(str,mstr.str)==0) return false;
	return true; 
}

char& my_str::operator[](int index) {
	if (index>=size) {
		cout << "String index out of bounds: " << index << " "<< endl;
	}
	return str[index];
}

bool my_str::operator<(my_str& mstr) {
	if (strcmp(str,mstr.str)<0) return true;
	return false; 
}

my_str my_str::operator+(my_str& mstr) {
	int con_len=length()+mstr.length(), j=0;
	my_str concat(con_len);
	for (int i=0; i<length(); i++) concat[j++]=str[i];
	for (int i=0; i<mstr.length(); i++) concat[j++]=mstr[i];
	return concat;
}



bool my_str::operator>=(my_str& mstr) {
	if (strcmp(str,mstr.str)>=0) return true;
	return false; 
}


bool my_str::operator==(my_str& mstr) {
	if (strcmp(str,mstr.str)==0) return true;
	return false; 
}

bool my_str::operator<=(my_str& mstr) {
	if (strcmp(str,mstr.str)<=0) return true;
	return false; 
}


int main() {
	my_str a,b,c;
	int n,m,flag=1, i;
	char ch, text[101];
	double mul,def;
	
	cout << "please mention the first string: " ;
	cin.getline(text,100);
	a=my_str(text);
	cout << "please mention the Second string: ";
	cin.getline(text,100);
	b=my_str(text);
	

	int choice, index;
	
	cout << "\n\n***********Welcome to our string********";
	while (1) {
		
			cout << "\n\n1. Concat 1st and 2nd array\n";
		cout << "2. Compare 1st and 2nd strings\n";		
		cout << "3. Assign a new string with an existing string\n";		
		cout << "4. Initialize a string\n";
		cout << "5. Exit\n\n";
		
		
		
		cin >> choice;
		switch(choice) {
			case 1: c=a+b;
					cout << "after conctionation the string is as follows: " << endl;
					cout << c << endl;
					break;
					
					
			case 2: 
			
			cout << "s1 - first string, s2 - second string, 1 - true, 0 - false" << endl;
			cout<< "the comparision result for all measures are as follows\n";		 
					cout << "s1==s2: " << (a==b) << endl;
					cout << "s1!=s2: " << (a!=b) << endl;
					cout << "s1<=s2: " << (a<=b) << endl;
					cout << "s1>=s2: " << (a>=b) << endl;
					cout << "s1<s2: " << (a<b) << endl;
					cout << "s1>s2: " << (a>b) << endl;
					break;
					
								
			
			
			
			case 3: cout << "please mention the string number:  " ;
					cin >> index;
					if (index==1) c=a;
					else if (index==2) c=b;
					else cout << "Invalid input" << endl;
					for (i=0; i<c.length(); i++) {
						cout << c[i] << " ";
					}
					cout << endl;
					break;
		
			case 4: 
			
			cout << "please mention string number: ";
					cin >> index;
					if (index==1) {
						cout << "please Enter string 1: ";
						cin.ignore(4,'\n');
						cin.getline(text,100);
						a=text;
						cout << "new string is: "  << a;
					}
					else if (index==2) {
						cout << "please Enter string 2: ";
						cin.ignore(4,'\n');
						cin.getline(text,100);
						b=text;
						cout << "new string is: " << b;
					}
					else cout << "Wrong input" << endl;
					break;		
					
			
			
			case 5: 
			cout << "*****Thank you********\n";
			return 0;		
			default: cout << "Invalud input" << endl;
			

		}
	}
	return 0;
}

