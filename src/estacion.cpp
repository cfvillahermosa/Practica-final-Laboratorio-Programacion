#include "estacion.h"

Estacion *Estacion :: miEstacion = NULL;

/**
 * Metodo constructor por defecto de la clase Estacion
 * \param "" No recibe parametros
 * \return No retorna ningun valor
 */
Estacion::Estacion()
{
    turnosimulacion=0;
}

/**
 * Metodo Destructor de la clase Estacion
 * \param "" No recibe parametros
 * \return No retorna ningun valor
 */
Estacion::~Estacion()
{
    for(int i=0;i<vec.size();i++){
        delete vec[i];
    }
    while(!salaprisioneros.empty()){
        delete salaprisioneros.front();
        salaprisioneros.pop();
    }
    while(!desalojados.empty()){
        delete desalojados.front();
        desalojados.pop();
    }
     GenAleatorios::destruir();
}

/**
 * Metodo que inserta en un vector de plantas una planta 
 * \param p es un objeto de la clase Planta
 * \return No retorna ningun valor
 */

void Estacion::insertarVector(planta * p)
{
    vec.push_back(p);
}


/**
 * Metodo que genera las plantas,calcula las rutas, controla los turnos...etc 
 * \param f es un flujo de entrada salida que escribe en mi fichero
 * \return No retorna ningun valor
 */
void Estacion::generar(ofstream & f)
{
    bool fin=false;
    for(int i=0;i<vec.size();i++){
        vec[i]->generarPlanta(f);
    }
    for(int i=0;i<vec.size();i++)
        vec[i]->calcularRutaSalasPlanta(f);
    
    while(desalojados.empty()){
        
        f<<"(turno:"<<turnosimulacion<<")"<<endl;
        f<<"(salaprisioneros:1101)"<<endl;
        //! Hacer el log de los personajes que son prisioneros
        Personaje *per;
        queue <Personaje*> aux;
        while(!salaprisioneros.empty()){
            per=salaprisioneros.front();
            aux.push(salaprisioneros.front());
            per->escribeLog(f);
            salaprisioneros.pop();
        }
        while(!aux.empty()){
            salaprisioneros.push(aux.front());
            aux.pop();
        }
        for(int i=vec.size()-1;i>=0;i--){
            vec[i]->escribeLogPlanta(f);
        }
        for(int i=vec.size()-1;i>=0;i--)
            vec[i]->accionesPersonajesSalas();
        if(!desalojados.empty())
            f<<"(fin de la simulacion)"<<endl;
        
        turnosimulacion=turnosimulacion +1;
    }
    f<<"(salaprisioneros:1101)"<<endl;
    //! log de los personajes que son prisioneros
    Personaje *per;
    queue <Personaje*> aux;
    while(!salaprisioneros.empty()){
        per=salaprisioneros.front();
        aux.push(salaprisioneros.front());
        per->escribeLog(f);
        salaprisioneros.pop();
    }
    while(!aux.empty()){
        salaprisioneros.push(aux.front());
        aux.pop();
    }
    
    for(int i=vec.size()-1;i>=0;i--){
        vec[i]->escribeLogPlanta(f);
        
    }
    escribeLogDesalojados(f);
}

/**
 * Metodo que inserta un personaje en su planta correspodiente y dentro de la sala correspondiente con su idsala
 * \param p es un objeto de la clase Personaje
 * \return No retorna ningun valor
 */
void Estacion::insertarPersonajeEstacion(Personaje * p)
{
    planta *aux=vec[p->getIdPlanta()];
    aux->insertarPersonajeSala(p);
}



/**
 * Metodo que devuelve la planta que se corresponde con el entero idp
 * \param idp es un parametro de entrada que corresponde con la casilla del vector de plantas que quiero obtener
 * \param p es un parametro puntero de entrada salida que devuelve la planta correspondiente a la celda del vector idp
 * \return No retorna ningun valor
 */
void Estacion::obtenerPlanta(int idp, planta *& p)
{
    p=vec[idp];
   
}

/**
 * Metodo que devuelve el entero asociado al tamaño de mi vector de plantas
 * \param "" no tiene parametros
 * \return Devuelve un entero que se corresponde con el tamaño de mi vector de plantas
 */
int Estacion::totalPlantas()
{
    return vec.size();
}


Estacion * Estacion::obtenerMiEstacion()
{
    if( Estacion :: miEstacion == NULL )
        miEstacion=new Estacion();
    return miEstacion;
}

/**
 * Metodo que calcula las rutas de las salas de las  plantas de mi vector de plantas 
 * \param f es un flujo de entrada salida que escribe en mi fichero todo lo correspondiente a las rutas de los personajes que almacenan las salas de cada una de las plantas de mi vector de plantas
 * \return No retorna ningun valor
 */
void Estacion::calcularRutaPlantasEstacion(ofstream & f)
{
    for(int i=0;i<vec.size();i++){
        vec[i]->calcularRutaSalasPlanta(f);
    }
}

/**
 * Metodo que asigna un valor entero a mi atributo turnosimulacion de mi clase estacion
 * \param t es un parametro de entrada del tipo entero
 * \return No retorna ningun valor
 */
void Estacion::setTurnoSimulacion(int t)
{
    turnosimulacion=t;
}
/**
 * Metodo que devuelve el entero que se corresponde con el atributo turnosimulacion de mi clase estacion
 * \param "" no recibe parametros
 * \return Retorna un entero que se corresponde con el atributo turnosimulacion de mi clase estacion
 */
int Estacion::getTurnoSimulacion()
{
    return turnosimulacion;
}

/**
 * Metodo que inserta en mi atributo cola salaprisioneros un personaje
 * \param per es un parametro de entrada de la clase Personaje
 * \return No retorna ningun valor
 */
void Estacion::insertarSalaPrisioneros(Personaje * per)
{
    salaprisioneros.push(per);
}

/**
 * Metodo que realiza las acciones de los personajes de cada planta con sus correspondientes salas
 * \param "" no recibe parametros
 * \return No retorna ningun valor
 */
void Estacion::accionesPersonajesPlanta()
{
    for(int i=totalPlantas()-1; i>=0;i++){
        vec[i]->accionesPersonajesSalas();
    }
}

/**
 * Metodo que inserta un personaje en en el atributo cola desalojados
 * \param p es un parametro de entrada de la clase Personaje
 * \return No retorna ningun valor
 */
void Estacion::insertarDesalojado(Personaje * p)
{
    desalojados.push(p);
}

/**
 * Metodo que escribe en mi registro.log los personajes contenidos en mi cola desalojados
 * \param f es un flujo de entrada salida que escribe en mi registro.log la informacion correspondiente a los personajes contenidos en mi atributo cola desalojados.
 * \return No retorna ningun valor
 */
void Estacion::escribeLogDesalojados(ofstream & f)
{
    f<<"(miembrosdesalojados)"<<endl;
    Personaje *aux;
    queue <Personaje*> aux2;
    while(!desalojados.empty()){
        aux=desalojados.front();
        aux->escribeLog(f);
        aux2.push(aux);
        desalojados.pop();
    }
    
    while(!aux2.empty()){
        desalojados.push(aux2.front());
        aux2.pop();
    }

    
    
    f<<endl;
}