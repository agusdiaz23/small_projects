#ifndef SOCIO
#define SOCIO

#define CANT_MASCOTAS 10
#define CANT_CONSULTAS 20
#define MAX_SOCIOS 50


#include <string>
#include "DtFecha.h"
#include "Mascota.h"
#include "Consulta.h"

using namespace std;

class Socio{
    private:
        string CI;
        string nombre;
        DtFecha fechaIngreso;
        Mascota* mascotas[CANT_MASCOTAS];
        Consulta* consultas[CANT_CONSULTAS];
        Socio* socios[MAX_SOCIOS];
        int topeMascotas;
        int topeConsultas;
        int topeSocios;
    public:
        Socio();
        Socio(string, string, DtFecha);
        
        string getCI();
        void setCI(string);

        string getNombre();
        void setNombre(string);

        DtFecha getFechaIngreso();
        void setFechaIngreso(DtFecha);

        ~Socio();

        Mascota** obtenerMascotas(int&);
        Consulta** obtenerConsulta(int&);

};

#endif