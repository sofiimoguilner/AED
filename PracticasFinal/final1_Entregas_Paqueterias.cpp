#include <iostream>
using namespace std; 

struct Camion
{
    int IdCamion;
    int CP; //codigo postal 
};

struct Envio
{
    char codigoPaquete[25];
    char direccion[50];
    int CP;
    int zIdCamion;
    char horaEntrega[6]; //HH:MM forma de la hora de entrega  
};

//para colas de paquetes
struct NodoPaquete {
    Envio envio;
    NodoPaquete* sgte;
};

struct Cola
{
    NodoPaquete frente;
    NodoPaquete final;
};

//lista de CP
struct NodoCP
{
    int CP;
    Cola paquetes;
    NodoCP* sgte;
};

struct Lista //lista de codigos postales asociados al camion
{
    NodoCP *listaCP;
};

Lista camiones[100];// vector de lista de camiones

//procesa el archivo de Camiones y genera el vector de listas
void leerCamiones(Lista camiones[],CamionesArchivo)
{
    FILE* Camiones = fopen("CamionesArchivo.txt", "rb");
    Camion registro;
    while(read(&regitro,sizeof(Camion),1,Camiones)==1)
    {
        NodoCP NuevoNodo = new NodoCP;
        NuevoNodo.CP = registro.CP;
        NuevoNodo.paquetes.frente = NuevoNodo.paquetes.final = NULL;//inicializo cola de camion vacia
        NuevoNodo.sgte = NULL;

        insertarSinRepetir(camiones[registro.IdCamion - 1].listaCP, registro);//funcion declarada del enunciado
    }

    fclose(Camiones);
}

//procesa el archivo de Envios y lo almacena en la estructura de camiones
//y segun el codigo postal los ordena 
void PlanificarEntregas(Lista camiones[],EnvioArchivos)
{
    FILE* Envios = fopen("EnvioArchivos.txt","rb");
    Envio registro;
    while (fread(&registro,sizeof(Envio),1,Envios))
    {
        NodoCP *nodoCP= buscarLista(camiones[registro.zIdCamion - 1].listaCP, registro.CP);

        if(NodoCP==NULL)
        {
            cout<<"Camion no encontrado"<<endl;
        }

        queue(nodoCP->paquetes.frente, nodoCP->paquetes.final, registro);//funcion definida enunciado
    }

    fclose(Envios);
}

void entregarPaquete(int idCamion, int codigoPostal)
{
    NodoCP* nodoCP = buscarLista(camiones[idCamion -1, codigoPostal]);

    if(nodoCP == NULL || nodoCP->paquetes.frente == NULL)
    {
        cout<<"no hay paquetes pendientes"<<endl;
    }
    
    NodoPaquete *paquete = nodoCP->paquetes.frente;

    cout<<"Paquete entregado en direccion "<<paquete->envio.direccion<<endl;
    cout<<"Hora de entrega (HH:MM) ";cin>>paquete->envio.horaEntrega;

    nodoCP->paquetes.frente = nodoCP->sgte; //pasa al siguiente paquete a entregar;

    delete paquete;


}





