#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Trabajo
{
    char titulo[50];
    int categoria;
    int Id_evaluadores[3];
    string resultado[3];
};

struct NodoTrabajo
{
    Trabajo info;
    NodoTrabajo*sgte;
};

NodoTrabajo categorias[5];

int main(){

}

NodoTrabajo* listaAprobados(NodoTrabajo categorias[])
{
    NodoTrabajo* lista = NULL; // aca inicializamos la lista que vamos 
    NodoTrabajo* ult = NULL ;
    
    for (int i = 0; i < 5; i++)
    {
        NodoTrabajo* actual = categorias[i];

        while (actual!=NULL)
        {
            bool aprobado = false;

            for (int j = 0; j < 3; ++)
            {
                if (actual->info.resultado[j] == "Aprobado totalmente" || actual->info.resultado[j] == "Aprobado requiere modificaciones")
                {
                    aprobado = true;
                }   
            } 
            if(aprobado)
            {
                //creo nuevo nodo para meter en la lista

                NodoTrabajo* nuevo = new NodoTrabajo;
                nuevo->info = actual->info;
                nuevo->sgte = NULL;

                if(lista == NULL)
                {
                    lista = ult = nuevo;
                }else
                {
                    ult->sgte = nuevo;
                    ult = nuevo;
                }
            }

            actual = actual->sgte;
        } 
    }

    return lista;
};

void dictamen(NodoTrabajo* categorias[], int puntajes[],int id_evaluador,int categoria, char tituloTrabajo[])
{

    NodoTrabajo* actual =  categorias[categoria];
    int puntajeTotal = 0;
    
        while(actual!=NULL){
            

             if (strcmp(actual.info.trabajo , tituloTrabajo) == 0)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (actual->info.Id_evaluadores[i] == id_evaluador)
                    {
                        int formales=0, cienciaYtec =0, autores=0;

                        for (int i = 0; i < 4; i++)
                        {
                            formales += puntajes[i];
                        };
                        for (int i = 4; i < 8; i++)
                        {
                            cienciaYtec += puntajes[i];
                        };
                        for (int i = 8; i < 12; i++)
                        {
                            autores += puntajes[i];
                        };

                        // como si algun item 0 se rechaza todo 

                        bool rechazado = false;

                        for (int i = 0; i < 12; i++)
                        {
                            if (puntajes[i]==0)
                            {
                                rechazado = true;
                            }
                        }

                        // hago las comparaciones e rechazado 

                        if(rechazado || formales <=17 || cienciaYtec <25 || autores < 12)
                        {
                            actual->info.resultado[i] = "Rechazado";
                        };

                        if (formales >17 && cienciaYtec >25 && autores > 12)
                        {
                            actual->info.resultado[i] = "No aprobado, reformular";
                        };
                        if (formales >20 && cienciaYtec >30 && autores > 25)
                        {
                            actual->info.resultado[i] = "Aprobado requiere modificaciones";
                        };
                        if (formales >22 && cienciaYtec >35 && autores > 17)
                        {
                            actual->info.resultado[i] = "Aprobado totalmente";
                        };
                    }
                    
                }
                
            }
            
            
        }
    
    
}