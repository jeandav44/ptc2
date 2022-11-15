#include "Alfabeto.hh"

Alfabeto::Alfabeto(){};

Alfabeto::~Alfabeto(){};

Alfabeto::Alfabeto(string texto) {
    this->texto = texto;
    nm = 0;
    iniMat(texto);
};

void Alfabeto::iniMat(string texto){
    string aux = texto;
    vector<string> vma;
    for (int i = 0; i < texto.size(); ++i) {
        vma.push_back(texto);
        char fin = aux[0];
        aux.erase(aux.begin());
        aux.push_back(fin);
    }
    matrix = vma;
}

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
