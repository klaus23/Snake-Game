/*
  Games Development with C++ GAV1031-N
  Snake ICA start project 
  
  Set up to use the SFML 2.5.1 64-bit API
    SFML documentation: https://www.sfml-dev.org/learn.php
*/

#include <iostream>

// SFML header file for graphics, there are also ones for Audio, Window, System and Network
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Game.h"
#include "Menu.h"

int main()
{
	Game game;
	game.Run();
	//bool Playing = true;//variable to make the game work

	//while (Playing==true)
	//{
	//	Playing=game.ChangeStatus();

	//}
}
