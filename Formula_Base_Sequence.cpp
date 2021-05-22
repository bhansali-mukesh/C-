#include<iostream>
#include<string>
using namespace std;

//@AUTHOR MUKESH KUMAR BHANSALI.
//A GENERIC PROGRAM TO GENERATE SEQUENCE ACCORDING TO FORMULA.

void Invalid_Input()
{
                cout << "YOUR INPUT IS NOT SEEMING GOOD.TRY IT AGAIN." << endl;
                exit(1);
}


int main()
{
	int power;
	float x2_variant,variable,constant_in_formula;
	int Upper_Bound, Lower_Bound;
	long sum = 0, x2 = 1;
	
	cout << "Enter A Formula.(eg. for 4x2 + 3x + 15 input should be 4 2 3 15)" <<endl;
	if(scanf("%f %d %f %f",&x2_variant,&power,&variable,&constant_in_formula) != 4)Invalid_Input();
	
	cout <<"YOUR FORMULA IS:\n"<<endl;
	cout <<"\t\t"<<x2_variant<<"x"<< power << "\t+\t" << variable <<"x\t+\t"<<constant_in_formula <<"\n"<<endl;

	cout << "Enter the range from where to where 'x' should vary." <<endl;	
	
	cout <<"Lower Bound ?" << endl;
	if(scanf("%d",&Lower_Bound) != 1)Invalid_Input();
	cout <<"Upper Bound ?" << endl;
        if(scanf("%d",&Upper_Bound) != 1)Invalid_Input();	

	cout << "\n     x = "<<Lower_Bound<<"   "<<Lower_Bound + 1<<"   "<< Lower_Bound + 2 <<"   "<<Lower_Bound + 3<<"..........\n\t";
	for(int x = Lower_Bound; x <= Upper_Bound; x++)
	{
		sum = 0;
		x2 = 1;
		for(int j = 1; j <= power; j++)
		{
			x2 *= x;
		}	
		sum = x2_variant * x2 + variable * x + constant_in_formula;
		cout << sum <<"  ";
	}
	
	cout << "\n"<<endl;
	return 0;
}
