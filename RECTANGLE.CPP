#include<iostream>
using namespace std;

class triangle
{
	float base, height;
	public:
	triangle(float m = 0, float k = 0)
	{
		base = m;
		height = k;
	}
	
	float getbase(){return base;}
	float geth(){return height;}

	void takesides(float m, float n)
	{
		base = m;
		height = n;
	}
	
	virtual float area()
	{
		return ( base * height / 2 );
	}
};

class square:public triangle
{
	public:
		square(float m = 0 , float k = 0 ):triangle(m,k)
		{
			
		}
		
		float are()
		{
			return ( area() * 2 );
		}
};

class rectangle:public triangle
{
	public:
		rectangle(float m = 0, float k = 0):triangle(m,k)
		{
			
		}
		
		rectangle operator + (square & sq)
		{
			rectangle local;
			local.takesides(sq.getbase() + this->getbase() , sq.geth() + this->geth());
			return local;
		}
		
		rectangle operator + (rectangle &rec)
		{
			rectangle local;
			local.takesides(rec.getbase() + this->getbase() , rec.geth() + this->geth());
			return local;
		}

		float are()
		{
			return ( area() * 2 );
		}
};

int main()
{
	triangle Tfirst(10,6.5);
	square Sfirst(10,10);
	rectangle Rfirst(10,6.5);
	rectangle RRfirst(10,3.5);
	rectangle rockrec;

	rockrec = Rfirst + RRfirst;

	cout<<Tfirst.area()<<endl;
	cout<<Sfirst.are()<<endl;
	cout<<Rfirst.are()<<endl;

	cout<<rockrec.are()<<endl;

	rockrec = rockrec + Sfirst;
	cout<<rockrec.are()<<endl;

	return 0;
}

