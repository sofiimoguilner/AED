#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
                                   //ESTRUCTURAS DE ENTRADA DE INFORMACION
//struct de la matriz

struct Cursos
{
    int cantMax;
    int inscriptos;
    int nro;
    NodoAlumno* lista_alumnos;
    
    
};

//se crea a partir que la consigna dice que tiene un puntero de la lista de alumnos

//struct de lista 

struct Alumno
{
    int legajo;
    char nombre[30];//apellid y nombre

};

struct NodoAlumno
{
    Alumno info;
    NodoAlumno* sgte;
};

//struct para el archivo

struct Solicitud
{
    char nombre [30];
    int legajo;
    Alternativas cursos;
    
};

struct Alternativas{
    int alternativa1;
    int alternativa2;
    int alternativa3;
};

                             //ESTRUCTURAS DE SALIDA DE INFORNACION

struct Aprobada
{
    char nombre[40];
    int curso;
    int legajo;
};

struct NodoAprobada
{
    Aprobada info;
    NodoAprobada*sgte;
};

// como denegava va en archivo no ponemos nodo
struct Denegada
{
    char nombre[40];
    int legajo;
};

int const cursos =20;

int main(){
    
};

// la funcion que nos pide en la consigna es la devolucion de una lista a partir de un archivo, por eso la hago como nodo y no void

NodoAprobada* ListarArchivas(Cursos cursos[][3], char nombre_archivo[]) // hago el char de solicitudes pq vienen de un archivo
{
    NodoAprobada* aprobada = NULL;
    //hay que mandar a un listado o a un archivo dependendo que se pasa con solicitus
    //EL DATO IMPORTANTE ESLA INSCRIPCION
    FILE* archivo = fopen("nombre_archivo","rb");

    //COMO NO HAY REPETICION - ORDEN -ETC -> NO HAY CORTE DE CONTROL

    Solicitud solicitud_actual;

    while (fread(&solicitud_actual, sizeof(Solicitud),1, archivo))
    {
        if(correlativas(solicitud_actual.legajo)) // funcion que dan en la cansigna
        {
            for (int i = 0; i < cursos; i++)//buscamos alternativas para ver si se puede meter usuario
            {
                if (cursos[i][0].nro == solicitud_actual.cursos.alternativa1)
                {
                    if (cursos[i][0].inscriptos < cursos[i][0].cantMax)
                    {
                        insertarAlumnos(aprobada, solicitud_actual);
                    }
                    
                }
                
            }
            
        }
    }
    
}









