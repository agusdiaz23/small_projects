all: main.o empresa.o empleados.o
	g++ -o main main.o empresa.o empleados.o
main.o: main.cpp
	g++ -c main.cpp
empresa.o: empresa.h empresa.cpp empleados.cpp
	g++ -c empresa.cpp empleados.cpp
clean:
	del /Q *.o
	del /Q main.exe

