// PRACTICA:    ViewNet entregable 1
// AUTOR:       Jorge Cabrera Rodríguez
// ALUMNO:      alu0101351773
// FECHA:       08-12-2021

#ifndef FILE_T
#define FILE_T

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <array>
#include <cstring>
#include <unistd.h>

#include <cerrno>
#include <exception>
#include "socket.h"

// Clase hecha para agilizar la lectura de ficheros
class File {
    public:
        File(const char* file_name);
        ~File();

        ssize_t Read(Message& notepad);

    private:
        int fd_;    // Descriptor del fichero abierto
};

#endif