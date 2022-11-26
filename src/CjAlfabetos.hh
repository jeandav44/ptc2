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
    //map<string,Alfabeto>::iterator it;
public:
    CjAlfabetos();
    ~CjAlfabetos();

    /*MODIFICADORES*/
    void nuevo_alfabeto();
    void borrar_alfabeto();

    bool buscarId(const string &ida);
    void incrementaI(const string &ida);
    void decrementaI(const string &ida);

    void esEspecial(const string &texto, bool &especial);

    //vector<string> matrixById(string ida);
    void matrixById(const string &ida, vector<string> &mat);


    /*ENTRADA/SALIDA*/
    void leer();
    void escribir();

};
#endif
