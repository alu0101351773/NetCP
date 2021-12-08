// PRACTICA:    ViewNet entregable 1
// AUTOR:       Jorge Cabrera Rodríguez
// ALUMNO:      alu0101351773
// FECHA:       08-12-2021

#include "socket.h"
#include <iostream>

Message mensaje_enviado;

int main(void) {

    // Establecemos las direcciones a utilizar
    sockaddr_in emisor = make_ip_address(0, "127.0.0.1");
    sockaddr_in receptor = make_ip_address(6000, "127.0.0.1");

    // Creamos el socket emisor
    Socket socket_para_enviar(emisor);

    // Abrimos el archivo de prueba
    int test_fd = open("prueba.txt", O_RDONLY);
    if (test_fd < 0) {
        throw std::system_error(errno, std::system_category(), "Error al abrir el fichero");
    }

    // Leemos el archivo
    while (read(test_fd, &mensaje_enviado.text, sizeof(mensaje_enviado.text) - 1) != 0) {
        // Enviamos el mensaje leido
        socket_para_enviar.send_to(mensaje_enviado, receptor);
    }  
    
    // Cerramos el archivo
    int close_status = close(test_fd);
    if (close_status < 0) {
        throw std::system_error(errno, std::system_category(), "Error al cerrar el fichero");
    }
    
    return 0;
}