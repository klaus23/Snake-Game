//#include "Menu.h"
//
//Menu::Menu(float width, float height)
//{
//	if (!Font.loadFromFile("BAUHS93.ttf"))
//	{
//		//std::cout << "Font not in source file" << std::endl;
//	}
//	menu[0].setFont(Font);
//	menu[0].setColor(sf::Color::Red);
//	menu[0].setString("Play");
//	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
//
//	menu[0].setFont(Font);
//	menu[0].setColor(sf::Color::White);
//	menu[0].setString("Options");
//	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
//
//	menu[0].setFont(Font);
//	menu[0].setColor(sf::Color::Green);
//	menu[0].setString("Quit");
//	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
//
//}
//
//void Menu::Draw(sf::RenderWindow & window)
//{
//	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
//	{
//		window.draw(menu[i]);
//	}
//}
//
//void Menu::MoveUp()
//{
//	if (selectedItemIndex - 1 >= 0) {
//		menu[selectedItemIndex].setColor(sf::Color::White);
//		selectedItemIndex--;
//		menu[selectedItemIndex].setColor(sf::Color::Red);
//	}
//}
//
//void Menu::MoveDown()
//{
//	if (selectedItemIndex + 1 <MAX_NUMBER_OF_ITEMS) {
//		menu[selectedItemIndex].setColor(sf::Color::White);
//		selectedItemIndex++;
//		menu[selectedItemIndex].setColor(sf::Color::Red);
//	}
//}
//
//Menu::~Menu()
//{
//}
