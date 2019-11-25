#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include <iostream>
#include "Collectables.h"
#include "Water.h"
Game::Game() :
	playersnake(sf::Vector2f(10, 10)),
	water(sf::Vector2f(0,0))
{
	
}

//bool Game::ChangeStatus(sf::RenderWindow &window)
//{
//	switch (SelectedState)
//	{
//		case GameState::eMainMenu:
//			//call the main menu display/draw
//			
//			return true;
//		break;
//		case GameState::eGame:
//			return true;
//			Run();
//		break;
//	    case GameState::eGameOver:
//		     return false;
//		break;
//	    default:
//			//
//		break;
//	}
//}

void Game::Run()
{
	sf::Text text;
	sf::Text text1;
	sf::Font font;
	text.setFont(font);
	text1.setFont(font);
	text.setCharacterSize(30); 
	text1.setCharacterSize(30);// in pixels, not points
	if (!font.loadFromFile("BAUHS93.ttf"))
	{
		std::cout << "Font not in source file" << std::endl;
	}
	text.setColor(sf::Color::Red);
	text1.setColor(sf::Color::Red);
	text.setPosition(500, 0);
	text1.setPosition(30, 0);

	std::cout << "SNAKE GAME LOADED! GOOD LUCK AND HAVE FUN!!!" << std::endl;
	srand(time(nullptr));
	sf::RenderWindow window(sf::VideoMode(800, 600), "C++ Snake ICA : V8015944");
	while (window.isOpen())
	{
		// Handle any pending SFML events
		// These cover keyboard, mouse,joystick etc.
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}

		}

		// GAME LOGIC
		playersnake.update();
		water.Waterdrop();
		text.setString("Score:" + std::to_string(playersnake.ReturnScore()));
		text1.setString("Breath:" + std::to_string(playersnake.GetBreath()));
		sf::VertexArray lines(sf::LinesStrip, 4);

		lines[0].position = sf::Vector2f(1, 1);

		lines[1].position = sf::Vector2f(1, 599);

		lines[2].position = sf::Vector2f(799, 599);

		lines[3].position = sf::Vector2f(799, 1);
		if (water.GetWaterPosition().y == 595)
		{ 
			std::cout << "Game over!" << std::endl;
			window.close();
		}
		for (auto &c : collectables)
		{
			if (!c.isAlive())
			{
				if (rand() % 100 == 0) {
					c.spawn(sf::Vector2f((rand() % 40)*20-10, (rand() % 30)*20-10));
				}// rand spawn
			}
		}
		
		// RENDERING
		window.clear();
		water.Render(window);
		window.draw(lines);
		window.draw(text);
		window.draw(text1);

		for (auto &c : collectables)
		{
			c.Render(window);
		}
		playersnake.CollectableCollision(collectables);
		playersnake.CheckSelfCollision();
		playersnake.CheckIfAboveWater(water); //check the function by passing the water existing in the water cpp
		playersnake.render(window);
		playersnake.GameOver(window);

		window.display();
		// PACING

		sf::Clock clock;
		while (clock.getElapsedTime().asMilliseconds() < 110);
		clock.restart();
		
	}
}

//void Game::DisplayUI(sf::RenderWindow & argumentwindow, const std::list<Snake>& argumentSnakeList)
//{
//
//}


Game::~Game()
{

}
