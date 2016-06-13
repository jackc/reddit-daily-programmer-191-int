// redditDailyProgrammer191.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <random>
#include "grid.h"
#include "accessible_grid.h"
#include "world.h"

void renderWorld(world& w);
void randomizeWorld(world& w, float asteroidsFraction, float gravityWellsFraction);

int main()
{
	world w(10, 10, '.');
	randomizeWorld(w, 0.3f, 0.1f);
	renderWorld(w);

	std::cout << '\n';

	accessible_grid ag(w);
	for (std::size_t y = 0; y < w.height(); ++y)
	{
		for (std::size_t x = 0; x < w.width(); ++x) {
			std::cout << (ag.is_accessible(x, y) ? ' ' : 'X');
		}
		std::cout << '\n';
	}


    return 0;
}

void renderWorld(world& w)
{
	for(dim y = 0; y < w.height(); ++y)
	{
		for (dim x = 0; x < w.width(); ++x) {
			std::cout << w.getCell(x, y);
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
	std::uniform_int_distribution<dim> widthDist(0, w.width()-1);
	std::uniform_int_distribution<dim> heightDist(0, w.height() - 1);

	for (std::size_t i = 0; i < asteroidsCount; ++i)
	{
		w.setCell(widthDist(eng), heightDist(eng), 'A');
	}

	for (std::size_t i = 0; i < gravityWellsCount; ++i)
	{
		w.setCell(widthDist(eng), heightDist(eng), 'G');
	}
}
