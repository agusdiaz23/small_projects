#ifndef DT_GATO
#define DT_GATO

#include <string>
#include "DtMascota.h"


using namespace std;

class DtGato : public DtMascota{

    private:
        TipoPelo tipoPelo;
    public: 
        DtGato(string nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipoPelo);
        
        TipoPelo getTipoPelo();
        
        ~DtGato();
};

#endif