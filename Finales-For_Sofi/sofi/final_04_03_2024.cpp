#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct otroLenguaje
{
    char nombre[10];
    int cant =0;
    otroLenguaje *sgte;
};

struct  Lenguaje
{
    int python=0;
    int c=0;
    int java=0;
    int otros =0;
    otroLenguaje* info;
};

Lenguaje matriz[3][3];
void cargarMatriz(Lenguaje matriz[][3])
{
    int actividad, lenguaje, institucion;
    char otro[10];

    while (unaEncuesta(actividad,institucion,lenguaje,otro))
    {
        if (lenguaje == 1)
        {
            matriz[actividad-1][institucion-1].python++;
        }
        if (lenguaje == 2)
        {
            matriz[actividad-1][institucion-1].c++;
        }
        if (lenguaje == 3)
        {
            matriz[actividad-1][institucion-1].java++;
        }
        if (lenguaje == 4)
        {
            otroLenguaje* aux;
            aux = insertarSinRepetir(matriz[actividad-1][institucion-1].info, otro);
            aux->cant ++;
            
        }
        
    }
    
}

void mostrarResultados(Lenguaje matriz[][3], int actividad)
{
    const string instituciones[]={"universidad publica","universidad privada","terciario"};
    for (int i = 0; i < 3; i++)
    {
        cout<<"Votos "<<instituciones[i]<<":";
        cout<<"Python " << matriz[actividad-1][i]<< "C "<<matriz[actividad-1][i] <<" Java "<<matriz[actividad-1][i];

        otroLenguaje* aux = matriz[actividad-1][i].info;

        while (aux!=NULL)
        {
            cout<<aux->nombre << aux->cant<< endl;
            aux = aux->sgte;
        }
        
    }

    
    
}