#include "socket.h"
#include <iostream>

Message mensaje_recibido;

int main(void) {
    sockaddr_in receptor = make_ip_address(6000, "127.0.0.1");
    sockaddr_in emisor;

    Socket socket_para_recibir(receptor);

    while (true) {
        socket_para_recibir.receive_from(mensaje_recibido, emisor);
        if (!mensaje_recibido.text.empty()) {
            std::cout << mensaje_recibido.text.data() << std::endl;
            break;
        }
    }



    return 0;
}