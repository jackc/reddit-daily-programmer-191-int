#pragma once

#include "grid.h"
#include "world.h"

class accessible_grid
{
public:
	accessible_grid(world& w);
	bool is_accessible(std::size_t x, std::size_t y);
private:
	grid<bool> grid;

	void setCell(std::size_t x, std::size_t y, bool value);
	bool inBounds(std::size_t x, std::size_t y);
};


