#pragma once
#include <vector>
#include "grid.h"
#include "world.h"

enum direction { Up, UpRight, Right, DownRight, Down, DownLeft, Left, UpLeft };
using path = std::vector<direction>;

path findPath(grid<dim, bool>& w, point<dim> start, point<dim> dest);
