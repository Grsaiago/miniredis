#include "../include/AWebSocket.hpp"

AWebSocket::AWebSocket(IpSockProtocols ipProtocol, unsigned long port, char *ipAddress) :
	_sockFd(-1),
	_ipProtocol(ipProtocol),
	_port(port),
	_ipAddress(inet_addr(ipAddress))
{ };

/* docs: close() internal socket and return */
AWebSocket::~AWebSocket(void)
{
	this->closeSocket();
	return ;
}

/* docs: close() the internal socketfd, it is safe to call multiple times */
void	AWebSocket::closeSocket(void)
{
	if (this->_sockFd >= 0)
		close(this->_sockFd);
	this->_sockFd = -1;
	return ;
}

/* docs: returns the ipProtocol of this socket as a string */
std::string	AWebSocket::getProtocolAsStr(void) const
{
	switch (this->_ipProtocol)
	{
		case (IPV4):
			return std::string("IPV4");
			break ;
		case (IPV6):
			return (std::string("IPV6"));
			break ;
	}
	return (std::string());
}

/* docs: returns the port of this socket as a string */
std::string		AWebSocket::getPortAsStr(void) const
{
	char	buff[MAXTCPPORTSTRSIZE];

	snprintf(buff, MAXTCPPORTSTRSIZE - 1, "%d", this->_port);
	return (std::string(buff));
}

/* docs: returns the ip of this socket as a string */
std::string		AWebSocket::getIpAsStr(void) const
{
	struct in_addr	aux = {
		.s_addr = this->_ipProtocol,
	};

	switch (this->_ipProtocol)
	{
		case (IPV4):
			return (std::string(inet_ntoa(aux)));
			break ;
		case (IPV6):
			return (std::string("To be implemented"));
			break ;
		default:
			return (std::string("To be implemented"));
			break ;
	}
}

/* docs: returns the ipProtocol of this socket as an int*/
unsigned int	AWebSocket::getProtocolAsUInt(void) const { return (this->_ipProtocol); }

/* docs: returns the port of this socket as an int*/
unsigned int	AWebSocket::getPortAsUInt(void) const { return (this->_port); }

unsigned int	AWebSocket::getIpAsUInt(void) const { return (this->_ipAddress); }
/* static functions */

/* docs: test if the fd is a socket */
bool	AWebSocket::isSocketFd(int fd)
{
	struct stat statbuff;
	char		ret;

	ret = fstat(fd, &statbuff);
	if (ret < 0 || S_ISSOCK(statbuff.st_mode))
		return (false);
	return (true);
}
