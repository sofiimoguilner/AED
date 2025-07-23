#include <iostream>
#include <stdio.h>

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
void visualizarPasajero(NodoPasajero*& lista, char nombre []);
void visualizarListaDestino(NodoPasajero*& lista, char destino[]);
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
         cout<<"Ingreso de nuevo pasajero"<<
         ingresarPasajero();
        
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
    nuevoPasajero->info.nombre = pasajero.nombre;
    nuevoPasajero->info.vuelo =pasajero.vuelo;
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

void visualizarPasajero(NodoPasajero*& lista, char nombre [])
{
    
};
void visualizarListaDestino(NodoPasajero*& lista, char destino[]);
void eliminarPasajero (NodoPasajero *&lista, char nombre[]);
void modificarDatosPas(NodoPasajero*& lista, char nombre[]);