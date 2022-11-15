#ifndef CJ_ALF_HH
#define CJ_ALF_HH


#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <iostream>
#include <limits>
#include "Alfabeto.hh"

using namespace std;

class CjAlfabetos {

private:
    map<string,Alfabeto> malf;
    map<string,Alfabeto>::iterator it;
public:
    CjAlfabetos();
    ~CjAlfabetos();

    /*MODIFICADORES*/
    void nuevo_alfabeto();
    void borrar_alfabeto();
    int sizeAct();
    bool buscarId(string ida);
    void incrementaI(string ida);
    void decrementaI(string ida);
    bool esEspecial(Alfabeto alf);


    /*ENTRADA/SALIDA*/
    void leer();
    void escribir();

};
#endif
