#include <iostream>
#include <stdio.h>

using namespace std;

/*Ejercicio 1: funcion que retorne lista ordenada a partir de unir una cola y una pila
usar estructuras pre definida que uno cree que necesita*/

struct Nodo {
    int info;
    Nodo* sgte;
}

void insertarOrdenado(Nodo &lista, int dato)
{
    Nodo* nuevo = new Nodo;
       nuevo->info = dato;
//si la lista esta vacia inserto al principio y si el dato es menor al que esta tmb(para eso sirve el o agregado)
    if (lista==NULL|| dato < lista->info)
    {
       nuevo->sgte = lista;
       lista = nuevo;

    } else //inserta en el medio o al final
    {
        Nodo* aux = lista;
// la segunda parte del 'y' nos permite comparar elemento por elemento para ver si es menor o no
        while (lista->sgte!=NULL && aux->info < dato) 
        {
            aux = aux->sgte;
        }
        nuevo->sgte = aux-> sgte;
        aux->sgte = nuevo;
    }
    
}


//APAREO = técnica de mezcla ordenada.
Nodo* apareo(Nodo* pila,Nodo* frente, Nodo* fin) //nodo frente y nodo fin pertenece a la cola que tenemos ue unir 
{
    //wihle para recorrer cualquier estructura dinamica
    while (pila!=NULL)
    {
        insertarOrdenado(lista,pila->info);
       
        pila=pila->sgte;
    }
    while (frente!=NULL)//como no le vamos a agregar datos a la cola no necesitamos el fin
    {
        insertarOrdenado(lista,frente->info);
       
        frente=frente->sgte;
    }

    return lista; 
}//funcion que nos tiene que devolver una lista ordenada

/*EJ 2: vector de notas de alumnos con campos (cuando nos dice campos va irecto un struct)
legajo nota 1erP, nota 2doP.
Tmb hay una lista que tiene las nostas del recu del 2do P, cada nodo tiene legajo nota recu 2doP
Objetivo: actualizar vector con la lista, si aprueba se pisa nota y si no no la cambia. Maximo 1500 alumnos*/

struct Alumno
{
    int legajo;
    float nota1;
    float nota2;
}

struct NodoNota
{
    int legajo;
    float nota;
    NodoNota* sgte;
};

void actualizar(Nota notas[], NodoNota* lista)
{
    while(lista)
    {
        for(int i=0; i<1500 ; i++)
        {
            if(nota[i].legajo == lista->legajo)
            {
                if(lista->nota >= 6)
                {
                    notas[i].nota2 = lista->nota;
                }
                i=1500; //es para que termine el for, si no lo pongo va a gastar mucho tiempo es buscar al resto de alumnos (OPTIMIZACION)
            }
        }
        lista = lista->sgte
    }
}

/*Ej 3: Decir lo que sale por pantalla 

struct Nodo {
    int info;
    Nodo *sgte;
};

int main() {
    Nodo *p = NULL; Nodo *aux;
    p = new Nodo();
    p->info = 1; p->sgte = new Nodo();
    p->sgte->info = 2; p->sgte->sgte = new Nodo();
    p->sgte->sgte->info = 3; p->sgte->sgte->sgte = NULL;
    aux = p;
    p = p->sgte;
    p->sgte->sgte = aux;
    aux->sgte = NULL;
    aux = p;
    while (aux) {
        cout << aux->info << " ";
        aux = aux->sgte;
    }
    return 0;
}

-> salida por pantalla
2 3 1

void doThat(int *p1, int *p2) {
    p1 = new int();
    *p1 = *p2;
    return;
}

int main() {
    int x;
    x = 10;
    int *p;
    p = &x;
    doThat(p, &x);
    cout << *p;
    delete p;
    return 0;
}
->salida por pantalla 10

*/

/*Ej 4: Verdadero/Falso 
"En el apareo, el conjunto resultante siempre contendrá todos los elementos únicos presentes en ambos conjuntos 
originales, sin ninguna pérdida de información."
 FALSO
Justificación: El apareo (también conocido como merge) no necesariamente conserva solo los elementos únicos; 
depende de cómo esté implementado. El objetivo principal del apareo es fusionar dos archivos ordenados, 
normalmente conservando el orden y posiblemente repitiendo elementos si aparecen en ambos conjuntos. 
Si se desea conservar solo los elementos únicos,
se debe implementar una lógica adicional (por ejemplo, eliminar duplicados manualmente).

"El corte de control en archivos sólo puede aplicarse si el archivo está 
ordenado y no tiene clave repetida."
 FALSO
Justificación: El corte de control requiere que el archivo esté ordenado por la clave sobre
la cual se realiza el corte, pero sí puede tener claves repetidas, y de hecho, 
es común usarlo precisamente para agrupar registros con la misma clave 
(por ejemplo, sumar ventas por cliente o producto). 
Lo importante es que los registros iguales estén consecutivos para que el corte funcione correctamente.*/
