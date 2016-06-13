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
	grid(std::size_t width, std::size_t height, ValT emptyVal);
	virtual ~grid();

	std::size_t width();
	std::size_t height();
	virtual ValT getCell(std::size_t x, std::size_t y);
	virtual void setCell(std::size_t x, std::size_t y, ValT value);

private:
	std::size_t mWidth;
	std::size_t mHeight;
	std::vector<ValT> cells;
	std::size_t coordToIdx(std::size_t x, std::size_t y);
};

template <typename ValT>
grid<ValT>::grid(std::size_t width, std::size_t height, ValT emptyVal) :
	mWidth(width),
	mHeight(height),
	cells(width*height, emptyVal)
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
ValT grid<ValT>::getCell(std::size_t x, std::size_t y)
{
	return cells[coordToIdx(x, y)];
}

template <typename ValT>
void grid<ValT>::setCell(std::size_t x, std::size_t y, ValT value)
{
	cells[coordToIdx(x, y)] = value;
}

template <typename ValT>
std::size_t grid<ValT>::coordToIdx(std::size_t x, std::size_t y)
{
	return y * width() + x;
}