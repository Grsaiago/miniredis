#include "../include/ConnectionSocket.hpp"
//tirar depois que trocar a linha 12 pra uma exception
#include <ostream>
#include <stdio.h>
#include <string>

// criar um construtor protected da classe AWebSocket que seja vazio, só pra usar aqui
ConnectionSocket::ConnectionSocket(int fd) : AWebSocket::AWebSocket()
{
	struct sockaddr_in	socketInfo;
	socklen_t			socketInfoSize = sizeof(struct sockaddr_in);

	(void)getpeername(fd, (struct sockaddr *)&socketInfo, &socketInfoSize);
	this->_ipProtocol = IPV4;
	this->_sockFd = fd;
	this->_port = htons(socketInfo.sin_port);
	this->_ipAddress = htonl(socketInfo.sin_addr.s_addr);
	this->_staticBuff = NULL;
}

ConnectionSocket::~ConnectionSocket(void)
{
	this->closeSocket();
	return ;
}

std::string	ConnectionSocket::receiveRequest(void)
{
	std::cout << "called receiveRequest on fd: " << this->_sockFd << std::endl;
	return (std::string("TBI"));
}

void	ConnectionSocket::sendResponse(void)
{
	std::cout << "called sendResponse on fd: " << this->_sockFd << std::endl;
	return ;
}

std::string	ConnectionSocket::getSocketType(void) const
{
	return (std::string("connection socket"));
}

std::ostream	&operator<<(std::ostream &os, ConnectionSocket const &rhs)
{
	std::string	line;

	line.clear();
	line.append("Peer Ip: ");
	line += rhs.getIpAsStr();
	line.push_back('\n');
	os << line;
	return (os);
}
