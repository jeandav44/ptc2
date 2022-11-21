#include "Mensaje.hh"

Mensaje::Mensaje(){};

Mensaje::~Mensaje(){};

Mensaje::Mensaje(string ida, string texto) {
    this->ida = ida;
    this->texto = texto;
};

void Mensaje::escribir() {


    cout << ida << endl;
    cout << '"' << texto << '"' <<  endl;
}

string Mensaje::getAlfa() {
    return this->ida;
}

string Mensaje::getTexto() {
    return this->texto;
}

void Mensaje::setTexto(string texto) {
    this->texto = texto;
}
