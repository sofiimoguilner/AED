#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int const SOLICITUDES = 70;

struct Solicitud{
    int nro_orden;
    int categoria;
    char nombre[40];
};


struct Categoria
{
    int id;
    char vehiculo_autorizada[20];
    Pregunta preguntas;
};


struct Pregunta{
    bool excluyente;
    char pregunta[50];
    int respuesta;
};

struct Aprobadas{
    int nroOrden;
    char nombre[40];
};

struct NodoAprobadas{
    Aprobadas aprobada;
    NodoAprobadas* sgte;
};


NodoAprobadas* LicenciasAprobadas(Solicitud solicitud[], Categoria vec[],int resultados[][42]);
int main()
{
    int resultados [SOLICITUDES][42];


};

// la finalidad es q devuelva una lista
NodoAprobadas* LicenciasAprobadas(Solicitud sol[], Categoria vec[],int resultados[][42]) //para matrices en funciones siempre poner el nro de columnas
{
    //veo si solicitud esta apta
    for (int i = 0; i < SOLICITUDES; i++)
    {
        bool rechazado = false;// nos va servir para en el if tener en cta lo del 0 y 1, donde 0 es que no es apta
        // tengo en cuenta que los test pscotecnicos y practicos son excluyentes y son las dos primeras columnas de la matriz
        //pscotecnico -> [i][0] practico-> [i][1]
        if (resultados[i][0]== 1 && resultados[i][1]== 1)
        {
            int puntos =0;
           
            for (int j = 0; j < 40; j++)
            {
                
                int respuesta_correcta = vec[i].preguntas.respuesta;//rta correcta, nos va a simplificar el if
                if(vec[sol[i].categoria-1].preguntas[j].excluyente && resultados[i][j+2] != respuesta_correcta)
                {
                    rechazado = true;
                };

                if(!vec[sol[i].categoria-1].preguntas[j].excluyente && resultados[i][j+2] == respuesta_correcta)
                {
                   puntos++;// suma puntos de las respuestas correctas no excluyentes ya que cada categoria nec una cierta cant de estas para aprobar 
                };
            };
            
        }else 
        {
            rechazado = true;
        }
        if(vec[sol[i].categoria] < 4 && puntos < 25)
        {
            rechazado = true;
        }
        if(vec[sol[i].categoria] > 3 && puntos < 30){
            rechazado = true;
        }
        if(!rechazado)
        {
            insertarOrdenado(lista,sol[i])
        }
        
    }
    

}