// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empresa.c
// Modulo de Implementacion de la Empresa

#include "empresa.h"
#include <iostream>

using namespace std;


TipoRet CrearOrg(Empresa &e, Cadena cargo){
// Inicializa la empresa y crea el primer cargo de la empresa.
// Originalmente la misma debería  estar vacía, en otro caso la operación quedará sin efecto.

	//Creo un cargo
	Cargo nuevo_cargo = new(nodo_cargo);
	nuevo_cargo->nombre=cargo;
	nuevo_cargo->personas=NULL;

	//Creo la empresa y le asigno el cargo
	e = new(nodo_empresa);
	e->cargos=nuevo_cargo;

	return OK;
}

TipoRet EliminarOrg(Empresa &e){
// Eliminar el organigrama, elimina toda la estructura del organigrama, liberando la memoria asignada.
	return NO_IMPLEMENTADA;
}




