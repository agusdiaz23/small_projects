#ifndef GATO
#define GATO

#include <string>
#include "Mascota.h"
#include "TipoPelo.h"

using namespace std;

class Gato: public Mascota{
    public:
        TipoPelo tipoPelo;
    private:
        Gato(string, Genero, float, TipoPelo);

        TipoPelo gettipoPelo();
        void settipoPelo(TipoPelo);

        ~Gato();

        float obtenerRacionDiaria(float);
};

#endif