#include <iostream>
#include <string>
#include "CjMensajes.hh"
#include "CjAlfabetos.hh"
#include "Mensaje.hh"

using namespace std;

int main() {
    CjAlfabetos ca;
    ca.leer();

    CjMensajes cm;
    cm.leer();

    string op;
    cout << "dime tu operacion" << endl;
    cin >> op;
    while (op != "fin") {
        cout << '#' << op << ' ';
        if( op == "nuevo_mensaje" or op == "nm"){
            cout << "TODO" << endl;
        }
        else if(op == "listar_mensajes" or op == "lm") cm.escribir();
        else if(op == "listar_alfabetos" or op == "la") ca.escribir();
        cin >> op;
    }

    exit(0);
}
