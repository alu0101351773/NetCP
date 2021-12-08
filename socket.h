// PRACTICA:    ViewNet entregable 1
// AUTOR:       Jorge Cabrera Rodríguez
// ALUMNO:      alu0101351773
// FECHA:       08-12-2021

#ifndef SOCKET
#define SOCKET

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <arpa/inet.h>
#include <fcntl.h>
#include <string>
#include <iostream>

#include <array>
#include <cstring>
#include <unistd.h>
#include <cerrno>

#include <exception>


sockaddr_in make_ip_address(int port, const std::string &ip_address);



// Creamos la estructura a mandar en el send_to
struct Message {
    std::array<char, 1024> text;
};



class Socket {
    public:
        Socket(const sockaddr_in& address);
        ~Socket();
        
        void send_to(const Message& message, const sockaddr_in& address);
        void receive_from(Message& message, sockaddr_in& address);
    private:
        int fd_;    // Descriptor del socket a nivel interno
};

#endif