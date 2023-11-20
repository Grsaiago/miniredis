#ifndef MENUFACTORY_HPP
# define MENUFACTORY_HPP
# include "./AMenu.hpp"

class MenuFactory
{
	public:
		static AMenu	*createMenu(std::string menuName);
	private:
		MenuFactory(void);
		~MenuFactory(void);
};

#endif
