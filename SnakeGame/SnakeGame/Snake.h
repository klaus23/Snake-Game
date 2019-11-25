#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<list>
#include "Collectables.h"
#include "Water.h"
enum class Direction
{
	eNorth,
	eEast,
	eSouth,
	eWest
};

class Snake
{
private:
	int TailGrowth=0;
	int score = 0;
	std::list<sf::Vector2f> snakeSegments;
	sf::Vector2f position;
	Direction e;
	sf::CircleShape circle;
	const float head_size = 20;
	Collectables c;
	int breath = 201;
	bool isAlive = true;
public:
	Snake(sf::Vector2f position);
	bool CheckIfAboveWater(Water water); //pass the water in the function
	int GetBreath();
	int ReturnScore();
	bool CheckSelfCollision();
	bool CollectableCollision(Collectables c[5]);
	void render(sf::RenderWindow &window);
	void update();
	void GameOver(sf::RenderWindow&argumentwindow);

	~Snake();
};

