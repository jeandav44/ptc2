#include "CjMensajes.hh"

CjMensajes::CjMensajes(){};
CjMensajes::~CjMensajes(){};

void CjMensajes::leer(CjAlfabetos &ca) {
    int nm; //numero de mensajes
    cin >> nm;

    for (int i = 0; i < nm ; i++) {
        string idm, ida, texto;
        cin >> idm >> ida;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin >> ws ,texto);
        Mensaje aux(ida,texto);
        mmen.insert(make_pair(idm,aux));
        ca.incrementaI(ida);
    }


}

void CjMensajes::escribir() {
    int i = 1;
    cout << endl;
    auto itm = mmen.begin();
    while (itm != mmen.end()) {
        cout << i << ". ";
        cout << itm->first << endl;
        itm->second.escribir();
        ++i;
        ++itm;
    }
}

void CjMensajes::nuevo_mensaje(CjAlfabetos &ca) {
    string idm, ida;
    cin >> idm >> ida;
    cout << ' ' << idm << ' '<< ida << endl;
    string texto;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin >> ws ,texto);

    if(buscarId(idm)) {
        cout << "error: ya existe un mensaje con ese identificador" << endl;
    }
    else if(not ca.buscarId(ida)) {
        cout << "error: el alfabeto no existe" << endl;
    }
    else {

        Mensaje aux(ida,texto);
        mmen.insert(make_pair(idm,aux));
        ca.incrementaI(ida);
        cout << mmen.size() << endl;
    }
}
void CjMensajes::borra_mensaje(CjAlfabetos &ca) {
    string idm;
    cin >> idm;
    cout << ' ' << idm << endl;
    if(buscarId(idm)){
        auto itm = mmen.find(idm);
        string ida = itm->second.getAlfa();
        mmen.erase(itm);
        cout << mmen.size() << endl;
        ca.decrementaI(ida);
    }
    else {
        cout << "error: el mensaje no existe" << endl;
    }
}

bool CjMensajes::buscarId(string idm) {
    auto itm = mmen.find(idm);
    return (itm != mmen.end());
}

void CjMensajes::codificar_sustitucion_guardado(CjAlfabetos &ca) {
    string idm, clave;
    cin >> idm;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin >> ws ,clave);
    cout << ' ' << idm << ' '<< '"'<< clave <<'"' << endl;
}
