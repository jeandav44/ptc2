#ifndef ALFABETO_HH
#define ALFABETO_HH

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Alfabeto {

private:
    string texto;
    int nm;
    vector<string> matrix;
public:
    /* CONSTRUCTORES */
    Alfabeto();

    Alfabeto(string texto);

    ~Alfabeto();



    /*MODIFICADORES*/
    void iniMat(string texto);
    void incrementa();
    void decrementa();
    int getNm();
    string getTexto();

    /* ENTRADA/SALIDA */
    void escribir(bool esp);
};
#endif
