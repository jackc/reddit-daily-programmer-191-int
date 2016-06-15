#include "stdafx.h"

#include <algorithm>
#include "accessible_grid.h"

accessible_grid::accessible_grid(world& w) :
	grid<bool>(w.width(), w.height(), true)
{
	for (int y = 0; y < w.height(); ++y)
	{
		for (int x = 0; x < w.width(); ++x)
		{
			auto cell = w.getCell({x, y});
			switch (cell) {
			case 'A':
				setCell({ x, y }, false);
				break;
			case 'G':
				int ymin = std::max(0, y - 1);
				int ymax = std::min(w.height() - 1, y + 1);
				int xmin = std::max(0, x - 1);
				int xmax = std::min(w.width() - 1, x + 1);

				point p;
				for (p.y = ymin; p.y <= ymax; ++p.y)
				{
					for (p.x = xmin; p.x <= xmax; ++p.x)
					{
						setCell(p, false);
					}
				}
				break;
			}
		}
	}
}

accessible_grid::~accessible_grid()
{
}