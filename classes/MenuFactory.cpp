#include "../include/MenuFactory.hpp"

AMenu	*MenuFactory::createMenu(unsigned int menuCode)
{
	AMenu	*menu = nullptr;

	switch (menuCode) {
		case (MAINMENU):
			menu = new MainMenu();
			break ;
		case (UTILSMENU):
			menu = new UtilsMenu();
			break ;
	}
	return (menu);
}

MenuFactory::MenuFactory(void) { }

MenuFactory::~MenuFactory(void) { }
