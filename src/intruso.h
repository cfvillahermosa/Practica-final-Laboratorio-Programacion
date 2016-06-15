#ifndef INTRUSO_H
#define INTRUSO_H

#include <personaje.h>
#include <typeinfo>
#include "planta.h"
#include "puerta.h"

/**
	@author Carlos,,, <carlos@carlos-linux>
*/
class Intruso : public Personaje
{
public:
    Intruso();
    Intruso (char m, string n, int t, int ids, int idp);
    void mostrar();
    void escribeLog(ofstream & f);
    void caminoMinimo(int origen,int destino,planta *pl);
    void ruta (ofstream & f);
    void escribeLogRuta(ofstream & f);
    void accionUno();
    void accionDos();
    void accionTres();
    void accionCuatro();
    

    ~Intruso();

};

#endif
