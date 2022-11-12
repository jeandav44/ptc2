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
        malf.insert(make_pair(ida,texto));
    }

}

void CjAlfabetos::escribir() {
    auto ita = malf.begin();
    while (ita != malf.end()) {
        cout << ita->first;
        cout << ' ';
        cout << ita->second;
        cout << endl;
        ++ita;
    }
}

bool CjAlfabetos::buscarId(string ida) {
    auto ita = malf.find(ida);
    return (ita != malf.end());
}
