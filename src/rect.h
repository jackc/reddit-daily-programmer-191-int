#pragma once

#include "point.h"

struct rect
{
	int left;
	int top;
	int right;
	int bottom;

	rect(int l, int t, int r, int b);
};
