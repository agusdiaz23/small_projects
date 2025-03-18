#ifndef SOCIO
#define SOCIO

#include <string>

using namespace std;

class Socio{
    private:
        string CI;
        string nombre;
    public:
        Socio();
        Socio(string, string);
        
        string getCI();
        void setCI(string);

        string getNombre();
        void setNombre(string);

        ~Socio();

};

#endif