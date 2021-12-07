#include "socket.h"
#include <iostream>

int main(void) {
    std::string a = "125.0.0.1";

    make_ip_address(0, a);
    std::cout << "Hola pinga\n";
    return 0;
}