#include <iostream>
using namespace std;

/*Se requiere un sistema que permita la administración de equipos en un torneo de fútbol. Cada equipo
tiene un conjunto de jugadores titulares y suplentes. El sistema debe ser capaz de agregar jugadores
a las listas correspondientes y realizar consultas sobre los equipos y sus jugadores
Operaciones a implementar:
1. Inicializa todos los equipos, estableciendo los código de los equipos del 10 al 30 y asegurando
que las listas de titulares y suplentes estén vacías.
2. Agrega un jugador a la lista del equipo indicado por codigoEquipo
3.Devuelve al mejor jugador del equipo*/

struct Jugador 
{
string nombre;
int habilidad;
};
struct NodoJugador
{
Jugador jugador;
NodoJugador* sgte;
};
struct Equipo 
{
int codigoEquipo;
NodoJugador jugadores;
};
Equipo equipos[20]; // Un array de equipos.


//1
void inicializarEquipos(Equipo equipo[], int cantidad)
{
    for(int i=0;i<cantidad;i++)
    {
        equipo[i].codigoEquipo= i+10;
        equipo[i].jugadores = nullptr;
    }
};


//2

NodoJugador* AgregarJugador(NodoJugador* jugador, string nombre, int habilidad)
{
    NodoJugador* Nuevojugador = new NodoJugador;
    Nuevojugador->nombre = nombre;
    Nuevojugador->habilidad = habilidad;
    Nuevojugador->sgte = nullptr;

    //veo si lista esta vacia
    if(jugador==nullptr)
    {
        jugador = Nuevojugador;
    }
    else
    {
        NodoJugador* actual = jugador;

        while (actual !=nullptr)
        {
            actual = actual->sgte;
        }

        actual->sgte = Nuevojugador;
    }
    return jugador;
}
void agregarJugador(Equipo equipos[], int codigoEquipo, string nombreJugador, int habilidad, int cantidadEquipos)
{
    //encontrar equipo

    for (int i = 0; i < cantidadEquipos; i++)
    {
        if(equipos[i].codigoEquipo==codigoEquipo)
        {
            equipos[i].jugadores = AgregarJugador(equipos[i].jugadores,nombreJugador,habilidad);
        }
    }

    cout<<"no se encontro equipo del jugador";
};

//3
Jugador obtenerCapitan(Equipo equipos[], int codigoEquipo, int cantidad)
{
    int contador = 0;
    Jugador JugMax;

    for(int i=0;i<cantidad;i++)
    {
        if(equipos[i].codigoEquipo == codigoEquipo)
        {
          int max=0;

          NodoJugador* jug = equipos[i].jugadores;

          while(jug!=null)
          {
            if (jug->jugador.habilidad > max)
            {
                max = jug->jugador.habilidad;
                JugMax = jug->jugador;
            }
            
            jug = jug->sgte;
          }
        }
    }

    return JugMax;
};