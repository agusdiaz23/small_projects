#include <string>
#include "DtMascota.h"

using namespace std;


DtMascota::DtMascota(string nombre, Genero genero, float peso, float racionDiaria;){
    this->nombre = nombre;
    this->genero = genero;
    this->peso = peso;
    this->racionDiaria = racionDiaria;
}
~DtMascota();

