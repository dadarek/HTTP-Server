#include "Server.h"
#include <iostream>

int main(int, char**) {
  Server server;

  server.start();

  std::cout << "All is good Hello" << std::endl;
}

