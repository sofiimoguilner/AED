#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

// retornar lista que sea la interseccion de una lista y una pila

struct NodoPila
{
    int info;
    NodoPila*sgte;
};

struct NodoLista
{
    int info;
    NodoLista*sgte; 
};

// Pre condiciones, la lista y la pila estan inializadas correctamente, pueden estar o no ordenadas
// Post condiciones lista ordenada de menor a mayor

NodoLista* interseccion (NodoLista* lista, NodoPila* pila)
{
    int cantElementosPila=0;
    int elementosPila[cantElementosPila];

    NodoPila* p1=pila;

    while (p1!=NULL)
    {
        elementosPila[cantElementosPila] = p1->info;
        p1 = p1->sgte;
        cantElementosPila++;
    }

    // para las listas enlazadas uso while y para los arrays for 

    NodoLista* aux = lista;
    NodoLista* nueva_lista = NULL;
    NodoLista* ultimo_elemento = NULL;

    while (aux!=NULL)
    {
        bool estaEnElVector = false;
        for (int i = 0; i < cantElementosPila; i++)
        {
            if (aux->info == elementosPila[i])
            {
                estaEnElVector = true;
                break; // salir del for pq ya lo encontre
            }
            
            
        }
        if (estaEnElVector == true)
        {
            NodoLista* lista_interseccion = new NodoLista;
            lista_interseccion->info = aux->info;
            lista_interseccion->sgte = NULL;

            if (nueva_lista == NULL)
            {
                nueva_lista = ultimo_elemento = NULL;
            }else{
                ultimo_elemento->sgte = lista_interseccion;
                ultimo_elemento = lista_interseccion;
            }
            
        }
        

        aux = aux->sgte;
        
    }
    

    
    return nueva_lista;


}

