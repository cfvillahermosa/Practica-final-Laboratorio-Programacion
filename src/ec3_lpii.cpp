

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <cstdlib>

#include "estacion.h"

using namespace std;

int main(int argc, char* argv[])
{
//     Personaje *p;
//     queue <Personaje*> c;
//     
//     p=new Intruso('0',"nombre",3,2,1);
//     p->insertarPila(new Llave(0));
//     p->insertarPila(new Llave(1));
//     p->insertarPila(new Llave(2));
//     c.push(p);
//     
//     p=new Lider('0',"nombre",3,2,1,"orientacion",'m');
//     p->insertarPila(new Llave(0));
//     p->insertarPila(new Llave(1));
//     p->insertarPila(new Llave(2));
//     c.push(p);
//     
//     p=new Trabajador('0',"nombre",3,2,1);
//     p->insertarPila(new Llave(0));
//     p->insertarPila(new Llave(1));
//     p->insertarPila(new Llave(2));
//     c.push(p);
//     
//     
//     ofstream f("registro.log",ios::trunc);
//     
//     
//     if(f.good()){
//         while(!c.empty()){
//             p=c.front();
//             p->mostrar();
//             p->escribeLog(f);
//             c.pop();
//             delete p;
//         }
//     }
  
    
    Estacion *estacion = Estacion :: obtenerMiEstacion();
    Cargador cargador(estacion);
    FicheroCarga::procesarFichero(argv[1], cargador);
    ofstream f("registro.log",ios::trunc); 
    estacion->generar(f);
   
    
//     Personaje *p = new Intruso('H',"carlos",0,99,0);
//     p->ruta(f);
//     p->escribeLog(f);
    delete estacion;

  return EXIT_SUCCESS;
}
