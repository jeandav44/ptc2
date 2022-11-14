#include "CjAlfabetos.hh"

CjAlfabetos::CjAlfabetos(){};
CjAlfabetos::~CjAlfabetos(){};

void CjAlfabetos::leer() {
    int na; //numero de alfabetos
    cin >> na;

    for (int i = 0; i < na ; ++i) {
        string ida, texto;
        cin >> ida;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,texto);
        Alfabeto aux(texto);
        malf.insert(make_pair(ida,texto));
    }

}

void CjAlfabetos::nuevo_alfabeto() {
    string ida, texto;
    cin >> ida;
    if(buscarId(ida)) {
        cout << "error: el alfabeto ya existe" << endl;
    }
    else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,texto);
        Alfabeto aux(texto);
        malf.insert(make_pair(ida,texto));
    }

}
/*
void CjAlfabetos::incrementaI(string clave) {
    auto ita = malf.find(clave);
    ita->second.incrementa();
}
*/
void CjAlfabetos::escribir() {
    int i = 1;
    cout << endl;
    auto ita = malf.begin();
    while (ita != malf.end()) {
        cout << i << ". ";
        cout << ita->first << endl;
        ita->second.escribir();
        ++i;
        ++ita;
    }
}
bool CjAlfabetos::buscarId(string ida) {
    auto ita = malf.find(ida);
    return (ita != malf.end());
}
