#include<iostream>
using namespace std;

class node
{
	int info;
	node *next;
	node* previous;
public:
	node(int m = 0 )	 	
	{
		info = m;
		next = NULL;
		previous = NULL;
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
	
	int getdata()
	{
		return info;
	}
};

class linklist
{
	node* start;
public:
	linklist()
	{
		start = NULL;
	}
	
	void add_node(int s)	 
	{
		node *temp = new node(s);
		if(start == NULL){start = temp;return;}
		
		node* search=start;
		if(temp->getdata() < search->getdata())
		{
			temp->setnext(search);
			start=temp;
			search->setprevious(temp);
			return;
		}		

		while(search->getnext() != NULL && search->getnext()->getdata() < temp->getdata())
		{
			search = search->getnext();
		}
	
		if(search->getnext() != NULL){search->getnext()->setprevious(temp);}
		temp->setprevious(search);
		temp->setnext(search->getnext());
		search->setnext(temp);
	}

	void deletion(int m )
	{
		if(start==NULL)
		{
			cout<<"OOPS!  THERE IS NO NODE IN THIS LIST."<<endl;
			return;
		}		

		node* search=start;

		while(search!=NULL)
		{
			if(search->getdata()==m)
			{
				node* del=search;
				if(search->getnext() != NULL){search->getnext()->setprevious(search->getprevious());}
				if(search != start){search->getprevious()->setnext(search->getnext());}
				else
				{start=search->getnext();}
				
				cout<<"\t"<<m<<" DELETED"<<endl;
				delete del;
				return;
			}
			search = search->getnext();
		}
		
			cout<<"NODE NOT FOUND"<<endl;
	}

	void display()
	{
		if(start==NULL){cout<<"LIST EMPTY"<<endl;return;}
		node *dis=start;
		while(dis!= NULL)
		{
			cout<<dis->getdata()<<endl;
			dis=dis->getnext();
		}
	}
};

int main()
{
	linklist list;
	linklist list7;
//	for(int i=0;i<12;i=i+2)
	{
		list.add_node(5);
		list.add_node(45);
		list.add_node(15);
		list.add_node(29);
		list.add_node(1);
		list.add_node(90);
	}
	list.display();
	list.deletion(1);
	list.display();
	list.deletion(5);
	list.display();
	list.deletion(90);
	list.add_node(21);
	list.add_node(13);
	list.add_node(89);
	list.add_node(77);
	list.display();
	cout<<endl;
/*	for(int i=0;i<15;i++)
	{
		list7.add_node(i);
	}
	
	list7.display();*/
	return 0;
}
