#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include "History.h"

class CommandManager
{
private:
	History& historyManager;

	void Echo(std::vector<std::string>& args);
	std::vector<std::string> SplitInput(const std::string& input);

public:
	CommandManager(History& historyManager);
	void ExecuteCommand(const std::string& command);
};
