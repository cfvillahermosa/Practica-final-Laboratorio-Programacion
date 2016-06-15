/**
 * \file cargador.h
 * \brief Práctica 2006-2007. Declaracion de la clase Cargador
 * \author
 *   \b Profesores LPII \n
 *   \b Asignatura Laboratorio de Programación II \n
 *   \b Curso 07/08 -- Revisado en Curso 08/09
 */

#ifndef CARGADOR_H
#define CARGADOR_H

#include "fichero.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

#include "intruso.h"
#include "lider.h"
#include "trabajador.h"


/*!
   \def DEPURAR
   Variable constante utilizada para mostrar o no mensajes de depuración de programa
 */
#define DEPURAR 0

/*!
   \def DEPURAR_MSG
   Macro utilizada para mostrar mensajes de depuración de programa y retener los mensajes en pantalla
 */
//#define DEPURAR_MSG(msg) if (DEPURAR){ cout<<msg; cin.get();}
#define DEPURAR_MSG(msg) if (DEPURAR){ cout<<msg;}


/**
* \def NUMELTOSCONF Indica el número de líneas de configuración diferentes que puede haber en el fichero
*/
#define NUMELTOSCONF 4//mas adelante habra que incrementarlo a 4 en la defensa habra que cambiarlo a 5

using namespace std;

class Estacion;

/**
* \class Cargador
* \brief La misión de esta clase es cargar el sistema con los elementos del fichero de configuración
*/
class Cargador//esta clase carga todos los elementos que tenemos en el fichero
{
    typedef struct DatoMapeo
    {
        char nombre[50];
        int numCampos;
    };

    /**
     * \var mapeo 
     * \brief Vector de Mapeo. Asigna a cada nombre de elemento un valor numérico (posición en el vector) y contiene el número de campos de configuración para cada elemento 
    */
    static DatoMapeo mapeo[NUMELTOSCONF];

    Estacion* E;

    int queElemento(string elto);
    void crearPlanta(int numCampos, string vCampos[MAXCAMPOS]);//le viene un entero que es el numero de campos , lo podemos usar ese entero o no , como queramos, y nos viene un vector de string 
    void crearIntruso(int numCampos, string vCampos[MAXCAMPOS]);
    void crearLider(int numCampos, string vCampos[MAXCAMPOS]);
    void crearTrabajador(int numCampos, string vCampos[MAXCAMPOS]);
    
public:
    Cargador(Estacion* p);
    void crear(string elto, int numCampos, string vCampos[MAXCAMPOS]);
};

#endif
