#include "../include/ServerSocket.hpp"
#include <cstdlib>
#include <vector>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./myredis <server port>" << std::endl;
		return (EXIT_FAILURE);
	}
	ServerSocket		serverSocket(IPV4, std::atoi(argv[1]));
	std::vector<int>	connPool;
	int					connFd;

	serverSocket.bindSocket();
	serverSocket.listenSocket();
	while (true)
	{
		connFd = serverSocket.acceptOnSocket();
		if (connFd < 0)
			continue ;
		connPool.push_back(connFd);
		std::cout << connPool[0] << std::endl;
	}
	return (EXIT_FAILURE);
	serverSocket.closeSocket();
	return (EXIT_SUCCESS);
}

