#include <iostream>
#include <stdio.h>

using namespace std;

int main(){}

void Interactuar()
{
    int rta;
    rta = GetAccion();
    while (rta != 5)
    {
        if (rta == 1)
        {
            /* code */
        }
        if (rta == 2)
        {
            /* code */
        }
        if (rta == 3)
        {
            /* code */
        }
        if(rta == 4)
        {
            
        }
        
        
        
    }
    
}

int GetAccion()
{
    int n;
    cout<<"Elija opcion:"<<endl;
    cout<<"1. Listar"<<endl;
    cout<<"2. Insertar"<<endl;
    cout<<"3. Eliminar" <<endl;
    cout<<"4. Vaciar"<<endl;
    cout<<"5. Finalizar"<<endl;
    cin >> n;

    return n;
}
