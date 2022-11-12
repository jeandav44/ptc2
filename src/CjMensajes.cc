#include "CjMensajes.hh"

CjMensajes::CjMensajes(){};
CjMensajes::~CjMensajes(){};

void CjMensajes::leer() {
    int nm; //numero de mensajes
    cin >> nm;

    for (int i = 0; i < nm ; i++) {
        string idm, ida, texto;
        cin >> idm >> ida;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin >> ws ,texto);
        Mensaje aux(ida,texto);
        mmen.insert(make_pair(idm,aux));
    }

}

void CjMensajes::escribir() {
    auto itm = mmen.begin();
    int i = 1;
    cout << endl;
    while (itm != mmen.end()) {
        cout << i << ". ";
        cout << itm->first << endl;
        itm->second.escribir();
        ++i;
        ++itm;
    }
}
