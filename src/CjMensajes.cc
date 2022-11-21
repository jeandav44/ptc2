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

    if(buscarId(idm)) {
        auto itm = mmen.find(idm);

        string ida = itm->second.getAlfa();
        string texto = itm->second.getTexto();
        vector<string> matrix = ca.matrixById(ida);
        //aho
        string codificado = codifica(clave,texto,matrix);
        cout << '"' << codificado << '"' << endl;
    }
    else cout << "error: el mensaje no existe" << endl;
}

void CjMensajes::codificar_sustitucion(CjAlfabetos &ca) {
    string ida, clave, texto;
    cin >> ida;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin >> ws ,clave);
    getline(cin >> ws ,texto);

    cout << ' ' << ida << ' '<< '"'<< clave <<'"' << endl;
    if(not ca.buscarId(ida)) {
        cout << "error: el alfabeto no existe" << endl;
    }
    else{
        vector<string> matrix = ca.matrixById(ida);
        string codificado = codifica(clave,texto,matrix);
        cout << '"' << codificado << '"' << endl;
    }

}

void CjMensajes::decodificar_sustitucion(CjAlfabetos &ca) {
    string ida, clave, texto;
    cin >> ida;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin >> ws ,clave);
    getline(cin >> ws ,texto);

    cout << ' ' << ida << ' '<< '"'<< clave <<'"' << endl;
    if(not ca.buscarId(ida)) {
        cout << "error: el alfabeto no existe" << endl;
    }
    else{
        vector<string> matrix = ca.matrixById(ida);
        string decodificado = decodifica(clave,texto,matrix);
        cout << '"' << decodificado << '"' << endl;
    }

}

string CjMensajes::decodifica(string clave, string texto,const vector<string> &matrix) {
    string alarga ="";
    string deco ="";
    auto itc = clave.begin();
    for (int i = 0; i < texto.size(); i++) {
        if(itc == clave.end() ) itc = clave.begin();
        alarga.push_back(*itc);
        ++itc;
    }

    string matrixF = matrix[0];

    for (int i = 0; i < texto.size(); i++) {
        int fil = getPos(matrixF,alarga[i]);
        int ret = getPos(matrix[fil],texto[i]);
        /*int fil = getPos(matrixF,texto[i]);
        int ret = getPos(matrix[fil],alarga[i]);*/
        deco.push_back(matrix[0][ret]);
    }
    return deco;
}

string CjMensajes::codifica(string clave, string texto,const vector<string> &matrix) {
    string alarga = "";
    string coded = "";
    auto itc = clave.begin();
    for (int i = 0; i < texto.size(); i++) {
        if(itc == clave.end() ) itc = clave.begin();
        alarga.push_back(*itc);
        ++itc;
    }

    string matrixF = matrix[0];

    for (int i = 0; i < texto.size(); i++) {
        int fil = getPos(matrixF,alarga[i]);
        int col = getPos(matrixF,texto[i]);
        coded.push_back(matrix[fil][col]);
    }

    return coded;
}

int CjMensajes::getPos(string matrixF,char c) {
    int i = 0;
    while(i < matrixF.size() ) {
        if(matrixF[i] == c) return i;
        else ++i;
    }
    return i;
}
