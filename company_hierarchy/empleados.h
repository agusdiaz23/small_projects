#ifndef EMPLEADOS_H
#define EMPLEADOS_H

#include "definiciones.h"
#include "persona.h"
#include "cargo.h"

// ________Funciones tipo definir

<<<<<<< HEAD

TipoRet EliminarPersona(Empresa &e, Cadena ci);
// Eliminar una persona de un cargo.
// Elimina una persona de cédula ci de la empresa siempre y cuando la misma exista,
// en caso contrario la operación quedará sin efecto.

TipoRet ReasignarPersona(Empresa &e, Cadena cargo, Cadena ci);
// Reasignar una persona a un nuevo cargo.
// Reasigna una persona de la empresa de cédula ci al nuevo cargo de nombre cargo
// siempre que el cargo exista en la empresa y esa persona no este ya asignada a
// dicho cargo. En caso contrario la operación quedará sin efecto.

//Define una lista vacia de empleados
=======
>>>>>>> c4b554be68c87e4e2810f6fa0f866d433ca8434c
Empleado CreaListaEmpleado();



// ________Funciones tipo manipular nodos (iterar, devolver y eliminar)

// Inserta persona al inicio de lista empleado.
Empleado consEmpleado(Empleado e, Cadena ci, Cadena nom);

//re direcciona nodo a la nueva lista de empleados, la idea es usar el mismo espacio de memoria
void ReasignaEmpleado(Empleado &origen, Empleado &destino, Cadena ci);

//Busca un empleado por CI y devuelve puntero a su nodo empleado
Empleado BuscaEmpleado(Empleado e, Cadena ci);

void EliminarEmpleadoPorCI(Empleado &e, Cadena ci);

// Elimina toda la lista de empleados
Empleado EliminarEmpleadosLista(Empleado e);




// __________Funciones tipo imprimir

//Lista las personas de una lista empleados
void ListaEmpleados(Empleado e);

//Verifica si persona de cedula CI existe en lista empleado
bool EsEmpleado(Empleado e, Cadena ci);

<<<<<<< Updated upstream
//Eliminar de la lista de empleados si encontro la CI
void EliminarEmpleadoPorCI(Empleado &e, Cadena ci);
=======

// _________Funciones tipo ifExiste

//Verifica si persona pertenece a la lista de empleados retorna true
bool EsEmpleado(Empleado e, Cadena ci);

>>>>>>> Stashed changes


#endif




