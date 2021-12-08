// PRACTICA:    ViewNet entregable 1
// AUTOR:       Jorge Cabrera Rodríguez
// ALUMNO:      alu0101351773
// FECHA:       08-12-2021

#include "socket.h"
#include "file.h"
#include <iostream>

Message mensaje_enviado;

int main(void) {

    // Establecemos las direcciones a utilizar
    sockaddr_in emisor = make_ip_address(0, "127.0.0.1");
    sockaddr_in receptor = make_ip_address(6000, "127.0.0.1");

    // Creamos el socket emisor
    Socket socket_para_enviar(emisor);

    // Abrimos el archivo de prueba con nuestra clase File
    File input("prueba.txt");

    // Leemos el archivo
    while ( input.Read(mensaje_enviado) != 0) {
        // Enviamos el mensaje leido
        socket_para_enviar.send_to(mensaje_enviado, receptor);
    }  
    
    return 0;
}