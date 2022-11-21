#include "CjAlfabetos.hh"

CjAlfabetos::CjAlfabetos(){};
CjAlfabetos::~CjAlfabetos(){};

void CjAlfabetos::leer() {
    int na; //numero de alfabetos
    cin >> na;

    map<string,Alfabeto> mp;
    malf = mp;

    for (int i = 0; i < na ; ++i) {
        string ida, texto;
        cin >> ida;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,texto);
        Alfabeto aux(texto);
        malf.insert(make_pair(ida,texto));
    }
    //cout << "tamaño inicial malf" << malf.size() << '\n';
}

void CjAlfabetos::nuevo_alfabeto() {
    string ida, texto;
    cin >> ida;
    cout << ' ' << ida << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,texto);

    if(buscarId(ida)) {
        cout << "error: el alfabeto ya existe" << endl;
    }
    else {

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
            malf.erase(ita);
            cout << malf.size() << endl;
        }
    }
}


void CjAlfabetos::incrementaI(string ida) {
    auto ita = malf.find(ida);
    ita->second.incrementa();
}

vector<string> CjAlfabetos::matrixById(string ida) {
    auto ita = malf.find(ida);
    return ita->second.getMat();
}

void CjAlfabetos::decrementaI(string ida) {
    auto ita = malf.find(ida);
    ita->second.decrementa();
}

void CjAlfabetos::escribir() {
    int i = 1;
    cout << endl;
    auto ita = malf.begin();
    while (ita != malf.end()) {
        cout << i << ". ";
        cout << ita->first << endl;
        bool especial = esEspecial(ita->second);
        ita->second.escribir(especial);
        ++i;
        ++ita;
    }
}

bool CjAlfabetos::buscarId(string ida) {
    auto ita = malf.find(ida);
    return (ita != malf.end());
}


bool CjAlfabetos::esEspecial(Alfabeto alf){
    string texto = alf.getTexto();
    char ini = texto[0];
    for (int i = 1; i < texto.size(); ++i) {
        if(texto[i] != ini+1 ) return false;
        ini = texto[i];
    }
    return true;
}
