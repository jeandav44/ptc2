#include <iostream>
#include <vector>
#include <string>
#include "CjMensajes.hh"
#include "CjAlfabetos.hh"
#include "Mensaje.hh"
#include "Alfabeto.hh"

using namespace std;


int main() {
    CjAlfabetos ca;
    ca.leer();

    CjMensajes cm;
    cm.leer(ca);

    string op;
    cout << "dime tu operacion" << endl;
    cin >> op;
    while (op != "fin") {
        cout << '#' << op << ' ';
        if( op == "nuevo_mensaje" or op == "nm") cm.nuevo_mensaje(ca);
        else if(op == "nuevo_alfabeto" or op == "na") ca.nuevo_alfabeto();
        else if(op == "borra_mensaje" or op == "bm") cm.borra_mensaje();
        else if (op == "borra_alfabeto" or op == "ba") ca.borrar_alfabeto();
        else if(op == "listar_mensajes" or op == "lm") cm.escribir();
        else if(op == "listar_alfabetos" or op == "la") ca.escribir();
        cin >> op;
    }
    //return 0;
    exit(0);
}
