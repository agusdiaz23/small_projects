#include "empleados.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci){
// Asigna una persona de nombre nom  y cédula de identidad ci al cargo cargo siempre que el cargo 
// exista en la empresa y esa persona no este asignada a ese u otro cargo, en caso contrario la operación 
// quedara sin efecto.
    Cadena new_ci, new_nom;
    Cargo cargos;

    // Asigno las variables a otra direccion.
    // IMPORTANTE: si no se asignan a otra memoria, el usuario las soobrescribe en la siguiente iteracion
    CopiarString(new_ci, ci);
    CopiarString(new_nom, nom);

    cargos = e->cargos;
    if(!if_PersonaExisteCargo(new_ci, cargos)){ // Si esta persona no esta en el cargo
        Persona nueva_persona = new(nodo_persona);
        nueva_persona->nom=new_nom;
        nueva_persona->ci=new_ci;
        nueva_persona->sig=NULL;

        if(cargos->sig == NULL){ // Si no hay nadie en cargo, pongo a la persona
            cargos->sig = nueva_persona;
        }
        
        else {
            Persona personas = cargos->sig; // Si hay alguien, pongo un pointer al inicio de la lista y itero
            while(personas->sig != NULL) {
                personas = personas->sig;
            }
            personas->sig = nueva_persona; // Al llegar al final de personas, pongo a la nueva
        }
        
    }
    else {

        return ERROR;
    }
    

	return OK;
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

TipoRet ListarPersonas(Empresa e, Cadena cargo){
// Dado un cargo listar las personas asignadas al mismo ordenadas por fecha de alta a la empresa. 
// Lista todas las personas asignadas al cargo de nombre cargo. 
	return NO_IMPLEMENTADA;
}

// Imprime los empleados en el cargo segun el orden de listado.
void ListarPersonasSimple(Empresa e, Cadena cargo) {
    Cargo cargos=e->cargos;
    Persona personas = cargos->sig;
    while (personas != NULL) {
        cout << "Persona: " << personas->nom << ", CI: " << personas->ci << endl;
        personas = personas->sig;
    }
}

// devuelve true si persona esta en el cargo
bool if_PersonaExisteCargo(Cadena ci, Cargo carg) {
    bool PersonaExiste=false;

    
    if(carg->sig != NULL) { // Si cargo tiene algo
        Persona pers_iter = carg->sig;
    
        while(pers_iter != NULL) {

            if(strcmp(pers_iter->ci, ci) == 0){ // Si encontre a la persona
                PersonaExiste = true;
            }
            pers_iter = pers_iter->sig;
        }
    }
    return PersonaExiste;
}

// Copia el contenido de la segunda string en la primera
int CopiarString(Cadena &new_string, Cadena old_string) {
    int size = strlen(old_string);
    new_string = new char[size+1];
    strcpy(new_string, old_string);

    return 0;

}