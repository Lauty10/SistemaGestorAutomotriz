#include <cctype>
#include <iostream>
#include <string.h>
#include "rlutil.h"
#include "ClassSolicitudAlta.h"

using namespace std;

void GraficarLineasHorizontales(int,int,int,bool,int);

void Solicitud::setNombre(char n[30]){
strcpy(this->nombre,n);
}
void Solicitud::setCorreo(char c[35]){
strcpy(this->correo,c);
}
void Solicitud::setClave(char cl[20]){
strcpy(this->clave,cl);
}
void Solicitud::setDni(char dni[9]){
strcpy(this->dni,dni);
}
void Solicitud::setEstado(bool e){
this->estado=e;
}
void Solicitud::setAprobado(bool a){
this->aprobado=a;
}
const char* Solicitud::getNombre(){
return nombre;
}
const char* Solicitud::getCorreo(){
return correo;
}
const char* Solicitud::getClave(){
return clave;
}
const char* Solicitud::getDni(){
return dni;
}
bool Solicitud::getEstado(){
return estado;
}
bool Solicitud::getAprobado(){
return aprobado;
}
void Solicitud::setId(int idN){
this->id=idN;
}
int Solicitud::getId(){
return id;
}


void Solicitud::cargarSolicitud(){
    int nuevaSoli;
    bool control=true;
    nuevaSoli=generarIdSolicitud();
    setId(nuevaSoli);
    estiloV();
    rlutil::locate(15,7);
    cout << "Bienvenido, complete los datos solicitados para generar una solicitud de alta en el sistema..." << endl;
    do{
     rlutil::showcursor();
     rlutil::locate(15,11);
     cout << "-> Ingrese su nombre para su alta:";
     rlutil::locate(50,11);
     cin.getline(nombre, 30);
     if(validarNombre(nombre)){control=false;}
     else{
          rlutil::setColor(rlutil::LIGHTRED);
          rlutil::locate(50,11);
          cout << "                               ";
          rlutil::locate(15,14);
          cout << "Nombre invalido, asegurese que el nombre ingresado no contenga numeros o simbolos especiales.";
          rlutil::locate(15,16);
          cout << "Intentelo de nuevo. ";
          rlutil::setColor(rlutil::WHITE);}
    }while(control);
    setNombre(nombre);
    rlutil::locate(50,11);
    cout << "                               ";
    rlutil::locate(15,14);
    cout << "                                                                                              ";
    rlutil::locate(15,16);
    cout << "                     ";
    rlutil::locate(15,11);
    cout << "-> Ingrese su correo para su alta:";
    cin.getline(correo, 35, '\n');
    setCorreo(correo);
    rlutil::locate(45,14);
    cout << "Ingrese su dni para su alta:";
    cin >> dni;
    cin.ignore();
    setDni(dni);
    rlutil::locate(45,16);
    cout << "El numero de solicitud es: " << getId() << endl;
    rlutil::locate(45,18);
    system("pause");
    system("cls");
}

void Solicitud::nuevaSolicitud(Solicitud objS){
FILE *soli;
soli=fopen("Solicitud.dat","rb");
if(soli==NULL){
    rlutil::locate(40,12);
    cout<<"Error al leer una nueva solicitud..."<<endl;
    return;
}
Solicitud objV;
while(fread(&objV,sizeof(Solicitud),1,soli)!=0){
    if(strcmp(objV.getCorreo(),objS.getCorreo())==0 || objV.getDni()==objS.getDni()){
            system("cls");
            estiloV();
            rlutil::locate(40,12);
            cout<<"No se puede completar solicitud de alta..."<<endl;
            rlutil::locate(40,14);
            cout<<"Datos repetidos o invalidos."<<endl;
            rlutil::locate(40,16);
            system("pause");
            system("cls");
            fclose(soli);
            return;
    }
}
fclose(soli);
soli=fopen("Solicitud.dat","ab");
if(soli==NULL){
    rlutil::locate(45,18);
    cout<<"Error al crear una nueva solicitud..."<<endl;
    return;
}
system("cls");
estiloV();
fwrite(&objS,sizeof(Solicitud),1,soli);
rlutil::locate(40,12);
cout<<"Solicitud generada correcamente en el sistema..."<<endl;
fclose(soli);
rlutil::locate(40,14);
system("pause");
system("cls");
fclose(soli);
}

 int Solicitud::generarIdSolicitud(){
   FILE *generar;
   int dato=0;
   generar=fopen("Solicitud.dat","rb");
   if(generar==NULL){
    dato=1;
    return dato;
   }
   Solicitud obj;
   while(fread(&obj,sizeof(Solicitud),1,generar)!=0){
    dato++;
   }
   fclose(generar);
   return dato+1;
    }

void Solicitud::listarSolicitudes(){
FILE *soli;
soli=fopen("Solicitud.dat","rb");
if(soli==NULL){
    cout<<"Error al listar solicitud..."<<endl;
}
Solicitud obj;
rlutil::locate(38,2);
cout<<"Vendedores que estan esperando la aprobacion en el sistema..."<<endl;
while(fread(&obj,sizeof(Solicitud),1,soli)!=0){
    if(obj.getEstado()==false){
        cout<<endl;
        cout<<"Nombre del usuario a dar de alta:"<<obj.getNombre()<<endl;
        cout<<"Correo del usuario a dar de alta:"<<obj.getCorreo()<<endl;
        cout<<"Dni del usuario a dar de alta:"<<obj.getDni()<<endl;
        cout<<"El id de la solicitud es:"<<obj.getId()<<endl;
        cout<<"-------------------------------------------------------------------------"<<endl;
    }
}
system("pause");
system("cls");
fclose(soli);
}

void Solicitud::aprobarSolicitudDeAlta(){
GraficarLineasHorizontales(1,121,1,false,176);
GraficarLineasHorizontales(1,121,3,false,205);
GraficarLineasHorizontales(1,121,30,false,176);
GraficarLineasHorizontales(1,121,28,false,205);
    FILE *aprobarS;
    aprobarS = fopen("Solicitud.dat", "rb+");
    if(aprobarS == NULL){
        cout << "Error al aprobar solicitud" << endl;
        return;
    }
    Solicitud objS;
    int id;
    bool encontrado = false;
    rlutil::locate(40,12);
    cout << "Ingrese el id de la solicitud que desea aprobar: ";
    cin >> id;
    while(fread(&objS, sizeof(Solicitud), 1, aprobarS) != 0){
        if(objS.getId() == id && objS.getEstado()==false){
            long posicion = ftell(aprobarS) - sizeof(Solicitud);
            objS.setAprobado(true);
            objS.setEstado(true);
            fseek(aprobarS, posicion, SEEK_SET);
            fwrite(&objS, sizeof(Solicitud), 1, aprobarS);
             rlutil::locate(45,14);
            cout << "Solicitud aprobada correctamente..." << endl;
            rlutil::locate(45,16);
            system("pause");
            encontrado = true;
            break;
        }
    }
    if(!encontrado){
        rlutil::locate(35,14);
        cout << "La solicitud ya fue aprobada o no fue encontrada en el sistema..." << endl;
        rlutil::locate(45,16);
        system("pause");
        system("cls");
    }
    system("cls");
    fclose(aprobarS);
}




//VALIDACIONES
//Nombre
void Solicitud::validarC(char* c){
FILE *correo;
correo=fopen("Solicitud.dat","rb");
if(correo==NULL){
cout<<"NO SE PUDO ABRIR ESTE ARCHIVO"<<endl;
return;
}
Solicitud obj;
while(c[0]==0){
cout<<"Campo incompleto"<<endl;
cin.ignore();
cin.getline(c,30,'\n');
}
while(fread(&obj,sizeof(Solicitud),1,correo)!=0){
if(strcmp(obj.getCorreo(),c)==0){
cout<<"Este correo fue dado de alta, igrese uno distinto"<<endl;
cout<<"Correo: ";
cin.ignore();
cin.getline(c,30,'\n');
}
}
fclose(correo);
}

//NOMBRE
bool Solicitud::validarNombre(char* n){
for(int x=0;n[x]!='\0';x++){
    if(!isalpha(n[x])){
        return false;
        }
}
return true;
}

//DNI
bool Solicitud::validarD(char* d){
int digitos=0;
for(int y=0;d[y]!='\0';y++){
    if(!isdigit(d[y])){
        return false;
    }
    digitos++;
}
if(digitos<7||digitos>8){
    return false;
}

if(d[0]=='0'){
    return true;

}
}

void Solicitud::estiloV(){
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
