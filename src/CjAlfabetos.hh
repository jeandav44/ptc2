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

    void nuevo_alfabeto();
    bool buscarId(string ida);
    void incrementaI(string ida);

    void leer();
    void escribir();

};
#endif
