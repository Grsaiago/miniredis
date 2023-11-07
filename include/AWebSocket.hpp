#ifndef AWEBSOCKET_HPP
# define AWEBSOCKET_HPP
# include <unistd.h>
# include <sys/stat.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <iostream>

#ifndef MAXTCPPORTSRTRSIZE
# define MAXTCPPORTSTRSIZE 7
#endif

typedef enum IpSockProtocols
{
	IPV4 = AF_INET,
	IPV6 = AF_INET6
}	IpSockProtocols;

class AWebSocket
{
	public:
		AWebSocket(IpSockProtocols ipProtocol, unsigned long port, char *ipAddress);
		~AWebSocket(void);
		void			closeSocket(void);
		std::string		getProtocolAsStr(void) const;
		std::string		getPortAsStr(void) const;
		std::string		getIpAsStr(void) const;
		unsigned int	getProtocolAsUInt(void) const;
		unsigned int	getPortAsUInt(void) const;
		unsigned int	getIpAsUInt(void) const;
		virtual std::string		getSocketType(void) const = 0;

		/* static functions */
		static bool isSocketFd(int fd);

	protected:
		/* internal socket fd */
		int				_sockFd;
		IpSockProtocols	_ipProtocol;
		int				_port;
		in_addr_t		_ipAddress;
};

#endif
