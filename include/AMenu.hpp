#ifndef AMENU_HPP
# define AMENU_HPP

# include "./MenuItem.hpp"
#include <cstddef>
# include <vector>
# include <iostream>

class AMenu
{
	public:
		AMenu(std::vector<MenuItem> const &options);
		AMenu(std::vector<std::string> const &options);
		~AMenu(void);
		virtual void			drawMenu(void) const;
		virtual void			menuLoop(void) = 0;

		/* getter/setter */
		std::vector<MenuItem>	*getOptions(void) const;
		void					addOption(const MenuItem &newOption);
		void					addOption(std::string newOption);
		int8_t					getCursorPosition(void) const;
	protected:
		std::vector<MenuItem>	_options;
		std::size_t				_cursorPosition;
		int8_t					captureInput(int8_t isBlocking) const;
		void					moveCursor(int8_t ammount);
};

#endif
