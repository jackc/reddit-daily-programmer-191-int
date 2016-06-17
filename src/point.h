#pragma once

struct point {
	int x;
	int y;

	bool operator==(const point& rhs) const { return x == rhs.x && y == rhs.y; }
	bool operator!=(const point& rhs) const { return !(*this == rhs); }
};

