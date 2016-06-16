#pragma once
#include <vector>

#include "point.h"

template <typename ValT>
class grid
{
public:
	grid(int width, int height, ValT defaultVal);
	virtual ~grid();

	int width();
	int height();
	ValT getCell(point p);
	ValT getCell(point p, ValT outOfBoundsValue);
	void setCell(point p, ValT value);

	bool inBounds(point p);
private:
	int mWidth;
	int mHeight;
	ValT mDefaultVal;
	std::vector<ValT> cells;
	std::size_t coordToIdx(point p);
};

template <typename ValT>
grid<ValT>::grid(int width, int height, ValT defaultVal) :
	mWidth(width),
	mHeight(height),
	cells(width*height, defaultVal)
{
}

template <typename ValT>
grid<ValT>::~grid()
{
}

template <typename ValT>
int grid<ValT>::width()
{
	return mWidth;
}

template <typename ValT>
int grid<ValT>::height()
{
	return mHeight;
}

template <typename ValT>
ValT grid<ValT>::getCell(point p)
{
	return cells[coordToIdx(p)];
}

template <typename ValT>
ValT grid<ValT>::getCell(point p, ValT outOfBoundsValue)
{
	if (inBounds(p)) {
		return getCell(p);
	}
	else {
		return outOfBoundsValue;
	}
}

template <typename ValT>
void grid<ValT>::setCell(point p, ValT value)
{
	cells[coordToIdx(p)] = value;
}

template <typename ValT>
std::size_t grid<ValT>::coordToIdx(point p)
{
	return p.y * width() + p.x;
}

template <typename ValT>
bool grid<ValT>::inBounds(point p)
{
	return 0 <= p.x && p.x < width() && 0 <= p.y && p.y < height();
}