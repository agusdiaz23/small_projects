all: main.o empresa.o cargo.o empleados.o persona.o manejaListaAlf.o
	g++ -o main main.o empresa.o cargo.o empleados.o persona.o manejaListaAlf.o
main.o: main.cpp
	g++ -c main.cpp
empresa.o: empresa.h empresa.cpp
	g++ -c empresa.cpp
manejaListaAlf.o: manejaListaAlf.h manejaListaAlf.cpp
	g++ -c manejaListaAlf.cpp
cargo.o: cargo.h cargo.cpp
	g++ -c cargo.cpp
empleados.o: empleados.h empleados.cpp
	g++ -c empleados.cpp
persona.o: persona.h persona.cpp
	g++ -c persona.cpp

clean:
	del /Q *.o
	del /Q main.exe


