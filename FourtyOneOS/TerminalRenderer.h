#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "History.h"

class TerminalRenderer
{
private:
	const int topDistance = 8;
	const std::string prompt = "FourtyOneOS>";

	int scrollOffset = 0;
	sf::RenderWindow& window;
	sf::Font font;

	sf::Text terminalText;
	sf::Text historyText;
	sf::Text inputText;

	History& historyManager;

	void TextInit();
	int DrawHistory(const std::vector<std::string>& history, int& currentTextPos);
	void SetOffset();

public:
	TerminalRenderer(sf::RenderWindow& window, History& historyManager);

	void Draw(const std::vector<std::string>& history, const std::string& input);
	void Setup();
};

