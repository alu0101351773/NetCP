// PRACTICA:    ViewNet entregable 1
// AUTOR:       Jorge Cabrera Rodríguez
// ALUMNO:      alu0101351773
// FECHA:       08-12-2021

#include "socket.h"
#include <iostream>

Message mensaje_recibido;

int main(void) {
    sockaddr_in receptor = make_ip_address(6000, "127.0.0.1");
    sockaddr_in emisor;

    Socket socket_para_recibir(receptor);

    while (true) {
        // Recibimos los mensajes y los guardamos en 'mensaje_recibido'
        socket_para_recibir.receive_from(mensaje_recibido, emisor);
        
        // Imprimimos los mensajes
        mensaje_recibido.text[1023] = '\0';
        std::cout << mensaje_recibido.text.data() << std::endl;

    }
    return 0;
}