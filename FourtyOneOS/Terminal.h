#pragma once

#include <SFML/Graphics.hpp>

#include "TerminalRenderer.h"
#include "CommandManager.h"
#include "InputHandler.h"
#include "History.h"

using namespace std;

class Terminal
{
private:

	sf::RenderWindow window;

	History* historyManager;
	InputHandler* inputHandler;
	CommandManager* commandManager;
	TerminalRenderer* terminalRenderer;

public:
	Terminal();
	void Run();
};

