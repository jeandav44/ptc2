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
        getline(cin, texto);
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
    getline(cin, texto);

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
        string ida;
        itm->second.getAlfa(ida);
        mmen.erase(itm);
        cout << mmen.size() << endl;
        ca.decrementaI(ida);
    }
    else {
        cout << "error: el mensaje no existe" << endl;
    }
}

bool CjMensajes::buscarId(const string &idm) {
    auto itm = mmen.find(idm);
    return (itm != mmen.end());
}

void CjMensajes::codificar_sustitucion_guardado(CjAlfabetos &ca) {
    string idm, clave;
    cin >> idm;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, clave);
    cout << ' ' << idm << ' '<< '"'<< clave <<'"' << endl;

    if(buscarId(idm)) {
        auto itm = mmen.find(idm);

        string texto;
        itm->second.getTexto(texto);

        string ida;
        itm->second.getAlfa(ida);

        vector<string> matrix;
        ca.matrixById(ida,matrix);

        codifica(clave,texto,matrix);
        cout << '"' << texto << '"' << endl;
    }
    else cout << "error: el mensaje no existe" << endl;
}

void CjMensajes::codificar_sustitucion(CjAlfabetos &ca) {
    string ida, clave, texto;
    cin >> ida;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin ,clave);
    getline(cin ,texto);


    cout << ' ' << ida << ' '<< '"'<< clave <<'"' << endl;
    if(not ca.buscarId(ida)) {
        cout << "error: el alfabeto no existe" << endl;
    }
    else{
        vector<string> matrix;
        ca.matrixById(ida,matrix);
        codifica(clave,texto,matrix);
        cout << '"' << texto << '"' << endl;
    }

}
void CjMensajes::codifica(const string &clave, string &texto, const vector<string> &matrix) {
    string alarga;
    string coded;
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

    texto = coded;
}

void CjMensajes::decodificar_sustitucion(CjAlfabetos &ca) {
    string ida, clave, texto;
    cin >> ida;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, clave);
    getline(cin, texto);

    cout << ' ' << ida << ' '<< '"'<< clave <<'"' << endl;
    if(not ca.buscarId(ida)) {
        cout << "error: el alfabeto no existe" << endl;
    }
    else{
        vector<string> matrix;
        ca.matrixById(ida,matrix);
        decodifica(clave,texto,matrix);
        cout << '"' << texto << '"' << endl;
    }

}


void CjMensajes::decodifica(const string &clave, string &texto,const vector<string> &matrix) {
    string alarga;
    string deco;
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
        deco.push_back(matrix[0][ret]);
    }
    texto = deco;
}

void CjMensajes::codificar_permutacion_guardado() {
    string idm;
    auto itm = mmen.find(idm);
    if(itm == mmen.end()) {
        cout << "error: el mensaje no existe" << endl;
    }
    else{
            BinTree<char> bt;
            string texto;
            itm->second.getTexto(texto);
            int medio = texto.size()/2;
            bt = createTree(medio,texto);
    }
}

BinTree CjMensajes::createTree() {

}

int CjMensajes::getPos(const string &matrixF,const char &c) {
    int i = 0;
    while(i < matrixF.size() ) {
        if(matrixF[i] == c) return i;
        else ++i;
    }
    return i;
}
