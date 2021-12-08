// PRACTICA:    ViewNet entregable 1
// AUTOR:       Jorge Cabrera Rodríguez
// ALUMNO:      alu0101351773
// FECHA:       08-12-2021

#include "socket.h"

sockaddr_in make_ip_address(int port, const std::string &ip_address) {

    // Comprobamos que el valor del puerto es positivo
    if (port < 0) {
        throw std::invalid_argument("ERROR: Puerto negativo.");
    }
    // Creamos la sockaddr_in que devolveremos mas tarde
    sockaddr_in return_address;

    return_address.sin_family = AF_INET;
    return_address.sin_port = htons(port);

    // Comprobamos que la string no este vacia
    if (!ip_address.empty()) {
        int ip_check = inet_aton(ip_address.c_str(), &return_address.sin_addr);

        // Si la IP no es valida, avisamos que es de buena eduacion
        if (!ip_check) {
            throw std::invalid_argument("ERROR: IP no permitida.");
        }
    }
    else {
        return_address.sin_addr.s_addr = htonl(INADDR_ANY);
    }
    return return_address;
}



Socket::Socket(const sockaddr_in& new_address) {
    // Creamos un socket de protocolo UDP
    fd_ = socket(AF_INET, SOCK_DGRAM, 0);

    // Comprobamos que el descriptor sea correcto
    if (fd_ < 0) {
        throw std::system_error(errno, std::system_category(), "Error al crear el socket.");
    }

    // Enlazamos el socket a la direccion (bindear)
    int bind_status = bind(fd_, reinterpret_cast<const sockaddr*>(&new_address), sizeof(new_address));

    // Comprobamos que el enlace sea correcto
    if (bind_status < 0) {
        throw std::system_error(errno, std::system_category(), "Error al bindear el socket.");
    }
}



Socket::~Socket() {
    int close_status = close(fd_);
    if (close_status < 0) {
        std::cout << "Error al cerrar el socket.";
    }
}



void Socket::send_to(const Message& message, const sockaddr_in& address) {
    // Enviamos el mensaje con la llamada del sistema 'sendto'
    int send_status = sendto(fd_, &message, sizeof(message), 0, reinterpret_cast<const sockaddr*>(&address), sizeof(address));

    // Comprobamos que se ha enviado correctamente
    if (send_status < 0) {
        throw std::system_error(errno, std::system_category(), "Error al enviar el mensaje.");
    } 
}



void Socket::receive_from(Message& message, sockaddr_in& address) {
    // Calculamos el tamaño del address
    socklen_t ad_size = sizeof(address);

    // Recibimos el mensaje de un socket desconocido (cosas de UDP)
    int receive_status = recvfrom(fd_, &message, sizeof(message), 0, reinterpret_cast<sockaddr*> (&address), &ad_size);

    // Comprobamos que se haya recibido bien
    if (receive_status < 0) {
        throw std::system_error(errno, std::system_category(), "Error al recibir el mensaje.");
    }
}