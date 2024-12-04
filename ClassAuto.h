#ifndef CLASSAUTO_H_INCLUDED
#define CLASSAUTO_H_INCLUDED
#include <string.h>

using namespace std;

class Auto{
private:
int idDelAuto;
char nombreAuto[20];
char marcaAuto[20];
float precioAuto;
bool estado;

public:
Auto(int id=0, const char* nombreA="XXX", const char* marcaA="XXX", float precioA=0.0, bool estado=true){
this->idDelAuto=id;
strcpy(this->nombreAuto,nombreA);
strcpy(this->marcaAuto,marcaA);
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
float getPrecioAuto(){
return precioAuto;
 }
bool getEstado(){
return estado;
}

 //FUNCIONES
 void menuAutos(int id){
 bool control_menu_vehiculo=true;
 int y=0;
    do{
       rlutil::hidecursor();
       rlutil::setBackgroundColor(rlutil::BLACK);
       rlutil::setColor(rlutil::WHITE);
       GraficarLineasHorizontales(1,121,2,false,176);
       GraficarLineasHorizontales(1,121,30,false,176);
        rlutil::locate(35,6);
        cout<<"BIENVENIDO AQUI PODRA EDITAR LOS VEHICULOS"<<endl;
        rlutil::locate(35,7);
        cout<<"--------------------------------------------------------------"<<endl;
        rlutil::locate(70,8);
        cout<<"GROUP 51 CAR CENTER"<<endl;
       GraficarOpiciones("Dar de alta nuevo vehiculo ",50,12,y==0,15,0);
       GraficarOpiciones("Modificar vehiculo ",50,14,y==1,15,0);
       GraficarOpiciones("Dar de baja vehiculo ",50,16,y==2,15,0);
       GraficarOpiciones("Listar vehiculos ",50,18,y==3,15,0);
       GraficarOpiciones("Buscar vehiculo ",50,20,y==4,15,0);
       GraficarOpiciones("Volver atras ",50,22,y==5,15,0);
       switch(rlutil::getkey()){
       case 14:
               y--;
               if(y<0){
               y=0;
               }
       break;
       case 15:
               y++;
               if(y>5){
               y=0;
               }
       break;
       case 1:
              switch(y){
              case 0:
                     system("cls");
                     altaAuto();
              break;
              case 1:
                     system("cls");
                     modificarAutos(id);
              break;
              case 2:
                     system("cls");
                     darBaja();
              break;
              case 3:
                     system("cls");
                     listarVehiculos();
              break;
              case 4:
                     system("cls");
                     buscarVehiculo();
              break;
              case 5:
                     rlutil::setBackgroundColor(rlutil::BLACK);
                     system("cls");
                     control_menu_vehiculo=false;
                     //menuDeVendedores(id);
              break;
           }
    break;
  }
  }while(control_menu_vehiculo);
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
    float precioAuto;
    bool estadoA = false;
    idUnico = generarIdAuto();
    obj.setIdAuto(idUnico);

    estiloAuto();
    rlutil::locate(25,10);
    cout << "Por favor, ingrese el nombre del nuevo auto para darlo de alta en el sistema..." << endl;
    rlutil::locate(45,14);
    cout << "Ingrese el nombre del auto: ";
    cin.getline(nombreAuto, 20);
    obj.NombreV(nombreAuto);
    obj.setNombreAuto(nombreAuto);
    system("cls");

    estiloAuto();
    rlutil::locate(25,10);
    cout << "Por favor, ingrese la marca del nuevo auto para darlo de alta en el sistema..." << endl;
    rlutil::locate(45,14);
    cout << "Ingrese la marca del auto: ";
    cin.getline(marcaAuto, 20);
    obj.marcaV(marcaAuto);
    obj.setMarcaAuto(marcaAuto);
    system("cls");

    estiloAuto();
    rlutil::locate(25,10);
    cout << "Por favor, ingrese el nombre del nuevo auto para darlo de alta en el sistema..." << endl;
    rlutil::locate(45,14);
    cout << "Ingrese el precio del auto: ";
    cin >> precioAuto;
    obj.precioV(precioAuto);
    obj.setPrecioAuto(precioAuto);
    system("cls");

    cin.ignore();
    estadoA = true;
    obj.setEstado(estadoA);
    estiloAuto();
    fwrite(&obj, sizeof(Auto), 1, vehiculo);
    rlutil::locate(45,14);
    cout << "Vehiculo cargado en el sistema" << endl;
    rlutil::locate(45,16);
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
void modificarAutos(int id) {
    bool control_menu_vehiculo = true;
    int y = 0;

    do {
        rlutil::hidecursor();
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        GraficarLineasHorizontales(1, 121, 2, false, 176);
        GraficarLineasHorizontales(1, 121, 4, false, 205);
        GraficarLineasHorizontales(1, 121, 30, false, 176);
        GraficarLineasHorizontales(1, 121, 27, false, 205);
        rlutil::locate(35, 6);
        cout << " GROUP 51 CAR CENTER" << endl;
        rlutil::locate(35, 7);
        cout << "--------------------------------------------------------------" << endl;
        rlutil::locate(54, 8);
        cout << "MODIFICACI" << char(224) << "N DE VEHICULOS " << endl;
        GraficarOpiciones("Modificar nombre del auto", 50, 12, y == 0, 15, 0);
        GraficarOpiciones("Modificar marca del auto", 50, 14, y == 1, 15, 0);
        GraficarOpiciones("Modificar precio del auto", 50, 16, y == 2, 15, 0);
        GraficarOpiciones("Volver atras...", 50, 18, y == 3, 15, 0);
        switch (rlutil::getkey()) {
            case 14:
                y--;
                if (y < 0) {
                    y = 0;
                }
                break;
            case 15:
                y++;
                if (y > 3) {
                    y = 0;
                }
                break;
            case 1:
                switch (y) {
                    case 0:
                        system("cls");
                        modificarNombre();
                        break;
                    case 1:
                        system("cls");
                        modificarMarca();
                        break;
                    case 2:
                        system("cls");
                        modificarPrecio();
                        break;
                    case 3:
                        rlutil::setBackgroundColor(rlutil::BLACK);
                        system("cls");
                        control_menu_vehiculo = false;
                        break;
                }
                break;
        }

    } while (control_menu_vehiculo);
}

//FUNCION PARA MODIFICAR NOMBRE

void modificarNombre(){
estiloAuto();
FILE *nombre;
nombre=fopen("Vehiculo.dat","rb+");

if(nombre==NULL){
cout<<"Error al editar nombre..."<<endl;
fclose(nombre);
}
Auto obj;
bool encontrado=false;
int idBuscado;
rlutil::locate(45,12);
cout<<"Ingrese el id del auto a modificar:";
cin>>idBuscado;
while(fread(&obj,sizeof(Auto),1,nombre)!=0){
if(idBuscado==obj.getId()){
encontrado=true;
if(obj.getEstado()==true){
rlutil::locate(45,14);
cout<<"Auto encontrado correctamente"<<endl;
rlutil::locate(3,6);
cout<<"El nombre actual es:"<<obj.getNombreAuto();
long longitud=ftell(nombre)-sizeof(Auto);
char nuevoNombre[20];
rlutil::locate(45,16);
cout<<"Ingresa el nombre:";
cin.ignore();
cin.getline(nuevoNombre,20,'\n');
obj.NombreV(nuevoNombre);
obj.setNombreAuto(nuevoNombre);
fseek(nombre,longitud,SEEK_SET);
fwrite(&obj,sizeof(Auto),1,nombre);
rlutil::locate(45,18);
cout<<"Nombre editado correctamente..."<<endl;
rlutil::locate(45,20);
system("pause");
break;
}else{
rlutil::locate(45,14);
cout<<"El vehiculo se encuentra dado de baja..."<<endl;
rlutil::locate(45,16);
system("pause");
}
}
}
if(!encontrado){
rlutil::locate(45,14);
cout<<"No se encontro el id correspondiente"<<endl;
rlutil::locate(45,16);
system("pause");
}
fclose(nombre);
system("cls");
}


//MODIFICAR MARCA

void modificarMarca(){
estiloAuto();
FILE *marca;
marca=fopen("Vehiculo.dat","rb+");

if(marca==NULL){
rlutil::locate(45,12);
cout<<"Error al editar marca..."<<endl;
fclose(marca);
}

Auto obj;
bool encontrado=false;
int idBuscado;
rlutil::locate(45,12);
cout<<"Ingrese el id del auto a modificar:";
cin>>idBuscado;

while(fread(&obj,sizeof(Auto),1,marca)!=0){
if(idBuscado==obj.getId()){
encontrado=true;
if(obj.getEstado()==true){
rlutil::locate(45,14);
cout<<"Auto encontrado correctamente"<<endl;
rlutil::locate(3,6);
cout<<"La marca actua es:"<<obj.getMarcaAuto()<<endl;
long longitud=ftell(marca)-sizeof(Auto);
char nuevaMarca[20];
rlutil::locate(45,16);
cout<<"Ingresa la marca:";
cin.ignore();
cin.getline(nuevaMarca,20,'\n');
obj.marcaV(nuevaMarca);
obj.setMarcaAuto(nuevaMarca);
fseek(marca,longitud,SEEK_SET);
fwrite(&obj,sizeof(Auto),1,marca);
rlutil::locate(45,18);
cout<<"Marca editada correctamente..."<<endl;
rlutil::locate(45,20);
system("pause");
break;
}else{
rlutil::locate(45,14);
cout<<"El vehiculo se encuentra dado de baja..."<<endl;
rlutil::locate(45,16);
system("pause");
}
}
}
if(!encontrado){
rlutil::locate(45,14);
cout<<"No se encontro el id correspondiente"<<endl;
rlutil::locate(45,16);
system("pause");
}
fclose(marca);
system("cls");
}


//MODIFICAR PRECIO
void modificarPrecio(){
estiloAuto();
FILE *precio;
precio=fopen("Vehiculo.dat","rb+");
if(precio==NULL){
cout<<"Error al editar el precio..."<<endl;
fclose(precio);
}
Auto obj;
bool encontrado=false;
int idBuscado;
rlutil::locate(45,12);
cout<<"Ingrese el id del auto a modificar:";
cin>>idBuscado;

while(fread(&obj,sizeof(Auto),1,precio)!=0){
if(idBuscado==obj.getId()){
encontrado=true;
if(obj.getEstado()==true){
rlutil::locate(45,14);
cout<<"Auto encontrado correctamente"<<endl;
rlutil::locate(3,6);
cout<<"El precio actual es:"<<obj.getPrecioAuto();
long longitud=ftell(precio)-sizeof(Auto);
float nuevoPrecio;
rlutil::locate(45,16);
cout<<"Ingresa el precio:";
cin>>nuevoPrecio;
obj.precioV(nuevoPrecio);
obj.setPrecioAuto(nuevoPrecio);
fseek(precio,longitud,SEEK_SET);
fwrite(&obj,sizeof(Auto),1,precio);
rlutil::locate(45,18);
cout<<"Precio editado correctamente..."<<endl;
rlutil::locate(45,20);
system("pause");
break;
}else{
rlutil::locate(45,14);
cout<<"El vehiculo se encuentra dado de baja..."<<endl;
rlutil::locate(45,16);
system("pause");
}
}
}
if(!encontrado){
rlutil::locate(45,14);
cout<<"No se encontro el id correspondiente"<<endl;
rlutil::locate(45,16);
system("pause");
}
fclose(precio);
system("cls");
}


//DAR DE BAJA VEHICULOS
void darBaja(){
estiloAuto();
int baja;
rlutil::locate(42,12);
cout<<"Ingrese el ID del vehiculo a dar de baja:";
cin>>baja;
FILE *bajaV;
bajaV=fopen("Vehiculo.dat","rb+");

if(bajaV==NULL){
rlutil::locate(42,14);
cout<<"Error al dar de baja vehiculo"<<endl;
rlutil::locate(42,16);
system("pause");
}
Auto obj;
bool encontrado=false;
while(fread(&obj,sizeof(Auto),1,bajaV)!=0){
if(baja==obj.getId()){
encontrado=true;
if(obj.getEstado()==true){
long posicion=ftell(bajaV)-sizeof(Auto);
obj.setEstado(false);
fseek(bajaV,posicion,SEEK_SET);
fwrite(&obj,sizeof(Auto),1,bajaV);
rlutil::locate(42,14);
cout<<"Vehiculo dado de baja correctamente..."<<endl;
rlutil::locate(42,16);
system("pause");
break;
}else{
rlutil::locate(42,14);
cout<<"El vehiculo ya se encuentra dado de baja..."<<endl;
rlutil::locate(42,16);
system("pause");
}
}
}
if(!encontrado){
rlutil::locate(45,16);
cout<<"ID no encontrado..."<<endl;
rlutil::locate(45,18);
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

rlutil::locate(38,3);
cout<<"Estos son los vehiculos listados disponibles en nuestro sistema"<<endl;
Auto obj;
while(fread(&obj,sizeof(Auto),1,listarA)!=0){
if(obj.getEstado()==true){
cout<<endl;
cout<<"EL ID DEL AUTO ES:"<<obj.getId()<<endl;
cout<<"EL NOMBRE DEL AUTO ES:"<<obj.getNombreAuto()<<endl;
cout<<"LA MARCA DEL AUTO ES:"<<obj.getMarcaAuto()<<endl;
cout<<"EL PRECIO DEL AUTO ES:"<<obj.getPrecioAuto()<<endl;
cout<<"-------------------------------------------------------------------"<<endl;
}
}
fclose(listarA);
system("pause");
system("cls");
}


//FUNCION PARA BUSCAR VEHICULO
void buscarVehiculo(){
estiloAuto();
FILE *buscarV;
buscarV=fopen("Vehiculo.dat","rb");

if(buscarV==NULL){
rlutil::locate(45,12);
cout<<"Error al buscar vehiculo..."<<endl;
rlutil::locate(45,14);
system("pause");
}

Auto obj;
int idBuscado;
rlutil::locate(40,8);
cout<<"Ingrese el id del vehiculo que esta buscando:";
cin>>idBuscado;
bool buscado=false;
while(fread(&obj,sizeof(Auto),1,buscarV)!=0){
if(idBuscado==obj.getId()){
buscado=true;
rlutil::locate(40,10);
cout<<"Vehiculo encontrado...."<<endl;
rlutil::locate(40,12);
cout<<"Nombre:"<<obj.getNombreAuto()<<endl;
rlutil::locate(40,14);
cout<<"Marca:"<<obj.getMarcaAuto()<<endl;
rlutil::locate(40,16);
cout<<"Precio:"<<obj.getPrecioAuto()<<endl;
rlutil::locate(40,18);
cout<<"ID:"<<obj.getId()<<endl;
if(obj.getEstado()==true){
    rlutil::locate(40,22);
    cout<<"El estado del auto es:"<<"Activo"<<endl;
}
else{
    rlutil::locate(40,22);
    cout<<"El estado del auto es:"<<"Inactivo"<<endl;
}
rlutil::locate(30,24);
cout<<"------------------------------------------------------------"<<endl;
rlutil::locate(40,25);
system("pause");
    }
}
if(!buscado){
    rlutil::locate(40,10);
    cout<<"El id del vehiculo no pudo ser encontrado..."<<endl;
    rlutil::locate(40,12);
    system("pause");
}
system("cls");
fclose(buscarV);
}

//VALIDACIONES
//NOMBRE
void NombreV(char* n){
while(n[0]=='\0'){
rlutil::locate(45,16);
cout<<"El campo ingresado se encuentra incompleto"<<endl;
rlutil::locate(45,18);
cout<<"Ingrese el nombre: ";
cin.getline(n,30);
}
}


//Marca
void marcaV(char* m){
while(m[0]=='\0'){
rlutil::locate(45,16);
cout<<"El campo ingresado se encuentra incompleto"<<endl;
rlutil::locate(45,18);
cout<<"Ingrese la marca: ";
cin.getline(m,20);
}
}


//FECHA
void fechaV(char* f){
while(f[0]=='\0'){
rlutil::locate(45,16);
cout<<"El campo ingresado se encuentra incompleto"<<endl;
rlutil::locate(45,18);
cout<<"Ingrese la fecha,(EJ:01/01/1900):";
cin.getline(f,11);
}
}

//PRECIO
void precioV(float&p){
while(p==0.0 || p<=0){
rlutil::locate(45,16);
cout<<"Campo incompleto o precio invalido"<<endl;
rlutil::locate(45,18);
cout<<"Ingrese el precio: ";
cin>>p;
}
}

void estiloAuto(){
for(int j=1;j<121;j++){
rlutil::locate(j,1);
cout<<char(176);
     }
for(int j=1;j<121;j++){
rlutil::locate(j,30);
cout<<char(176);
    }
for(int j=1;j<121;j++){
rlutil::locate(j,28);
cout<<char(205);
     }
for(int j=1;j<121;j++){
rlutil::locate(j,3);
cout<<char(205);
}
}

};

#endif // CLASSAUTO_H_INCLUDED
