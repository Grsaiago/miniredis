#ifndef MENUSTACK_HPP
# define MENUSTACK_HPP

# include <stack>
# include "./AMenu.hpp"

class MenuStack
{
	public:
		MenuStack(std::initializer_list<AMenu *> const options);
		~MenuStack(void);
		std::stack<AMenu *>	menuStack;
		MenuStack			*menuStackLoop(void);

		/* overloads */
		void		*operator new(size_t size);

		/* static instance */
		static MenuStack	*instance;
};
 
#endif
