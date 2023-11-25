#include "../include/UtilsMenu.hpp"

UtilsMenu::UtilsMenu(void) : AMenu({"List network interfaces", "second option", "<---"}) { }

UtilsMenu::UtilsMenu(std::vector<MenuItem> const &options) : AMenu(options) { }

UtilsMenu::UtilsMenu(std::vector<std::string> const &options) : AMenu(options) { }

UtilsMenu::UtilsMenu(std::initializer_list<MenuItem> const options) : AMenu::AMenu(options) { }

UtilsMenu::UtilsMenu(std::initializer_list<std::string> const options) : AMenu::AMenu(options) { }

UtilsMenu::~UtilsMenu(void) { };

AMenu	*UtilsMenu::menuLoop(void)
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
				switch (this->getCursorPosition()) {
					case 0:
					case 1:
					case 2:
						return (nullptr);
						break ;
				}
				break ;
		}
	} while (true);
}
