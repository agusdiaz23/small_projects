all: main.o empresa.o empleados.o persona.o
	g++ -o main main.o empresa.o cargo.o empleados.o persona.o
main.o: main.cpp
	g++ -c main.cpp
empresa.o: empresa.h empresa.cpp empleados.h empleados.cpp persona.h persona.cpp cargo.h cargo.cpp
	g++ -c empresa.cpp empleados.cpp persona.cpp cargo.cpp
clean:
	del /Q *.o
	del /Q main.exe

