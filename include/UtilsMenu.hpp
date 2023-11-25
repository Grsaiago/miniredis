#ifndef UTILSMENU_HPP
# define UTILSMENU_HPP

# include "AMenu.hpp"

class UtilsMenu : public AMenu
{
	public:
		UtilsMenu(void);
		virtual 		~UtilsMenu(void);
		virtual AMenu	*menuLoop(void);
	private:
		UtilsMenu(std::vector<MenuItem> const &options);
		UtilsMenu(std::vector<std::string> const &options);
		UtilsMenu(std::initializer_list<MenuItem> const options);
		UtilsMenu(std::initializer_list<std::string> const options);
};

#endif
