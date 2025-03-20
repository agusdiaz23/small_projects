#include "Gato.h"

Gato::Gato(){}
Gato::Gato(TipoPelo tipoPelo){
    this->tipoPelo=tipoPelo;
}

TipoPelo Gato::gettipoPelo(){
    return this->tipoPelo;
}
void Gato::settipoPelo(TipoPelo){
    this->tipoPelo=tipoPelo;
}

Gato::~Gato(){}

float Gato::obtenerRacionDiaria(float peso) {
    return this->getPeso()*0,025;
}