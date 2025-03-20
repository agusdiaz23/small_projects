#include "DtGato.H"


DtGato::DtGato(string nombre, Genero genero, float peso, float racionDiaria, TipoPelo, tipoPelo):
DtMascota(nombre, genero, peso, racionDiaria){
    this->tipoPelo = tipoPelo;
}

DtGato::~DtGato();
