#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "History.h"
#include "CommandManager.h"
#include "TerminalRenderer.h"

using namespace std;

class InputHandler
{
private:

	CommandManager& commandManager;
	History& historyManager;
	TerminalRenderer& terminalRenderer;
	sf::RenderWindow& window;
	string input;
	int cursorPos = 0;

	void AddCharacter(char charachter, int index);
public:
	InputHandler(sf::RenderWindow& window, History& historyManager, CommandManager& commandManager, TerminalRenderer& terminalRenderer);
	string GetInput() const { return input; }
	int GetCursorPos() const { return cursorPos; }
	void PollEvents();
};
