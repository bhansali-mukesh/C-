#include<iostream>
using namespace std;

//FORMULATING FORMULA FOR A GIVEN SEQUENCE.
//@ AUTHOR MUKESH KUMAR BHANSALI

void Invalid_Input()
{
                cout << "YOUR INPUT IS NOT SEEMING GOOD.TRY IT AGAIN." << endl;
                exit(1);
}

int main()
{
	int first, second, third;
	int x2, x, constant, delta_of_delta, delta_one, delta_two, first_x, total_variants, next, next_x;
	x2 = x = constant = 0;

	cout << "ENTER 3 CONSECUTIVE NUMBERS IN YOUR SEQUENCE." <<endl;

	if(scanf("%d %d %d",&first,&second,&third) != 3)Invalid_Input();
	
	delta_one = second - first;
	delta_two = third - second;
	delta_of_delta = delta_two - delta_one;

	if( delta_of_delta % 2 == 0 )
	{
		x2 = (delta_of_delta/2);
		if(delta_of_delta != 0)
		{
			total_variants = delta_one % delta_of_delta;
			x = total_variants - x2;
			first_x = delta_one / delta_of_delta;
		}
		else
		{
			x = delta_one;
			first_x = 0;
		}
		constant  = first - ( x2 * first_x * first_x + x * first_x ) ;
		next_x = first_x + 3;		
		next = x2 * next_x * next_x + x * next_x + constant;

		constant  = first - ( x2 * first_x * first_x + x * first_x ) ;
		cout<<"---------------------------------------------------------"<<endl;
		cout<<"--------------------YOUR FORMULA IS----------------------"<<endl;
		cout << "\t\t" << x2 << "x2\t+\t" << x << "x\t+\t" << constant << endl;
		cout<<"---------------------------------------------------------\n"<<endl;	
		cout << "And The First Value Of x In This Series Is\t"<< first_x <<endl;
		cout << "& The Next Number In This Series Will Be\t";
		
		cout << next << "\t Where x = " << next_x << endl;	
		cout<<"---------------------------------------------------------\n"<<endl;	
	}
	else
	{
		cout<<"----------------------------------------------------------------------------------"<<endl;	
		cout << "I WAS NOT PROGRAMMED TO FIND FORMULA FOR SUCH TYPE OF SEQUENCES. GOING, BYE....." <<endl;
		cout<<"----------------------------------------------------------------------------------\n"<<endl;	
	}
	return 0;
}

