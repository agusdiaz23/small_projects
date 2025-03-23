#define MAX_SOCIOS 30
#include "Socio.h"
#include "Consulta.h"
#include "Mascota.h"
#include "Perro.h"
#include "Gato.h"
#include "RazaPerro.h"
#include "Genero.h"
#include "TipoPelo.h"
#include "DtConsulta.h"
#include "DtFecha.h"
#include "DtPerro.h"
#include "DtGato.h"
#include "DtMascota.h"

#include <iostream>
#include <stdexcept>

using namespace std;

// Todos los usuarios del sistema
struct{
    Socio* socios[MAX_SOCIOS];
    int topeS = 0;
} arraySocios;

// OPERACION 1 (SEMI IMPLEMENTADA)
void registrarSocio();

// OPERACIONES POR IMPLEMENTAR
void agregarMascota() {}
void ingresarConsulta() {}
void verConsultasAntesDeFecha() {}
void eliminarSocio() {}
void obtenerMascota() {}

// Declaraciones de funciones
void registrarSocio(string, string, DtFecha); // IMPLEMENTADA
void agregarMascota(); // NO IMPLEMENTADA 
void ingresarConsulta(); // NO IMPLEMENTADA 
void verConsultasAntesDeFecha(); // NO IMPLEMENTADA 
void eliminarSocio(); // NO IMPLEMENTADA 
void obtenerMascotas(); // NO IMPLEMENTADA 
void liberarMemoria(); // IMPLEMENTADA

// OPERACIONES AUXILIARES
void noExisteSocio(string ci);
void limpiarPantalla();
void esperarPorInput();


int main() {
    //van todos los topes
    int opcion;
    do {
        cout << "\n--- Bienvenido a la Veterinaria ---" << endl;
        cout << "1) Registrar socio" << endl;
        cout << "2) Agregar mascota" << endl;
        cout << "3) Ingresar consulta" << endl;
        cout << "4) Ver consultas antes de fecha" << endl;
        cout << "5) Eliminar socio" << endl;
        cout << "6) Obtener mascotas" << endl;
        cout << "0) Salir" << endl;
        cout << "Opcion: ";

        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarSocio();
                break;
            case 2:
                cout << "NO IMPLEMENTADA" << endl;
                //agregarMascota();
                break;
            case 3:
                cout << "NO IMPLEMENTADA" << endl;
                //ingresarConsulta();
                break;
            case 4:
                cout << "NO IMPLEMENTADA" << endl;
                //verConsultasAntesDeFecha();
                break;
            case 5:
                cout << "NO IMPLEMENTADA" << endl;
                //eliminarSocio();
                break;
            case 6:
                cout << "NO IMPLEMENTADA" << endl;
                //obtenerMascotas();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente de nuevo..." << endl;
                break;
        }
    } while (opcion != 0);

    liberarMemoria();
    return 0;
}


 // OPERACION 1
void registrarSocio() {
    DtMascota dtmascota("Buddy", Genero::MACHO, 10.5, 0.75);

    limpiarPantalla(); // Esta funcion limpia la pantalla en linux y windows
    cout <<"________________________"<<endl;
    cout <<"____REGISTRO_DE_SOCIO____"<< endl;
    
    string socio_ci, socio_nombre;
    int dia, mes, anio;

    cout << "\nCI: ";
    cin >> socio_ci;

    try {
        noExisteSocio(socio_ci);
        cout << "NOMBRE: ";
        cin >> socio_nombre;

        cout << "\nFECHA DE INGRESO" << endl;
        cout << "DIA: ";
        cin >> dia;

        cout << "MES: ";
        cin >> mes;

        cout << "ANIO: ";
        cin >> anio;

        DtFecha fecha = DtFecha(dia, mes, anio);

        registrarSocio(socio_ci, socio_nombre, fecha);
        cout << "\nSe ha registrado en el Sistema al socio " << socio_nombre << " de CI " << socio_ci << " correctamente\n";

        esperarPorInput(); // lee el enter del usuario en linux y windows
    }
    catch(invalid_argument& e){
        cout << e.what() << endl;
    }
}


// OPERACIONES AUXILIARES
void noExisteSocio(string ci) {
    int i=0;
    bool existe=false;
    while((i<arraySocios.topeS)&&(!existe)){

        if(ci == arraySocios.socios[i]->getCI()){
            existe=true;
        }
        i++;
    }
    if (existe)
        throw invalid_argument("\nERROR: YA EXISTE USUARIO CON ESA CI EN EL SISTEMA\n");
}

void limpiarPantalla(){
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear");
    #endif
}

void esperarPorInput() {
    #ifdef _WIN32
        system("pause");
    #else
        system("read -p \"Press enter to continue...\" X");
    #endif
}


// DECLARACIONES DE FUNCIONES
void registrarSocio(string ci, string nombre, DtFecha fecha) {
    Socio* socio = new Socio(ci,nombre,fecha);
    arraySocios.socios[arraySocios.topeS] = socio;
    arraySocios.topeS++;
}

//Funcion para liberar los socios almacenados en arraySocios
void liberarMemoria() {
    for (int i = 0; i < arraySocios.topeS; ++i) {
        delete arraySocios.socios[i]; 
    }
    arraySocios.topeS = 0; 
}

