#include "../include/MainMenu.hpp"
#include <initializer_list>

MainMenu::MainMenu(std::vector<MenuItem> const &options) : AMenu(options) {}

MainMenu::MainMenu(std::vector<std::string> const &options) : AMenu(options) {}

MainMenu::MainMenu(std::initializer_list<std::string> const options) : AMenu(options) {}

MainMenu::MainMenu(std::initializer_list<MenuItem> const options) : AMenu(options) {}

MainMenu::~MainMenu(void) { }

AMenu *MainMenu::menuLoop(void)
{
	int	key;

	do {
		this->clearTerminal();
		this->drawMenu();
		key = this->captureInput(true);
		switch (key) {
			case (UPCODE):
				this->moveCursor(-1);
				break ;
			case (DOWNCODE):
				this->moveCursor(1);
				break ;
			case (ENTERCODE):
				std::cout << "você clicou Enter" << std::endl;
				break ;
		}
	} while (true);
}

void	AMenu::clearTerminal(void) const
{
	write(1, CLEAR, strlen(CLEAR));
	return ;
}
