#ifndef MASCOTA
#define MASCOTA

#include <string>

using namespace std;

class Mascota{
    private:
        string nombre;
    public:
        Mascota();
        Mascota(string);

        void setNombre(string);
};

#endif