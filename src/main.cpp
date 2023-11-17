#include "../include/ConnectionSocket.hpp"
#include "../include/ServerSocket.hpp"
#include "../include/MenuItem.hpp"
#include "../include/AMenu.hpp"
#include "../include/MenuStack.hpp"
#include "../include/MainMenu.hpp"
#include <cstdlib>
#include <vector>

int	main(void)
{
	MenuStack	menuStack(std::vector<std::string>(0));

	menuStack.menuLoop();
	return (0);
}
/*
int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./myredis <server port>" << std::endl;
    return (EXIT_FAILURE);
  }
  if (std::string(argv[1]).compare("--menu") == 0) {
	  std::cout << "entrou no menu" << std::endl;
  }
  ServerSocket serverSocket(IPV4, std::atoi(argv[1]));
  std::vector<ConnectionSocket> connPool;
  int incomingConnectionFd;

  serverSocket.bindSocket();
  serverSocket.listenSocket();
  while (true) {
    incomingConnectionFd = serverSocket.acceptOnSocket();
    if (incomingConnectionFd < 0)
      continue;
    connPool.emplace_back<ConnectionSocket>(incomingConnectionFd);
    std::cout << connPool.back() << std::endl;
  }
  return (EXIT_FAILURE);
  serverSocket.closeSocket();
  return (EXIT_SUCCESS);
}
*/
