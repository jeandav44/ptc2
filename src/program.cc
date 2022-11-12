#include <iostream>
#include <string>
#include "CjMensajes.hh"
#include "Mensaje.hh"

using namespace std;

int main() {
    CjMensajes cm;
    cm.leer();

    string op;
    cout << "dime tu operacion" << endl;
    cin >> op;
    while (op != "fin") {
        if(op == "tet") cm.escribir();
        else cout << op << endl;
        cin >> op;
    }
    return 0;
}
