#ifndef PERRO_H
#define PERRO_H

#include <string>
#include "Mascota.h"
#include "DtRazaPerro.h"

using namespace std;

class Perro : public Mascota{

    private: 
        RazaPerro raza;
        bool vacunaCachorro;
        
    public: 

//constructor y destructor

    Perro(string nombre, Genero genero, float peso, TipoPelo tipoPelo, RazaPerro raza, bool vacunaCachorro);
    ~Perro();

    float obtenerRacionDiaria() override;

    RazaPerro getRazaPerro();
    bool getVacunaCachorro();

    void setRazaPerro(RazaPerro raza);
    void setVacunaCachorro(bool vacunaCachorro);
};

#endif