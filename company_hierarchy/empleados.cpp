#include "empleados.h"

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

Empleado CreaListaEmpleado(){
	return NULL;
}

Empleado cons(Empleado e, Cadena ci, Cadena nom){
// Inserta persona al inicio de lista empleado.
	Empleado aux = new(nodo_empleado);
	aux->personas = creaPers(ci,nom);
	aux->sig = e;
	return aux;
}

void ListaEmpleados(Empleado e){
	Empleado iter = e;  // Iterador desde el inicio

    while (iter != NULL) {  // Recorre la lista mientras no llegue al final
        // Accede a los datos de la persona en el nodo actual
        Persona p = iter->personas;
        
        // Imprime los datos de la persona (ci y nombre)
        cout << "CI: " << getCI(p) << ", Nombre: " << getNombre(p) << endl;

        // Avanza al siguiente nodo
        iter = iter->sig;
	}
}

bool EsEmpleado(Empleado e, Cadena ci) {

    // Itera sobre la lista de empleados
    while (e != NULL) {
        // Comparar usando strcmp con la función getCI
        if (e->personas != NULL && strcmp(getCI(e->personas), ci) == 0){
            return true;
        }
        e = e->sig; 
    }
    return false; 
}

void EliminarEmpleadoPorCI(Empleado &e, Cadena ci) {
    Empleado actual = e;
    Empleado anterior = NULL;
    bool eliminado = false;

    // Recorre la lista buscando el empleado con la CI proporcionada
    while (actual != NULL && !eliminado) {

        // Compara el CI del empleado actual
        if (strcmp(getCI(actual->personas), ci) == 0) {
            // Si es el primer nodo de la lista
            if (anterior == NULL) {
                e = actual->sig;
            } else {
                // Engancha el nodo anterior al siguiente
                anterior->sig = actual->sig;
            }
            // Libera la memoria del nodo actual
            delete actual;
            eliminado = true;  
        } else {
            // Mueve los punteros al siguiente nodo
            anterior = actual;
            actual = actual->sig;
        }
    }
}

TipoRet EliminarPersona(Empresa &e, Cadena ci){
// Eliminar una persona de un cargo.
// Elimina una persona de cédula ci de la empresa siempre y cuando la misma exista,
// en caso contrario la operación quedará sin efecto.
    return NO_IMPLEMENTADA;
}

TipoRet ReasignarPersona(Empresa &e, Cadena cargo, Cadena ci){
// Reasignar una persona a un nuevo cargo.
// Reasigna una persona de la empresa de cédula ci al nuevo cargo de nombre cargo
// siempre que el cargo exista en la empresa y esa persona no este ya asignada a
// dicho cargo. En caso contrario la operación quedará sin efecto.
	return NO_IMPLEMENTADA;
}














