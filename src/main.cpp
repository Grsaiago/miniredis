#include "../include/ConnectionSocket.hpp"
#include "../include/ServerSocket.hpp"
#include <cstdlib>
#include <vector>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./myredis <server port>" << std::endl;
    return (EXIT_FAILURE);
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
