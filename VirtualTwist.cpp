#include <iostream>


class Parent
{
	private:
		int num1;
	public:
		Parent(int x)
		{
			num1 = x;
		}
		
		virtual int getNum(){return num1;}
		
		virtual void twistIt()
		{
			num1 *= 3;
		}
		
		int getTwist()
		{
			twistIt();
			return getNum();	
		}
};

class Child : public Parent
{
	private:
		int num2;
	public:
		Child(int x = 5)
		:Parent(2)// satisfy the parent first because we dont have default constructor
		{
			num2 = x;
		}
		
		int getNum(){return num2;}
		
		void twistIt()
		{
			num2 *= 10;
		}
		
};



int main()
{
	Parent Sandrine(2);
	
	std::cout<<"\nParent num1: "<<Sandrine.getNum(); // prints 2
	std::cout<<"\nParent num1: "<<Sandrine.getTwist(); // prints 2 * 3 || 6
	

	Child Maximillian;
	
//	std::cout<<"\nChild num2: "<<Parent::Maximillian.getNum(); // wrong syntax
	std::cout<<"\nChild num2: "<<Maximillian.Parent::getNum(); // using the parent scope operator to get num1
	
	std::cout<<"\nChild num2: "<<Maximillian.getNum(); // 5
	std::cout<<"\nChild num2: "<<Maximillian.getTwist(); // retunrs 6 // child doesnt have a getTwist but it calls the parents twist beacuse its not virtual
	// in order to use it since we are caling from the parent we need to make all the functions it uses virtual
	 
	
};
