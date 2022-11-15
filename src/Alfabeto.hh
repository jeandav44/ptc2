#ifndef ALFABETO_HH
#define ALFABETO_HH

#include <string>
#include <iostream>

using namespace std;

class Alfabeto {

private:
    string texto;
    int nm;
public:
    /* CONSTRUCTORES */
    Alfabeto();

    Alfabeto(string texto);

    ~Alfabeto();



    /*MODIFICADORES*/
    void incrementa();
    int getNm();

    /* ENTRADA/SALIDA */
    void escribir();
};
#endif
