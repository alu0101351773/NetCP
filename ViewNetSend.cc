#include "socket.h"
#include <iostream>

Message mensaje_enviado;

int main(void) {
    std::string texto("Prueba de socket: hola mundo!");
    texto.copy(mensaje_enviado.text.data(), mensaje_enviado.text.size() - 1, 0);

    sockaddr_in emisor = make_ip_address(0, "127.0.0.1");
    sockaddr_in receptor = make_ip_address(6000, "127.0.0.1");

    Socket socket_para_enviar(emisor);
    socket_para_enviar.send_to(mensaje_enviado, receptor);

    return 0;
}