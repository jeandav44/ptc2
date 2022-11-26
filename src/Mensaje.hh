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
    Mensaje(const string &ida,const string &texto);
    ~Mensaje();
    /*MODIFICADORES*/
    void  getAlfa(string &alfa);
    void getTexto(string &texto);

    /* ENTRADA/SALIDA */
    void escribir();
};
#endif
