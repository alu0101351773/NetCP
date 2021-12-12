// PRACTICA:    ViewNet entregable 1
// AUTOR:       Jorge Cabrera Rodríguez
// ALUMNO:      alu0101351773
// FECHA:       08-12-2021

#include "socket.h"
#include <iostream>

Message mensaje_recibido;

int protected_main(void) {
    sockaddr_in receptor = make_ip_address(6000, "pepinillos");
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



int main(void) {

    try {
        return protected_main();
    }
    catch(std::invalid_argument& e) {
        std::cerr << "ViewNetSend (argumento inválido): " << e.what() << '\n';
        return 2;
    }
    catch(std::system_error& e) {
        std::cerr << "ViewNetSend (error del sistema): " << e.what() << '\n';
        return 2;
    }

    return 0;
}