#include "Alfabeto.hh"

Alfabeto::Alfabeto(){};

Alfabeto::~Alfabeto(){};

Alfabeto::Alfabeto(string texto) {
    this->texto = texto;
    nm = 0;

};

void Alfabeto::incrementa() {
    nm += 1;
}
int Alfabeto::getNm() {
    return this->nm;
}



void Alfabeto::escribir() {
    cout << "todo ";
    cout << texto << ' ' << nm << " mensajes" << endl;
}
