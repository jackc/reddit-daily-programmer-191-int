#pragma once
#include <vector>

struct point {
	std::size_t x;
	std::size_t y;
};

template <typename ValT>
class grid
{
public:
	grid(std::size_t width, std::size_t height, ValT defaultVal);
	virtual ~grid();

	std::size_t width();
	std::size_t height();
	ValT defaultVal();
	ValT getCell(std::size_t x, std::size_t y);
	void setCell(std::size_t x, std::size_t y, ValT value);
private:
	bool inBounds(std::size_t x, std::size_t y);

	std::size_t mWidth;
	std::size_t mHeight;
	ValT mDefaultVal;
	std::vector<ValT> cells;
	std::size_t coordToIdx(std::size_t x, std::size_t y);
};

template <typename ValT>
grid<ValT>::grid(std::size_t width, std::size_t height, ValT defaultVal) :
	mWidth(width),
	mHeight(height),
	mDefaultVal(defaultVal),
	cells(width*height, defaultVal)
{
}

template <typename ValT>
grid<ValT>::~grid()
{
}

template <typename ValT>
std::size_t grid<ValT>::width()
{
	return mWidth;
}

template <typename ValT>
std::size_t grid<ValT>::height()
{
	return mHeight;
}

template <typename ValT>
ValT grid<ValT>::defaultVal()
{
	return mDefaultVal;
}

template <typename ValT>
ValT grid<ValT>::getCell(std::size_t x, std::size_t y)
{
	if (inBounds(x, y)) {
		return cells[coordToIdx(x, y)];
	}
	else {
		return defaultVal();
	}
}

template <typename ValT>
void grid<ValT>::setCell(std::size_t x, std::size_t y, ValT value)
{
	if (inBounds(x, y))
	{
		cells[coordToIdx(x, y)] = value;
	}
}

template <typename ValT>
std::size_t grid<ValT>::coordToIdx(std::size_t x, std::size_t y)
{
	return y * width() + x;
}

template <typename ValT>
bool grid<ValT>::inBounds(std::size_t x, std::size_t y)
{
	return x < width() && y < height();
}