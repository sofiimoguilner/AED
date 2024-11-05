#include <iostream>
using namespace std;

// Definición de la estructura Nodo
struct Nodo {
    string cancion;
    Nodo* siguiente;
};

//struct de punt 3

struct registro
{
    string tilulo;
    string artista;
    int calificacion;

};

// Función para crear un nuevo nodo
Nodo* crearNodo(string valor) {
    Nodo* nuevaCancion = new Nodo;
    nuevaCancion->cancion = valor;
    nuevaCancion->siguiente = nullptr;
    return nuevaCancion;
};

// Función para insertar un elemento en la pila
void push(Nodo*& pila, string valor) {
    Nodo* nuevaCancion = crearNodo(valor);
    nuevaCancion->siguiente = pila;
    pila = nuevaCancion;
};

// Función para eliminar y obtener el elemento en la cima de la pila
string pop(Nodo*& pila) {
    if (pila == nullptr) {
        cout << "La playlist está vacía." << std::endl;
        
    }
    string valor = pila->cancion;
    Nodo* temp = pila;
    pila = pila->siguiente;
    delete temp;
    return valor;
};

//mostrar siguiente cancion sin removerla
string pop2(Nodo*& pila) {
    if (pila == nullptr) {
        cout << "La playlist está vacía." << std::endl;
        
    }
    string valor = pila->cancion;
    Nodo* temp = pila;
    pila = pila->siguiente;
    return valor;
}

//Función para verificar si la pila está vacía
bool isEmpty( Nodo* pila) {
    return pila == nullptr;
}

//punto 2, revertir playlist
void revertir(Nodo*& playlist)
{
    Nodo* pilauxiliar = nullptr;

    while (playlist!=nullptr)
    {
        string cancion=pop(playlist);
        push(playlist,cancion);

    }

    playlist = pilauxiliar;
    cout<<"Playlist revertida"<<endl;
    
}

// muestro playlist completa
void mostrarPlaylist(Nodo* pila) {
    Nodo* temp = pila;
    cout << "Playlist:" << endl;
    while (temp != nullptr) {
        cout << "- " << temp->cancion << endl;
        temp = temp->siguiente;
    }
}

int main() {
    Nodo* playlist = nullptr; // Inicializar la pila
    int rta;
    string nueva_cancion;

    
    while (!isEmpty(playlist)) {

        cout<<"Menu"<<endl;
        cout<<"1.Agregar cancion"<<endl;
        cout<<"2.Escuchar siguiente cancion"<<endl;
        cout<<"3.Próxima canción "<<endl;
        cout<<"4.Revertir playlist"<<endl;
        cout<<"5.Historial"<<endl;
        cin>>rta;
        switch(rta)
        {
            case 1:
            cout<<"Nueva cancion: ";
            cin>>nueva_cancion;
            push(playlist,nueva_cancion);

            break;

            case 2:
            if (isEmpty(playlist)) {
                cout << "La playlist está vacía." << endl;
            } else {
                pop(playlist);
            };

            break;

            case 3:
            pop2(playlist);

            break;

            case 4:
            revertir(playlist);

            break;

            case 5:

            break;


        }
        
    }
    cout << endl;

    return 0;
}