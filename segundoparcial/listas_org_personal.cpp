#include <iostream>
using namespace std;

/*Estás desarrollando una aplicación de organización personal que permite a los usuarios gestionar múltiples grupos
de tareas pendientes. Las tareas tiene un tipo y deben completarse primero las tareas que se ingresaron de manera
más reciente por cada tipo.
Estructura de datos que debes utilizar:

Operaciones a implementar:
1. Agregar nueva lista de tareas según su tipo*/

struct NodoTarea 
{
 string descripcion;
 NodoTarea* sgte;
};

struct ListaPorTipo {
 NodoTarea pilaDeTareas;
 int codigoTipo;
 ListaPorTipo* sgte;
};

ListaPorTipo* lista;

ListaPorTipo* agregarNuevaListaPorTipo(ListaPorTipo* lista, int codigoTipo)
{
    ListaPorTipo ListaActual = new ListaPorTipo;
    ListaActual.codigoTipo = codigoTipo;
    ListaActual.pilaDeTareas = nullptr; //inicilizo todo el resto en null
    ListaActual.sgte = nullptr;

    //ESTO ES NECESARIO PAEA AGREGAR AL FINAL DE LA LISTA PRINCIPAL
    ListaPorTipo* Anterior = lista;
    ListaPorTipo* Auxiliar = nullptr;

    while(Anterior != nullptr)
    {
        Anterior = Auxiliar;
        Auxiliar = Auxiliar->sgte;
    }

    if(Anterior == nullptr)
    {
        lista = ListaActual;
    }
    else
    {
        Anterior->sgte = ListaActual;
    }

    return ListaActual;

};

//2Agrega una tarea a la pila de acuerdo a su código. Si no existe pila de dicho tipo debe agregarla, puedes usar
//la función del punto 1.
void agregarTarea(ListaPorTipo* lista, int codigoTipo, string descripcion)
{
    ListaPorTipo* TipoActual = lista;
    ListaPorTipo* tipoAnterior = nullptr;

    //busco lista correspondiente
    while(TipoActual!=nullptr && TipoActual->codigoTipo != codigoTipo)
    {
        tipoAnterior = TipoActual;
        TipoActual = TipoActual->sgte;
    }
    if(TipoActual == nullptr)
    {
        TipoActual = agregarNuevaListaPorTipo(TipoActual,codigoTipo)
    }

    //agregar tarea
    NodoTarea* nuevaTarea = new NodoTarea;
    nuevaTarea->descripcion= descripcion;
    nuevaTarea->sgte = TipoActual->pilaDeTareas;
    TipoActual->pilaDeTareas = nullptr;
};

//3. Retorna la próxima tarea del código. Retorna “No tengo” si no hay.
string dameProximaTarea(ListaPorTipo* lista, int codigoTipo)
{
    ListaPorTipo* actual = lista;

    while(actual!=nullptr && actual->codigoTipo!=codigoTipo)
    {
        actual = actual->sgte;
    }
    if(actual!=nullptr && actual->codigoTipo == codigoTipo)
    {
        return actual->pilaDeTareas.descripcion;
    }
    if (actual == nullptr || actual->pilaDeTareas == nullptr)
    {
        returnt "no hay";
    }
 
    // avance en la lista
    string descripcion = actual->pilaDeTareas.descripcion;
    NodoTarea* eliminar = actual->pilaDeTareas;
    actual->pilaDeTareas = actual->pilaDeTareas.sgte;

    delete eliminar;
    return descripcion;
    
};
//4 cantidad de tareas pendientes
int dameCantidadDePilasConTareasPendientes(ListaPorTipo* lista)
{
    int contador = 0;

    ListaPorTipo* actual = lista;

    while (actual!=nullptr)
    { 
        if(actual->pilaDeTareas!=null){
        contador++;}
        actual = actual->sgte;
    }

    return contador;
    
};
