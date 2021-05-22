#include<iostream>
using namespace std;

namespace d
{
class node
{
	int info;
	node *next;
public:
	node(int m = 0 )	 	
	{
		info = m;
		next = NULL;
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
	
	node* getstart()
	{
		return start;
	}

	void setstart(node * m)
	{
		start = m;
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
			return;
		}			

 		while(search->getnext() != NULL && search->getnext()->getdata() < temp->getdata())
		{
			search = search->getnext();
		}
		temp->setnext(search->getnext());
		search->setnext(temp);
	}

	void deletion(int m )
	{
		if(start==NULL)
		{
			cout<<"OOPS!  THERE IS NO NODE IN THIS LIST."<<endl;
			cout<<endl;
			return;
		}		

		node* search=start;
		if(start->getdata()==m)
		{
			cout<<"\t"<<m<<"  DELETED"<<endl;
			start=start->getnext();
			delete search;
			cout<<endl;
			return;
		}

		while(search->getnext()!=NULL)
		{
			if(search->getnext()->getdata()==m)
			{
				node* del=search->getnext();
				search->setnext(search->getnext()->getnext());
				cout<<"\t"<<m<<" DELETED"<<endl;
				delete del;
				cout<<endl;
				return;
			}
			search = search->getnext();
		}
		
			cout<<"NODE NOT FOUND"<<endl;
			cout<<endl;
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
		cout<<endl;
	}

	void merge(node* one,node* two)
	{
		if(one != NULL && two != NULL)
		{
			node* some;
			if(one->getdata() < two->getdata())
			{
				some = new node(one->getdata());
				one = one->getnext();
			}
			else
			{
				some = new node(two->getdata());
				two = two->getnext();
			}
			start = some;
			while(one != NULL && two != NULL)
			{
				if(one->getdata() < two->getdata())
				{
					some->setnext(new node(one->getdata()));
					one = one->getnext();
				}
				else
				{
					some->setnext(new node(two->getdata()));
					two = two->getnext();
				}	
				some = some->getnext();
			}

			if(one == NULL)
			{
				while(two != NULL)
				{
					some->setnext(new node(two->getdata()));
					some = some->getnext();
					two = two->getnext();
				}
			}
			else
			{
					while(one != NULL)
					{
						some->setnext(new node(one->getdata()));
						some = some->getnext();
						one = one->getnext();
					}	
			}
			}
		
		}

};
};
using namespace d;

int main()
{
	linklist list;
	linklist list7;
	linklist list15;
	int option,data;
	do
	{
		cout<<"1.ADD RECORD.\n2.DELETE RECORD\n3.DISPLAY DATABASE.\n\n4.ADD IN SECOND LIST\n5.DELETE FROM SECOND.\n6.DISPLAY SECOND DATABASE\n\n7.MERGE BOTH DATABASES.\n8.DISPLAY MERGED LIST.\n9.EXIT\n"<<endl;
		cout<<"ENTER THE CHOICE FROM THE ABOVE OPTION."<<endl;
		cin>>option;
		switch(option)
		{
		case 1:			
				cout<<"ENTER A DATA VALUE"<<endl;
				cin>>data;
				list.add_node(data);
				cout<<endl;
				break;
		case 2:
				cout<<"ENTER A DATA VALUE"<<endl;
				cin>>data;
				list.deletion(data);
				break;
		case 3:		
				
				list.display();
				cout<<endl;
				break;
		case 4:		
				cout<<"ENTER A DATA VALUE"<<endl;
				cin>>data;
				list7.add_node(data);
				cout<<endl;
				break;
		case 5:		
				cout<<"ENTER A DATA VALUE"<<endl;
				cin>>data;
				list7.deletion(data);
				break;
		case 6:
				list7.display();
				break;
		case 7:
				list15.merge(list.getstart(),list7.getstart());
				break;
		case 8:
				cout<<"MERGED LIST IS LIKE THIS:"<<endl;
				list15.display();
				cout<<endl;
				break;
		case 9:
				break;
		default:
				cout<<"BAD CHOICE__TRY AGAIN."<<endl;
		}
	}while(option != 9);
	cout<<endl;
	char a;cin>>a;
	return 0;
}
//};

