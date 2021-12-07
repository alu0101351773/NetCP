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