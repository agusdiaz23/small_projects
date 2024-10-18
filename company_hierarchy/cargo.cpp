#include <stdio.h>
#include <iostream>
#include <string.h>

#include "empleados.h"
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
	
	

	return NO_IMPLEMENTADA;
}

TipoRet ListarPersonas(Empresa e, Cadena cargo){
// Dado un cargo listar las personas asignadas al mismo ordenadas por fecha de alta a la empresa. 
// Lista todas las personas asignadas al cargo de nombre cargo. 
	if(!ifCargoExiste(cargo, getEmpresaRaiz(e))){
		return ERROR;
	}	
	else{
		Cargo c = iteradorEmpresa(cargo, getEmpresaRaiz(e)); //Encuentro cargo con el nombre pasado por parametro
		ListaEmpleados(c->empleados);//Manda imprimir a la funcion de empleados .h pasando la lista de empleados
	}
	return OK;
}

// Asigna una persona de nombre nom  y cédula de identidad ci al cargo cargo siempre que el cargo 
// exista en la empresa y esa persona no este asignada a ese u otro cargo, en caso contrario la operación 
// quedara sin efecto.
TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci){
	
	// Pido el primer cargo
	Cargo cargo_nodo = getEmpresaRaiz(e);

	if((!ifCargoExiste(cargo, getEmpresaRaiz(e))) || (existePersonaEmpresa(e,ci))) {
		return ERROR;
	}
	
	// se posiciona en cargo que debe asignar persona
	cargo_nodo = iteradorEmpresa(cargo, cargo_nodo);
	// asigna persona usando el cons empleado de empleados.h
	cargo_nodo->empleados = cons(cargo_nodo->empleados, ci, nom);
	
	return OK;
}

TipoRet ReasignarPersona(Empresa &e, Cadena cargo, Cadena ci){
	if(!ifCargoExiste(cargo,getEmpresaRaiz(e)))	{
		return ERROR;
	}
	if (!existePersonaEmpresa(e,ci)){
		return ERROR;
	}
	//Se posiciona en cargo que debe asignar persona
	Cargo cargo_nodo = getEmpresaRaiz(e);
	Cargo cargo_asignar = iteradorEmpresa(cargo, cargo_nodo);
	if (EsEmpleado(cargo_asignar->empleados,ci)){
		return ERROR;
	}
	Cargo raiz = getEmpresaRaiz(e);
	//Busco cargo que debo desasignar
	Cargo cargo_desasignar = BuscaCargoPersona(raiz,ci);
	Empleado emp_sacar = cargo_desasignar ->empleados;
	Empleado emp_poner = cargo_asignar ->empleados; 
	cargo_asignar ->empleados = ReasignaEmpleado(emp_sacar,emp_poner,ci);
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

// Itera todo el arbol buscando el cargo de la persona Ci pasa por parametro, devuelve el cargo donde este la persona o null
Cargo BuscaCargoPersona(Cargo cargos, Cadena ci) {

	if(EsEmpleado(cargos->empleados,ci)) { // Encontre un cargo con la persona como empleado
		return cargos;
	} else if(cargos->hermano == NULL && cargos->hijo == NULL) {  // Si llegue al final de ambos
		return NULL;
	} else if(cargos->hermano == NULL && cargos->hijo != NULL) { // Si llegue al final de hermano voy al hijo
		return BuscaCargoPersona(cargos->hijo, ci);
	} else if(cargos->hermano != NULL && cargos->hijo == NULL) { // Si llegue al final de hijo voy al hermano
		return BuscaCargoPersona(cargos->hermano, ci);
	} else if(cargos->hermano != NULL && cargos->hijo != NULL) { // Si hay ramas para los dos lados voy a hijo primero (exploro toda esa rama)
		Cargo result = BuscaCargoPersona(cargos->hijo, ci);
        if (result != NULL) {
            return result;
        } else {
            return BuscaCargoPersona(cargos->hermano, ci);
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
	cout << "Entre en funcion existe cargo" << endl;
	if(cargos_lista == NULL) {
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
// Esta funcion verifica si existe la CI como persona empleada en toda la empresa
bool existePersonaEmpresa(Empresa e, Cadena ci){
	
	Cargo cargo_iter = getEmpresaRaiz(e);//Cargo para iterar que inicia desde raiz
	bool retorno = false;	
	while (cargo_iter != NULL and !retorno){//Mientras cargo donde estoy no es NULL y aún no encontre a la persona sigo iterando		
		retorno = EsEmpleado (cargo_iter->empleados, ci);//En cada nodo verifico si Ci existe usando funcion pertenece de empleado.h		
		if (cargo_iter->hijo != NULL) { //Si tengo hijo avanzo a ese hijo
			cargo_iter = cargo_iter->hijo;
		}
		else if (cargo_iter->hermano != NULL){//No tiene hijo pero tiene hermano, voy a ese hermano
			cargo_iter = cargo_iter->hermano;
		}
		else {//Si estoy en una hoja sin hijo/hermano, retrocedo a padre  			
			while (cargo_iter != NULL && cargo_iter ->hermano == NULL){
				cargo_iter = cargo_iter ->padre;
			}
			if (cargo_iter != NULL){//itero en siguiente hermano
				cargo_iter = cargo_iter -> hermano;
			}
		}
	}
	// Si en algún ciclo encontre a la persona, se acaba while y retorno será true
	return retorno;
}

// Esta función imprime los parientes de un cargo
void imprimeInfoCargo(Cargo cargo) {
	cout << "Nombre: " << getCarNom(cargo) << " | " << "Nombre del hijo: " << getCarNomH(cargo) << " | " << "Nombre del padre: " << getCarNomP(cargo) << endl;
}