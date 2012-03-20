#include "Server.h"

Server::Server()
  : isStarted_(false)
{
}

void Server::start() {
  this->isStarted_ = true;
}

void Server::stop() {
  this->isStarted_ = false;
}

bool Server::isStarted() {
  return this->isStarted_;
}


