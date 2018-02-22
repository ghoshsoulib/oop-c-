#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;


struct node

{

	int priority;

	
	string value;

	struct node *next;

};



class Priority_Queue

{

    private:

        node *front;
        node *Rear;

    public:

        Priority_Queue()

        {

            front = NULL;
            Rear = NULL;

        }

   

        void insert(string item, int priority)

        {

          
            node *q;

            Rear = new node;

            Rear->value = item;

            Rear->priority = priority;

            if (front == NULL || priority < front->priority)

            {

                Rear->next = front;

                front = Rear;

            }

            else

            {

                q = front;

                while (q->next != NULL && q->next->priority <= priority)

                    q=q->next;

                Rear->next = q->next;

                q->next = Rear;

            }

        }

    

        void del()

        {

            node *Rear;

            if(front == NULL)

                cout<<"Queue is empty\n";

            else

            {

                Rear = front;

                cout<<"Deleted item is: "<<Rear->value<<endl;

                front = front->next;

                free(Rear);

            }

        }

       

        void display()

        {
	  cout << endl;
            node *ptr;

            ptr = front;

            if (front == NULL)

                cout<<"Queue is empty\n\n";

            else

            {	cout<<"Queue is :\n\n";

                cout<<"Priority       Item\n\n";

                while(ptr != NULL)

                {

                    cout<<ptr->priority<<"                 "<<ptr->value<<endl;

                    ptr = ptr->next;

                }

            }

        }

};



int main()

{

    int choice, priority;
    //char item[10];
    string item;
    Priority_Queue pq; 
    
    cout << "\n***********Welcome***********\n";
    do

    {

        cout<<"\n1.Insert an element ( enqueue )\n";

        cout<<"2.Delete from the queue ( dequeue )\n";

        cout<<"3.Display the present queue\n";

        cout<<"4.Exit from the process\n";

        cout<<"\tEnter your choice : \n"; 

        cin>>choice;

        switch(choice)

        {

        case 1:

            cout<<"Please Input the item value : ";

            cin>>item;

            cout<<"Please Enter its priority : ";

            cin>>priority;

            pq.insert(item, priority);

            break;

        case 2:

            pq.del();

            break;

        case 3:

            pq.display();

            break;

        case 4:
        
        cout << "\n***************Thank you*****************\n";
	   return 0;
            break;

        default :

            cout<<"\nWrong choice\n";

        }

    }

    while(1);

    return 0;

}
