#ifndef CONSULTA
#define CONSULTA

#include <string>
#include <DtFecha.h>


using namespace std;

class Consulta{
    private:
        DtFecha fechaConsulta;
        string motivo;
        
    public:
        Consulta();
        Consulta(DtFecha, string);
        
        DtFecha getFechaConsulta();
        void setFechaConsulta(DtFecha);

        ~Consulta();


};

#endif