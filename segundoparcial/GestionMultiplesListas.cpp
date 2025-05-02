#include <iostream>
using namespace std;


/*aplicación de organización personal que permite a los usuarios gestionar múltiples grupos
de tareas pendientes. Las tareas tiene un tipo y deben completarse primero las tareas que se ingresaron de manera
más reciente por cada tipo.*/

struct Tarea  
{
    string descripcion;
    int tipo;
    Tarea* sgte;
};

struct ListaPorTipo
{
    Tarea pilaDeTareas;
    ListaPorTipo* sgte;
};

//1.Agregar nueva lista de tareas según su tipo
ListaPorTipo* agregarNuevaListaPorTipo(ListaPorTipo* lista, int codigoTipo,string descripcion)
{
    ListaPorTipo* nuevaLista = new ListaPorTipo;
    nuevaLista->pilaDeTareas.tipo= codigoTipo;
    nuevaLista->pilaDeTareas.descripcion = descripcion;
    nuevaLista->stgte = nullptr;

    //ver si lista esta vacia
    if(lista==nullptr)
    {
        lista = nuevaLista;
    }
    else
    {
        ListaPorTipo* actual= lista;

        while(actual!=nullptr)
        {
            actual = ListaPorTipo* actual->sgte;
        }

        actual->sgte = nuevaLista;

        return lista;
    }

}

//Agrega una tarea a la pila de acuerdo a su código. 
//Si no existe pila de dicho tipo debe agregarla, puedes usarla función del punto 1.


void agregarTarea(ListaPorTipo* lista, int codigoTipo, string descripcion)
{
    ListaPorTipo* tipoActual = lista;
    ListaPorTipo* tipoAnterior = nullptr;
    while (tipoActual!=nullptr && tipoActual.pilaDeTareas.tipo != codigoTipo)
    {
        tipoAnterior = tipoActual;
        tipoActual = tipoActual->sgte;
    }
    if(tipoActual==nullptr)
    {
        tipoActual = agregarNuevaListaPorTipo(tipoActual,codigoTipo,descripcion);
    }

    //agregar tarea a la pila de tareas
    Tarea* nuevaTarea = new Tarea;
    nuevaTarea->tipo=codigoTipo;
    nuevaTarea->descripcion=descripcion;
    nuevaTarea->sgte=tipoActual->pilaDeTareas;
    tipoActual->pilaDeTareas = nuevaTarea;
};

//3.Retorna la próxima tarea del código. Retorna “No tengo” si no hay.
string dameProximaTarea(ListaPorTipo* lista, int codigoTipo)
{
    ListaPorTipo actual = lista;

    while(actual!=nullptr && actual.pilaDeTareas.tipo != codigoTipo)
    {
        actual = actual.sgte;
    }
    if(actual !=nullptr && actual.pilaDeTareas.tipo== codigoTipo)
    {
        return actual.tarea.descripcion;
    }
    if(actual==nullptr  &&   actual->pilaDeTareas==nullptr)
    {
        return "no hay";
    }

    //debemos avanzar en la lista
    string descripcion = actual->pilaDeTareas->descripcion; //apunta tarea de cima de pila 
    Tarea* eliminar = actual->pil aDeTareas; //creacion de nodo que va a eliminar la tarea
    actual->pilaDeTareas = actual->pilaDeTareas->sgte //actualiza pilaDeTareas y va al sgte
    delete eliminar; 

    return descripcion
};
