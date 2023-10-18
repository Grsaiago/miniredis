#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void)
{
	int					fd;
	int					val = 1;
	struct sockaddr_in	conf = {};

	fd = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
	conf.sin_family = AF_INET;
	conf.sin_port = ntohs(1234);
	conf.sin_addr.s_addr = ntohl(0);
	return (0);
}
