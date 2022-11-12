#ifndef CJ_ALF_HH
#define CJ_ALF_HH



#include <string>
#include <map>
#include <iterator>
#include <iostream>
#include <limits>

using namespace std;

class CjAlfabetos {

private:
    map<string,string> malf;
    map<string,string>::iterator it;
public:
    CjAlfabetos();
    ~CjAlfabetos();

    bool buscarId(string ida);

    void leer();
    void escribir();

};
#endif
