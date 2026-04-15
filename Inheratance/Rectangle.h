#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
	// private vs protected
	// private is private only the class can accses them 
	//protectd allows inheritance 
	private:
		int lenght;
		int width;
		
	public:
		void setData(int lenght, int width);
		void show();
		int compute();
	
};

#endif
