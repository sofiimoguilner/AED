#include <iostream>
using namespace std;

struct Pasajero
{
    char NomyA [50];
    char destino[25];
    string vuelo;
    int asiento;
    int salida;//ddmmaaaa
    int llegada;
};

struct Nodo
{
    Pasajero pasajeros;
    Nodo *sgte;
};

void menu();
void insertarPasajero(Nodo*& cliente,Pasajero);
void ingresarPasajero(Nodo* cliente);
void VerPasajero(string nombre,Nodo*);
void VerLista(Nodo*);
void VerListaDestino(Nodo*, char destino[]);
Nodo *eliminarPasajero(Nodo*, char nombre[]);
void ModificarDatos(Nodo*, Pasajero);

int main()
{
    menu();

    return 0;  
}

void menu(){};
void insertarPasajero(Nodo&* cliente, Pasajero pasajero) //tener en cuenta que es lista circular
{
    Nodo* nuevoPasajero = new Nodo;
    Nodo* aux;
    nuevoPasajero->pasajeros = pasajero;

    if(!cliente)
    {
        nuevoPasajero->sgte = lista;
        lista = nuevoPasajero;
    }else
    {
        aux = cliente;
        while (aux->sgte != cliente)
        {
            aux = aux->sgte;
        }
        aux->sgte = nuevoPasajero;
        nuevoPasajero->sgte = cliente;
    }
}

void ingresarPasajero(Nodo&* lista)
{
    Pasajero pasajero;

    cout<<"Nombre del pasajero "<<endl;
    cin>>pasajero.NomyA;
    cout<<"Destino "<<endl;
    cin>>pasajero.destino;
    cout<<"Vuelo "<<endl;
    cin>>pasajero.vuelo;
    cout<<"Asiento "<<endl;
    cin>>pasajero.asiento;
    cout<<"salida "<<endl;
    cin>>pasajero.salida;
    cout<<"llegada "<<endl;
    cin>>pasajero.llegada;

    insertar(lista, pasajero);

};

void VerPasajero(string nombre,Nodo* lista)
{
    Nodo* aux = lista;
    while (aux->sgte != lista)
    {
        if(aux->pasajeros.NomyA == nombre)
        {
            mostrar(aux->pasajeros);
        }else
        {
            aux = aux->sgte;
        }
    }
    if(aux->pasajeros.NomyA == nombre)
    {
        mostrar(aux->pasajeros);
    }
    
};

void VerListaCompleta(Nodo*lista)
{
    Nodo*aux = lista;
    while(aux->sgte != lista)
    {
        mostrarPasajero(aux->pasajeros);
        aux = aux->sgte;
    }
    mostrarPasajero(aux->sgte);
     
};

void mostrar(Pasajero aux)
{
    cout<<"nombre y apellido: "<<aux.NomyA<<endl;
    cout<<"destino: "<<aux.destino<<endl;
    cout<<"vuelo: "<<aux.vuelo<<endl;
    cout<<"asiento: "<<aux.asiento<<endl;
    cout<<"salida: "<<aux.salida<<endl;
    cout<<"llegada: "<<aux.llegada<<endl;   
};

void VerListaDestino(Nodo* lista, char destino[])
{
    Nodo* aux = lista;
    while (aux->sgte!=lista)
    {
        if(aux->pasajeros.destino == destino)
        {
            mostrar(aux->pasajeros)
        }
        aux = aux->sgte;
    }
    if(aux->pasajeros.destino == destino)
    {
        mostrar(aux->pasajeros)
    }
};

void eliminarPasajero(Nodo* lista, char nombre[])
{
    Nodo* actual;
    Nodo* anterior = NULL;
    Nodo* nodoAEliminar;

    if(lista->pasajeros.NomyA == nombre)//si el nodo a eliminar está al principio de la lista
    {
        nodoAEliminar = lista;
        actual = lista;

        while(actual->sgte != lista)//busca el ultimo nodo
        {
            anterior = actual;
            actual = actual->sgte;
        }

        actual->sgte = lista->sgte;
        lista = lista->sgte;
        delete nodoAEliminar;
    }else //si el nodo a eliminar no esta al principio de la lista
    {
        actual = lista;
        while(actual->pasajeros.NomyA != nombre)
        {
            anterior = actual;
            actual = actual->sgte;
        }
        if(actual->pasajeros.NomyA == nombre)
        {
            anterior->sgte = actual->sgte;
            delete actual;
        };   

    }
}

