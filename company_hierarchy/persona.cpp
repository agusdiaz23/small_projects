#include "persona.h"
#include <iostream>
#include <stdio.h>
#include <string.h>


Persona creaPers (Cadena ci, Cadena nombre){
    Persona p = new(nodo_persona);
    p -> ci = new char[MAX_COMANDO];
    p -> nom = new char[MAX_COMANDO];
    strcpy(p->ci, ci);
    strcpy(p->nom, nombre);
    return p;
}

Persona destruir (Persona p){
    if (p != NULL){
        delete[] p->ci;
        delete[] p->nom;
        delete p;
    }
    return NULL;
}

// obtener el CI de la persona
Cadena getCI (Persona p){
    if (p != NULL) {
        return p->ci;
    }
    return NULL;
}

//obtener el nombre de la persona
Cadena getNombre (Persona p){
    if (p != NULL) {
        return p->nom;
    }
    return NULL;
}