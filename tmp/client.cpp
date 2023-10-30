#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

int	main(void) 
{
	int					sockFd;
	char				buff[64] = { };
	struct sockaddr_in	addr = { };

	try {
		sockFd = socket(AF_INET, SOCK_STREAM, 0);
		if (sockFd < 0)
			throw new std::logic_error("Socket Error");
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr("127.0.0.1");
		addr.sin_port = ntohs(1234);
		if (connect(sockFd, (struct sockaddr *)&addr, sizeof(addr)))
			throw new std::logic_error("Connect error");
		write(sockFd, "Cinco", 5);
		read(sockFd, buff, 3);
		printf("Recebi de volta [%s]\n", buff);
		close(sockFd);
	} catch (std::exception &error) {
		return (perror(error.what()), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
