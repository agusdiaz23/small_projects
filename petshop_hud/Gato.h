#ifndef GATO_H
#define GATO_H

#include <string>
#include "Mascota.h"
#include "DtTipoPelo.h"

using namespace std;

class Gato : public Mascota{

    private: 
    TipoPelo tipoPelo;

    public: 

//constructor y destructor

    Gato(string nombre, Genero genero, float peso, TipoPelo tipoPelo);
    ~Gato();

    float obtenerRacionDiaria() override;
    
    TipoPelo getTipoPelo();

    void setTipoPelo(TipoPelo tipoPelo);
}

#endif