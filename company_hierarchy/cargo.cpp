#include <stdio.h>
#include <iostream>
#include <string.h>


#include "definiciones.h"
#include "cargo.h"

using namespace std;

TipoRet NuevoCargo(Empresa &e, Cadena cargoPadre, Cadena nuevoCargo){
	
	if(ifCargoExiste(nuevoCargo, getEmpresaRaiz(e))) {
		return ERROR;
	}
	
	// Busco el cargo con el mismo nombre
	Cargo cargoPadre_nodo = getEmpresaRaiz(e);
	cargoPadre_nodo = iteradorEmpresa(cargoPadre, cargoPadre_nodo);

	// Asigno el nuevo nodo como hijo
	if (cargoPadre_nodo == NULL) {
		cout << ERROR << endl;
	} else {
		Cargo nuevoHijo_nodo = definirCargo(nuevoCargo);
		AsignarCargoHijo(nuevoHijo_nodo, cargoPadre_nodo);
	}


	return OK;
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
	Cargo cargos = getEmpresaRaiz(e);
	imprimirArbolCargos(cargos, 0);
	
	return OK;
}

// Dado un cargo listar los cargos que lo anteceden.
TipoRet ListarSuperCargos (Empresa e, Cadena cargo){
	
	// Empiezo por buscar el cargo pedido en el arbol. Me quedo con el puntero
	Cargo cargos = getEmpresaRaiz(e);
	cargos = iteradorEmpresa(cargo, cargos);

	// Le paso el puntero a la funcion de imprimir
	imprimirArbolCargosUntil(cargos, cargo, 0); // El 0 se puede cambiar para mover todo el arbol a la derecha


	return NO_IMPLEMENTADA;
}

// Imprime  el arbol hasta que encuentra el cargo que se le paso
bool imprimirArbolCargosUntil(Cargo cargos, Cadena car_nom, int ident) {
	if(strcmp(getCarNom(cargos), car_nom)==0) {
		return true;
	}

	if(!imprimirArbolCargos){
		
	}

}

// Asigna una persona de nombre nom  y cédula de identidad ci al cargo cargo siempre que el cargo 
// exista en la empresa y esa persona no este asignada a ese u otro cargo, en caso contrario la operación 
// quedara sin efecto.
TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci){
	
	// Pido el primer cargo
	Cargo cargo_nodo = getEmpresaRaiz(e);
	cargo_nodo = iteradorEmpresa(cargo, cargo_nodo);

	cargo_nodo->empleados = cons(cargo_nodo->empleados, ci, nom);
	

	return OK;
}

Cadena getCarNom(Cargo cargo){
	if(cargo != NULL) {
		return cargo->nombre;
	} else
		return NULL;
}

Cadena getCarNomH(Cargo cargo){
	if(cargo->hijo != NULL) {
		cargo = cargo->hijo;
		return cargo->nombre;
	} else
		return NULL;
}

Cadena getCarNomP(Cargo cargo){
	if(cargo->padre != NULL) {
		cargo = cargo->padre;
		return cargo->nombre;
	} else
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
void AsignarCargoHijo(Cargo cargo_hijo, Cargo cargo_padre) {
	
	// Voy al final de la lista de cargos hermanos
	if(cargo_padre->hijo == NULL) {
		cargo_padre->hijo=cargo_hijo;
		
		cargo_hijo->padre = cargo_padre;
	} else {
		Cargo cargo_hermano = iteradorCargoHermanos(cargo_padre->hijo);
		cargo_hermano->hermano = cargo_hijo;
		
		cargo_hijo->padre = cargo_padre;
	}
}

// Itera todo el arbol usando el nodo pasado como raiz y devuelve el puntero al cargo con el nombre pasado
Cargo iteradorEmpresa(Cadena cargo, Cargo cargos) {

	if(strcmp(cargos->nombre, cargo) == 0) { // Encontre un cargo con el mismo nombre
		return cargos;
	} else if(cargos->hermano == NULL && cargos->hijo == NULL) {  // Si llegue al final de ambos
		return NULL;
	} else if(cargos->hermano == NULL && cargos->hijo != NULL) { // Si llegue al final de hermano voy al hijo
		return iteradorEmpresa(cargo, cargos->hijo);
	} else if(cargos->hermano != NULL && cargos->hijo == NULL) { // Si llegue al final de hijo voy al hermano
		return iteradorEmpresa(cargo, cargos->hermano);
	} else if(cargos->hermano != NULL && cargos->hijo != NULL) { // Si hay ramas para los dos lados voy a hijo primero (exploro toda esa rama)
		Cargo result = iteradorEmpresa(cargo, cargos->hijo);
        if (result != NULL) {
            return result;
        } else {
            return iteradorEmpresa(cargo, cargos->hermano);
        }
	}
}

// Itera hasta el final de la lista de cargos hijos y devuelve el ultimo miembro
Cargo iteradorCargoHermanos(Cargo cargos) {
	
	if(cargos->hermano == NULL) {
		return cargos;
	}
	else if(cargos->hermano != NULL) {
		return (iteradorCargoHermanos(cargos->hermano));
	}
	
}


// Se llama desde ListarJerarquia(). Usa un int para aumentar la identacion segun avanza por los hijos
void imprimirArbolCargos(Cargo cargos, int ident) {
	if(cargos == NULL) {
	} else {
		imprimirIdent(ident);
		cout << "->" << getCarNom(cargos) << endl;

		if(cargos->hijo != NULL) {
			imprimirArbolCargos(cargos->hijo, ident + 2);
		}
		if(cargos->hermano != NULL) {
			imprimirArbolCargos(cargos->hermano, ident);
		}
	}
}

// Recibe un int y imprime ese numero de espacios
void imprimirIdent(int ident) {
	for(int i = 0; i<=ident; i++) {
		cout << " ";
	}
}


bool ifCargoExiste(Cadena cargo, Cargo cargos_lista) {

	if(cargo == NULL) {
		return false;
	} else if(strcmp(cargos_lista->nombre, cargo) == 0) {
		return true;
	} else if(cargos_lista->hijo != NULL && cargos_lista->hermano != NULL) {
		return (ifCargoExiste(cargo, cargos_lista->hijo) || ifCargoExiste(cargo, cargos_lista->hermano));
	} else if(cargos_lista->hijo != NULL && cargos_lista->hermano == NULL) {
		return ifCargoExiste(cargo, cargos_lista->hijo);
	} else if(cargos_lista->hijo == NULL && cargos_lista->hermano != NULL) {
		return ifCargoExiste(cargo, cargos_lista->hermano);
	} else if(cargos_lista->hijo == NULL && cargos_lista->hermano == NULL) {
		return false;
	}
}

// Esta función imprime los parientes de un cargo
void imprimeInfoCargo(Cargo cargo) {
	cout << "Nombre: " << getCarNom(cargo) << " | " << "Nombre del hijo: " << getCarNomH(cargo) << " | " << "Nombre del padre: " << getCarNomP(cargo) << endl;
}