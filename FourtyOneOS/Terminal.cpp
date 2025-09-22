#include "Terminal.h"

Terminal::Terminal() :
	window(sf::VideoMode(1200, 800), "FourtyOne_Terminal"),
	historyManager(),
	terminalRenderer(window, *historyManager),
	inputHandler(){}

void Terminal::Run()
{
	while (window.isOpen())
	{
		inputHandler->PollEvents();
		terminalRenderer->Setup();
		terminalRenderer->Draw(historyManager->GetHistory(), inputHandler->GetInput());
	}
}