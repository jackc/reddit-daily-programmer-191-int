#include "stdafx.h"

#include <stack>
#include <limits>
#include <algorithm>
#include "grid.h"
#include "accessible_grid.h"
#include "pathfinder.h"


std::vector<point> findPath(accessible_grid& ag, point start, point dest)
{
	std::vector<point> steps;

	if (!ag.getCell(start)) {
		return steps;
	}

	grid<int> costGrid(ag.width(), ag.height(), std::numeric_limits<int>::max());

	costGrid.setCell(start, 0);

	std::stack<point> workStack;
	workStack.push(start);

	while (!workStack.empty()) {
		auto cell = workStack.top();
		workStack.pop();
		auto cost = costGrid.getCell(cell);


		// ******************
		// really would be good to have "grid region/selection" which implemented STL iterator
		// ******************

		int ymin = std::max(0, cell.y - 1);
		int ymax = std::min(ag.height() - 1, cell.y + 1);
		int xmin = std::max(0, cell.x - 1);
		int xmax = std::min(ag.width() - 1, cell.x + 1);

		point p;
		for (p.y = ymin; p.y <= ymax; ++p.y)
		{
			for (p.x = xmin; p.x <= xmax; ++p.x)
			{
				auto newCost = cost + 1;
				if (ag.getCell(p) && newCost < costGrid.getCell(p))
				{
					costGrid.setCell(p, newCost);
					workStack.push(p);
				}
			}
		}
	}

	// No path found
	if (costGrid.getCell(dest) == std::numeric_limits<int>::max())
	{
		return steps;
	}

	point p = dest;
	steps.push_back(p);
	while (p != start)
	{
		point bestPoint;
		auto bestCost = std::numeric_limits<int>::max();

		int ymin = std::max(0, p.y - 1);
		int ymax = std::min(ag.height() - 1, p.y + 1);
		int xmin = std::max(0, p.x - 1);
		int xmax = std::min(ag.width() - 1, p.x + 1);

		point tp;
		for (tp.y = ymin; tp.y <= ymax; ++tp.y)
		{
			for (tp.x = xmin; tp.x <= xmax; ++tp.x)
			{
				auto cost = costGrid.getCell(tp);
				if (cost < bestCost)
				{
					bestPoint = tp;
					bestCost = cost;
				}
			}
		}

		p = bestPoint;
		steps.push_back(p);
	}

	std::reverse(steps.begin(), steps.end());
	
	return steps;
}