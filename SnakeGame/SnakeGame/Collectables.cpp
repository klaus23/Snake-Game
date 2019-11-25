#include "Collectables.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>


Collectables::Collectables()
{
	acollectable.setRadius(5);
	acollectable.setFillColor(sf::Color::Red);
}

void Collectables::Render(sf::RenderWindow &window)
{
	if (alive)
	{
		acollectable.setPosition(position);
		window.draw(acollectable);
	}
		
}

void Collectables::Collision_test()
{
}

bool Collectables::isAlive()
{
	return alive;
}

void Collectables::spawn(sf::Vector2f position_)
{
	foodvalue= rand() % 5+1;// set random value
	position = position_;// set position
	alive = true;
}

sf::Vector2f Collectables::getPosition()
{
	return position;
}

int Collectables::GetFoodValue()
{

	return foodvalue;
}


Collectables::~Collectables()
{
}
