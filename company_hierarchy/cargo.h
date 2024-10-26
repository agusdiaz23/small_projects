#ifndef CARGO_H
#define CARGO_H

#include "definiciones.h"
#include "empresa.h"
#include "empleados.h"
#include "cargo.h"
#include "manejaListaAlf.h"



//________Funciones de imprimir 

// Imprime el arbol hasta el cargo pasado (no incluye el cargo pasado)
void imprimirArbolCargosHasta(Cargo cargos, Cadena car_nom, int ident);

// Se llama desde ListarJerarquia(). Usa un int para aumentar la identacion segun avanza por los hijos
void imprimirArbolCargos(Cargo cargos, int ident);

// Esta función imprime los parientes de un cargo (llama a funciones de tipo get para obtener la info)
void imprimeInfoCargo(Cargo cargo);

// Recibe un int y imprime ese numero de espacios
void imprimirIdent(int ident);


//________Funciones tipo get

Cadena getCarNom(Cargo cargo);
Cadena getCarNomH(Cargo cargo);
Cadena getCarNomP(Cargo cargo);


//______Funiones tipo iterar y devolver

// Itera todo el arbol usando el nodo pasado como raiz y devuelve el puntero al cargo con el nombre pasado
Cargo iteradorEmpresa(Cadena cargo, Cargo cargos);

// Itera hasta el final de la lista de cargos hijos y devuelve el ultimo miembro
Cargo iteradorCargoHermanos(Cargo cargos);

// Itera todo el arbol buscando el cargo de la persona Ci pasa por parametro, devuelve el cargo donde este la persona o null
Cargo BuscaCargoPersona(Cargo cargos, Cadena ci);
	

//_______Funcciones tipo asignar, definir y eliminar

Cargo definirCargo(Cadena cargo_nom);

// Asigno el nuevo cargo como hijo del cargo pedido
void AsignarCargoHijo(Cargo cargo_hijo, Cargo cargo_padre);

void ArbolCargo_A_ListaCargo(Cargo cargos, listaSimple &lista);

// Dado un cargo raiz pasado, eliminar ese cargo y todo lo que esta unido
Cargo eliminarCargosDesde(Cargo cargos);

// Dado un cargo raiz pasado, eliminar ese cargo y todo lo que este unido
Cargo eliminarCargos_Y_Parientes(Cargo cargos);

//Asigno persona a lista empleado de un cargo
void AsignoPersonaCargo (Cargo &cargos, Cadena ci, Cadena nombre);

void ReasignaEmpleadoEnCargo (Cargo Cdesde, Cargo Cpara, Cadena ci);

void EliminaPersonaDeCargo (Cargo cargo, Cadena ci);

void ListaEmpleadosCargo (Cargo cargo);


//_______Funciones tipo ifExiste

bool ifCargoExiste(Cadena cargo, Cargo cargos_lista);

// Esta funcion verifica si existe la CI como persona empleada en toda la empresa
bool existePersonaEmpresa(Cargo cargo_iter, Cadena ci);
	
bool EsEmpleadoEnCargo(Cargo cargo, Cadena ci);


#endif