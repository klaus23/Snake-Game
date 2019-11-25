#include "Water.h"



sf::Vector2f Water::GetWaterPosition()
{
	return position;
}

Water::Water(sf::Vector2f pos_ ):
	position(pos_)
{
	shape.setFillColor(sf::Color::Blue);
	shape.setSize(sf::Vector2f(800,600));


}

void Water::Waterdrop()
{
	position.y += 0.799;
	shape.setPosition(position);
}

void Water::Render(sf::RenderWindow & window)
{
	window.draw(shape);
}


Water::~Water()
{
}
