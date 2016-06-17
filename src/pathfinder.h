#pragma once
#include <vector>
#include "grid.h"
#include "world.h"

std::vector<point> findPath(accessible_grid& ag, point start, point dest);
