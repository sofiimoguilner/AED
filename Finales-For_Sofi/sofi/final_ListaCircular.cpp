#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

struct Pasajero
{
    char nombre[40];
    char destino [30];
    char vuelo[6];
    int asiento;
    Fecha salida;
    Fecha llegada;
    
};

struct Fecha{
    int dia;
    int hh;
    int mm;
};

struct NodoPasajero
{
    Pasajero info;
    NodoPasajero* sgte;
};

void ingresarPasajero(NodoPasajero*& lista, Pasajero pasasjero);
NodoPasajero* visualizarPasajero(NodoPasajero* cabeza_de_lista, char nombre []);
void visualizarListaDestino(NodoPasajero* cabeza_lista, char destino[]);
void eliminarPasajero (NodoPasajero *&lista, char nombre[]);
void modificarDatosPas(NodoPasajero*& lista, char nombre[]);

int main(){

    // el desarrollo principal seria un menu de opciones 

    int rta;

    cout<< "Menu Principal:"<<endl;
    cout<<"1. Agregar pasajero"<<endl;
    cout<<"2. Ver datos del pasajero"<<endl;
    cout<<"3. Ver todos los pasajeros"<<endl;
    cout<<"4. Elimina Pasajero"<<endl;
    cout<<"5. Modificar Datos de un pasajer"<<endl;
    cout<<"6. Salir"<<endl;

    cin>>rta;

    switch(rta){

         case (1):
               ingresarPasajero(lista);

         break;

         case(2):
              char nombre[40];
              cout<<"Nombre del pasajero a visualizar";
              cin>> nombre;
              visualizarPasajero(lista, nombre);
         break;

         case (3):
              char destino[30];
              cout<<"Destno a visualizar";
              cin>>destino;
              visualizarListaDestino(lista, destino);
         break;

         case(4):
              char nombre[40];
              cout<< "Pasajero a eliminar";
              cin>>nombre;
              eliminarPasajero(lista, nombre);
         break;

         case(5):
             char nombre[40];
              cout<< "Pasajero a Modificar";
              cin>>nombre;
              modificarDatosPas(lista,nombre);

         break;
             
    }

}

void ingresarPasajero(NodoPasajero*& lista)
{
    Pasajero pasajero;
    cout<<"Ingrese nombre de nuevo pasajero: ";
    cin>>pasajero.nombre;
    cout<<"Ingrese Destino: ";
    cin>>pasajero.destino;
    cout<<"Ingrese Vuelo: ";
    cin>>pasajero.vuelo;
    cout<<"Asiento: ";
    cin>>pasajero.asiento;
    cout<<"Ingrese fecha de salida: Dia: ";
    cin>>pasajero.salida.dia;
    cout<<"Hora: ";
    cin>>pasajero.salida.hh;
    cout<<"Min: ";
    cin>>pasajero.salida.mm;
    cout<<"Ingrese fecha de llegada: Dia: ";
    cin>>pasajero.llegada.dia;
    cout<<"Hora: ";
    cin>>pasajero.llegada.hh;
    cout<<"Min: ";
    cin>>pasajero.llegada.mm;
    NodoPasajero *nuevoPasajero = new NodoPasajero;
    strcpy(nuevoPasajero->info.nombre ,pasajero.nombre);
    strcpy(nuevoPasajero->info.destino, pasajero.destino);
    strcpy(nuevoPasajero->info.vuelo , pasajero.vuelo);
    nuevoPasajero->info.asiento =pasajero.asiento;
    nuevoPasajero->info.salida = pasajero.salida;
    nuevoPasajero->info.llegada = pasajero.llegada;
    
    if(lista!=NULL)
    {
        nuevoPasajero->sgte= lista->sgte;
        lista->sgte = nuevoPasajero;
    }
    else
    {
        nuevoPasajero->sgte = nuevoPasajero;
        lista = nuevoPasajero;
    }
};

NodoPasajero* visualizarPasajero(NodoPasajero* cabeza_de_lista, char nombre [])
{
    if(cabeza_de_lista == NULL)
    {
        return NULL;
    };
    
    NodoPasajero* aux = cabeza_de_lista;

    do 
    {
        if(strcmp(aux->info.nombre , nombre)== 0)
        {
            return aux;

        }else aux->sgte = aux;
    }while (aux != cabeza_de_lista);
    
};


void visualizarListaDestino(NodoPasajero* cabeza_lista, char destino[])
{ 
    if(cabeza_lista == NULL)
    {
        cout<<"Lista vacia"<<endl;
    }

    NodoPasajero* aux = cabeza_lista;

    if (strcmp(aux->info.destino , destino)==0)
    {
        cout<< aux<<endl;
        aux->sgte = aux;
    }
    else
    {
        aux->sgte = aux;
    }
};
void eliminarPasajero (NodoPasajero *&lista, char nombre[])
{
    NodoPasajero* aux = lista;
    NodoPasajero* auxiliar2;

    do 
    {
        auxiliar2 = aux;
        aux = aux->sgte;
    }while (aux!=NULL && strcmp(aux->info.nombre, nombre)!=0);
    
    if(aux!= NULL && strcmp(aux->info.nombre , nombre)==0)
    {
        if(aux!=lista)
        {
            auxiliar2->sgte = aux->sgte;
        }
        else
        {
            lista = aux->sgte;
        }

        delete aux;

    }
    
};
void modificarDatosPas(NodoPasajero*& lista, char nombre[])
{
    if(lista == NULL)
    {
        cout<<"Lista Vacia";
    
    };
    
    NodoPasajero* aux = lista;

    do 
    {
        if(strcmp(aux->info.nombre, nombre) == 0)
        {
             cout<<"Ingrese los datos del pasajero "<<nombre<<" nuevamente";
             cout<<"Ingrese Destino: ";
             cin>>aux->info.destino;
             cout<<"Ingrese Vuelo: ";
             cin>>aux->info.vuelo;
             cout<<"Asiento: ";
             cin>>aux->info.asiento ;
              cout<<"Ingrese fecha de salida: Dia: ";
             cin>>aux->info.salida.dia;
             cout<<"Hora: ";
             cin>>aux->info.salida.hh;
             cout<<"Min: ";
             cin>>aux->info.salida.mm;
             cout<<"Ingrese fecha de llegada: Dia: ";
             cin>>aux->info.llegada.dia;
             cout<<"Hora: ";
             cin>>aux->info.llegada.hh;
             cout<<"Min: ";
             cin>>aux->info.llegada.mm;
             


        }else aux->sgte = aux;
    }while(aux != lista);
}; 