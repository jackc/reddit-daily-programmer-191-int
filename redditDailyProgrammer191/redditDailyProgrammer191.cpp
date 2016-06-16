// redditDailyProgrammer191.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <random>
#include "grid.h"
#include "accessible_grid.h"
#include "world.h"
#include "pathfinder.h"

void renderWorld(world& w);
void randomizeWorld(world& w, float asteroidsFraction, float gravityWellsFraction);

int main()
{
	world w(10, 10, '.');
	randomizeWorld(w, 0.2f, 0.01f);

	std::cout << "Map" << '\n';
	renderWorld(w);

	std::cout << '\n';
	std::cout << "Accessability Grid" << '\n';
	accessible_grid ag(w);
	for (int y = 0; y < w.height(); ++y)
	{
		for (int x = 0; x < w.width(); ++x) {
			std::cout << (ag.getCell({ x, y }) ? ' ' : 'X');
		}
		std::cout << '\n';
	}

	std::cout << '\n';

	auto path = findPath(ag, { 0,0 }, { 9,9 });

	if (path.empty()) {
		std::cout << "No path found" << '\n';
	}
	else {
		std::cout << "Path" << '\n';

		for (auto& p : path) {
			w.setCell(p, '#');
		}
	}

	renderWorld(w);

    return 0;
}

void renderWorld(world& w)
{
	for(int y = 0; y < w.height(); ++y)
	{
		for (int x = 0; x < w.width(); ++x) {
			std::cout << w.getCell({ x, y });
		}
		std::cout << '\n';
	}
}

void randomizeWorld(world& w, float asteroidsFraction, float gravityWellsFraction)
{
	std::size_t cellCount = w.width() * w.height();
	std::size_t asteroidsCount = static_cast<std::size_t>(static_cast<float>(cellCount) * asteroidsFraction);
	std::size_t gravityWellsCount = static_cast<std::size_t>(static_cast<float>(cellCount) * gravityWellsFraction);

	std::random_device rndDevice;
	std::mt19937 eng(rndDevice());
	std::uniform_int_distribution<int> widthDist(0, w.width()-1);
	std::uniform_int_distribution<int> heightDist(0, w.height() - 1);

	for (std::size_t i = 0; i < asteroidsCount; ++i)
	{
		w.setCell({ widthDist(eng), heightDist(eng) }, 'A');
	}

	for (std::size_t i = 0; i < gravityWellsCount; ++i)
	{
		w.setCell({ widthDist(eng), heightDist(eng) }, 'G');
	}
}
