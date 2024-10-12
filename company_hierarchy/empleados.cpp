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

TipoRet EliminarPersona(Empresa &e, Cadena ci){
    if (e == NULL || e->cargos == NULL) { // La empresa o los cargos están vacíos
        return ERROR;  
    }

    Cargo cargoActual = e->cargos;
    bool personaEliminada = false;  // Bandera para saber si se eliminó la persona

    while (cargoActual != NULL) {
        Empleado actual = cargoActual->empleados;
        Empleado anterior = NULL;

        // Recorremos la lista de empleados en el cargo actual
        while (actual != NULL) {
            if (strcmp(getCI(actual->personas), ci) == 0) {
				// Si es el primer empleado de la lista
                if (anterior == NULL) { 
                    cargoActual->empleados = actual->sig;
                } else {
                    anterior->sig = actual->sig;
                }
                // Liberar la memoria del nodo y de la persona
                delete actual->personas;
                delete actual;

                personaEliminada = true;
                return OK;  // Retorna OK después de eliminar la persona
            }
            // Avanzamos al siguiente nodo
            anterior = actual;
            actual = actual->sig;
        }
        // Si no encontramos la persona en el cargo actual, continuamos con el siguiente cargo (hermano o hijo)
        cargoActual = cargoActual->hermano;  // Cambiar si deseas buscar en los hijos también
    }

    return ERROR;  // Si no se encontró la persona en ningún cargo
}

TipoRet ReasignarPersona(Empresa &e, Cadena cargo, Cadena ci){
// Reasignar una persona a un nuevo cargo.
// Reasigna una persona de la empresa de cédula ci al nuevo cargo de nombre cargo
// siempre que el cargo exista en la empresa y esa persona no este ya asignada a
// dicho cargo. En caso contrario la operación quedará sin efecto.
	return NO_IMPLEMENTADA;
}

TipoRet ListarPersonas(Empresa e, Cadena cargo){
// Dado un cargo listar las personas asignadas al mismo ordenadas por fecha de alta a la empresa. 
// Lista todas las personas asignadas al cargo de nombre cargo. 
	return NO_IMPLEMENTADA;
}












