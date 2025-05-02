#include <iostream>
using namespace std;

//1. Declarar las estructuras que vas a necesitar y explicar por qué las elegiste. (1 puntos)
struct Persona{
    int dni, codsorteo;
    string nombre;
    Persona* siguiente;//puntero para la colas
};
struct Sorteo
{
    char descripcion[200];
    int cantganadores, codigo;
    Persona persona;
};
struct Nodo
{
    Sorteo sorteo;
    Nodo *siguienteSorteo;
} 
//perona: representa a cada participante de cada sorteo
//sorteo: representa a cada sorteo del archivo 
//nodo: me va aayudar a la hora crear las estructuras dinamicas para poder cargar los sorteo 
//y las personas de cada sorteo.

//2. Leer todo el archivo de sorteos y alojarlos en la estructura que haya sido elegida (2 puntos)
void cargarSorteos(Nodo*& inicio, Sorteo sorteo)
{
  sorteo = dameSiguienteRegistroDelArchivo; //supongo que la funcion abre y lee el archivo de sorteos 

  while(sorteo.codigo!=0)
  {
    sorteo = addElementoLista(inicio, sorteo);
    sorteo = dameSiguienteRegistroDelArchivo;
  }   
}
//3. Registrar persona a un sorteo. Las personas que se registran deben ingresar su nombre y su DNI.

void RegistrarPersonas(Persona* persona, Persona p, Sorteo* sorteolista)
{
    Persona* persona = new perosna;
    int codigo
    cout<<"Reistro"<<endl;
    cout<<"Nombre: "<<endl; cin>>persona->nombre;
    cout<<"DNI: "<<endl; cin>>persona->dni;

    cout<<"Codigo del sorteo a ingresar: "<<endl;cin>>codigo;

    //comparo sorteo igresado con el de lista 
    Nodo* sorteoActual = sorteolista;
    while (sorteoActual != nullptr && sorteoActual->sorteo.codigo != codigo)
    {
        sorteoActual = sorteoActual->siguienteSorteo;
    }

    if (sorteoActual!=nullptr)//existe el sorteo
    {
        push(persona, p);
    }
    else
    {
        cout<<"Sorteo no existente";
        delete persona; //libero memoria
    }
}
//4.Eliminar un sorteo entero liberando la memoria correspondiente. (2 puntos)

//asumo que en main se ingresa el sorteo para elimnar  
void eliminarPilaPersonas(Persona*& topePila)
{
    while (topePila != nullptr)
    {
        Persona* aux = topePila;
        topePila = topePila->siguiente;
        delete aux;
    }
}

void eliminarListaSorteos(Nodo*& inicio)
{
    while (inicio != nullptr)
    {
        // Primero eliminamos la pila de personas asociada al sorteo actual
        eliminarPilaPersonas(inicio->sorteo.persona.siguiente);

        // Luego eliminamos el nodo del sorteo
        Nodo* aux = inicio;
        inicio = inicio->siguienteSorteo;
        delete aux;
    }
}

//Pueden dar por hecho que existen las siguientes funciones: (El Nodo es a modo ilustrativo, 
//puede ser de los struct que cada uno genere)
void push(Nodo*& pila, int valor);
int pop(Nodo*& pila);
void encolar(Nodo*& frente, Nodo*& final, int valor);
int desencolar(Nodo*& frente, Nodo*& final);
Nodo* addElementoLista(Nodo* inicio, int valor);
Sorteo dameSiguienteRegistroDelArchivo(); // Devuelve un sorteo del archivo mientras el mismo exista, 
//sino devuelve un Sorteo que tiene Codigo igual a 0. 
