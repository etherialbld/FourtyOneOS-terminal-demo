#pragma once
#include <SFML/Graphics.hpp>

class History
{
private:
	std::vector<std::string> history;
	std::vector<std::string> historyCommands;

public:
	History();

	void AddToHistory(const std::string& command);
	void AddToHistoryCommands(const std::string& command);


	std::vector<std::string> GetHistory() const { return history; }
	std::vector<std::string> GetHistoryCommands() const { return historyCommands; }

	int GetHistorySize() { return history.size(); }
	int GetHistoryCommandsSize() { return historyCommands.size(); }

	void ClearHistory();
};

