#include "../include/MainMenu.hpp"
#include "../include/MenuFactory.hpp"

MainMenu::MainMenu(void) : AMenu({"op1", "Network Utils", "<---"}) { }

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
				switch (this->getCursorPosition()) {
					case 0:
						return (nullptr);
					case 1:
						return MenuFactory::createMenu(UTILSMENU);
						break ;
					case 2:
						return (nullptr);
						break ;
				}
				break ;
		}
	} while (true);
}

void	AMenu::clearTerminal(void) const
{
	write(1, CLEAR, strlen(CLEAR));
	return ;
}
