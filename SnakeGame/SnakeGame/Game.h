#pragma once
#include "Snake.h"
#include "Collectables.h"
#include "Water.h"
#include "Menu.h"
//enum class GameState {
//	eMainMenu,
//	eGame,
//	eGameOver
//};
class Game
{
private:
	Snake playersnake;
	Collectables collectables[5];
	Water water;
	/*Menu menu;*/
	/*GameState SelectedState = GameState::eMainMenu;*/
public:
	Game();
	/*bool ChangeStatus(sf::RenderWindow &window);*/
	void Run();
	//void DisplayUI(sf::RenderWindow&argumentwindow, const std::list<Snake>&argumentSnakeList);
	~Game();
};

