#ifndef AMENU_HPP
# define AMENU_HPP

# include "./MenuItem.hpp"
# include <cstddef>
#include <initializer_list>
# include <iterator>
# include <numeric>
# include <vector>
# include <iostream>
# include <unistd.h>
# include <termios.h>
# include <string.h>

# define UP "\e[B"
# define DOWN "\e[A"
# define RIGHT "\e[C"
# define LEFT "\e[D"
# define ENTER "\n\0\0"
# define CLEAR "\e[H\e[J"
# define CURSORBACK "\e[#A"
# define UPCODE 1
# define DOWNCODE 2
# define ENTERCODE 4

class AMenu
{
	public:
		AMenu(std::vector<MenuItem> const &options);
		AMenu(std::vector<std::string> const &options);
		AMenu(std::initializer_list<std::string> const options);
		AMenu(std::initializer_list<MenuItem> const options);
		virtual						~AMenu(void);
		void						drawMenu(void) const;
		void						clearTerminal(void) const;
		virtual AMenu				*menuLoop(void) = 0;

		/* getter/setter */
		std::vector<MenuItem>		*getOptions(void) const;
		void						addOption(const MenuItem &newOption);
		void						addOption(std::string newOption);
		int							getCursorPosition(void) const;
		std::vector<std::string>	getKeysToCapture(void) const;
	protected:
		std::vector<MenuItem>		_options;
		int							_cursorPosition;
		int							captureInput(bool isBlocking) const;
		void						moveCursor(int ammount);
};

#endif
