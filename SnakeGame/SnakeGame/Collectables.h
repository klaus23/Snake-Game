#pragma once
#include <SFML/Graphics.hpp>
class Collectables
{
private:
	sf::Vector2f position;
	int foodvalue;
	sf::CircleShape acollectable;

public:
	Collectables();
	void Render(sf::RenderWindow &window);
	void Collision_test();
	bool alive = false;
	bool isAlive();
	void spawn(sf::Vector2f position);
	sf::Vector2f getPosition();
	int GetFoodValue();
	~Collectables();
};

