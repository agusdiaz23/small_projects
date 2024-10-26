#include "empleados.h"

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct nodo_empleado {
    Persona personas;
    Empleado sig;
};



// ________Funciones tipo definir

Empleado CreaListaEmpleado(){
	return NULL;
}



// ________Funciones tipo manipular nodos (iterar, devolver y eliminar)

Empleado consEmpleado(Empleado e, Cadena ci, Cadena nom){
// Inserta persona al inicio de lista empleado.
	Empleado aux = new(nodo_empleado);
	aux->personas = creaPers(ci,nom);
	aux->sig = e;
	return aux;
}

void ReasignaEmpleado(Empleado &origen, Empleado &destino, Cadena ci){
//re direcciona nodo a la nueva lista de empleados, la idea es usar el mismo espacio de memoria

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
            reasignado = true;// Corto ciclo para que no vuelva a entrar a while ya que actual ahora apunta a lista destino
        }
        anterior = actual;
        actual = actual->sig;        
    }
}

Empleado BuscaEmpleado(Empleado e, Cadena ci) {
//Busca un empleado por CI y devuelve puntero a su nodo empleado

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

void EliminarEmpleadoPorCI(Empleado &e, Cadena ci) {
    Empleado actual = e;
    Empleado anterior = NULL;
    bool eliminado = false;

    // Recorre la lista buscando el empleado con la CI proporcionada
    while (actual != NULL && !eliminado) {

        // Compara el CI del empleado actual con el proporcionado
        if (strcmp(getCI(actual->personas), ci) == 0) {
            // Si es el primer nodo de la lista
            if (anterior == NULL) {
                e = actual->sig;
            } else {
                // Engancha el nodo anterior al siguiente
                anterior->sig = actual->sig;
            }
            // Libera la memoria del nodo actual
            destruir (actual->personas);
            delete actual;
            eliminado = true;  
        } else {
            // Mueve los punteros al siguiente nodo
            anterior = actual;
            actual = actual->sig;
        }
    }
}


Empleado EliminarEmpleadosLista(Empleado e) {
// Elimina toda la lista de empleados
    
    if(e == NULL) {
        return NULL;
    }

    if(e->sig == NULL) { // Si mi siguiente nodo es nulo elimino el nodo en el que estoy parado
        e->personas = destruir(e->personas); // Destruye la persona (sus datos) y devuelve un null
        delete e; // Destruye el nodo en el que estoy parado
        return NULL; // Salgo de esta iteracion
    }
    else if (e->sig != NULL) { // Si todavia no estoy al final de la lista
        EliminarEmpleadosLista(e->sig);

        e->personas = destruir(e->personas); // Destruye la persona (sus datos) y devuelve un null
        delete e; // Destruye el nodo en el que estoy parado

    }
    return NULL;
}

// __________Funciones tipo imprimir

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



// _________Funciones tipo ifExiste

bool EsEmpleado(Empleado e, Cadena ci) {
//Verifica si persona pertenece a la lista de empleados retorna true

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









