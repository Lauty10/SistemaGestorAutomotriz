#ifndef CLASSAUTO_H_INCLUDED
#define CLASSAUTO_H_INCLUDED
#include <string.h>

using namespace std;

class Auto{
private:
int idDelAuto;
char nombreAuto[20];
char marcaAuto[20];
char anioAuto[10];
float precioAuto;
bool estado;

public:
Auto(int id=0, const char* nombreA="XXX", const char* marcaA="XXX", const char* anioA="19/07/2000", float precioA=0.0, bool estado=true){
this->idDelAuto=id;
strcpy(this->nombreAuto,nombreA);
strcpy(this->marcaAuto,marcaA);
strcpy(this->anioAuto,anioA);
this->precioAuto=precioA;
this-> estado=estado;
 }
void setIdAuto(int id){
this->idDelAuto=id;
 }
void setNombreAuto(char nombreA[20]){
strcpy(this->nombreAuto,nombreA);
 }

void setMarcaAuto(char marcaA[20]){
strcpy(this->marcaAuto,marcaA);
 }
void setAnio(char anioA[10]){
strcpy(this->anioAuto,anioA);
 }
void setPrecioAuto(float precioA){
this->precioAuto=precioA;
 }
void setEstado(bool estadoA=false){
this->estado=estadoA;
}
int getId(){
return idDelAuto;
 }
const char* getNombreAuto(){
return nombreAuto;
 }
const char* getMarcaAuto(){
return marcaAuto;
 }
const char* getAnioAuto(){
return anioAuto;
 }
float getPrecioAuto(){
return precioAuto;
 }
bool getEstado(){
return estado;
}

 //FUNCIONES

 void menuAutos(int id){
 int opcion;
 while(true){
 for(int j=1;j<121;j++){
rlutil::locate(j,1);
cout<<char(176);
     }
for(int j=1;j<121;j++){
rlutil::locate(j,30);
cout<<char(176);
    }
for(int j=1;j<121;j++){
rlutil::locate(j,27);
cout<<char(205);
     }
for(int j=1;j<121;j++){
rlutil::locate(j,3);
cout<<char(205);
}
rlutil::locate(45,5);
cout<<"GESTIONANDO AUTOS"<<endl;
rlutil::locate(45,6);
cout<<"------------------------------------------------"<<endl;
rlutil::locate(65,7);
cout<<"GROUP 51 CAR CENTER"<<endl;
rlutil::locate(45,10);
cout<<"1-)Dar de alta nuevo vehiculo"<<endl;
rlutil::locate(45,12);
cout<<"2-)Modificar vehiculo"<<endl;
rlutil::locate(45,14);
cout<<"3-)Dar de baja vehiculo"<<endl;
rlutil::locate(45,16);
cout<<"4-)Listar vehiculo"<<endl;
rlutil::locate(45,18);
cout<<"5-)Buscar vehiculo"<<endl;
rlutil::locate(45,20);
cout<<"0-)Volver atras"<<endl;
rlutil::locate(45,22);
cout<<"Ingrese la opcion que desee:";
cin>>opcion;
switch(opcion){
case 1:
system("cls");
altaAuto();
    break;

case 2:
system("cls");
modificarAutos(id);
    break;

case 3:
system("cls");
darBaja();
    break;

case 4:
system("cls");
listarVehiculos();
    break;

case 5:
system("cls");
buscarVehiculo();
    break;

case 0:
system("cls");
menuDeVendedores(id);
    break;
}
}
}


//FUNCION PARA DAR DE ALTA UN NUEVO VEHICULO
void altaAuto(){
    FILE *vehiculo;
    vehiculo = fopen("Vehiculo.dat", "ab");
    if (vehiculo == NULL) {
        cout << "NO SE PUDO ABRIR ESTE ARCHIVO" << endl;
        return;
    }

    Auto obj;
    int idUnico;
    char nombreAuto[20];
    char marcaAuto[20];
    char anioVehiculo[11];
    float precioAuto;
    bool estadoA = false;
    idUnico = generarIdAuto();
    obj.setIdAuto(idUnico);
    cout << "Ingrese el nombre del auto: ";
    cin.ignore();
    cin.getline(nombreAuto, 20, '\n');
    obj.setNombreAuto(nombreAuto);
    cout << "Ingrese la marca del auto: ";
    cin.getline(marcaAuto, 20, '\n');
    obj.setMarcaAuto(marcaAuto);
    cout << "Ingrese la fecha de fabricacion del auto: ";
    cin.getline(anioVehiculo, 11, '\n');
    obj.setAnio(anioVehiculo);
    cout << "Ingrese el precio del auto: ";
    cin >> precioAuto;
    obj.setPrecioAuto(precioAuto);
    estadoA = true;
    obj.setEstado(estadoA);
    fwrite(&obj, sizeof(Auto), 1, vehiculo);
    cout << "Vehiculo cargado en el sistema" << endl;
    system("pause");
    system("cls");
    fclose(vehiculo);
}


//GENERADOR DE ID PARA NUEVOS AUTOS
 int generarIdAuto() {
   FILE *generar;
   int dato=0;
   generar=fopen("Vehiculo.dat","rb");
   if(generar==NULL){
    dato=1;
    return dato;
   }
   Auto obj;
   while(fread(&obj,sizeof(Auto),1,generar)!=0){
    dato++;
   }
   return dato+1;
   fclose(generar);
    }


//MODIFICAR DATOS
void modificarAutos(int id){
int opcion;
while(true){
cout<<"-1)Modificar nombre"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"-2)Modificar marca"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"-3)Modificar fecha de fabricacion"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"-4)Modificar precio"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"-0)Salir"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"Eliga la opcion que desee:";
cin>>opcion;
switch(opcion){
case 1:
system("cls");
modificarNombre();
    break;
case 2:
system("cls");
modificarMarca();
    break;
case 3:
system("cls");
modificarAnio();
    break;
case 4:
system ("cls");
modificarPrecio();
    break;
case 0:
system("cls");
menuAutos(id);
    break;
}
}
}

//FUNCION PARA MODIFICAR NOMBRE

void modificarNombre(){
FILE *nombre;
nombre=fopen("Vehiculo.dat","rb+");

if(nombre==NULL){
cout<<"Error al editar nombre..."<<endl;
fclose(nombre);
}

Auto obj;
bool encontrado=false;
int idBuscado;

cout<<"Ingrese el id del auto a modificar:";
cin>>idBuscado;

while(fread(&obj,sizeof(Auto),1,nombre)!=0){
if(idBuscado==obj.getId()){
cout<<"Auto encontrado correctamente"<<endl;
cout<<"------------------------------------------------------------"<<endl;
encontrado=true;
long longitud=ftell(nombre)-sizeof(Auto);
char nuevoNombre[20];
cout<<"Ingresa el nombre:";
cin.ignore();
cin.getline(nuevoNombre,20,'\n');
obj.setNombreAuto(nuevoNombre);
fseek(nombre,longitud,SEEK_SET);
fwrite(&obj,sizeof(Auto),1,nombre);
cout<<"Nombre editado correctamente..."<<endl;
system("pause");
break;
}
}
if(!encontrado){
cout<<"No se encontro el id correspondiente"<<endl;
system("pause");
}
fclose(nombre);
system("cls");
}


//MODIFICAR MARCA

void modificarMarca(){
FILE *marca;
marca=fopen("Vehiculo.dat","rb+");

if(marca==NULL){
cout<<"Error al editar marca..."<<endl;
fclose(marca);
}

Auto obj;
bool encontrado=false;
int idBuscado;

cout<<"Ingrese el id del auto a modificar:";
cin>>idBuscado;

while(fread(&obj,sizeof(Auto),1,marca)!=0){
if(idBuscado==obj.getId()){
cout<<"Auto encontrado correctamente"<<endl;
cout<<"------------------------------------------------------------"<<endl;
encontrado=true;

long longitud=ftell(marca)-sizeof(Auto);
char nuevaMarca[20];
cout<<"Ingresa la marca:";
cin.ignore();
cin.getline(nuevaMarca,20,'\n');
obj.setMarcaAuto(nuevaMarca);
fseek(marca,longitud,SEEK_SET);
fwrite(&obj,sizeof(Auto),1,marca);
cout<<"Marca editada correctamente..."<<endl;
system("pause");
break;
}
}
if(!encontrado){
cout<<"No se encontro el id correspondiente"<<endl;
system("pause");
}
fclose(marca);
system("cls");
}


//MODIFICAR ANIO
void modificarAnio(){
FILE *anio;
anio=fopen("Vehiculo.dat","rb+");

if(anio==NULL){
cout<<"Error al editar el anio..."<<endl;
fclose(anio);
}

Auto obj;
bool encontrado=false;
int idBuscado;

cout<<"Ingrese el id del auto a modificar:";
cin>>idBuscado;

while(fread(&obj,sizeof(Auto),1,anio)!=0){
if(idBuscado==obj.getId()){
cout<<"Auto encontrado correctamente"<<endl;
cout<<"------------------------------------------------------------"<<endl;
encontrado=true;
long longitud=ftell(anio)-sizeof(Auto);
char nuevoAnio[10];
cout<<"Ingresa la fecha de fabricacion:";
cin.getline(nuevoAnio,10,'\n');
obj.setAnio(nuevoAnio);
fseek(anio,longitud,SEEK_SET);
fwrite(&obj,sizeof(Auto),1,anio);
cout<<"anio editado correctamente..."<<endl;
system("pause");
break;
}
}
if(!encontrado){
cout<<"No se encontro el id correspondiente"<<endl;
system("pause");
}
fclose(anio);
system("cls");
}

//MODIFICAR PRECIO

void modificarPrecio(){
FILE *precio;
precio=fopen("Vehiculo.dat","rb+");

if(precio==NULL){
cout<<"Error al editar el precio..."<<endl;
fclose(precio);
}

Auto obj;
bool encontrado=false;
int idBuscado;

cout<<"Ingrese el id del auto a modificar:";
cin>>idBuscado;

while(fread(&obj,sizeof(Auto),1,precio)!=0){
if(idBuscado==obj.getId()){
cout<<"Auto encontrado correctamente"<<endl;
cout<<"------------------------------------------------------------"<<endl;
encontrado=true;

long longitud=ftell(precio)-sizeof(Auto);
int nuevoPrecio;
cout<<"Ingresa el precio:";
cin>>nuevoPrecio;
obj.setPrecioAuto(nuevoPrecio);
fseek(precio,longitud,SEEK_SET);
fwrite(&obj,sizeof(Auto),1,precio);
cout<<"Precio editado correctamente..."<<endl;
system("pause");
break;
}
}
if(!encontrado){
cout<<"No se encontro el id correspondiente"<<endl;
system("pause");
}
fclose(precio);
system("cls");
}


//DAR DE BAJA VEHICULOS
void darBaja(){
int baja;
cout<<"Ingrese el ID del vehiculo a dar de baja:";
cin>>baja;
FILE *bajaV;
bajaV=fopen("Vehiculo.dat","rb+");

if(bajaV==NULL){
cout<<"Error al dar de baja vehiculo"<<endl;
}
Auto obj;
bool encontrado=false;
while(fread(&obj,sizeof(Auto),1,bajaV)!=0){
if(baja==obj.getId()){
encontrado=true;
long posicion=ftell(bajaV)-sizeof(Auto);
obj.setEstado(false);
fseek(bajaV,posicion,SEEK_SET);
fwrite(&obj,sizeof(Auto),1,bajaV);
cout<<"Vehiculo dado de baja correctamente..."<<endl;
system("pause");
break;
 }
}
if(!encontrado){
cout<<"ID no encontrado..."<<endl;
system("pause");
}
fclose(bajaV);
system("cls");
}

//FUNCION PARA LISTAR VEHICULOS
void listarVehiculos(){
FILE *listarA;
listarA=fopen("Vehiculo.dat","rb");

if(listarA==NULL){
cout<<"Error al intentar listar los vehiculos"<<endl;
 }

Auto obj;
while(fread(&obj,sizeof(Auto),1,listarA)!=0){
if(obj.getEstado()==true){
cout<<"EL ID DEL AUTO ES:"<<obj.getId()<<endl;
cout<<"EL NOMBRE DEL AUTO ES:"<<obj.getNombreAuto()<<endl;
cout<<"LA MARCA DEL AUTO ES:"<<obj.getMarcaAuto()<<endl;
cout<<"EL ANIO DE FABRICACION ES:"<<obj.getAnioAuto()<<endl;
cout<<"EL PRECIO DEL AUTO ES:"<<obj.getPrecioAuto()<<endl;
cout<<"----------------------------------------------------------------------------------------"<<endl;
}
}
fclose(listarA);
cout<<"Estos son los autos disponibles actualmente"<<endl;
system("pause");
system("cls");
}


//FUNCION PARA BUSCAR VEHICULO
void buscarVehiculo(){
FILE *buscarV;
buscarV=fopen("Vehiculo.dat","rb");

if(buscarV==NULL){
cout<<"Error al buscar vehiculo..."<<endl;
}

Auto obj;
int idBuscado;
cout<<"Ingrese el id del vehiculo que esta buscando:";
cin>>idBuscado;
bool buscado=false;
while(fread(&obj,sizeof(Auto),1,buscarV)!=0){
if(idBuscado==obj.getId()){
buscado=true;
cout<<"Vehiculo encontrado :"<<endl;
cout<<"Nombre :"<<obj.getNombreAuto()<<endl;
cout<<"Marca :"<<obj.getMarcaAuto()<<endl;
cout<<"La fecha de fabricacion :"<<obj.getAnioAuto()<<endl;
cout<<"Precio: "<<obj.getPrecioAuto()<<endl;
cout<<"ID:"<<obj.getId()<<endl;
cout<<"------------------------------------------------------------"<<endl;
system("pause");
    }
}
if(!buscado){
    cout<<"El id del vehiculo no pudo ser encontrado..."<<endl;
}
system("cls");
fclose(buscarV);
}
};

#endif // CLASSAUTO_H_INCLUDED
