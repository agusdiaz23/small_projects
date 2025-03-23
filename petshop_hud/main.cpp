#include "Socio.h"
#include "Consulta.h"
#include "Mascota.h"

#include "DtFecha.h"
#include "DtFecha.h"

using namespace std;

//Todos los Socios del sistema
struct {
	Socio* socioS[MAX_SOCIOS];
	int topeSocios;
} coleccionSocio;

//Funcion para liberar los socios almacenados en coleccionSocio
void liberarMemoria() {
    for (int i = 0; i < coleccionSocio.topeSocios; i++) {
        delete coleccionSocio.socioS[i];
        coleccionSocio.socioS[i] = nullptr;
    }
    coleccionSocio.topeSocios = 0;
}

//Funciones a Implementar
void registrarSocio() {}
void agregarMascota() {}
void ingresarConsulta() {}
void verConsultasAntesDeFecha() {}
void eliminarSocio() {}
void obtenerMascotas() {}


// Declaraciones de funciones
void registrarSocio();
void agregarMascota();
void ingresarConsulta();
void verConsultasAntesDeFecha();
void eliminarSocio();
void obtenerMascotas();
void liberarMemoria();


int main() {
    //van todos los topes
    coleccionSocio.topeSocios=0;
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
                agregarMascota();
                break;
            case 3:
                ingresarConsulta();
                break;
            case 4:
                verConsultasAntesDeFecha();
                break;
            case 5:
                eliminarSocio();
                break;
            case 6:
                obtenerMascotas();
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