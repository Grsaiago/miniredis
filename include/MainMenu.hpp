#ifndef MAINMENU_HPP 
# define MAINMENU_HPP

# include "./AMenu.hpp"

class MainMenu : public AMenu
{
	public:
		MainMenu(std::vector<MenuItem> const &options);
		MainMenu(std::vector<std::string> const &options);
		virtual 		~MainMenu(void);
		virtual AMenu	*menuLoop(void);
};

#endif
