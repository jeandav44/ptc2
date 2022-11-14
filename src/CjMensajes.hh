#ifndef CJ_MEN_HH
#define CJ_MEN_HH

#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <iostream>
#include <limits>
#include "Mensaje.hh"

class CjMensajes {

private:
    map<string,Mensaje> mmen;
    //map<string,Mensaje>::iterator it2;
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
