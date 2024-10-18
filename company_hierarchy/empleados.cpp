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
//re direcciona nodo a la nueva lista de empleados, la idea es usar el mismo espacio de memoria
 Empleado ReasignaEmpleado(Empleado &origen, Empleado &destino, Cadena ci){
    Empleado actual = origen;
    Empleado anterior = NULL;
    bool reasignado = false;
    while (actual != NULL && !reasignado){
        Persona p = actual ->personas;
        if (strcmp(getCI(p),ci) == 0){ // Tengo que re direccionar
            if (anterior == NULL){ // Soy el primero
                origen = actual->sig;                             
            }else{ // no soy el primero
                anterior->sig = actual->sig; 
            }
            // Apunto el nodo al inicio de la lista destino
            actual->sig = destino;
            destino = actual;    
            reasignado = true;
        }
        anterior = actual;
        actual = actual->sig;        
    }
    return destino;
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

 //Verifica si persona pertenece a la lista de empleados retorna true
bool EsEmpleado(Empleado e, Cadena ci) {
   
	//Itera sobre la lista de empleados
    while (e != NULL) {
        // Comparar usando strcmp
        if (e->personas != NULL && strcmp(getCI(e->personas), ci) == 0) {
            return true;
        }
        e = e->sig;
    }
    return false; 
}
//Busca un empleado por CI y devuelve puntero a su nodo empleado
Empleado BuscaEmpleado(Empleado e, Cadena ci) {
   
	//Itera sobre la lista de empleados
    while (e != NULL) {
        // Comparar usando strcmp
        if (e->personas != NULL && strcmp(getCI(e->personas), ci) == 0) {
            return e;
        }
        e = e->sig;
    }
    return NULL; 
}

TipoRet EliminarPersona(Empresa &e, Cadena ci){
// Eliminar una persona de un cargo.
// Elimina una persona de cédula ci de la empresa siempre y cuando la misma exista,
// en caso contrario la operación quedará sin efecto.
    return NO_IMPLEMENTADA;
}














