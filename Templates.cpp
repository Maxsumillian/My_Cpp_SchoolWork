#include <iostream>


template <class T>
class Item {
	private:
		T value;
		
	public:
		Item(T n): value (n){}
		
		T getValue(){return value;}
		
		
		void displayValue(){
			std::cout<<value;
		}
};















template <typename T>
T add(T x, T y)
{
	return x + y;
}

template <typename T, typename U>
bool compare(T x, U y)
{
	return x > y;
}



//int add(int x, int y){
//	return x + y;
//};
//int add(float x, float y){
//	return x + y;
//};
//std::string add(std::string x, std::string y){
//	return x + y;
//};

int main(){
	std::string first="kim", last="Mosc";
	int a = 5, b = 10;
	float x = 2.8, y = 3.7;
	std::cout<<"\nInts: "<<add(a,b); 
	std::cout<<"\nFloats: "<<add(x,y); 
	std::cout<<"\nString: "<<add(first,last); 
	
};


