#pragma once
#include <vector>
#include "grid.h"
#include "world.h"

enum direction { Up, UpRight, Right, DownRight, Down, DownLeft, Left, UpLeft };
using path = std::vector<direction>;

path findPath(accessible_grid& ag, point start, point dest);
