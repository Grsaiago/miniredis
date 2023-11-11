#ifndef CONNECTIONSOCKET_HPP
# define CONNECTIONSOCKET_HPP
# include "AWebSocket.hpp"
# include <iostream>

class ConnectionSocket : public AWebSocket
{
	public:
		ConnectionSocket(int fd);
		~ConnectionSocket(void);
		std::string	receiveRequest(void);
		void		sendResponse(void);
		std::string getSocketType(void) const;

	private:
		char	*_staticBuff;
};

std::ostream	&operator<<(std::ostream &os, ConnectionSocket const &rhs);

#endif
