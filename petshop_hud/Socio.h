#ifndef SOCIO
#define SOCIO
#define CANT_MASCOTAS 10

#include <string>
#include "DtFecha.h"
#include "Mascota.h"

using namespace std;

class Socio{
    private:
        string CI;
        string nombre;
        DtFecha fechaIngreso;
        Mascota* mascotas[CANT_MASCOTAS];
        int topeMascotas;
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

};

#endif