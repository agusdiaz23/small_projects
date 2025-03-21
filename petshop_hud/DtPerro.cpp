#include "DtPerro.h"

DtPerro::DtPerro(string nombre, Genero genero, float peso,float racionDiaria, RazaPerro raza, bool vacuna):
Mascota(nombre,genero,peso,racionDiaria){
    this->raza = raza; 
    this->vacunaCachorro = vacuna;
}

RazaPerro DtPerro::getraza(){
    return this->raza;
}

bool DtPerro::getvacunaCachorro(){
    return this->vacunaCachorro;
}

DtPerro::~DtPerro(){}