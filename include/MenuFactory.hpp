#ifndef MENUFACTORY_HPP
# define MENUFACTORY_HPP
# include "./AMenu.hpp"
# include "./MainMenu.hpp"
# include "./UtilsMenu.hpp"

# define MAINMENU 1
# define UTILSMENU 2

class MenuFactory
{
	public:
		static AMenu	*createMenu(unsigned int menuCode);
	private:
		MenuFactory(void);
		~MenuFactory(void);
};

#endif
