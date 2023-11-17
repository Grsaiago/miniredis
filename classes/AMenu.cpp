#include "../include/AMenu.hpp"

AMenu::AMenu(std::vector<MenuItem> const &options) :
	_options(std::vector<MenuItem>(options)),
	_cursorPosition(0)
{ }

AMenu::AMenu(std::vector<std::string> const &options) :
	_cursorPosition(0)
{
	for (auto pos = options.begin(); pos != options.end(); pos++)
		this->_options.emplace_back(*pos);
	return ;
}

AMenu::~AMenu(void) { }

void	AMenu::drawMenu() const
{
	for (unsigned long int i = 0; i < this->_options.size(); i++)
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
	this->_options.emplace_back(newOption);
	return ;
}

int	AMenu::getCursorPosition(void) const
{
	return (this->_cursorPosition);
}

int	AMenu::captureInput(bool isBlocking) const
{
	struct termios	oldTerm, newTerm;
	char			readBuff[4];
	int				ret = 0;

	if (tcgetattr(STDIN_FILENO, &oldTerm) != 0)
		return (-1);
	newTerm = oldTerm;
	newTerm.c_lflag ^= (ECHO | ICANON);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &newTerm) != 0)
		return (-1);
	do {
		memset(readBuff, 0, sizeof(readBuff));
		read(STDIN_FILENO, readBuff, sizeof(readBuff));
		if (strncmp(readBuff, UP, 4)) {
			ret = UPCODE;
			goto _BREAKLOOP;
		} else if (strncmp(readBuff, DOWN, 4)) {
			ret = DOWNCODE;
			goto _BREAKLOOP;
		} else if (strncmp(readBuff, ENTER, 4)) {
			ret = ENTERCODE;
			goto _BREAKLOOP;
		}
	} while (isBlocking);
	_BREAKLOOP:
	if (tcsetattr(STDIN_FILENO, TCSANOW, &oldTerm) != 0)
		return (-1);
	return (ret);
}

void	AMenu::moveCursor(int ammount)
{
	int	newPosition;

	newPosition = this->_cursorPosition + ammount;
	if (newPosition < 0)
		this->_cursorPosition = 0;
	else if (newPosition >= (int)this->_options.size())
		this->_cursorPosition = this->_options.size() - 1;
	else
		this->_cursorPosition = newPosition;
	return ;
}
