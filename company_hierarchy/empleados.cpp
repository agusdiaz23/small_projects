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
    // Verifica si la empresa o los cargos están vacíos
    if (e == NULL || e->cargos == NULL) {
        return ERROR;

    Cargo cargoActual = e->cargos;  // cargos es la raíz de los cargos

    // Recorre todos los cargos
    while (cargoActual != NULL) {
        // Recorre la lista de empleados del cargo actual
        Empleado actual = cargoActual->empleados;
        Empleado anterior = NULL;

        while (actual != NULL) {
            // Verifica si el empleado actual es el que queremos eliminar
            if (strcmp(getCI(actual->personas), ci) == 0) {
                // Si es el primer empleado de la lista
                if (anterior == NULL) {
                    cargoActual->empleados = actual->hermano;  // Asigna el siguiente hermano
                } else {
                    anterior->hermano = actual->hermano;  // Conecta el anterior con el siguiente
                }

                // Liberar la memoria del nodo actual
                delete actual;

                return OK;  // El empleado fue eliminado
            }

            // Avanza al siguiente empleado
            anterior = actual;
            actual = actual->hermano;
        }

        // Recorre en el cargo hijo 
        if (cargoActual->hijo != NULL) {
            // Aquí llamamos a EliminarPersona recursivamente sobre los cargos hijos
            Empresa subEmpresa; 
            subEmpresa->cargos = cargoActual->hijo;
            TipoRet resultadoHijo = EliminarPersona(subEmpresa, ci);  // Llama a la misma función con los subcargos
            if (resultadoHijo == OK) {
                return OK;  // Eliminó el hijo
            }
        }

        // Avanza al siguiente cargo
        cargoActual = cargoActual->hermano;
    }

        return ERROR;  // Persona no encontrada
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
    if (e == NULL) {
        return false;  // No se encuentra la persona
    }

    // Comparamos la cédula del nodo actual con la que estamos buscando
    if (strcmp(getCI(e->personas), ci) == 0) {
        return true;  // Persona encontrada
    }

    // Si no la encontramos en el nodo actual, buscamos en los hijos
    if (BuscarPersona(e->hijo, ci)) {
        return true; 
    }

    // Si no la encontramos en los hijos, buscamos en los hermanos
    return BuscarPersona(e->hermano, ci);
}








