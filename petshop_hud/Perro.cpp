#include "Perro.h"

Perro::Perro(){}
Perro::Perro(RazaPerro raza, bool vacunaCachorro){
    this->raza=raza;
    this->raza=raza;
}

RazaPerro Perro::getRazaPerro(){
    return this->raza;
}
void Perro::setRazaPerro(RazaPerro raza){
    this->raza=raza;
}

bool Perro::getvacunaCachorro(){
    return this->vacunaCachorro;
}
void Perro::setvacunaCachorro(bool vacunaCachorro){
    this->vacunaCachorro=vacunaCachorro;
}

Perro::~Perro(){}

float Perro::obtenerRacionDiaria(float peso) {
    return this->getPeso()*0,015;
}