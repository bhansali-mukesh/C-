#include<iostream>
using namespace std;

class stack
{
	int* st;
	int length,top;
public :
	stack(int m=10)
	{
		length=m;
		st= new int[m];
		top=0;
	}
	
   void	push(int m=0)
	{
		if(top==length)
		{
			cout<<"STACK OVERFLOWING. CANN'T ADD MORE ELEMENTS.."<<endl;
			return;
		}
		st[top++]=m;
	}

   int pop()	
	{
		int p;
		if(top==0)
		{
			cout<<"STACK EMPTY.. CANN'T POP ANYMORE"<<endl;
			return 0;			
		}
		p=st[--top];
		return p;
	}

   void display()
	{
		for(int i=top-1;i>=0;i--)
		{
			cout<<st[i]<<endl;
		}
	}	

};


int main()
{
	char postfix[10];
	stack one;
	cout<<"ENTER A POSTFIX EXPRESSION."<<endl;
	cin>>postfix;
	cout<<endl;
	int index=0;
	while(postfix[index]!='\0')
	{
	if(postfix[index]<48||postfix[index]>57)
	{
	int first,second;
	first=one.pop();
	second=one.pop();
	switch(postfix[index])
	{
		case '+':
			one.push(second+first);
			break;

		case'-':
			one.push(second-first);
			break;
		case'*':
			one.push(second*first);
			break;
		case'/':
			one.push(second/first);
			break;
		default:
			cout<<"INVALID EXPRESSION"<<endl;
			cout<<endl;
	}
	}
	else
	one.push(postfix[index]-48);

	index++;
	}
	
	cout<<one.pop()<<endl;

/*	cout <<"I AM HERE  GUYS."<<endl;
	cout<<endl;
	one.push(15);
	one.push(587);
	one.push();
	one.display();
	cout<<endl;
	cout<<one.pop()<<"  IS GOTNG TO BE DELETED"<<endl;
	cout<<endl;	
	one.display();
	cout<<endl;*/
	char a;cin>>a;
	return 0;
}
