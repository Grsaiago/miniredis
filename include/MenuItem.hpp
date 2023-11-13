#ifndef MENUITEM_HPP
# define MENUITEM_HPP

# ifndef COLORTERMINATOR
#  define COLORTERMINATOR "end"
# endif

# ifndef SELECTEDCOLOR
#  define SELECTEDCOLOR "red"
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
