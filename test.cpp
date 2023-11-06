#include <iostream>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <cstdio>
#include <termios.h>
#include <fcntl.h>

typedef struct s_keyOption
{
	char	value[4];
	int		code;
}	t_keyOption;

int	getKey(t_keyOption *keyOptions, size_t optionsCount, bool isInputBlocking = 0);

#define UP "\e[A"
#define DOWN "\e[B"
#define RIGHT "\e[C"
#define LEFT "\e[D"
#define ENTER "\n\0\0\0"
#define CURSORBACK "\e[1A"

int	main(void)
{
	int				key;
	int				opt = 0;
	t_keyOption		keyOptions[] = {
		{ .value = UP, .code = 1 }
	};

	printf("Digite um caracter:\n");
	do {
		key = getKey(keyOptions, sizeof(keyOptions) / sizeof(t_keyOption), 1);
		std::cout << "The key pressed was [" << key << "]" << std::endl;
		std::cout << CURSORBACK;
	} while (42);
}

int	getKey(t_keyOption *keyOptions, size_t optionsCount, bool isInputBlocking)
{
	struct termios	oldTerm, newTerm;
	char			readBuff[4];
	int				ret = 0;

	// get current terminal confs
	if (tcgetattr(STDIN_FILENO, &oldTerm) != 0)
		return (-1);
	// set new terminal confs
	newTerm = oldTerm;
	newTerm.c_lflag &= ~(ECHO | ICANON);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &newTerm) != 0)
		return (-1);
	// initialize readBuff, read key, compare and do again if flag is on
	do {
		memset(readBuff, 0, sizeof(readBuff));
		read(STDIN_FILENO, readBuff, sizeof(readBuff));
		for (int i = 0; i < optionsCount; i++) {
			if (strncmp(readBuff, keyOptions[i].value, sizeof(readBuff)) == 0) {
				ret = keyOptions[i].code;
				goto breakLoop;
			}
		}
	} while (isInputBlocking);
	breakLoop:
	// reset terminal confs
	if (tcsetattr(STDIN_FILENO, TCSANOW, &oldTerm) != 0)
		return (-1);
	return (ret);
}
