#include <stdio.h>
#include <iostream>
#include <string.h>


#include "definiciones.h"
#include "empresa.h"
#include "cargo.h"

using namespace std;

TipoRet NuevoCargo(Empresa &e, Cadena cargoPadre, Cadena nuevoCargo){
	
	Cargo cargoPadre_nodo = getEmpresaRaiz(e);
	cargoPadre_nodo = iteradorEmpresa(cargoPadre, cargoPadre_nodo);

	if (cargoPadre_nodo == NULL) { // Sino hay cargo padre
		cout << "ERROR AL CREAR CARGO" << endl;
	} else { // Si hay cargo padre

		Cargo nuevoHijo_nodo = definirCargo(nuevoCargo);
		AsignarCargoHijo(nuevoHijo_nodo, cargoPadre_nodo);
	}

	cout << "Se imprime arbol: " << endl;
	ImprimirArbolCargos(getEmpresaRaiz(e));

	return OK;
}

// Hace un cargo y devuelve el puntero
Cargo makePrimerCargo(Cadena cargo_nom) {
	//Creo un cargo
	Cargo nuevo_cargo = definirCargo(cargo_nom);

	return nuevo_cargo;
}

TipoRet EliminarCargo(Empresa &e, Cadena cargo){
// Eliminar un cargo, junto con sus subcargos y personas asociadas.
// Elimina un cargo en la empresa si cargo ya existe en la misma.
// En otro caso la operación quedará sin efecto.
// Si el cargo a eliminar posee subcargos, éstos deberán ser eliminados también, así como
// las personas asociadas a cada uno de los cargos suprimidos.
	return NO_IMPLEMENTADA;
}

TipoRet ListarCargosAlf(Empresa e){
// Listar todos los cargos ordenados alfabéticamente.
// Lista todos los cargos de la empresa ordenados alfabéticamente por nombre del cargo. 
	return NO_IMPLEMENTADA;
}

// Listar todos los cargos de la empresa en orden jerárquico. 
// Lista todos los cargos de la empresa ordenados por nivel jerárquico e indentados
// según se muestra el ejemplo de la letra. 
TipoRet ListarJerarquia(Empresa e){
	return NO_IMPLEMENTADA;
}

TipoRet ListarSuperCargos (Empresa e, Cadena cargo){
// Dado un cargo listar los cargos que lo anteceden.
// Lista todas los cargos que anteceden, en la jerarquía, al cargo de nombre cargo.
	return NO_IMPLEMENTADA;
}

TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci){
// Asigna una persona de nombre nom  y cédula de identidad ci al cargo cargo siempre que el cargo 
// exista en la empresa y esa persona no este asignada a ese u otro cargo, en caso contrario la operación 
// quedara sin efecto.
   

	return NO_IMPLEMENTADA;
}

Cadena getCarNom(Cargo cargo){
	if(cargo != NULL) {
		return cargo->nombre;
	}
		return NULL;
}

Cargo definirCargo(Cadena cargo_nom) {
	
	Cargo nuevo_cargo = new(nodo_cargo);
	nuevo_cargo->empleados = CreaListaEmpleado();
	nuevo_cargo->hijo = NULL;
	nuevo_cargo->hermano = NULL;
	nuevo_cargo->padre = NULL;

	Cadena nombre = new char[MAX_COMANDO];
	strcpy(nombre, cargo_nom);
	nuevo_cargo->nombre = nombre;
	
	return nuevo_cargo;
}

// Asigno el nuevo cargo como hijo del cargo pedido
void AsignarCargoHijo(Cargo cargo, Cargo cargo_padre) {
	if(cargo_padre->hijo == NULL) { // Si nunca se asigno un cargo hijo al cargo padre
		cargo_padre->hijo = cargo;
	} 
	else { // Si ya se asigno uno, itero hasta el final de la lista y lo agrego

	}
}

// Itera todo el arbol usando el nodo pasado como raiz y devuelve el puntero al cargo con el nombre pasado
Cargo iteradorEmpresa(Cadena cargo, Cargo cargos) {

	//Estoy diseñando una funcion que itera todo el arbol
	if(strcmp(cargos->nombre, cargo) == 0) { // Encontre un cargo con el mismo nombre
		return cargos;
	
	} else if(cargos->hermano == NULL && cargos->hijo == NULL) {  // Si llegue al final de ambos
		return NULL;
	
	} else if(cargos->hermano == NULL && cargos->hijo != NULL) { // Si llegue al final de hermano
		cargos = iteradorEmpresa(cargo, cargos->hijo);
		return cargos;
	
	} else if(cargos->hermano != NULL && cargos->hijo == NULL) { // Si llegue al final de hijo
		cargos = iteradorEmpresa(cargo, cargos->hermano);
		return cargos;
	
	} else {
		cargos = (iteradorEmpresa(cargo, cargos->hijo), iteradorEmpresa(cargo, cargos->hermano));
		return cargos;
	}

}

// Itera hasta el final de la lista de cargos hijos y devuelve el ultimo miembro
Cargo iteradorCargoHermanos(Cargo cargos) {
	if(cargos->hermano == NULL) {
		return cargos;
	}
	else if(cargos->hermano != NULL) {
		return iteradorCargoHermanos(cargos->hermano);
	}
}

// Imprime el arbol a partir del cargo dado
Cargo ImprimirArbolCargos(Cargo cargos) {
	if(cargos == NULL) {
		return NULL;
	}
	else if(cargos->hijo == NULL && cargos->padre == NULL) {
		cout << "Nombre: " << getCarNom(cargos) << endl;
		return NULL;
	}
	else if(cargos->hijo != NULL && cargos->padre == NULL) {
		cout << "Nombre: " << getCarNom(cargos) << endl;
		return (ImprimirArbolCargos(cargos->hijo));
		
	}
	else if(cargos->hijo != NULL && cargos->padre == NULL) {
		cout << "Nombre: " << getCarNom(cargos) << endl;
		return (ImprimirArbolCargos(cargos->padre));
		
	}
	else if(cargos->hijo != NULL && cargos->padre != NULL) {
		cout << "Nombre: " << getCarNom(cargos) << endl;
		return (ImprimirArbolCargos(cargos->hijo), ImprimirArbolCargos(cargos->padre));
		
	}

}