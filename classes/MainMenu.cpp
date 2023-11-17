#include "../include/MainMenu.hpp"

MainMenu::MainMenu(std::vector<MenuItem> const &options) : AMenu(options) {}

MainMenu::MainMenu(std::vector<std::string> const &options) : AMenu(options) {}

MainMenu::~MainMenu(void) { }

AMenu *MainMenu::menuLoop(void)
{
	int	key;

	do {
		this->drawMenu();
		key = this->captureInput(true);
		std::cout << "Key é : " << key << std::endl;
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
