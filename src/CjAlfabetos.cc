#include "CjMensajes.hh"

CjMensajes::CjMensajes(){};
CjMensajes::~CjMensajes(){};

void CjMensajes::leer() {
    int nm; //numero de mensajes
    cin >> nm;

    for (int i = 0; i < nm ; ++i) {
        string idm, ida, texto;
        cin >> idm >> ida >> texto;
        Mensaje aux(ida,texto);
        mmen.insert(make_pair(idm,aux));
    }
}
