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

TipoRet EliminarPersona(Empresa &e, Cadena ci) {
    if (e->cargos == NULL) {
        return ERROR;  // Si no hay cargos en la empresa, no hay empleados que eliminar
    }

    Cargo cargoActual = e->cargos;
    
    while (cargoActual != NULL) {
        Empleado actual = cargoActual->empleados;
        Empleado anterior = NULL;

            // Iterar sobre los empleados del cargo actual
        while (actual != NULL) {
            // Usar getCI para obtener la cédula y compararla
            if (strcmp(getCI(actual->personas), ci) == 0) { 
                // Si el empleado a eliminar es el primero en la lista
                if (anterior == NULL) {
                    cargoActual->empleados = actual->sig;
                    anterior->sig = actual->sig;
                }

                // Liberar la memoria del empleado
                delete actual->personas;  // Primero liberamos la persona
                delete actual;            // Luego liberamos el nodo empleado

                return OK;
            }

            // Avanzar en la lista
            anterior = actual;
            actual = actual->sig;  // Avanzar al siguiente empleado
        }

        // Avanzar al siguiente cargo
        cargoActual = cargoActual->hermano;

        return ERROR;  // La persona no fue encontrada en ningún cargo
    }

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


bool BuscarPersona(Empleado e, Cadena ci) {
    // Iterar sobre la lista de empleados
    while (e != NULL) {
        // Comparar usando strcmp
        if (e->personas != NULL && strcmp(e->personas->ci, ci) == 0) {
            return true;
        }
        e = e->sig;
    }
    return false; 
}








