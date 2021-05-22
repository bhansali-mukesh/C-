#include<iostream>
using namespace std;

class node
{
	bool status;
	int info;
	node *next;
	node* previous;
public:
	node(int m = 0 )	 	
	{
		info = m;
		next = NULL;
		previous = NULL;
		status = false;
	}

	void setdata(int m)
	{
		info = m;
	}
	
	node* getnext()
	{
		return next;
	}

	void setnext(node* p)
	{
		next = p;
	}
		
	void setprevious(node* p)
	{
		previous = p;
	}
	
	node* getprevious()
	{
		return previous;
	}
	
	void setstatus(bool m)
	{status = m;}

	int getstatus()
	{return status;	}
		
	int getdata()
	{
		return info;
	}
};

class tree
{
	node* start;
public:
	tree()
	{
		start = NULL;
	}
	
	void add_node(int s)	 
	{
		node *temp = new node(s);
		if(start == NULL){start = temp;return;}
				
		node* search=start;
		node* papa;
		while(search != NULL)
		{
			papa = search;
			if(temp->getdata() < search->getdata())
			{
				search = search->getprevious();
				continue;
			}
			search = search->getnext();
		}
		
 		if(temp->getdata() < papa->getdata())
		{
			papa->setprevious(temp);
			return;
		}
			papa->setnext(temp);
			return;
	}	


	void deletion(int m )
	{
		if(start==NULL)
		{
			cout<<"OOPS!  THERE IS NO ITEM IN THIS LIST."<<endl;
			return;
		}		

		node* search=start;
		node* last = start;
		
		while(search!=NULL)
		{
					
			if(search->getdata()==m)
			{
				
				if(search->getnext() != NULL && search->getprevious() != NULL)
				{
	
					node* upper = last;
					node* traverse = search->getnext();
					while(traverse->getprevious() != NULL)
					{
						upper = traverse;
						traverse = traverse->getprevious();
					}
					
					if(upper != last)
					{
						upper->setprevious(traverse->getnext());
					}
					
					if(search == start){}
					else if(m < last->getdata()){last->setprevious(traverse);}
					else{last->setnext(traverse);}
					
					traverse->setprevious(search->getprevious());
					
					if(upper != last)
					{
						traverse->setnext(search->getnext());
					}
					
					if(search == start){start=traverse;}
					cout<<"\t"<<m<<" DELETED."<<endl;
					delete search;
					return;
					
				}
				
				if(search == start)
				{
					if(search->getnext() != NULL)
					{
					node* upper = start;
					node* traverse = start->getnext();
					while(traverse->getprevious() != NULL)
					{
						upper = traverse;
						traverse = traverse->getprevious();
					}
						if(traverse != start->getnext())
						{
							upper->setprevious(traverse->getnext());
							traverse->setnext(start->getnext());
						} 
						start = traverse;
						
				}
					else if(start->getprevious() != NULL)
					{
						start = start->getprevious();
					}
					else
					{
						start =NULL;
					}
					delete search;
					return;
				}
				
				if(m < last->getdata())
				{
					if(search->getnext()==NULL)
					{last->setprevious(search->getprevious());}
					else
					{last->setprevious(search->getnext());}
				}
				else
				{
					if(search->getnext()==NULL)
					{last->setnext(search->getprevious());}
					else
					{last->setnext(search->getnext());}
				}
					cout<<"\t"<<m<<" DELETED."<<endl;
					delete search;
					return;
		 	}
					
			last = search;
			
			if(m < search->getdata()){search = search->getprevious();}
			else
				search = search->getnext();
		}
		
			cout<<"NODE NOT FOUND"<<endl;
	}

	void graphdfs(node* dis)
	{
		node* stack[20];
		int top = 0, pop;
		stack[top++] = dis;
		while(top != 0)
		{
			dis = stack[--top];
			pop = dis->getdata();
			cout<<pop<<endl;
			if(dis->getprevious() != NULL)
			{
				if(!dis->getprevious()->getstatus())
				{
					stack[top++] = dis->getprevious();
					dis->getprevious()->setstatus(true);
				}
			}
			if(dis->getnext() != NULL)
			{
				if(!dis->getnext()->getstatus())
				{
					stack[top++] = dis->getnext();
					dis->getnext()->setstatus(true);
				}
			}
			
		}
		setfalse(start);
			
	}
	void graphbfs(node* dis)
	{
		node* stack[20]; 
		int front = 0,rear = 0, pop;
		stack[rear++] = dis;
		while(front != rear)
		{
			dis = stack[front++];
			pop = dis->getdata();
			cout<<pop<<endl;
			if(dis->getprevious() != NULL)
			{
				if(!dis->getprevious()->getstatus())
				{
					stack[rear++] = dis->getprevious();
					dis->getprevious()->setstatus(true);
				}
			}
			if(dis->getnext() != NULL)
			{
				if(!dis->getnext()->getstatus())
				{
					stack[rear++] = dis->getnext();
					dis->getnext()->setstatus(true);
				}
			}
			
		}
		setfalse(start);
			
	}

	
	void setfalse(node * dis )		
	{
				if(dis!= NULL)
				{
					dis->setstatus(false);
					setfalse(dis->getprevious());
					setfalse(dis->getnext());
				}
	}
	
	void rootfirst(node * dis )		
	{
				if(dis!= NULL)
				{
					cout<<dis->getdata()<<endl;
					rootfirst(dis->getprevious());
					rootfirst(dis->getnext());
				}
	}
	
	void rootin(node * dis)
	{
				if(dis!= NULL)
				{
					rootin(dis->getprevious());
					cout<<dis->getdata()<<endl;
					rootin(dis->getnext());
				}
	}	
	
	void rootlast(node * dis)	
	{		
				if(dis!= NULL)
				{
					rootlast(dis->getprevious());
					rootlast(dis->getnext());
					cout<<dis->getdata()<<endl;					
				}
	}
	
	void truncate(node * dis)	
	{		
				if(dis!= NULL)
				{
					truncate(dis->getprevious());
					truncate(dis->getnext());
					delete dis;					
				}
				start = NULL;
	}
	
	void decending(node * dis)
	{
				if(dis!= NULL)
				{
					decending(dis->getnext());
					cout<<dis->getdata()<<endl;
					decending(dis->getprevious());
				}
	}	
	void display(int option)
	{
		if(start==NULL){cout<<"LIST EMPTY"<<endl;return;}
		node* dis=start;
		switch(option)
		{
			case 3:
				rootfirst(start);
				break;
			case 4:
				rootin(start);
				break;
			case 5:
				rootlast(start);
				break;
			case 9:
				truncate(start);
				cout<<"\tDATABASE TRUNCATED."<<endl;
				break;
			case 10:
				graphdfs(start);
				break;
			case 11:
				graphbfs(start);
				break;
			case 12:
				decending(start);
				break;
			default:
				cout<<"BAD CHOICE___  GO HOME & SLEEP...  FURRRRRRRRRRRRRRRRRRR"<<endl;
		}
	}
	
	void search(int value)
	{
		node* khoj=start;
		while(khoj!=NULL)
		{
			if(value==khoj->getdata())
			{
			
	cout<<"FOUND  ";
				int count = 0;
				do
				{
					if(khoj->getdata()==value)
					{
						khoj = khoj->getnext();
						count++;
					}
					else
						khoj = khoj->getprevious();
					}while(khoj != NULL);
				cout<<count<<"  TIMES"<<endl;
				return;
			}
			if(value < khoj->getdata())
			{khoj = khoj->getprevious();}
			else
			khoj = khoj->getnext();
		}
		cout<<"THIS DATA IS NOT IN LIST."<<endl;
	}
	int getroot()
	{
		if(start == NULL){ cout<<"LIST EMPTY.";return 0;}
		return start->getdata();
	}
};

int main()
{
	int chak; 
	tree list;
	tree list7;
	{
		list.add_node(35);
		list.add_node(45);
		list.add_node(15);
		list.add_node(3);
		list.add_node(29);
		list.add_node(15);
		list.add_node(1);
		list.add_node(90);
	}
	
  do 
  {		
	cout<<endl;
	cout<<"1.INSERT A DATA.\n2.INSERT MULTIPLE DATA ENTRY.\n3.TRAVERSE ROOT FIRST (PREORDER).\n4.BETWEEN CHILD (INORDER).\n5.ROOT LAST (POSTORDER).\n6.SEARCH DATA.\n7.ROOT VALUE\n8.DELETE A SPECIFIC DATA\n9.TRUNCATE ENTIRE LIST.\n10.GRAPH DFS SEARCH.\n11.GRAPH BFS SEARCH\n12.TRAVERSE IN DECENDING ORDER.\n13.EXIT\n";
   	cout<<endl;
	cout<<"ENTER YOUR CHOICE FROM THE ABOVE."<<endl;
	int data;
	cin>>chak;
	cout<<endl;
	switch(chak)
	{
		case 1:
		case 2:
			{
				int how_many = 1;
				if(chak==2)
				{
					cout<<"HOW MANY ELEMENTS DO YOU WANT TO ENTER."<<endl;
					cin>>how_many;
					cout<<"ENTER DATA ELEMENTS ONE BY ONE."<<endl;
				}
				else
				{cout<<"ENTER A DATA ENTERY"<<endl;}
				for(int i = 0; i < how_many; i++)
				{
					cin>>data;
					list.add_node(data);
				}
				break;
			}
		case 3:
		case 4:
		case 5:
		case 9:
		case 10:
		case 11:
		case 12:
			{
				list.display(chak);
				break;
			}
		case 6:
			{
				cout<<"ENTER DATA VALUE TO BE SEARCHED."<<endl
				;cin>>data;
				list.search(data);
				break;
			}
		case 7:
				cout<<list.getroot()<<endl;
				break;
		case 8:
				cout<<"ENTER DATA VALUE TO BE DELETED."<<endl;
				cin>>data;
				list.deletion(data);
				break;
		case 13:
			break;
		default:
				cout<<"BAD CHOICE. TRY AGAIN.\n";
			
	}
   }while(chak != 13);
	cout<<endl;	
	return 0;
}
