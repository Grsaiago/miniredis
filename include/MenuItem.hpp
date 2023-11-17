#ifndef MENUITEM_HPP
# define MENUITEM_HPP

# ifndef COLORTERMINATOR
#  define COLORTERMINATOR "\e[0m"
# endif

# ifndef SELECTEDCOLOR
#  define SELECTEDCOLOR "\e[1;32m"
# endif

# include <string>
# include <iostream>

class MenuItem
{
	public:
		MenuItem(std::string name);
		~MenuItem(void);

		/* getter/setter */
		std::string	getName(void) const;
		void		setName(std::string name);

		/* methods */
		void		draw(bool isSelected) const;
		private:
			std::string	_name;
};

#endif
