#include "TerminalRenderer.h"

TerminalRenderer::TerminalRenderer(sf::RenderWindow& window, History& historyManager)
	: window(window), historyManager(historyManager)
{
	TextInit();
}

void TerminalRenderer::Setup()
{
	sf::Color textColor = sf::Color(135, 206, 250);

	terminalText.setFillColor(textColor);
	historyText.setFillColor(textColor);
	inputText.setFillColor(textColor);
}

int TerminalRenderer::DrawHistory(const std::vector<std::string>& history, int& currentTextPos)
{
	for (int i = 0; i < history.size(); i++)
	{
		historyText.setString(history[i]);
		historyText.setPosition(10, i * 20 + topDistance - scrollOffset);

		window.draw(historyText);

		currentTextPos += 20;
	}

	return currentTextPos;
}

void TerminalRenderer::TextInit()
{
	font.loadFromFile("Fonts/consolas.ttf");

	terminalText = sf::Text();
	terminalText.setFont(font);
	terminalText.setCharacterSize(20);
	terminalText.setFillColor(sf::Color::White);
	terminalText.setLetterSpacing(1);

	historyText = sf::Text();
	historyText.setFont(font);
	historyText.setCharacterSize(20);
	historyText.setFillColor(sf::Color::White);
	historyText.setLetterSpacing(1);

	inputText = sf::Text();
	inputText.setFont(font);
	inputText.setCharacterSize(20);
	inputText.setFillColor(sf::Color::White);
	inputText.setLetterSpacing(1);

	historyText.setString("FourtyOneOS welcomes you!");
	historyManager.AddToHistory(historyText.getString());

	historyManager.AddToHistory("\n");
}

void TerminalRenderer::SetOffset()
{
	int historySize = historyManager.GetHistorySize();

	if (historySize > 20) {
		scrollOffset = (historySize - 20) * 20 - 8;
	}
	else {
		scrollOffset = 0;
	}
}

void TerminalRenderer::Draw(const std::vector<std::string>& history, const std::string& input)
{
	int currentTextPos = 0;
	window.clear(sf::Color(0, 0, 0));
	inputText.setString(input);
	terminalText.setString(prompt);

	SetOffset();

	currentTextPos = DrawHistory(history, currentTextPos);

	terminalText.setPosition(10, currentTextPos + topDistance - scrollOffset);
	inputText.setPosition(terminalText.getGlobalBounds().left + terminalText.getGlobalBounds().width + 1, currentTextPos + topDistance - scrollOffset);

	window.draw(terminalText);
	window.draw(inputText);

	window.display();
}