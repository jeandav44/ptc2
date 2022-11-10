#include "Mensaje.hh"

Mensaje::Mensaje(){};

Mensaje::~Mensaje(){};

Mensaje::Mensaje(string ida, string texto) {
    this->ida = ida;
    this->texto = texto;
};

void Mensaje::escribir() {

    cout <<' '<< ida << endl;
    cout << texto << endl;
}
