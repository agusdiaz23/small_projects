#ifndef MANEJALISTAALF_H
#define MANEJALISTAALF_H

#include "definiciones.h"

typedef struct nodo_listaSimple * listaSimple;


void imprimeListaSimple(listaSimple lista);

void setNom(listaSimple lista, Cadena nombre);

Cadena getListaSimpleNom(listaSimple lista);

listaSimple definirListaSimple();

listaSimple ordenarListaAlf(listaSimple lista);

bool ifListSorted(listaSimple lista);

// Esta funcion recibe dos string. Las compara char a char. Si string_a > string_b (alfabeticamente) devuelve true
bool compareStringsAlf(int indice, Cadena string_a, Cadena string_b);

#endif