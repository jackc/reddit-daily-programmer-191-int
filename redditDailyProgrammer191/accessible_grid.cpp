#include "stdafx.h"

#include "accessible_grid.h"

accessible_grid::accessible_grid(world& w) :
	grid(w.width(), w.height(), true)
{
	for (std::size_t y = 0; y < w.height(); ++y)
	{
		for (std::size_t x = 0; x < w.width(); ++x) {
			auto cell = w.getCell(x, y);
			switch (cell) {
			case 'A':
				setCell(x, y, false);
				break;
			case 'G':
				setCell(x - 1, y - 1, false);
				setCell(x, y - 1, false);
				setCell(x + 1, y - 1, false);
				setCell(x - 1, y, false);
				setCell(x, y, false);
				setCell(x + 1, y, false);
				setCell(x - 1, y + 1, false);
				setCell(x, y + 1, false);
				setCell(x + 1, y + 1, false);
				break;
			}
		}
	}
}

bool accessible_grid::is_accessible(std::size_t x, std::size_t y)
{
	return inBounds(x, y) && grid.getCell(x, y);
}

void accessible_grid::setCell(std::size_t x, std::size_t y, bool value)
{
	if (inBounds(x, y))
	{
		grid.setCell(x, y, value);
	}
}

bool accessible_grid::inBounds(std::size_t x, std::size_t y)
{
	return x < grid.width() && y < grid.height();
}