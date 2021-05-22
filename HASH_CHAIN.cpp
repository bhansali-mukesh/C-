#include<iostream>
using namespace std;
#define MAX  100

class record
{
	int key , data ,next;
	//static int count;
	public:
	record()
	{ key = -1; data = -1; next = -1;}

	record(int m)
	{key = -1; data = m; next = -1;}

	int getkey(){ return key; }

	void setkey( int m){ key = m; }

	int getdata(){return data;}

	int getnext(){return next;}

	void setnext(int m){next = m;}

	void setdata(int d){data = d;}

};

class hash_database
{
	int hash[MAX];
	record hashing[MAX];
	int count, available, avail[MAX], rear, front;
public:
	hash_database()
	{
		for(int i =0; i < MAX; i++)
		{
			hash[i] = -1;
			avail[i] = i;
		}
		count = front = 0;
		rear = MAX;
		available = MAX;
	}	

	void insert(int n)
	{
		if(available == 0)
		{	
			cout<<"DATABASE IS ALREADY FULL."<<endl;
			return;
		}
		int k = ++count;
		int hk = (k-1) % 100;
		hash[hk] = front; 
		hashing[front].setdata(n);
		hashing[front].setkey(k);
		hashing[front++].setnext(hash[hk]);
		if(front == MAX)front = 0;
		available--;
		}
	
	void search(int choice, int n)
	{
		int hk = (n-1) % 100;
		int k = hash[hk];
		if(k != -1)
		{
			int previous;
			while(hashing[k].getkey() != n && hashing[k].getnext() != -1)
			{
				previous = k; 
				k = hashing[k].getnext();
			}
		  if(hashing[k].getkey() == n)
		  {
				if(choice == 3)
				{
				cout<<"YOUR DATA IS: "<<hashing[hash[hk]].getdata()<<endl;
				return;
				}
			
				else
				{
					cout<<"YOUR DATA "<<hashing[hash[hk]].getdata()<<" IS GOING TO BE DELETED"<<endl;
					avail[rear++] = hash[hk];
					if(rear == MAX) rear = 0;
					available++;
					if(hashing[hk].getkey() == n)
					{
						hash[hk] = -1;
						return;
					}
					hashing[previous].setnext(hashing[k].getnext()); 
				}
		  }
		}
			cout<<"RECORD NOT FOUND."<<endl;
	}

	void display()
	{
		cout<<endl;
		int k = rear%MAX;
		int i =k;
		while(i < front)
		{	
			
			if(hashing[avail[i]].getkey()!= -1)
			{
				if(hash[i] != -1)cout<<"YOUR KEY IS "<<hashing[i].getkey()<<"   & DATA IS   "<<hashing[i].getdata()<<endl;
			}
			i = (i+1)%MAX;
		}
	}
};

int main()
{
	int n, option, variable;
	hash_database h;
	do
	{
		cout<<"\n1.ENTER A SINGLE DATA.\n2.ENTER MULTIPLE DATA ENTRY.\n3.SEARCH.\n4.DELETE\n5.EXIT."<<endl;
		cout<<"\nENTER YOUR CHOICE FROM ABOVE."<<endl;
		cin>>option;
		switch(option)
		{
		case 1:cout<<"ENTER A DATA"<<endl;
		case 2:
			{
				int how_many = 1;
				if(option == 2)
				{
					 cout<<"HOW MANY DATA YOU WANT TO ENTER."<<endl;
				     cin>>how_many;
					 cout<<"ENTER DATA ONE BY ONE."<<endl;
				}
				for(int i = 0; i < how_many; i++)
				{
					cin>>variable;
					h.insert(variable);
				}
				h.display();
				break;
			}
		case 3:cout<<"ENTER THE KEY OF RECORD."<<endl;
		case 4:
				if(option == 4)
				{
					cout<<"ENTER KEY OF RECORD TO BE DELETED."<<endl;
				}
				cin>>variable;
				h.search(option,variable);
				break;
		case 5:
				h.display();
				break;
		case 6:
				break;
		default:
				cout<<"I AM DOING SO MANY THINGS FOR YOU.\n BUT CANN'T YOU GIVE EVEN A VALID CHOICE.TRY AGAIN."<<endl;
		}
}while(option != 6);
char a;cin>>a;
return 0;
}