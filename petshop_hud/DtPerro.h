#ifndef DT_PERRO
#define DT_PERRO

#include "DtMascota.h"
#include "DtRazaPerro.h"

class DtPerro{

    private:
        RazaPerro raza;
        bool vacunaCachorro;

    public: 
        DtPerro(string nombre, Genero genero, float peso, float racionDiaria, razaPerro raza, bool vacunaCachorro);
        ~DtPerro();
}

#endif