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
    while (itm != mmen.end()) {
        cout << itm->first;
        itm->second.escribir();
        cout << endl;
        ++itm;
    }


}
