

#include<iostream>
#include<ctime>
#include<stdlib.h>

using namespace std;

class toss
{
	
	int total_toss;		
	int temp;
	int head_count;
	public:

	toss()
	{
		total_toss=0;
		head_count = 0;
				
	}
	void tossing()
	{
		srand(time(NULL));		
		while(head_count<3)
		{
			temp=rand()%2;
			if(temp)
			{
				cout<<"\nThe result is	Head";
				head_count++;	
			}
			else
			{	
				cout<<"\nThe result is	Tail";
				head_count=0;	
			}
			
			total_toss++;
		}
		
		cout << "\n\n******Yes !!!! You got 3 consecutive heads**********";
		
		cout<<"\n\nTotal toss need is : "<<total_toss <<endl;
	}
};

int main()
{

	cout <<"\n\n********The coin flipping begins***********\n";
	toss ct1;
	ct1.tossing();
	
	cout << "**************Thank You*****************\n";
	return 0;
}
		
