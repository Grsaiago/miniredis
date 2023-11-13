#include "../include/MenuItem.hpp"
#include <numeric>
#include <string>

MenuItem::MenuItem(std::string name) : _name(name) { }

MenuItem::~MenuItem(void) { }

std::string	MenuItem::getName(void) const
{
	return (std::string(this->_name));
}

void	MenuItem::setName(std::string name)
{
	this->_name = name;
	return ;
}

void	MenuItem::draw(bool isSelected) const
{
	std::string	line;

	if (isSelected)
		line.append(SELECTEDCOLOR);
	line.append(this->_name);
	if (isSelected)
		line.append(COLORTERMINATOR);
	std::cout << line;
	return ;
}
