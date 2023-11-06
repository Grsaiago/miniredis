#ifndef MINIREDIS_HPP
# define MINIREDIS_HPP
# define UP "\e[A"
# define DOWN "\e[B"
# define RIGHT "\e[C"
# define LEFT "\e[D"
# define ENTER "\n\0\0\0"
# define CURSORBACK "\e[1A"
# include <string.h>
# include <termios.h>
# include <unistd.h>

typedef struct s_keyOption
{
	char	value[4];
	int		code;
}	t_keyOption;

int	getKey(t_keyOption *keyOptions, size_t optionsCount, bool isInputBlocking = false);

#endif
