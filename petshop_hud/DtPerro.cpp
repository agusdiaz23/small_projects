#include DtPerro.h

DtPerro::DtPerro(string nombre, Genero genero, float peso, float racionDiaria, razaPerro raza, bool vacunaCachorro):
DtMascota(nombre, genero, peso, racionDiaria){
    this->raza = raza;
    this->vacunaCachorro = vacunaCachorro;
}

DtPerro::~DtPerro(){}