#pragma once
#include <SFML/Graphics.hpp>
class Water
{private:
	sf::Vector2f position;
	sf::RectangleShape shape;
public:
	sf::Vector2f GetWaterPosition();
	Water(sf::Vector2f position );
	void Waterdrop();
	void Render(sf::RenderWindow &window);
	~Water();
};

