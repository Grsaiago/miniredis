#include "../include/AMenu.hpp"
#include <cstddef>
#include <numeric>
#include <vector>


AMenu::AMenu(std::vector<MenuItem> const &options) :
	_options(std::vector<MenuItem>(options)),
	_cursorPosition(0)
{ }

AMenu::AMenu(std::vector<std::string> const &options)
{
	for (auto pos = options.begin(); pos != options.end(); pos++)
		this->_options.push_back(MenuItem(*pos));
	return ;
}

void	AMenu::drawMenu() const
{
	for (long unsigned int i = 0; i < this->_options.size(); i++)
	{
		this->_options[i].draw(i == this->_cursorPosition);
		std::cout << '\n';
	}
	std::cout.flush();
}

std::vector<MenuItem>	*AMenu::getOptions(void) const
{
	std::vector<MenuItem>	*ret;

	ret = new std::vector<MenuItem>(this->_options);
	return (ret);
}

void	AMenu::addOption(const MenuItem &newOption)
{
	this->_options.push_back(newOption);
	return ;
}

void	AMenu::addOption(std::string newOption)
{
	this->_options.push_back(MenuItem(newOption));
	return ;
}

int8_t	AMenu::getCursorPosition(void) const
{
	return (this->_cursorPosition);
}

int8_t	AMenu::captureInput(int8_t isBlocking) const
{

}

void	AMenu::moveCursor(int8_t ammount)
{
	int8_t	newPosition;

	newPosition = this->_cursorPosition + ammount;
	if (newPosition < 0)
		this->_cursorPosition = 0;
	else if (newPosition >= (int8_t)this->_options.size())
		this->_cursorPosition = this->_options.size() - 1;
	else
		this->_cursorPosition = ammount;
	return ;
}
