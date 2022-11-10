#ifndef CJ_MEN_HH
#define CJ_MEN_HH

#include <string>
#include <map>
#include <iostream>
#include "Mensaje.hh"

using namespace std;

class CjMensajes {

private:
    map<string,Mensaje> mmen;
    map<string,Mensaje>::iterator it;
public:
    /* CONSTRUCTORES */
    CjMensajes();

    ~CjMensajes();

    /* MODIFICADORES */
    void nuevo_mensaje();

    /* ENTRADA/SALIDA */

    void leer();

    void escribir();


};
#endif
