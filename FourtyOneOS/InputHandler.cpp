#include "InputHandler.h"

using namespace sf;

InputHandler::InputHandler(RenderWindow& window, History& historyManager, CommandManager& commandManager, TerminalRenderer& terminalRenderer)
    : window(window), historyManager(historyManager), commandManager(commandManager), terminalRenderer(terminalRenderer)
{

}

void InputHandler::PollEvents()
{
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed)
            window.close();
        else if (event.type == Event::TextEntered) {
            if (event.text.unicode == 8) { //Backspace
                if (!input.empty()) {
                    input.pop_back();
                    cursorPos--;
                }
            }
            else if (event.text.unicode == 13) { //Enter
                if (!input.empty()) {
                    commandManager.ExecuteCommand(input);
                    historyManager.AddToHistoryCommands(input);
                    input.clear();
                    cursorPos = 0;
                }
                else if (event.text.unicode == 27) { // Escape
                    window.close();
                }
                else if (event.text.unicode < 128) {
                    AddCharacter(static_cast<char>(event.text.unicode), cursorPos);
                    cursorPos++;
                }
            }
        }
    }

}

void InputHandler::AddCharacter(char character, int index)
{
    if (index >= 0 && index <= input.size()) {
        input.insert(input.begin() + index, character);
    }
}