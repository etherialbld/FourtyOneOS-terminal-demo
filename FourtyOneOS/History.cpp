#include "History.h"

History::History() {}

void History::AddToHistory(const std::string& command)
{
	history.push_back(command);
}

void History::AddToHistoryCommands(const std::string& command)
{
	if (historyCommands.empty() || historyCommands[0] != "")
	{
		historyCommands.insert(historyCommands.begin(), "");
	}
	historyCommands.insert(historyCommands.begin() + 1, command);
}

void History::ClearHistory()
{
	history.clear();

	AddToHistory("FourtyOneOS welcomes you!");
}
