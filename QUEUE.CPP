#include<iostream>
using namespace std;

class queue
{
	int* storage;
	int length,rear,front;
public :
	queue(int m=10)
	{
		length=m;
		storage=new int[m];
		rear=0;
		front=0;
	}
	
   void	insert(int m = 0)
	{
		if(rear==length)
		{
			cout<<"QUEUE IS ALREADY FULL. CANN'T ADD MORE ELEMENTS.."<<endl;
			return;
		}
		storage[rear++]=m;
	}

   int deletion()	
	{
		if(front==rear)
		{
			cout<<"EMPTY QUEUE... CANN'T POP ANYMORE"<<endl;
			return 0;			
		}
		int p=storage[front++];
		return p;
	}

   void display()
	{
		for(int i=front;i<rear;i++)
		{cout<<storage[i]<<endl;}
	}	

};


int main()
{
	cout<<endl;
	cout <<"I AM HERE  GUYS."<<endl;
	cout<<endl;
	queue one;
	one.deletion();
	one.insert(15);
	one.insert(587)
	;one.display();
	cout<<"THIS ELEMENT IS DISCARDED: "<< one.deletion()<<endl;
	one.display();
	cout<<endl;
	one.insert();
	one.insert(1000);
	one.insert(2500);
	cout<<endl;	
	one.display();
	cout<<endl;
	return 0;
}
