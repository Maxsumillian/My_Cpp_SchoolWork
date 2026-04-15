#ifndef BLOCK_H
#define BLOCK_H

#include "Rectangle.h"

class Block : public Rectangle
{
	private:
		int height;
	public:
		void setData(int lenght, int width, int height);
		void show();
		int compute();
};

#endif
