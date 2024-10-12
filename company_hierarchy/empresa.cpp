// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empresa.c
// Modulo de Implementacion de la Empresa

#include "empresa.h"
#include "cargo.h"
#include <iostream>
#include <string.h>

using namespace std;

// Inicializa la empresa y crea el primer cargo de la empresa.
// Originalmente la misma debería  estar vacía, en otro caso la operación quedará sin efecto.
TipoRet CrearOrg(Empresa &e, Cadena cargo){

	Cargo nuevo_cargo_nodo = definirCargo(cargo);
		
	e = new(nodo_empresa);
	e->cargos = nuevo_cargo_nodo;

	return OK;
}

TipoRet EliminarOrg(Empresa &e){
// Eliminar el organigrama, elimina toda la estructura del organigrama, liberando la memoria asignada.
	return NO_IMPLEMENTADA;
}

// Devuelve nodo_cargo al que apunta el nodo_empresa
Cargo getEmpresaRaiz(Empresa e) {
	Cargo nodo_raiz = e->cargos;
	return nodo_raiz;
}






