#include "../include/ATcpIpSocket.hpp"
#include <cstdlib>
#include <vector>

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (perror("ussage: ./myredis <server port> <ip in 0.0.0.0 notation>"), EXIT_FAILURE);

	ATcpIpSocket		serverSocket(IPV4, std::atoi(argv[1]), argv[2]);
	std::vector<int>	connPool;
	int					connFd;

	serverSocket.initSocket();
	serverSocket.listenSocket();
	while (true)
	{
		connFd = serverSocket.acceptOnSocket();
		if (connFd < 0)
			continue ;
		connPool.push_back(connFd);
		std::cout << connPool[0] << std::endl;
	}
	serverSocket.closeSocket();
	return (EXIT_SUCCESS);
}

