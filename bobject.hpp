#ifndef LIERO_BOBJECT_HPP
#define LIERO_BOBJECT_HPP

#include "math.hpp"
#include "objectList.hpp"

struct Game;

struct BObject : ObjectListBase
{
	void process(Game& game);
	
	fixed x, y;
	fixed velX, velY;
	int colour;
};

//void createBObject(fixed x, fixed y, fixed velX, fixed velY);

#endif // LIERO_BOBJECT_HPP
