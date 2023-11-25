#include "ConnectionSocket.hpp"
#include "ServerSocket.hpp"
#include "MenuItem.hpp"
#include "AMenu.hpp"
#include "MenuStack.hpp"
#include "UtilsMenu.hpp"
#include "MainMenu.hpp"


int	main(void)
{
	MenuStack *menuStack = new MenuStack({new MainMenu()});

	menuStack->menuStackLoop();
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
