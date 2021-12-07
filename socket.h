#ifndef SOCKET
#define SOCKET

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

// Pura paja
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string>
#include <iostream>
#include <array>
#include <cstring>
#include <unistd.h>
#include <cerrno>
#include <exception>

#include <string>

sockaddr_in make_ip_address(int port, const std::string &ip_address);

#endif