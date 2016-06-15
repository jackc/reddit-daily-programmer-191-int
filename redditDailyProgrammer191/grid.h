#pragma once
#include <vector>

struct point {
	int x;
	int y;
};

template <typename ValT>
class grid
{
public:
	grid(int width, int height, ValT defaultVal);
	virtual ~grid();

	int width();
	int height();
	ValT getCell(int x, int y);
	ValT getCell(int x, int y, ValT outOfBoundsValue);
	void setCell(int x, int y, ValT value);

	bool inBounds(int x, int y);
private:
	int mWidth;
	int mHeight;
	ValT mDefaultVal;
	std::vector<ValT> cells;
	int coordToIdx(int x, int y);
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
ValT grid<ValT>::getCell(int x, int y)
{
	return cells[coordToIdx(x, y)];
}

template <typename ValT>
ValT grid<ValT>::getCell(int x, int y, ValT outOfBoundsValue)
{
	if (inBounds(x, y)) {
		return getCell(x, y);
	}
	else {
		return outOfBoundsValue;
	}
}

template <typename ValT>
void grid<ValT>::setCell(int x, int y, ValT value)
{
	cells[coordToIdx(x, y)] = value;
}

template <typename ValT>
int grid<ValT>::coordToIdx(int x, int y)
{
	return y * width() + x;
}

template <typename ValT>
bool grid<ValT>::inBounds(int x, int y)
{
	return 0 <= x && x < width() && 0 <= y && y < height();
}