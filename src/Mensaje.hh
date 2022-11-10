#ifndef MENSAJE_HH
#define MENSAJE_HH

#include <string>
#include <iostream>

using namespace std;

class Mensaje {

private:
    string ida;
    string texto;
public:
    /* CONSTRUCTORES */
    Mensaje();

    Mensaje(string ida, string texto);

    ~Mensaje();

    /* ENTRADA/SALIDA */
    void escribir();
};
#endif
