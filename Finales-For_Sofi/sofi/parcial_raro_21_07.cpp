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
    int opcion;
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
NodoAprobadas* LicenciasAprobadas(Solicitud solicitud[], Categoria vec[],int resultados[][42]) //para matrices en funciones siempre poner el nro de columnas
{
    //veo si solicitud esta apta
    for (int i = 0; i < SOLICITUDES; i++)
    {
        // tengo en cuenta que los test pscotecnicos y practicos son excluyentes y son las dos primeras columnas de la matriz
        //pscotecnico -> [i][0] practico-> [i][1]
        if (resultados[i][0]== 1 && resultados[i][1]== 1)
        {
            for (int j = 0; j < 40; j++)
            {
                if(vec.[solicitud[i].])
            }
            
        }else 
        {
            cout<<"bochado"<<endl;
        }
        
        
        
    }
    

}