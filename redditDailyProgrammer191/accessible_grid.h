#pragma once

#include "grid.h"
#include "world.h"

class accessible_grid : public grid<bool>
{
public:
	accessible_grid(world& w);
	virtual ~accessible_grid();
};


