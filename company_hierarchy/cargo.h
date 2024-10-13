#ifndef CARGO_H
#define CARGO_H

#include "definiciones.h"
#include "empresa.h"
#include "empleados.h"
#include "cargo.h"


TipoRet AsignarPersona(Empresa &e, Cadena cargo, Cadena nom, Cadena ci);
// Asignar una persona a un cargo, si este existe.
// Asigna una persona de nombre nom  y cédula de identidad ci al cargo cargo
// siempre que el cargo exista en la empresa y esa persona no este asignada a
// ese u otro cargo, en caso contrario la operación quedará sin efecto.

TipoRet NuevoCargo(Empresa &e, Cadena cargoPadre, Cadena nuevoCargo);
// Insertar un nuevo cargo como dependiente de otro ya existente.
// El nuevo cargo no debe existir en el sistema.

TipoRet EliminarCargo(Empresa &e, Cadena cargo);
// Eliminar un cargo, junto con sus subcargos y personas asociadas.
// Elimina un cargo en la empresa si cargo ya existe en la misma.
// En otro caso la operación quedará sin efecto.
// Si el cargo a eliminar posee subcargos, éstos deberán ser eliminados también, así como
// las personas asociadas a cada uno de los cargos suprimidos.

TipoRet ListarCargosAlf(Empresa e);
// Listar todos los cargos ordenados alfabéticamente.
// Lista todos los cargos de la empresa ordenados alfabéticamente por nombre del cargo. 

TipoRet ListarJerarquia(Empresa e);
// Listar todos los cargos de la empresa en orden jerárquico. 
// Lista todos los cargos de la empresa ordenados por nivel jerárquico e indentados
// según se muestra el ejemplo de la letra. 


TipoRet ListarSuperCargos (Empresa e, Cadena cargo);
// Dado un cargo listar los cargos que lo anteceden.
// Lista todas los cargos que anteceden, en la jerarquía, al cargo de nombre cargo.

// Asigno el nuevo cargo como hijo del cargo pedido
void AsignarCargoHijo(Cargo cargo_hijo, Cargo cargo_padre);

// Define un cargo con punteros vacíos y el nombre pasado. Devuelve el puntero al cargo
Cargo definirCargo(Cadena cargo_nom);

// Imprime los datos del cargo pasado
Cadena getCarNom(Cargo cargo);
Cadena getCarNomH(Cargo cargo);
Cadena getCarNomH(Cargo cargo);

void imprimeInfoCargo(Cargo cargo);

// Itera todo el arbol usando el nodo pasado como raiz y devuelve el puntero al cargo con el nombre pasado
Cargo iteradorEmpresa(Cadena cargo, Cargo cargos);

// Se llama desde ListarJerarquia(). Usa un int para aumentar la identacion segun avanza por los hijos
void imprimirArbolCargos(Cargo cargos, int ident);

// Itera hasta el final de la lista de cargos hijos y devuelve el ultimo miembro
Cargo iteradorCargoHermanos(Cargo cargos);

//Devuelve true si el cargo con el nombre pasado existe en el arbol pasado
bool ifCargoExiste(Cadena cargo, Cargo cargos_lista);


// Recibe un int y imprime ese numero de espacios
void imprimirIdent(int ident);

// Esta función imprime los parientes de un cargo y el cargo
void imprimeInfoCargo(Cargo cargo);


#endif