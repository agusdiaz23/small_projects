// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// empresa.c
// Modulo de Implementacion de la Empresa

#include <stdio.h>
#include <iostream>
#include <string.h>

#include "empresa.h"
#include "cargo.h"
#include "manejaListaAlf.h"


using namespace std;

// Empresa es simplemente un pointer al primer y unico cargo

struct  nodo_empresa {
    Cargo cargos;
};


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

	Cargo cargos = e->cargos;

	eliminarCargos_Y_Parientes(cargos); // Borro todo el arbol

	delete e; // Borro la empresa

	return OK;
}

TipoRet NuevoCargo(Empresa &e, Cadena cargoPadre, Cadena nuevoCargo){
	
	Cargo cargos = e->cargos;

	if(ifCargoExiste(nuevoCargo, cargos)) {
		return ERROR;
	}
	
	// Busco el cargo con el mismo nombre
	Cargo cargoPadre_nodo = cargos;
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
	
	Cargo cargo_a_eliminar, cargo_padre, cargo_hermano_ant, cargo_hermano_sig; // Declaro variables


	if(!ifCargoExiste(cargo, e->cargos)) // Compruebo que el cargo existe
		return ERROR;


	cargo_a_eliminar = iteradorEmpresa(cargo, e->cargos); // Busco el cargo que quiero eliminar. Esta enlazado a todo su subarbol

	eliminarCargoSeleccionado(cargo_a_eliminar);

	
	return OK;
}

TipoRet ListarCargosAlf(Empresa e){
// Listar todos los cargos ordenados alfabéticamente.
// Lista todos los cargos de la empresa ordenados alfabéticamente por nombre del cargo.


	// Itero en todos los cargos y voy añadiendo nodos a una lista que luego imprimo
	Cargo cargos = e->cargos;
	ArbolCargo_A_ListaCargo(cargos);


	return OK;
}

TipoRet ListarJerarquia(Empresa e){
// Listar todos los cargos de la empresa en orden jerárquico. 
// Lista todos los cargos de la empresa ordenados por nivel jerárquico e indentados
// según se muestra el ejemplo de la letra. 

	Cargo cargos = e->cargos;
	

	imprimirArbolCargos(cargos, 0);
	
	return OK;
}

TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci){
// Asigna una persona de nombre nom  y cédula de identidad ci al cargo cargo siempre que el cargo 
// exista en la empresa y esa persona no este asignada a ese u otro cargo, en caso contrario la operación 
// quedara sin efecto.

	// Pido el primer cargo
	Cargo cargo_nodo = e->cargos;

	if((!ifCargoExiste(cargo, cargo_nodo)) || (existePersonaEmpresa(cargo_nodo, ci))) {
		return ERROR;
	}
	
	// se posiciona en cargo que debe asignar persona
	cargo_nodo = iteradorEmpresa(cargo, cargo_nodo);
	// asigna persona usando el cons empleado de empleados.h
	AsignoPersonaCargo(cargo_nodo, ci, nom);
	
	return OK;
}

TipoRet EliminarPersona(Empresa &e, Cadena ci){
// Eliminar una persona de un cargo.
// Elimina una persona de cédula ci de la empresa siempre y cuando la misma exista,
// en caso contrario la operación quedará sin efecto.
	// Llama a una funcion que itera por toda la empresa para eliminar la cedula
	// Compruebo que la persona existe
	if(!EsEmpleadoEnCargo(e->cargos, ci))
		return ERROR;

	Cargo cargo_con_persona = BuscaCargoPersona(e->cargos, ci); // Busco el cargo con esa persona (Gracias por esta funcion Mauro)
	EliminaPersonaDeCargo(cargo_con_persona, ci); // Mando el cargo y la ci para eliminar el empleado

    return OK;
}

TipoRet ReasignarPersona(Empresa &e, Cadena cargo, Cadena ci){
	if(!ifCargoExiste(cargo, e->cargos))	{
		return ERROR;
	}
	if (!existePersonaEmpresa(e->cargos,ci)){
		return ERROR;
	}
	//Se posiciona en cargo que debe asignar persona
	Cargo cargo_asignar = iteradorEmpresa(cargo, e->cargos);
	if (EsEmpleadoEnCargo(cargo_asignar,ci)){
		return ERROR;
	}
	//Busco cargo que debo desasignar
	Cargo cargo_desasignar = BuscaCargoPersona(e->cargos,ci);
	ReasignaEmpleadoEnCargo(cargo_desasignar,cargo_asignar,ci);
	return OK;
}

TipoRet ListarPersonas(Empresa e, Cadena cargo){
// Dado un cargo listar las personas asignadas al mismo ordenadas por fecha de alta a la empresa. 
// Lista todas las personas asignadas al cargo de nombre cargo. 

	if(!ifCargoExiste(cargo, e->cargos)){
		return ERROR;
	}	
	else{
		Cargo c = iteradorEmpresa(cargo, e->cargos); //Encuentro cargo con el nombre pasado por parametro
		cout << getCarNom(c) << endl;
		ListaEmpleadosCargo(c);//Manda imprimir a la funcion de cargo.h pasandole el cargo
	}
	return OK;
}

TipoRet ListarSuperCargos (Empresa e, Cadena cargo){
// Listar todos los cargos ordenados alfabéticamente.
// Lista todos los cargos de la empresa ordenados alfabéticamente por nombre del cargo. 
	
	// Compruebo que el cargo al que quiero llegar existe
	if(!ifCargoExiste(cargo, e->cargos)) {
		return ERROR;
	}
	
	// Entro en una funcion para imprimirlo
	Cargo cargos = e->cargos;
	imprimirArbolCargosHasta(cargos, cargo, 0);
	
	return OK;
}







