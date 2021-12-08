// PRACTICA:    ViewNet entregable 1
// AUTOR:       Jorge Cabrera Rodríguez
// ALUMNO:      alu0101351773
// FECHA:       08-12-2021
#include "file.h"

File::File(const char *file_name) {
    fd_ = open(file_name, O_RDONLY);

    if (fd_ < 0) {
        throw std::system_error(errno, std::system_category(), "Error al abrir el fichero");
    }
}



File::~File() {
    close(fd_);
}



ssize_t File::Read(Message& notepad) {
    return read(fd_, &notepad.text, sizeof(notepad.text) - 1);
}