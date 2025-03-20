#ifndef DT_MASCOTA
#define DT_MASCOTA

#include <string>
#include "Genero.h"

using namespace std;

class DtMascota{

    private:
        string nombre;
        Genero genero;
        float peso;
        float racionDiaria;

    public: 
        DtMascota(string nombre, Genero genero, float peso, float racionDiaria);
        ~DtMascota();
};

#endif