#ifndef CJ_MEN_HH
#define CJ_MEN_HH

#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <iostream>
#include <limits>
#include "Mensaje.hh"
#include "CjAlfabetos.hh"

class CjMensajes {

private:
    map<string,Mensaje> mmen;
    //map<string,Mensaje>::iterator it2;
public:
    /* CONSTRUCTORES */
    CjMensajes();

    ~CjMensajes();

    /* MODIFICADORES */
    void nuevo_mensaje(CjAlfabetos &ca);
    void borra_mensaje(CjAlfabetos &ca);
    bool buscarId(string idm);
    void codificar_sustitucion_guardado(CjAlfabetos &ca);
    void codificar_sustitucion(CjAlfabetos &ca);
    void decodificar_sustitucion(CjAlfabetos &ca);
    string codifica(string clave, string texto,const vector<string> &matrix);
    string decodifica(string clave, string texto,const vector<string> &matrix);
    int getPos(string texto ,char c);

    /* ENTRADA/SALIDA */

    void leer(CjAlfabetos &ca);

    void escribir();

};
#endif
