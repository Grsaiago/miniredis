#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>


int	throwErrorInC(int errnoCode, char *perrorValue)
{
	errno = errnoCode;
	write(2, "Error!\n", 7);
	perror(perrorValue);
	return (1);
}
int main(void)
{
	int					fd;
	int					val = 1;
	struct sockaddr_in	socketConf = {};

	// get the socket fd
	// AF_INET é de internet protocol
	// SOCK_STREAM é pra uma stream bidirecional (TCP)
	// 0 é o argumento padrão pq usa-se só esse protocolo AF_INET
	// https://man7.org/linux/man-pages/man2/socket.2.html
	fd = socket(AF_INET, SOCK_STREAM, 0);

	//  configurar o socket
	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

	// configurar a conexão do socket e dar bind
	socketConf.sin_family = AF_INET;
	socketConf.sin_port = ntohs(1234);
	socketConf.sin_addr.s_addr = ntohl(0);
	if (bind(fd, (const sockaddr *)&socketConf, sizeof(socketConf)) != 0)
		return (throwErrorInC(EPROTO, "bind() failed"));
	// escutar nesse socket nas confs settadas
	if (listen(fd, SOMAXCONN))
			return (throwErrorInC(EPROTO, "listen() failed"));

	return (0);
}
