#include <stdio.h>
#include <iostream>
#include <string.h>

#include "manejaListaAlf.h"

using namespace std;


// Esta lista contiene solo el nombre de los cargos. Se ordenara alfabeticamente
struct nodo_listaSimple {
    listaSimple sig;
    Cadena nombre;
};


listaSimple ordenarListaAlf(listaSimple lista) {
    bool sorted = false;
    listaSimple act, fut, ant;

    
    while(sorted == false) {
        act = lista;
        fut = lista->sig;
        ant = NULL;


        while(fut != NULL) {
            // Si no esta por orden alfabetico y al principio de la lista
            // Devuelve true si mi palabra es mas grande 
            if( strcasecmp( getListaSimpleNom(act), getListaSimpleNom(fut) ) > 0 ) {
                // Invierto los nodos
                if(ant == NULL) {
                    act->sig = fut->sig;
                    fut->sig = act;
                    lista = fut;
                    
                }
                else {
                    ant->sig = fut;
                    act->sig = fut->sig;
                    fut->sig = act;

                }
            }

            // Muevo los pointer hacia adelante en la lista
            ant = act;
            act = fut;
            fut = act->sig;
        }
        
        sorted = ifListSorted(lista);
    }

    return lista;
}

bool ifListSorted(listaSimple lista) {
    listaSimple act, fut, ant, aux_1, aux_2;
    act = lista;
    fut = lista->sig;

    while(fut != NULL) {
        if( strcasecmp( getListaSimpleNom(act), getListaSimpleNom(fut) ) > 0 ) {
            return false;
        }

        // Muevo los pointer hacia adelante en la lista
        act = fut;
        fut = fut->sig;
    }

    return true;
}



void imprimeListaSimple(listaSimple lista) {
    if(lista == NULL) {
        return;
    }
    else {
        cout << getListaSimpleNom(lista) << endl;
        imprimeListaSimple(lista->sig);
    }
}


/* Recibe un nodo y una lista y lo asigna
Si bool = true no copia string. 
Si bool = false copia la string */


void setNom(listaSimple lista, Cadena nombre) {
// Recibe un nodo de lista vacio y pone el nombre en el dato
    lista->nombre = nombre;
}  

// Devuelve un pointer al dato
Cadena getListaSimpleNom(listaSimple lista){
    return lista->nombre;
}

listaSimple definirListaSimple(Cadena nombre) {
    listaSimple nuevaLista = new(nodo_listaSimple);
    setNom(nuevaLista, nombre);
    nuevaLista->sig=NULL;

    return nuevaLista;
}

void concatenarLista(listaSimple &lista, listaSimple nuevaLista) {
    	// Si estoy en una lista que no se inicializo, mi nuevo nodo sera el primero
		if(lista == NULL) {
			lista = nuevaLista;
		}
		else {
			nuevaLista->sig = lista;
			lista = nuevaLista;
		}
}

listaSimple definirListaSimpleVacia() {
    return NULL;
}