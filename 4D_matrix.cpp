#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

bool Validating_Number(const string& candidate)
{
	for(int i = 0; i < candidate.length(); i++)
	{
		if(!std::isdigit(candidate[i]))
			{return false;}
	}
	return true;			

}
int main()
{
	int Validated_Number,Validated_Choice = -99;
	do
	{
		//clrscr();
		string number,choice;
		cout<<"\n\t\tTHIS IS A PROGRAM ABLE TO GENERATE MAGIC SQUARES.\n"<<endl;
		cout<<"ENTER THE TOTAL FOR EACH STRIGHT LINE OF MATRIX."<<endl;
		cin >> number;
		if(Validating_Number(number))
		{
			Validated_Number = atoi(number.c_str());
			cout<<"\nWE HAVE THE 5 TYPES OF MATRICES AVAILABLE TO BE PRINT.ENTER CHOICE ACCORDINGLY."<<endl;
			cout<<"1.\t1X1\n3.\t3X3\n5.\t5X5\n7.\t7X7\n9.\t9X9\n0.\tEXIT."<<endl;
			cin >> choice;
			if(Validating_Number(choice))
			{
				Validated_Choice = atoi(choice.c_str());
				float middle = Validated_Number/(float)Validated_Choice;
				
				switch(Validated_Choice)
				{
					case 1:
					case 3:
					case 5:
					case 7:
							{
								float a7X7[7][7] = 
								{
									{middle + 17, middle + 19, middle - 26, middle -18, middle + 20, middle - 27, middle + 15},
									{middle - 21, middle + 7, middle + 9, middle - 8, middle - 13, middle + 5, middle + 21},
									{middle + 28, middle - 10, middle + 3, middle - 4, middle + 1, middle + 10, middle -28},
									{middle - 16, middle - 6, middle - 2, middle, middle + 2,middle + 26, middle + 16}, 
									{middle - 22, middle +14 , middle - 1, middle + 4, middle - 3, middle -14, middle + 22},
									{middle + 29, middle - 5, middle - 9, middle + 8, middle + 13, middle - 7, middle -29},
									{middle  - 15, middle - 19, middle + 26, middle + 18, middle - 20, middle + 27, middle - 17}
								};
								int dimension = (7 - Validated_Choice)/2;
								cout<<"\n\n\t";
								for(int i = dimension; i < dimension + Validated_Choice; i++ )
								{	
									for(int j = dimension; j < dimension + Validated_Choice; j++)
										{cout<<a7X7[i][j]<<"\t";}
										cout<<" | "<<Validated_Number<<"\n\n\t";
								}
								
							}
					case 9:	
							if(Validated_Choice == 9)
							{
								float middles[3][3] = {middle + 3, middle - 4, middle + 1, middle - 2, middle, middle + 2, middle - 1, middle + 4, middle - 3};
								float Logic_Array[3][3] = { 30, -40, 10, -20, 0, 20, -10, 40, -30};
								float array[3][3][3][3];
								for(int i = 0; i < 3; i++)
								{
									for(int j = 0; j < 3; j++)
									{
										for(int k = 0; k < 3; k++)
										{		
											for(int l = 0; l < 3; l++)	
											{
												array[i][j][k][l] = middles[k][l] + Logic_Array[i][j];
											}
										}
									}
								}
								cout<<"\t";
								for(int i = 0; i < 3; i++)
								{
									for(int j = 0; j < 3; j++)
									{
										for(int k = 0; k < 3; k++)
										{		
											for(int l = 0; l < 3; l++)	
											{
												cout<<array[i][k][j][l]<<"\t";
											}
										}
										cout<<" | "<<Validated_Number<<"\n\n\t";									}
								}
								cout<<endl;
											
							}
								if(Validated_Choice != 9){cout<<"\b\b\b\b\b\b\b\b";}
								for(int i = 0; i < Validated_Choice + 2; i++)
									{cout<<"________";}
								cout<<"__"<<endl;
								for(int i = 0; i < Validated_Choice + 2; i++)
								{
									cout<<Validated_Number<<"\t";
								}
								cout<<endl;
								for(int i = 0; i < Validated_Choice + 2; i++)
									{cout<<"________";}
								cout<<"__"<<endl;
								cout<<endl;
								return 0;
							return 0;
					case 0:
							return 0;	
					default:
							cout<<"YOU HAVE ENTERED A WRONG CHOICE.MATRIX NOT AVAILABLE.\n"<<endl;
							continue;
								
				}
				
			}
			else
			{
			cout<<"Not a Valid Input, Enter only Integer."<<endl;
			cin >> number;
			}	
		}
		else
		{
			cout<<"Not a Valid Input, Enter only Integer."<<endl;
			cin >> number;
		}			
	}while(Validated_Choice != 0);
	return 0;
}