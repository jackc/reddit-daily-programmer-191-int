#include "stdafx.h"

#include "accessible_grid.h"

accessible_grid::accessible_grid(world& w) :
	grid<bool>(w.width(), w.height(), false)
{
	for (std::size_t y = 0; y < w.height(); ++y)
	{
		for (std::size_t x = 0; x < w.width(); ++x) {
			setCell(x, y, true);
		}
	}

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

accessible_grid::~accessible_grid()
{
}