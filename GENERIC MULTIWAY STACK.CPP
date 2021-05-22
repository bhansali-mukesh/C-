#include<iostream>
using namespace std;

template<class M>
class stack
{
	M* st;
	int length,top,bottom;
public :
	stack(int m=10)
	{
		length=m;
		st= new M[m];
		top=0;
		bottom=length;
	}
	
   void	push(M m=0)
 	{
		if(top==length)
		{
			cout<<"STACK OVERFLOWING. CANN'T ADD MORE ELEMENTS.."<<endl;
			return;
		}
		st[top++]=m;
	}
    void insert(M m=0)
	{
		if(top==bottom)
		{
			cout<<"STACK OVERFLOWING. CANN'T ADD MORE ELEMENTS.."<<endl;
			return;
		}
		st[--bottom]=m;
	}

   	
   M pop()	
	{
		M p;
		if(top==0)
		{
			cout<<"STACK EMPTY.. CANN'T POP ANYMORE";
			return 0;			
		}
		p=st[--top];
		return p;
	}
   M put_off()	
	{
		M p;
		if(bottom==length)
		{
			cout<<"STACK EMPTY.. CANN'T POP ANYMORE"<<endl;
			return 0;			
		}
		p=st[bottom++];
		return p;
	}

   
   void display()
	{
		for(int i=top-1;i>=0;i--)
		{
			cout<<st[i]<<endl;
		}
	}	
   void out()
	{
		for(int i=bottom;i<length;i++)
		{
			cout<<st[i]<<endl;
		}
	}	

};


int main()
{
	cout<<endl;
	cout <<"I AM HERE GUYS."<<endl;
	cout<<endl;
	stack <char>one;
	one.push(77);
	one.push(57);
	one.push(65);
	one.display();
	cout<<endl;
	cout<<one.pop()<<"  IS GOING TO BE DELETED"<<endl;
	cout<<endl;	
	one.display();
	cout<<endl;
	cout <<"I AM HERE GUYS."<<endl;
	cout<<endl;
	one.insert(75);
	one.insert(87);
	one.insert('S');
	one.insert(50);
	one.out();
	cout<<endl;
	cout<<one.put_off()<<"  IS GOING TO BE DELETED"<<endl;
	cout<<endl;	
	//one.put_off();
	//one.put_off();
	//one.put_off();
	//one.put_off();
	one.out();
	cout<<endl;
	return 0;
}
