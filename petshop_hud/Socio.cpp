#include "Socio.h"

Socio::Socio(){}
Socio::Socio(string CI, string nombre) {
    this->CI=CI;
    this->nombre=nombre;
}

string Socio::getCI(){
    return this->CI;
}
void Socio::setCI(string CI){
    this->CI=CI;
}

string Socio::getNombre(){
    return this->nombre;
}
void Socio::setNombre(string nombre){
    this->nombre=nombre;
}

Socio::~Socio(){}