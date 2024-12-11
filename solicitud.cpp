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

bool Solicitud::abrir_crear_arch_solicitud(){
FILE *ptr_a_arch_solicitudes;
ptr_a_arch_solicitudes=fopen("Solicitud.dat","ab");
if(ptr_a_arch_solicitudes==NULL){
    rlutil::locate(45,18);
    cout<<"Error al abrir o crear archivo"<<endl;
    return false;
}
fclose(ptr_a_arch_solicitudes);
return true;
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
     cin.getline(nombre, 30,'\n');
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
    //setNombre(nombre);
    rlutil::locate(50,11);
    cout << "                               ";
    rlutil::locate(15,14);
    cout << "                                                                                              ";
    rlutil::locate(15,16);
    cout << "                     ";
    control=true;
    do{
    rlutil::locate(15,11);
    cout << "-> Ingrese su correo electronico para su alta: ";
    rlutil::locate(62,11);
    cin.getline(correo, 35, '\n');
    switch(validarC(correo)){
     case 0:
     control=false;
     break;
     case 1:
          rlutil::locate(15,16);
          cout << "                    ";
          rlutil::locate(15,18);
          cout << "                    ";
          rlutil::locate(15,19);
          cout << "                    ";
          rlutil::locate(15,20);
          cout << "                    ";
          rlutil::locate(15,21);
          cout << "                    ";
          rlutil::locate(15,23);
          cout << "                    ";
          rlutil::locate(47,11);
          cout << "                                                                      ";
          rlutil::locate(15,14);
          cout << "                                                                      ";
          rlutil::setColor(rlutil::LIGHTRED);
          rlutil::locate(50,11);
          cout << "                                                                      ";
          rlutil::locate(15,14);
          cout << "Error: El correo ingresado es demasiado corto";
          rlutil::locate(15,16);
          cout << "Intentelo de nuevo. ";
          rlutil::setColor(rlutil::WHITE);
     break;
     case 2:
          rlutil::locate(15,16);
          cout << "                    ";
          rlutil::locate(15,18);
          cout << "                    ";
          rlutil::locate(15,19);
          cout << "                    ";
          rlutil::locate(15,20);
          cout << "                    ";
          rlutil::locate(15,21);
          cout << "                    ";
          rlutil::locate(15,23);
          cout << "                    ";
          rlutil::locate(47,11);
          cout << "                                                                      ";
          rlutil::locate(15,14);
          cout << "                                                                      ";
          rlutil::setColor(rlutil::LIGHTRED);
          rlutil::locate(50,11);
          cout << "                                                                      ";
          rlutil::locate(15,14);
          cout << "Error: El correo ingresado debe contener (@) ";
          rlutil::locate(15,16);
          cout << "Intentelo de nuevo. ";
          rlutil::setColor(rlutil::WHITE);
     break;
     case 3:
          rlutil::locate(15,16);
          cout << "                    ";
          rlutil::locate(15,18);
          cout << "                    ";
          rlutil::locate(15,19);
          cout << "                    ";
          rlutil::locate(15,20);
          cout << "                    ";
          rlutil::locate(15,21);
          cout << "                    ";
          rlutil::locate(15,23);
          cout << "                    ";
          rlutil::locate(47,11);
          cout << "                                                                      ";
          rlutil::locate(15,14);
          cout << "                                                                      ";
          rlutil::setColor(rlutil::LIGHTRED);
          rlutil::locate(50,11);
          cout << "                                                                      ";
          rlutil::locate(15,14);
          cout << "Error: El correo ingresado no debe contener mas de 1 (@).";
          rlutil::locate(15,16);
          cout << "Intentelo de nuevo. ";
          rlutil::setColor(rlutil::WHITE);
     break;
     case 4:
          rlutil::locate(47,11);
          cout << "                                                                      ";
          rlutil::locate(15,14);
          cout << "                                                                      ";
          rlutil::setColor(rlutil::LIGHTRED);
          rlutil::locate(50,11);
          cout << "                                                                      ";
          rlutil::locate(15,14);
          cout << "Error: El dominio de este correo no esta permitido en nuestro sistema";
          rlutil::locate(15,16);
          cout << "                    ";
          rlutil::locate(15,16);
          cout << "Dominios permitidos:";
          rlutil::locate(15,18);
          cout << "> @gmail.com";
          rlutil::locate(15,19);
          cout << "> @hotmail.com";
          rlutil::locate(15,20);
          cout << "> @outlook.com";
          rlutil::locate(15,21);
          cout << "> @yahoo.com";
          rlutil::locate(15,23);
          cout << "Intentelo de nuevo. ";
          rlutil::setColor(rlutil::WHITE);
     break;
     case 5:
          rlutil::locate(15,16);
          cout << "                    ";
          rlutil::locate(15,18);
          cout << "                    ";
          rlutil::locate(15,19);
          cout << "                    ";
          rlutil::locate(15,20);
          cout << "                    ";
          rlutil::locate(15,21);
          cout << "                    ";
          rlutil::locate(15,23);
          cout << "                    ";
          rlutil::locate(47,11);
          cout << "                                                                      ";
          rlutil::locate(15,14);
          cout << "                                                                      ";
          rlutil::setColor(rlutil::LIGHTRED);
          rlutil::locate(50,11);
          cout << "                                                                      ";
          rlutil::locate(15,14);
          cout << "Error: El correo ingresado no debe contener mas caracteres despues del dominio permitido";
          rlutil::locate(15,16);
          cout << "Intentelo de nuevo. ";
          rlutil::setColor(rlutil::WHITE);
     break;
     case 6:
          rlutil::locate(15,16);
          cout << "                    ";
          rlutil::locate(15,18);
          cout << "                    ";
          rlutil::locate(15,19);
          cout << "                    ";
          rlutil::locate(15,20);
          cout << "                    ";
          rlutil::locate(15,21);
          cout << "                    ";
          rlutil::locate(15,23);
          cout << "                    ";
          rlutil::locate(47,11);
          cout << "                                                                      ";
          rlutil::locate(15,14);
          cout << "                                                                      ";
          rlutil::setColor(rlutil::LIGHTRED);
          rlutil::locate(50,11);
          cout << "                                                                      ";
          rlutil::locate(15,14);
          cout << "Error: El correo ingresado ya se encuentra registrado";
          rlutil::locate(15,16);
          cout << "Intentelo de nuevo. ";
          rlutil::setColor(rlutil::WHITE);
     break;

     default:
      cout<<"Error desconocido";
        break;

    }
    }while (control);
    rlutil::setColor(rlutil::WHITE);
    //setCorreo(correo);
    rlutil::locate(15,16);
    cout << "                    ";
    rlutil::locate(15,18);
    cout << "                    ";
    rlutil::locate(15,19);
    cout << "                    ";
    rlutil::locate(15,20);
    cout << "                    ";
    rlutil::locate(15,21);
    cout << "                    ";
    rlutil::locate(15,23);
    cout << "                    ";
    rlutil::locate(47,11);
    cout << "                                                                      ";
    rlutil::locate(15,14);
    cout << "                                                                      ";
    rlutil::locate(50,11);
    cout << "                                                                      ";
    rlutil::locate(15,16);
    cout << "                                                                      ";
    rlutil::locate(50,11);
    cout << "                                                                      ";
    control=true;
    do{
    rlutil::locate(15,11);
    cout << "-> Ingrese su dni para su alta: ";
    rlutil::locate(47,11);
    cin.getline(dni,10);
    switch(validarD(dni)){
     case 0:
     control=false;
     break;
     case 1:
          rlutil::locate(47,11);
          cout << "                                                             ";
          rlutil::locate(15,14);
          cout << "                                                              ";
          rlutil::setColor(rlutil::LIGHTRED);
          rlutil::locate(50,11);
          cout << "                               ";
          rlutil::locate(15,14);
          cout << "Error: El DNI no puede ser negativo.";
          rlutil::locate(15,16);
          cout << "Intentelo de nuevo. ";
          rlutil::setColor(rlutil::WHITE);
     break;
     case 2:
          rlutil::locate(47,11);
          cout << "                                                           ";
          rlutil::locate(15,14);
          cout << "                                                           ";
          rlutil::setColor(rlutil::LIGHTRED);
          rlutil::locate(50,11);
          cout << "                                                           ";
          rlutil::locate(15,14);
          cout << "Error: El DNI no debe contener letras o simbolos especiales.";
          rlutil::locate(15,16);
          cout << "Intentelo de nuevo. ";
          rlutil::setColor(rlutil::WHITE);
     break;
     case 3:
          rlutil::locate(47,11);
          cout << "                                                           ";
          rlutil::locate(15,14);
          cout << "                                                            ";
          rlutil::setColor(rlutil::LIGHTRED);
          rlutil::locate(50,11);
          cout << "                               ";
          rlutil::locate(15,14);
          cout << "Error: El DNI debe contener 7 u 8 digitos.";
          rlutil::locate(15,16);
          cout << "Intentelo de nuevo. ";
          rlutil::setColor(rlutil::WHITE);
     break;
     case 4:
          rlutil::locate(47,11);
          cout << "                                                            ";
          rlutil::locate(15,14);
          cout << "                                                            ";
          rlutil::setColor(rlutil::LIGHTRED);
          rlutil::locate(50,11);
          cout << "                               ";
          rlutil::locate(15,14);
          cout << "Error: El DNI no debe empezar en 0";
          rlutil::locate(15,16);
          cout << "Intentelo de nuevo. ";
          rlutil::setColor(rlutil::WHITE);
     break;
     case 5:
          rlutil::locate(47,11);
          cout << "                                                            ";
          rlutil::locate(15,14);
          cout << "                                                            ";
          rlutil::setColor(rlutil::LIGHTRED);
          rlutil::locate(50,11);
          cout << "                               ";
          rlutil::locate(15,14);
          cout << "Error: Este DNI ya se encuentra registrado ";
          rlutil::locate(15,16);
          cout << "Intentelo de nuevo. ";
          rlutil::setColor(rlutil::WHITE);
     break;


     default:
      cout<<"Error desconocido";
        break;

    }

    }while (control);

    rlutil::locate(15,11);
    cout << "                                                                                              ";
    rlutil::locate(50,11);
    cout << "                               ";
    rlutil::locate(15,14);
    cout << "                                                                                              ";
    rlutil::locate(15,16);
    cout << "                     ";
    rlutil::locate(45,14);
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

int Solicitud::validarC(char* c){
int longitud=strlen(c);
if(longitud<11){
return 1;
}
int arroba=0;
for(int x=0;x<longitud;x++){
if(c[x]=='@'){
arroba++;
}
}
if(arroba==0){
    return 2;
}else if(arroba>=2){
return 3;
}
char*dominio=strstr(c,"@");
dominio++;
if(strcmp(dominio,"gmail.com")!=0
             &&
   strcmp(dominio,"hotmail.com")!=0
             &&
   strcmp(dominio,"outlook.com")!=0
             &&
   strcmp(dominio,"yahoo.com")!=0
){return 4;}

char *fin_dominio=dominio+strlen(dominio);
if(*fin_dominio!='\0'){
    return 5;
}
FILE *correo;
correo=fopen("Solicitud.dat","rb");
if(correo==NULL){
cout<<"NO SE PUDO ABRIR ESTE ARCHIVO"<<endl;
return -1;
}
Solicitud obj;
while(fread(&obj,sizeof(Solicitud),1,correo)!=0){
if(strcmp(obj.getCorreo(),c)==0){
return 6;
}
}
fclose(correo);
return 0;
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
//1 negativo, 2 letra,3,limiite,4 cero, 0 valido

int Solicitud::validarD(char* d){
int digitos=0;
for(int y=0;d[y]!='\0';y++){
    if(d[y]=='-'){
        return 1;
    }else if(!isdigit(d[y])){
        return 2;
    }
     digitos++;
}

if(digitos>8){
    return 3;
}

if(digitos<7){
    return 3;
}
if(d[0]=='0'){
    return 4;

}
FILE *ptr_a_arch_solicitudes;
ptr_a_arch_solicitudes=fopen("Solicitud.dat","rb");
if(ptr_a_arch_solicitudes==NULL){
cout<<"NO SE PUDO ABRIR ESTE ARCHIVO"<<endl;
return -1;
}
Solicitud obj_;
while(fread(&obj_,sizeof(Solicitud),1,ptr_a_arch_solicitudes)!=0){
if(strcmp(obj_.getDni(),dni)==0){
return 5;
}
}
fclose(ptr_a_arch_solicitudes);
return 0;
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
