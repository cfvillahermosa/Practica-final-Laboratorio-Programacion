#ifndef LIDER_H
#define LIDER_H

#include <miembro.h>
#include <stack>
#include <set>
#include <iostream>
using namespace std;
/**
	@author Carlos,,, <carlos@carlos-linux>
*/
class Lider : public Miembro
{
    string secuenciaorientaciones;
    char movimiento;
    set <Personaje*> grupo;
    
public:
    Lider();
    Lider(char m, string n, int t, int ids, int idp, string sec, char mov);
    void setMovimiento(char m);
    char getMovimiento();
    void setSecuenciaOrientaciones(string s);
    void getSecuenciaOrientaciones(string & s);
    void mostrar();
    void escribeLog(ofstream & f);
    void ruta(ofstream & f);
    void actualizarMovimiento();
    bool recorrerVecinos(int ids, stack< char > &secorientaciones, stack< int > &idvecinos, set <int> &vecinos);
    void escribeLogRuta(ofstream & f,stack <char> & s,stack <int> &idsalas);
    void accionUno(); 
    void accionDos();
    void accionTres();
    ~Lider();

};

#endif
