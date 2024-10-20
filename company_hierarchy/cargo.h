#ifndef CARGO_H
#define CARGO_H

#include "definiciones.h"
#include "empresa.h"
#include "empleados.h"
#include "cargo.h"
#include "manejaListaAlf.h"

// Insertar un nuevo cargo como dependiente de otro ya existente.
// El nuevo cargo no debe existir en el sistema.
TipoRet NuevoCargo(Empresa &e, Cadena cargoPadre, Cadena nuevoCargo);

// Eliminar un cargo, junto con sus subcargos y personas asociadas.
// Elimina un cargo en la empresa si cargo ya existe en la misma.
// En otro caso la operación quedará sin efecto.
// Si el cargo a eliminar posee subcargos, éstos deberán ser eliminados también, así como
// las personas asociadas a cada uno de los cargos suprimidos.
TipoRet EliminarCargo(Empresa &e, Cadena cargo);

// Listar todos los cargos de la empresa en orden jerárquico. 
// Lista todos los cargos de la empresa ordenados por nivel jerárquico e indentados
// según se muestra el ejemplo de la letra. 
TipoRet ListarJerarquia(Empresa e);

// Listar todos los cargos ordenados alfabéticamente.
// Lista todos los cargos de la empresa ordenados alfabéticamente por nombre del cargo. 
TipoRet ListarCargosAlf(Empresa e);

// Dado un cargo listar los cargos que lo anteceden.
// Lista todas los cargos que anteceden, en la jerarquía, al cargo de nombre cargo.
TipoRet ListarSuperCargos (Empresa e, Cadena cargo);

// Asignar una persona a un cargo, si este existe.
// Asigna una persona de nombre nom  y cédula de identidad ci al cargo cargo
// siempre que el cargo exista en la empresa y esa persona no este asignada a
// ese u otro cargo, en caso contrario la operación quedará sin efecto.
TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci);

TipoRet ReasignarPersona(Empresa &e, Cadena cargo, Cadena ci);

// Eliminar una persona de un cargo.
// Elimina una persona de cédula ci de la empresa siempre y cuando la misma exista,
// en caso contrario la operación quedará sin efecto.
TipoRet EliminarPersona(Empresa &e, Cadena ci);

// Dado un cargo listar las personas asignadas al mismo ordenadas por fecha de alta a la empresa. 
// Lista todas las personas asignadas al cargo de nombre cargo. 
TipoRet ListarPersonas(Empresa e, Cadena cargo);


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





//_______Funciones tipo ifExiste

bool ifCargoExiste(Cadena cargo, Cargo cargos_lista);

// Esta funcion verifica si existe la CI como persona empleada en toda la empresa
bool existePersonaEmpresa(Empresa e, Cadena ci);
	


#endif