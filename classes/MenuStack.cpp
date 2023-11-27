#include "../include/MenuStack.hpp"
#include "../include/MainMenu.hpp"
#include <vector>

MenuStack *MenuStack::instance = nullptr;

MenuStack::~MenuStack(void) { }

MenuStack::MenuStack(std::initializer_list<AMenu *> const options)
{
	for (auto elem : options) {
		if (elem)
			this->menuStack.push(elem);
	}
	return ;
}

MenuStack	*MenuStack::menuStackLoop(void)
{
	AMenu						*nextMenu;

	// mainMenu = new MainMenu({"op1", "op2", "op3"});
	// this->menuStack.push(mainMenu);
	// criar o MainMenu com a factory e dar push nele pra stack.
	do {
		nextMenu = this->menuStack.top()->menuLoop();
		if (!nextMenu) {
			delete this->menuStack.top();
			this->menuStack.pop();
		}
		else
			this->menuStack.push(nextMenu);
	} while (this->menuStack.empty() == false);
	std::cout << "terminou" << std::endl;
	return (this);
}

void	*MenuStack::operator new(size_t size)
{
	MenuStack	*ptr;

	if (MenuStack::instance)
		return MenuStack::instance;
	ptr = (MenuStack *) ::operator new(size);
	MenuStack::instance = ptr;
	return (ptr);
}
