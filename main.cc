#include "socket.h"
#include <iostream>

int main(void) {
    std::string a = "";

    sockaddr_in ip = make_ip_address(0, a);
    Socket nuevo_socket(ip);
    return 0;
}