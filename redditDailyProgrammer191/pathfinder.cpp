#include "stdafx.h"

#include <stack>
#include <limits>
#include "grid.h"
#include "accessible_grid.h"
#include "pathfinder.h"


path findPath(accessible_grid& ag, point start, point dest)
{
	path p;

	grid<int> costGrid(ag.width(), ag.height(), std::numeric_limits<int>::max());

	costGrid.setCell(start.x, start.y, 0);

	std::stack<point> workStack;
	workStack.push(start);

	while (!workStack.empty()) {
		auto cell = workStack.top();
		workStack.pop();

		
		
	}

	

	return p;
}