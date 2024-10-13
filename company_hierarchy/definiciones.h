#ifndef DEFINICIONES_H
#define DEFINICIONES_H


// Estructuras de Datos y Algoritmos - Curso 2024
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// definiciones.h
// Definiciones generales del proyecto (constantes, etc).

#define MAX_COMANDO 50

enum tipo_retorno{OK, ERROR, NO_IMPLEMENTADA};
typedef enum tipo_retorno TipoRet;

typedef char * Cadena;

// Las tres estructuras basicas del obligatorio.

// Empleado tiene sus datos y un pointer al siguiente empleado
typedef struct nodo_persona * Persona;
struct nodo_persona {
    Cadena ci;
    Cadena nom;
};


typedef struct nodo_empleado * Empleado;
struct nodo_empleado {
    Persona personas;
    Empleado sig;           
    Empleado hijo;       
    Empleado hermano;   
    Empleado padre;
};


// Cargo tiene un pointer a la linked list de personas
// hasta que el profesor explique como van a ser los trees
typedef struct nodo_cargo * Cargo;
struct nodo_cargo {
    Cadena nombre;
    Empleado empleados;
    Cargo hijo;
    Cargo hermano;
    Cargo padre;
};

// Empresa es simplemente un pointer al primer y unico cargo
typedef struct nodo_empresa * Empresa;
struct  nodo_empresa {
    Cargo cargos;
};


#endif
