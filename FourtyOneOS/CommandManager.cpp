#include "CommandManager.h"


CommandManager::CommandManager(History& historyManager)
    : historyManager(historyManager)
{

}

void CommandManager::ExecuteCommand(const std::string& command)
{
    historyManager.AddToHistory("Terminal>" + command);
    std::vector<std::string> commandParts = SplitInput(command);
    std::string mainCommand = commandParts[0];
    std::vector<std::string> arguments(commandParts.begin() + 1, commandParts.end());

    if (mainCommand == "echo") {
        Echo(arguments);
    }


}

void CommandManager::Echo(std::vector<std::string>& args) {
    std::cout << "echo";
    return;
}

std::vector<std::string> CommandManager::SplitInput(const std::string& input) {
    std::stringstream ss(input);
    std::string word;
    std::vector<std::string> result;

    while (ss >> word)
        result.push_back(word);

    return result;
}
