#include "Mensaje.hh"

Mensaje::Mensaje(){};

Mensaje::~Mensaje(){};

Mensaje::Mensaje(const string &ida,const string &texto) {
    this->ida = ida;
    this->texto = texto;
};

void Mensaje::escribir() {


    cout << ida << endl;
    cout << '"' << texto << '"' <<  endl;
}

void Mensaje::getAlfa(string &alfa) {
    alfa = this->ida;
}

void Mensaje::getTexto(string &texto) {
    texto = this->texto;
}
