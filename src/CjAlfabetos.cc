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
    cout << "tamaño inicial malf" << malf.size() << '\n';
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
        cout << malf.size() << endl;
        //cout << "añadido todo size" << endl;
    }
}

void CjAlfabetos::borrar_alfabeto() {
    string ida;
    cin >> ida;
    cout << ' ' << ida << endl;
    if(not buscarId(ida)) {
        cout << "error: el alfabeto no existe" << endl;
    }
    else{
        auto ita = malf.find(ida);
        if(ita->second.getNm() != 0) {
            cout << "error: hay mensajes guardados con el alfabeto" << endl;
        }
        else {
            ita = malf.find(ida);
            malf.erase(ita);
            cout << "TODO:borrar alfabeto" << endl;
        }
    }
}


void CjAlfabetos::incrementaI(string ida) {
    auto ita = malf.find(ida);
    ita->second.incrementa();
}

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
    std::cout << malf.size() << '\n';
}
bool CjAlfabetos::buscarId(string ida) {
    auto ita = malf.find(ida);
    return (ita != malf.end());
}
