#include "Alfabeto.hh"

Alfabeto::Alfabeto(){};

Alfabeto::~Alfabeto(){};

Alfabeto::Alfabeto(const string &texto) {
    this->texto = texto;
    nm = 0;
    //iniMat(texto);
};

void Alfabeto::iniMat(string texto){
    string aux = texto;
    vector<string> vma;
    for (int i = 0; i < texto.size(); ++i) {
        vma.push_back(aux);
        char fin = aux[0];
        aux.erase(aux.begin());
        aux.push_back(fin);
    }
    matrix = vma;
}

void Alfabeto::incrementa() {
    nm += 1;
}

void Alfabeto::decrementa() {
    nm += -1;
}

int Alfabeto::getNm() {
    return this->nm;
}

string Alfabeto::getTexto() {
    return this->texto;
}

void Alfabeto::getMat(vector<string> &mat) {
    if(this->matrix.empty()) iniMat(this->texto);
    mat = this->matrix;
}

void Alfabeto::escribir(const bool &esp) {
    if(esp) {
        cout << "especial " << '[' << texto[0] << ".." << texto.back() << ']';
    }
    else {
        cout << "normal " << '"' << texto << '"';
    }
    cout << ' ' << nm << " mensajes" << endl;
}
