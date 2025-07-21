#include <iostream>
#include <stdio.h>
#define t 100 

// struct del enunciado

struct ArchivoCamion {
    int id;
    int CP;
};

struct horaEntrega{
    int hora;
    int minutos;
};

struct ArchivoEnvios{
    char codigoPaquete[25];
    char direccion[50];
    ArchivoCamion camion;
    horaEntrega horario;
};

// struct que necesito para construir el vector de camiones, donde cada elemento tiene una lista ordenada por codigo postal
// y cada elemnto de esa lista se desprende una cola de paquetes

struct vectorCamion
{
    int id;
    NodoCodigo* listaCodigos;
};

struct Codigo
{
    int cp;
    NodoPaquete* colapaquetes;
};

struct NodoCodigo
{
    Codigo info;
    NodoCodigo* sgte;
};

// el paquete es el dato mas chico de todos 

struct Paquetes
{
    char codigo[25];
    char dirreccion[50];
    horaEntrega horario;
};

struct NodoPaquete
{
    Paquetes info;
    NodoPaquete* sgte;
};





void leerVehiculos(vectorCamion vec[], char archivo[]);
void planificarEntregas (vectorCamion vec[],char enviostxt[]);

int main(){};

void leerVehiculos (vectorCamion vec[], char camionestxt[]){ 

    FILE* camiones = fopen ("camionestxt","wb");

    int i= 0;
    ArchivoCamion lectura;

    fread(&lectura, sizeof(camiones), 1, camiones);

    while (!feof(camiones))
    {
        vec[i].id = lectura.id;
        int aux = lectura.id;
        while (!feof(camiones) && aux == lectura.id ) // la comparacion del aux es para ver si seguimos en el mismo camion o se cambia de camion
        {
            insertarOrdenado(vec[i].listaCodigos, lectura.CP); // funcion dada en el parcial
            fread(&lectura, sizeof(camiones), 1, camiones);
        };
        i++;
    };
    
}

void planificarEntregas (vectorCamion vec[],char enviostxt[]){
    FILE* envios = fopen("enviostxt", "rb");

    ArchivoEnvios lectura;

    while (fread(&lectura, sizeof(envios),1,envios))
    {
        

        for(int i =0; i<100; i++)
        {
   
            if( vec[i].listaCodigos->info.cp == lectura.camion.CP)
            {
                NodoCodigo* aux = vec[i].listaCodigos; // aplico esto para no ir modificanco la raiz de la lista
                
                while (aux!= NULL)
                {
                    if(aux->info.cp == lectura.camion.CP){
                        queu(aux->info.colapaquetes, lectura); // funcionm que me dan en el parcial
                    }
                    aux = aux->sgte; // super importante
                }

                

            };
            
        }
        
    }
    
};

void entregarPaquete( vectorCamion vec[],int idCamion, int cp)
{

    for (int i = 0; i < 100; i++)
    {
        if(vec[i].id == idCamion && vec[i].listaCodigos->info.cp == cp)
        {
            NodoCodigo*aux = vec[i].listaCodigos;
            while (aux!=NULL)
            {
                if(aux->info.cp = cp){
                    unQueu(aux->info.colapaquetes); //funcion para eliminar paquete
                }
                aux = aux->sgte;
            }
            
        }

    }
    
};