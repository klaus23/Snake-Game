#include "Snake.h"
#include <iostream>


Snake::Snake(sf::Vector2f pos_) :
	position(10,10),
	circle(10)
{
	circle.setFillColor(sf::Color::Magenta);
	//snakeSegments.push_front(position);
	sf::Vector2f pos = position;
	for (size_t i = 0; i < 1; i++) //how many circles it spawn on the snake body
	{
		snakeSegments.push_back(pos);
		pos.x -= 100;
	}

}


bool Snake::CheckIfAboveWater(Water water)
{
	//if (water.GetWaterPosition().y == 600)
	//{
	  // isAlive = false;
	//}
	
	if (position.y < water.GetWaterPosition().y)//snake head above the water position
	{
		breath = 201;
	}
	return false;
}

int Snake::GetBreath()
{
	
	return breath;
}

int Snake::ReturnScore()
{

	return score;
}

bool Snake::CheckSelfCollision()
{
	bool first = true;
	for (std::list<sf::Vector2f>::iterator it=snakeSegments.begin(); it !=snakeSegments.end(); it++)
	{
		if (first)
		{
			first = false;// so that it skips the head in the linked list
			continue;
		}
		if (snakeSegments.front().x == it->x&&snakeSegments.front().y == it->y)
			//checks if the position of the snake head matches the body's position 
		{
			isAlive = false;
	   }
	}

	return false;
}

bool Snake::CollectableCollision(Collectables c[5])
{
	for (int i = 0; i < 5; i++) {
		if (c[i].alive && (position.x == c[i].getPosition().x) && (position.y== c[i].getPosition().y))
			//checking if the position of the collectable is on the position of the snake head
		{
			TailGrowth = c[i].GetFoodValue();
			score += c[i].GetFoodValue();
			c[i].alive = false;
			//snakeSegments.push_back(position);
		}
	}
	return false;
}


void Snake::render(sf::RenderWindow & window)
{
	if (isAlive == true) {
		circle.setPosition(position);
		for (auto& s : snakeSegments)
		{
			circle.setPosition(s);
			window.draw(circle);
		}
	}
}


void Snake::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && e != Direction::eEast)
	{
		// left key is pressed: move our character to the left

		e = Direction::eWest;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& e != Direction::eWest)
	{
		e = Direction::eEast;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& e != Direction::eSouth)
	{
		e = Direction::eNorth;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& e != Direction::eNorth)
	{
		e = Direction::eSouth;
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
	{
		//quit the game
		isAlive = false;
	}

	switch (e)
	{
	case Direction::eNorth:
		position.y -= head_size;
		break;
	case Direction::eSouth:
		position.y += head_size;
		break;
	case Direction::eWest:
		position.x += head_size;
		break;
	case Direction::eEast:
		position.x -= head_size;
		break;
	}

	snakeSegments.push_front(position);
	if(TailGrowth==0)
		{
		snakeSegments.pop_back();
		}
	if (TailGrowth > 0)
	{
		TailGrowth--;
	}
	breath -= 1;
	
	if (position.x <= 1 || position.y <= 1 || position.x >= 799 || position.y >= 599)
	{
		isAlive = false;//kills snake if it hits the wall tanks
		//makes game exit
		
	}
	if (breath == 0)
	{
		isAlive = false;
	}
}

void Snake::GameOver(sf::RenderWindow & argumentwindow)
{
	if (isAlive == false)
	{
		std::cout << "You have died! :(" << std::endl;
		breath = 0;
		argumentwindow.close();
		
	}
}


Snake::~Snake()
{
}
