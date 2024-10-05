all: main.o empresa.o 
	g++ -o main main.o empresa.o 
main.o: main.cpp
	g++ -c main.cpp
empresa.o: empresa.h empresa.cpp
	g++ -c empresa.cpp
clean:
	del /Q *.o
	del /Q main.exe

