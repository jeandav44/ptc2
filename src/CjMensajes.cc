#include "CjMensajes.hh"

CjMensajes::CjMensajes(){};
CjMensajes::~CjMensajes(){};

void CjMensajes::leer() {
    int nm; //numero de mensajes
    cin >> nm;

    for (int i = 0; i < nm ; ++i) {
        string idm, ida, texto;
        cin >> idm >> ida;
        cin.get();
        getline(cin,texto);
        cin.get();
        Mensaje aux(ida,texto);
        mmen.insert(make_pair(idm,aux));
    }
}


void CjMensajes::escribir() {
    it = mmen.begin();

    cout << "/*IMPRIMIENDO*/" << endl;
    while (it != mmen.end()) {
        cout << it->first;
        it->second.escribir();
        cout << endl;
        ++it;
    }
}
