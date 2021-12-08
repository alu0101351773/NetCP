# PRACTICA:    ViewNet entregable 1
# AUTOR:       Jorge Cabrera Rodríguez
# ALUMNO:      alu0101351773
# FECHA:       08-12-2021

socket.o:
	g++ -c socket.cc -o socket.o

file.o:
	g++ -c file.cc -o file.o

send:
	g++ socket.o file.o ViewNetSend.cc -o send 

receive: socket.o

all: send receive

clean:
	rm -f *.o send receive