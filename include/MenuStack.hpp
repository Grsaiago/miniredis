#ifndef MENUSTACK_HPP
# define MENUSTACK_HPP

# include <stack>
# include "./AMenu.hpp"

class MenuStack : public AMenu
{
	public:
		MenuStack(std::vector<MenuItem> const &options);
		MenuStack(std::vector<std::string> const &options);
		MenuStack(std::initializer_list<std::string> const options);
		MenuStack(std::initializer_list<MenuItem> const options);
		virtual				~MenuStack(void);
		std::stack<AMenu *>	menuStack;
		virtual AMenu		*menuLoop(void);
};

#endif
