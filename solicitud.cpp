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
void Solicitud::setDni(int d){
this->dni=d;
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
int Solicitud::getDni(){
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
    nuevaSoli=generarIdSolicitud();
    setId(nuevaSoli);
    estiloV();
    rlutil::locate(15,7);
    cout << "Bienvenido, complete los datos solicitados para generar una solicitud de alta en el sistema..." << endl;
    rlutil::locate(45,10);
    cout << "Ingrese su nombre para su alta:";
    cin.getline(nombre, 30, '\n');
    setNombre(nombre);
    rlutil::locate(45,12);
    cout << "Ingrese su correo para su alta:";
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
void Solicitud::validarN(char* n){
while(n[0]==0){
cout<<"Campo incompleto"<<endl;
cout<<"Nombre: ";
cin.ignore();
cin.getline(n,30,'\n');
}
}

//DNI
void Solicitud::validarD(int d){
while(d==0){
cout<<"Campo incompleto"<<endl;
cout<<"Dni: ";
cin>>d;
}

FILE *dni;
dni=fopen("Solicitud.dat","rb");
if(dni==NULL){
cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
return;
}
Solicitud obj;
while(fread(&obj,sizeof(Solicitud),1,dni)!=0){
if(obj.getDni()==d){
cout<<"Este dni ya fue dado de alta, ingrese otro"<<endl;
cout<<"Dni: ";
cin>>d;
}
}
fclose(dni);
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
