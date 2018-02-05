/*

Modify the STRING class so that assigning/initializing a string by another will not copy it physically
but will keep a reference count, which will be incremented. Reference value 0 means the space can be
released.

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
	int size, *count=NULL;
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
	void show_count() const{cout << *count << endl;}
};
my_str::my_str(int len=0) {
	
	size=0;
	if (str) {
		*count=*count-1;
		size=0;
		if (*count==0) {
			delete count;
			delete str;
		}
	}
	if (len==0) {
		str=NULL;
		count=NULL;
		size=0;
	}
	else if(len<0) {
		cout << " error" << endl;
	}
	else if(len>0) {
		size=len;
		str=new char[size+1];
		for (int i=0; i<len; i++)
		str[i]='\0';
		str[size]='\0';
		count=new int(1);
	}
	
	//cout << "Array created with size: " << len << endl;
}
my_str::my_str(const my_str& instr) {
	
	//cout << "2" << endl;
	
	if (str) {
		cout << "deleting " << str  << *count << endl;
		*count=*count-1;
		size=0;
		if (*count==0) {
			cout << "remove space" << endl;;
			delete count;
			delete str;
		}
	}
	if((size=instr.length())) { 
		cout << "copying" << endl;
		str=instr.str;
		cout << "update count" << endl;
		count=instr.count;
		*count=*count+1;
		cout << "count updated" << endl; 
	}
}
my_str::my_str(const char *instr) {
	
	int len=strlen(instr);
	
	if (str) {
		*count=*count-1;
		if (*count==0) {
			delete count;
			delete str;
		}
		size=0;
	}
	size=0;
	if (len==0) {
		str=NULL;
		count=NULL;
		size=0;
	}
	else if (len<0) {
		cout << "memory allocation error" << endl;
	}
	else if(len>0) {
		size=len;
		
		str=new char[size+1]; 
		strcpy(str,instr);
		count=new int(1);
	}
}
my_str::~my_str() {

	if (str) {
		size=0;
		*count=*count-1;
		if(*count==0) {
			delete count;
			delete str;
		}
	}
}
void my_str::operator=(my_str mstr) {

	cout << mstr << *mstr.count << endl;
	if (str) {
		cout << str << endl;
		*count=*count-1;
		size=0;
		cout << "count of current_ptr: " << *count << endl;
		if (*count==0) {
			
			delete count;
			cout << "enter" << endl;
			cout << str << endl;
			delete str; 
		}
	}
	if((size=mstr.length())) {
		str=mstr.str;
		count=mstr.count;
		*count=*count+1;
	}
	
}
char& my_str::operator[](int index) {
	if (index>=size) {
		cout << "String index out of bounds: " << index << " "<< endl;
	}
	return str[index];
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
	
	char ch, text[101];
	int n,m,flag=1, i;
	
	double temp1,temp2;
	
	cout << "please mention string1: " ;
	cin.getline(text,100);
	a=my_str(text);
	cout << "please mention string2: ";
	cin.getline(text,100);
	b=my_str(text);
	int choice, index;
	
	cout << "\n\n***********welcome to our string**************";
	while (1) {
		
		cout << "\n\n1. Concat 1st and 2nd array\n";
		cout << "2. Initialize a string\n";
		cout << "3. Assign a new string with an existing string\n";		
		cout << "4. Compare 1st and 2nd strings\n";		
		cout << "5. Exit\n" << endl;
		
		cin >> choice;
		switch(choice) {
		
			case 1: c=a+b;
					cout << "after concatination the string is as follows: " << endl;
					cout << c << endl;
					break;
					
					
			case 2: cout << "please mention the string number: ";
					cin >> index;
					if (index==1) {
						cout << "please enter Enter string 1: " ;
						cin.ignore(4,'\n');
						cin.getline(text,100);
						a=text;
						cout << a;
					}
					else if (index==2) {
						cout << "please Enter string 2: ";
						cin.ignore(4,'\n');
						cin.getline(text,100);
						b=text;
						cout << b;
					}
					else cout << "Wrong input" << endl;
					break;
					
					
			case 3: cout << "please mention the string number: " ;
					cin >> index;
					if (index==1) c=a;
					else if (index==2) c=b;
					else cout << "invalid input" << endl;
					for (i=0; i<c.length(); i++) {
						cout << c[i] << " ";
					}
					cout << endl;
					break;
					
					
			
					
					
			case 4: 
			
			cout << "s1 - first string, s2 - second string, 1 - true, 0 - false" << endl;
			cout<< "the comparision result for all measures are as follows\n";
					
					cout << "s1==s2: " << (a==b) << endl;
					cout << "s1!=s2: " << (a!=b) << endl;
					cout << "s1<=s2: " << (a<=b) << endl;
					cout << "s1>=s2: " << (a>=b) << endl;
					cout << "s1<s2: " << (a<b) << endl;
					cout << "s1>s2: " << (a>b) << endl;
					break;
			
			case 5:
			cout<< "*************Thank you***********\n\n";
			return 0;
					
			temp2ault: cout << "Invalud input" << endl;
			

		}
	}

	return 0;
	
}
