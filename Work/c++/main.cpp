#include<iostream>
using namespace std;

class Base
{
	public:
		int i;
		
		virtual void fun()
		{
			cout<<"Inside base fun\n";
		}
		
		void gun()
		{
			cout<<"Inside base gun";
			cout<<"i = "<<i<<"\n";
		}
};

class Derived1: public Base
{
	public:
		void fun()
		{
			cout<<"Inside derived1 fun";
		}
		
		void gun()
		{
			cout<<"Inside derived1 gun";
			cout<<"i = "<<i<<"\n";
		}
};

class Derived2: public Derived1
{
	public:
		void fun()
		{
			cout<<"Inside derived2 fun";
		}
		
		void gun()
		{
			cout<<"Inside derived2 gun";
			cout<<"i = "<<i<<"\n";
		}
};

int main()
{
	Base *bp = NULL;
	
	bp = new Derived2();
	bp -> i = 10;
	bp -> gun();
	
	Derived1 *dp = new Derived1();
	dp -> gun();
		
	return 0;
}
