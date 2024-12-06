#include <iostream>
#include "ClassRecaudaciones.h"
#include "rlutil.h"

using namespace std;

void GraficarLineasHorizontales(int,int,int,bool,int);

    void Recaudacion::setIngreso(int i){
    this->ingreso=i;
    }
    void Recaudacion::setMesIngreso(int i){
    this->mesDelIngreso=i;
    }
    void Recaudacion::setAnioIngreso(int i){
    this->anioDelIngreso=i;
    }
    void Recaudacion::setIdVendedor(int i){
    this->idVendedor=i;
    }
    int Recaudacion::getIdVendedor(){
    return idVendedor;
    }
    int Recaudacion::getIngreso(){
    return ingreso;
    }
    int Recaudacion::getMes(){
    return mesDelIngreso;
    }
    int Recaudacion::getAnio(){
    return anioDelIngreso;
    }

    void Recaudacion::cargarRecaudacion(int importe, int mes, int anio, int idDelVendedor){
    FILE *nuevaRecaudacion;
    nuevaRecaudacion=fopen("Recaudaciones.dat","ab");
    if(nuevaRecaudacion==NULL){
        cout<<"Error al grabar nueva recaudacion"<<endl;
    }
    Recaudacion objR;
    objR.setIngreso(importe);
    objR.setMesIngreso(mes);
    objR.setAnioIngreso(anio);
    objR.setIdVendedor(idDelVendedor);
    fwrite(&objR,sizeof(Recaudacion),1,nuevaRecaudacion);
    cout<<"Venta realizada con exito..."<<endl;
    fclose(nuevaRecaudacion);
    }

void Recaudacion::recaudacionTotal(){
GraficarLineasHorizontales(1,121,1,false,176);
GraficarLineasHorizontales(1,121,30,false,176);
FILE *recaudacionT;
recaudacionT=fopen("Recaudaciones.dat","rb");
if(recaudacionT==NULL){
cout<<"NO SE PUDO ABRIR ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
float totalR=0;
while(fread(&obj,sizeof(Recaudacion),1,recaudacionT)!=0){
totalR+=obj.getIngreso();
}
fclose(recaudacionT);
rlutil::locate(45,12);
cout<<"LA RECAUDACION TOTAL ES DE: "<<totalR<<endl;
cout<<endl;
rlutil::locate(45,14);
system("pause");
system("cls");
}

void Recaudacion::recaudacionMesyAnio(){
GraficarLineasHorizontales(1,121,1,false,176);
GraficarLineasHorizontales(1,121,30,false,176);
int mes;
int anio;
int recaudacionT=0;
rlutil::locate(33,12);
cout<<"Ingrese el anio para obtener informacion de sus recaudaciones:";
cin>>anio;
rlutil::locate(33,14);
cout<<"Ingrese el mes para obtener informacion de sus recaudaciones:";
cin>>mes;
if(mes<0||mes==0||mes>12||anio<2024){
    rlutil::locate(32,16);
    cout<<"No contamos con registros de la fecha ingresada, intentelo nuevamente"<<endl;
    rlutil::locate(45,18);
    system("pause");
    system("cls");
    return;
}
FILE *informacion;
informacion=fopen("Recaudaciones.dat","rb");
if(informacion==NULL){
    cout<<"Error al obtener las recaudaciones"<<endl;
    fclose(informacion);
    return;
}
Recaudacion obj;
while(fread(&obj,sizeof(Recaudacion),1,informacion)!=0){
    if(anio==obj.getAnio() && mes==obj.getMes()){
        recaudacionT+=obj.getIngreso();
    }
}
rlutil::locate(50,16);
cout<<"La recaudacion es de:"<<recaudacionT<<endl;
rlutil::locate(45,18);
system("pause");
system("cls");
cout<<endl;
fclose(informacion);
}

void Recaudacion::recaudacionXanio(){
GraficarLineasHorizontales(1,121,1,false,176);
GraficarLineasHorizontales(1,121,30,false,176);
int ingresos=0;
FILE *anios;
anios=fopen("Recaudaciones.dat","rb");
if(anios==NULL){
cout<<"No se pudo abrir este archivo"<<endl;
return;
}
Recaudacion obj;
int anio;
rlutil::locate(33,12);
cout<<"Ingrese el anio para obtener informacion de sus recaudaciones:";
cin>>anio;
if(anio<2024){
    rlutil::locate(32,14);
    cout<<"No contamos con registros de la fecha ingresada, intentelo nuevamente"<<endl;
    rlutil::locate(45,16);
    system("pause");
    return;
}
while(fread(&obj,sizeof(Recaudacion),1,anios)!=0){
if(obj.getAnio()==anio){
ingresos+=obj.getIngreso();
}
}
rlutil::locate(45,14);
cout<<"La recaudacion para el anio "<<anio<<" es de: "<<ingresos<<endl;
cout<<endl;
fclose(anios);
rlutil::locate(45,16);
system("pause");
system("cls");
}

void Recaudacion::recaudacionPorId() {
    GraficarLineasHorizontales(1, 121, 1, false, 176);
    GraficarLineasHorizontales(1, 121, 30, false, 176);
    int idV;
    float recaudacion = 0;
    rlutil::locate(30, 12);
    cout << "Ingrese el id del vendedor para saber el total de sus recaudaciones:";
    cin >> idV;
    bool encontrado = false;
    FILE *informacion = fopen("Recaudaciones.dat", "rb");
    if (informacion == NULL) {
        cout << "Error al obtener informacion de las recaudaciones..." << endl;
        return;
    }
    Recaudacion obj;
    while (fread(&obj, sizeof(Recaudacion), 1, informacion) != 0) {
        if (obj.getIdVendedor()==idV) {
            recaudacion += obj.ingreso;
            encontrado = true;
        }
    }
    if (!encontrado) {
        rlutil::locate(25, 14);
        cout << "El id del vendedor no fue encontrado en el sistema o no cuenta con recaudaciones..." << endl;
        fclose(informacion);
        rlutil::locate(45, 16);
        system("pause");
        system("cls");
        return;
    }
    rlutil::locate(45, 14);
    cout << "Las recaudaciones del vendedor son: " << recaudacion;
    rlutil::locate(45, 16);
    system("pause");
    system("cls");
    fclose(informacion);
}
