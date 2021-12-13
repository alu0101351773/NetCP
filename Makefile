# PRACTICA:    ViewNet entregable 1
# AUTOR:       Jorge Cabrera Rodríguez
# ALUMNO:      alu0101351773
# FECHA:       08-12-2021

# Código objeto del socket
socket:
	g++ -c socket.cc -o socket.o


# Código objeto del file
file:
	g++ -c file.cc -o file.o


# Ejecutable del send
send:
	g++ socket.o file.o ViewNetSend.cc -o emisor/send 


# Ejecutable del receive
receive:
	g++ socket.o file.o ViewNetReceive.cc -o receptor/receive


# Compilamos todo de una vez
all: socket file send receive

tar:
	tar -v -czf ViewNet.tar.gz *


# Limpiamos los archivos residuales y ejecutables
clean:
	rm -r -f *.o */send */receive *.tar.gz
