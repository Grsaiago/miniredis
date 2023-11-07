#include "../include/ServerSocket.hpp"

/* docs: constructor only initialized _sockFd to 0 */
ServerSocket::ServerSocket(IpSockProtocols ipProtocol, unsigned long port) : AWebSocket::AWebSocket(ipProtocol, port, (char *)std::string("0").c_str())
{ };

ServerSocket::~ServerSocket(void)
{
	this->closeSocket();
	return ;
}

/* !throws! docs: socket() with protocol, SOCK_STREAM, 0 -
* setsockopt() with SOL_SOCKET, SO_REUSEADDR, 1 - 
* bind() with protocol, ntohs(port), ntohs(ipAddress)
*/
void	ServerSocket::bindSocket(void)
{
	struct sockaddr_in	socketConf = {};
	int					val = 1;

	this->_sockFd = socket(this->_ipProtocol, SOCK_STREAM | SOCK_NONBLOCK, 0);
	if (this->_sockFd < 0)
		throw new SocketFailedException("Failed to get socket\n");

	if (setsockopt(this->_sockFd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val)) != 0)
		throw new SocketFailedException("Failed to setup socket\n");

	socketConf.sin_family = this->_ipProtocol;
	socketConf.sin_port = ntohs(this->_port);
	socketConf.sin_addr.s_addr = ntohl(this->_ipAddress);
	if (bind(this->_sockFd, (const sockaddr *)&socketConf, sizeof(socketConf)))
		throw new SocketFailedException("Failed to bind socket\n");
	return ;
}

/*
 * !throws! docs: Use listen() on the class _sockFd
 * with default to maxConnections is unistd SOMAXCONN 
 */
int	ServerSocket::listenSocket(int maxConnections)
{
	if (this->_sockFd < 0 || listen(this->_sockFd, maxConnections) != 0)
		throw new SocketFailedException("Failed to listen on socket\n");
	return (0);
}

/* !throws! docs: use accept() to fetch an fd for the next connection */
int	ServerSocket::acceptOnSocket(void)
{
	int					retFd;
	struct sockaddr_in	conf = { };
	socklen_t			confLen = sizeof(conf);

	retFd = accept(this->_sockFd,(struct sockaddr *)&conf, &confLen); 
	return (retFd);
}

std::string	ServerSocket::getSocketType(void) const
{
	return (std::string("ServerSocket"));
}

/* exceptions */

ServerSocket::SocketFailedException::SocketFailedException(std::string message)
	: std::runtime_error(message) { } 
