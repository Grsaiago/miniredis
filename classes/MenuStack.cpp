#include "../include/MenuStack.hpp"
#include "../include/MainMenu.hpp"
#include <vector>

MenuStack::MenuStack(std::vector<MenuItem> const &options) : AMenu(options) { }

MenuStack::MenuStack(std::vector<std::string> const &options) : AMenu(options) { }

MenuStack::MenuStack(std::initializer_list<std::string> const options) : AMenu(options) { }

MenuStack::MenuStack(std::initializer_list<MenuItem> const options) : AMenu(options) { } 

MenuStack::~MenuStack(void) { }

AMenu	*MenuStack::menuLoop(void)
{
	MainMenu					*mainMenu;
	AMenu						*nextMenu;

	mainMenu = new MainMenu({"op1", "op2", "op3"});
	this->menuStack.push(mainMenu);
	// criar o MainMenu com a factory e dar push nele pra stack.
	do {
		nextMenu = this->menuStack.top()->menuLoop();
		if (!nextMenu)
			this->menuStack.pop();
		else
			this->menuStack.push(nextMenu);
	} while (this->menuStack.empty() == false);
	std::cout << "terminou" << std::endl;
	return (this);
}
