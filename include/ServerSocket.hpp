#ifndef SERVERSOCKET_HPP
# define SERVERSOCKET_HPP
# include "./AWebSocket.hpp"

#ifndef MAXTCPPORTSRTRSIZE
# define MAXTCPPORTSTRSIZE 7
#endif


class ServerSocket : public AWebSocket
{
	public:
		ServerSocket(IpSockProtocols ipProtocol, unsigned long port);
		~ServerSocket(void);
		void			bindSocket(void);
		int				listenSocket(int maxConnections = SOMAXCONN);
		int				acceptOnSocket(void);
		std::string		getSocketType(void) const;

		/* exceptions */
		class SocketFailedException : public std::runtime_error {
			public:
				SocketFailedException(std::string message);
		};
};

#endif
