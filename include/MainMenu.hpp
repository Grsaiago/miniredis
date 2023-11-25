#ifndef MAINMENU_HPP 
# define MAINMENU_HPP

# include "./AMenu.hpp"

class MainMenu : public AMenu
{
	public:
		MainMenu(void);
		virtual 		~MainMenu(void);
		virtual AMenu	*menuLoop(void);
	private:
		MainMenu(std::vector<MenuItem> const &options);
		MainMenu(std::vector<std::string> const &options);
		MainMenu(std::initializer_list<std::string> const options);
		MainMenu(std::initializer_list<MenuItem> const options);
};

#endif
