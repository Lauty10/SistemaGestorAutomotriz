#ifndef CLASSVENDEDOR_H_INCLUDED
#define CLASSVENDEDOR_H_INCLUDED
#include <cstring>
#include <string.h>
#include <conio.h>
#include "rlutil.h"

using namespace std;

//Volver a los menus
void menuDeVendedores(int id);
void menu();

class Vendedores{
private:
    int idVendedor;
    char nombre[30];
    int dni;
    char correo[35];
    char clave[20];
    char rol[6];
    bool estado;
public:
    Vendedores(int i=0, const char* n="XXX", int d=1000000,const char * c="usuariox@gmail.com",const char* claveV="123456789",const char* r="seller",bool estado=true){
    this->idVendedor=i;
    strcpy(this->nombre,n);
    this->dni=d;
    strcpy(this->correo,c);
    strcpy(this->clave,claveV);
    strcpy(this->rol,r);
    this->estado=estado;
    }
    ///Setters
    void setId(int idV){
    this->idVendedor=idV;
    };
    void setNombre(char nombre[30]){
    strcpy(this->nombre,nombre);
    };
    void setDni(int dni){
    this->dni=dni;
    };
    void setCorreo(char correo[35]){
    strcpy(this->correo,correo);
    };
    void setClave(char clave[20]){
    strcpy(this->clave,clave);
    };
    void setRol(char rol[6]){
    strcpy(this->rol,rol);
    };
    void setEstado(bool est=false){
    this->estado=est;
    };
    ///Getters
    int getIdVendedor(){
    return idVendedor;
    }
    const char* getNombre(){
    return nombre;
    }
    int getDni(){
    return dni;
    }
    const char* getCorreo(){
    return correo;
    }

    const char* getClave(){
    return clave;
    }
    const char* getRol(){
    return rol;
    }
    bool getEstado(){
    return estado;
    }

//Funciones
    void cargarVendedor(){
    Vendedores objVal;
    cout << "Ingrese el nombre del vendedor: ";
    cin.ignore();
    cin.getline(nombre, 30,'\n');
    objVal.nombreV(nombre);
    setNombre(nombre);
    cout << "Ingrese el correo: ";
    cin.getline(correo, 35,'\n');
    objVal.correoV(correo);
    setCorreo(correo);
    cout << "Ingrese la clave:";
    char ch;
    int index = 0;
    while (true) {
    ch = _getch();
    if (ch == 13) {
     clave[index] = '\0';
        break;
    }else if (ch == 8) {
      if (index > 0) {
        index--;
        cout << "\b \b";
        }
        } else {
        clave[index++] = ch;
     cout << "*";
        }
    }
    setClave(clave);
    cout << endl;
    cout << "Ingrese el DNI:";
    cin >> dni;
    objVal.dniV(dni);
    setDni(dni);
    idVendedor=generarIdVendedor();
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"Vendedor registrado correctamente"<<endl;
    cout<<"Nombre:"<<getNombre()<<endl;
    cout<<"Correo:"<<getCorreo()<<endl;
    cout<<"Dni:"<<getDni()<<endl;
    cout<<"Estado:"<<getEstado()<<endl;
    cout<<"ID:"<<getIdVendedor()<<endl;
    cout<<"------------------------------------------------------------"<<endl;
}

 int generarIdVendedor() {
   FILE *generar;
   int dato=0;
   generar=fopen("Vendedores.dat","rb");
   if(generar==NULL){
    dato=1;
    fclose(generar);
    return dato;
   }
   Vendedores obj;
   while(fread(&obj,sizeof(Vendedores),1,generar)!=0){
    dato++;
   }
   fclose(generar);
   return dato+1;
    }

void registrarVendedor(Vendedores obj){
FILE *registro;
registro=fopen("Vendedores.dat","ab");
if(registro==NULL){
    cout<<"Error al registrar vendedor"<<endl;
}
fwrite(&obj,sizeof(Vendedores),1,registro);
cout<<"Vendedor registrado correctamente..."<<endl;
fclose(registro);
system("pause");
system("cls");
}



int iniciarSesion() {
    FILE *logeo;
    logeo = fopen("Vendedores.dat", "rb");
    if (logeo == NULL) {
        cout << "Error al intentar iniciar sesion" << endl;
        return false;
    }
    Vendedores obj;
    char correoLogin[35];
    char claveLogin[20];
    bool inicio = false;

    rlutil::locate(39,13);
    cin.getline(correoLogin, 35, '\n');
    rlutil::locate(39,18);
    char ch;
    int index = 0;
    while (true) {
        ch = _getch();
        if (ch == 13) {
            claveLogin[index] = '\0';
            break;
        } else if (ch == 8) {
            if (index > 0) {
                index--;
                cout << "\b \b";
            }
        } else {
            claveLogin[index++] = ch;
            cout << "*";
        }
    }
   cout << endl;
    if(correoLogin[0]=='\0'||claveLogin[0]=='\0'){

    cout<<"Los campos no fueron cargados correctamente"<<endl;

    fclose(logeo);
    }

    while (fread(&obj, sizeof(Vendedores), 1, logeo) != 0) {
        if (strcmp(obj.getCorreo(), correoLogin) == 0 && strcmp(obj.getClave(), claveLogin) == 0) {
            inicio = true;
            int idLogeado=obj.getIdVendedor();
            fclose(logeo);
            system("cls");
            return idLogeado;
        }
    }
    if (!inicio) {

    cout << "Los datos no coinciden..." << endl;
    fclose(logeo);
    system("pause");
    system("cls");
    return false;
    }
}




void funcionalidadesVendedor(int id){
Vendedores obj;
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
    rlutil::locate(j,25);
    cout<<char(205);
     }
     for(int j=1;j<121;j++){
     rlutil::locate(j,3);
     cout<<char(205);
      }
rlutil::locate(45,7);
cout<<"MENU DE VENDEDORES"<<endl;
rlutil::locate(38,8);
cout<<"------------------------------------------------"<<endl;
rlutil::locate(60,9);
cout<<"GROUP 51 CAR CENTER"<<endl;
rlutil::locate(46,12);
cout<<"1-)Listar vendedores"<<endl;
rlutil::locate(46,14);
cout<<"2-)Buscar un vendedor"<<endl;
rlutil::locate(46,16);
cout<<"0-)Volver atras"<<endl;
rlutil::locate(46,18);
cout<<"Ingrese la opcion que desee:";
cin>>opcion;
switch(opcion){
case 1:
    system("cls");
    obj.listarVendedores();
    break;
case 2:
    system("cls");
    obj.buscarVendedor();
    break;
case 0:
    system("cls");
    menuDeVendedores(id);
default:
    cout<<"Opcion incorrecta..."<<endl;
}
}
}

void bajaVendedores(){
FILE *baja;
baja=fopen("Vendedores.dat","rb+");
if(baja==NULL){
    cout<<"Error al dar de baja vendedor..."<<endl;
}
bool encontrado=false;
int id;
Vendedores objV;
cout<<"Ingrese el id del vendedor que desea dar de baja:";
cin>>id;
while(fread(&objV,sizeof(Vendedores),1,baja)!=0){
    if(objV.getEstado()==true){
        if(objV.getIdVendedor()==id){
            encontrado=true;
            long posicion=ftell(baja)-sizeof(Vendedores);
            objV.setEstado(false);
            fseek(baja,posicion,SEEK_SET);
            fwrite(&objV,sizeof(Vendedores),1,baja);
            cout<<"Vendedor dado de baja correctamente..."<<endl;
             system("pause");
            break;
        }
    }else{
    cout<<"El vendedor ya se encuentra dado de baja..."<<endl;
    system("pause");
    break;
    }
}
fclose(baja);
system("cls");
}


void listarVendedores(){
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
FILE *listaV;
listaV=fopen("Vendedores.dat","rb");
if(listaV==NULL){
    cout<<"Error al listar vendedores..."<<endl;
}
Vendedores objV;
int fila=9;
rlutil::locate(50,6);
cout<<"Estos son los vendedores en nuestro sistema"<<endl;
rlutil::locate(30,7);
cout<<"--------------------------------------------------------------------------------"<<endl;
while(fread(&objV,sizeof(Vendedores),1,listaV)!=0){
    if(objV.getEstado()==true){
    rlutil::locate(3, fila);
    cout<<"Nombre:"<<objV.getNombre()<<endl;
    rlutil::locate(40, fila);
    cout<<"Correo:"<<objV.getCorreo()<<endl;
    rlutil::locate(80, fila);
    cout<<"Dni:"<<objV.getDni()<<endl;
    rlutil::locate(100, fila);
    cout<<"ID:"<<objV.getIdVendedor()<<endl;
     fila++;
    if (fila > 25) {
    system("cls");
    fila = 8;
    }
    }
}
fclose(listaV);
rlutil::locate(45, 25);
system("pause");
system("cls");
}

void buscarVendedor(){
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
FILE *buscarV;
buscarV=fopen("Vendedores.dat","rb");
if(buscarV==NULL){
    cout<<"Error al buscar vendedor..."<<endl;
}
Vendedores listaV;
rlutil::locate(50,6);
cout<<"BUSCAR VENDEDOR EN EL SISTEMA"<<endl;
rlutil::locate(30,8);
cout<<"-------------------------------------------------------------------------"<<endl;
int idBuscado;
rlutil::locate(45,10);
cout<<"Ingrese el id del vendedor que esta buscando:";
cin>>idBuscado;
bool buscado=false;
while(fread(&listaV,sizeof(Vendedores),1,buscarV)!=0){
    if(idBuscado==listaV.getIdVendedor()){
    buscado=true;
    rlutil::locate(45,12);
    cout<<"Vendedor encontrado:"<<endl;
    rlutil::locate(45,14);
    cout<<"Nombre:"<<listaV.getNombre()<<endl;
    rlutil::locate(45,16);
    cout<<"Correo:"<<listaV.getCorreo()<<endl;
    rlutil::locate(45,18);
    cout<<"Dni:"<<listaV.getDni()<<endl;
    rlutil::locate(45,20);
    cout<<"ID:"<<listaV.getIdVendedor()<<endl;
    rlutil::locate(45,22);
    system("pause");
    }
}
if(!buscado){
    rlutil::locate(45,12);
    cout<<"El id del vendedor no pudo ser encontrado..."<<endl;
    rlutil::locate(45,14);
    system("pause");
}
system("cls");
fclose(buscarV);
}

void menuMiCuenta(){
Vendedores obj;
int opcion;
cout<<"Bienvenido aqui podra editar los datos dos vendedores"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"-1)Editar nombre"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"-2)Editar correo"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"-3)Editar clave"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"4-)Editar dni"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"0-)Salir"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"Ingrese la opcion que desee:";
cin>>opcion;
switch(opcion){
case 1:
    system("cls");
    obj.editarMiNombre();
    break;
case 2:
    system("cls");
    obj.editarMiCorreo();
    break;
case 3:
    system("cls");
    obj.editarMiClave();
    break;
case 4:
    system("cls");
    obj.editarDni();
    break;
case 0:
    system("cls");
    break;
default:
    cout<<"Opcion incorrecta..."<<endl;
}
}



void editarMiNombre(){
FILE *nombrePersonal;
nombrePersonal=fopen("Vendedores.dat","rb+");
if(nombrePersonal==NULL){
    cout<<"Error al editar nombre..."<<endl;
}
Vendedores obj;
bool encontrado=false;
char nuevoNombre[30];
int id;
cout<<"Ingrese el id del usuario a modificar:";
cin>>id;
while(fread(&obj,sizeof(Vendedores),1,nombrePersonal)!=0){
    if(id==obj.getIdVendedor()){
        encontrado=true;
        long posicion=ftell(nombrePersonal)-sizeof(Vendedores);
        cout<<"Ingresa el nombre:";
        cin.ignore();
        cin.getline(nuevoNombre,30,'\n');
        obj.nombreV(nuevoNombre);
        obj.setNombre(nuevoNombre);
        fseek(nombrePersonal,posicion,SEEK_SET);
        fwrite(&obj,sizeof(Vendedores),1,nombrePersonal);
        cout<<"Nombre actualizado correctamente..."<<endl;
        system("pause");
        break;
    }
}
if(!encontrado){
    cout<<"Error al encontrar usuario con ese ID"<<endl;
    system("pause");
}
fclose(nombrePersonal);
system("cls");
}

void editarMiCorreo(){
FILE *correoPersonal;
correoPersonal=fopen("Vendedores.dat","rb+");
if(correoPersonal==NULL){
    cout<<"Error al editar correo..."<<endl;
}
Vendedores obj;
bool encontrado=false;
char nuevoCorreo[35];
int id;
cout<<"Ingrese el id del usuario a modificar:";
cin>>id;
while(fread(&obj,sizeof(Vendedores),1,correoPersonal)!=0){
    if(id==obj.getIdVendedor()){
        encontrado=true;
        long posicion=ftell(correoPersonal)-sizeof(Vendedores);
        cout<<"Ingresa el correo:";
        cin.ignore();
        cin.getline(nuevoCorreo,35,'\n');
        obj.correoV(nuevoCorreo);
        obj.setCorreo(nuevoCorreo);
        fseek(correoPersonal,posicion,SEEK_SET);
        fwrite(&obj,sizeof(Vendedores),1,correoPersonal);
        cout<<"Correo actualizado correctamente..."<<endl;
        system("pause");
        break;
    }
}
if(!encontrado){
    cout<<"Error al encontrar usuario con ese ID"<<endl;
    system("pause");
}
fclose(correoPersonal);
system("cls");
}

void editarMiClave(){
FILE *clavePersonal;
clavePersonal=fopen("Vendedores.dat","rb+");
if(clavePersonal==NULL){
    cout<<"Error al editar correo..."<<endl;
}
Vendedores obj;
bool encontrado=false;
char nuevaCLave[20];
int id;
cout<<"Ingrese el id del usuario a modificar:";
cin>>id;
while(fread(&obj,sizeof(Vendedores),1,clavePersonal)!=0){
    if(id==obj.getIdVendedor()){
        encontrado=true;
        long posicion=ftell(clavePersonal)-sizeof(Vendedores);
        cout<<"Ingresa la clave:";
        cin.ignore();
        cin.getline(nuevaCLave,20,'\n');
        obj.setClave(nuevaCLave);
        fseek(clavePersonal,posicion,SEEK_SET);
        fwrite(&obj,sizeof(Vendedores),1,clavePersonal);
        cout<<"Clave actualizada correctamente..."<<endl;
        system("pause");
        break;
    }
}
if(!encontrado){
    cout<<"Error al encontrar usuario con ese ID"<<endl;
    system("pause");
}
fclose(clavePersonal);
system("cls");
}

void editarDni(){
FILE *dniPersonal;
dniPersonal=fopen("Vendedores.dat","rb+");
if(dniPersonal==NULL){
    cout<<"Error al editar dni..."<<endl;
}
Vendedores obj;
bool encontrado=false;
int nuevoDni;
int id;
cout<<"Ingrese el id del usuario a modificar:";
cin>>id;
while(fread(&obj,sizeof(Vendedores),1,dniPersonal)!=0){
    if(id==obj.getIdVendedor()){
        encontrado=true;
        long posicion=ftell(dniPersonal)-sizeof(Vendedores);
        cout<<"Ingresa el dni:";
        cin>>nuevoDni;
        obj.dniV(nuevoDni);
        obj.setDni(nuevoDni);
        fseek(dniPersonal,posicion,SEEK_SET);
        fwrite(&obj,sizeof(Vendedores),1,dniPersonal);
        cout<<"Dni actualizado correctamente..."<<endl;
        system("pause");
        break;
    }
}
if(!encontrado){
    cout<<"Error al encontrar usuario con ese ID"<<endl;
    system("pause");
}
fclose(dniPersonal);
system("cls");
}


//VALIDACIONES

//NOMBRE
void nombreV(char* nV){
while(nV[0]=='\0'){
cout<<"Campo incompleto"<<endl;
cout<<"Nombre: ";
cin.ignore();
cin.getline(nV,30,'\n');
}
}

//DNI
void dniV(int d){
FILE *dV;
dV=fopen("Vendedores.dat","rb");
if(dV==NULL){
cout<<"NO SE PUDO ABRIR ESTE ARCHIVO"<<endl;
return;
}
Vendedores objd;
while(d==0){
cout<<"Campo incompleto"<<endl;
cout<<"Dni: ";
cin>>d;
}
while(fread(&objd,sizeof(Vendedores),1,dV)!=0){
if(objd.getDni()==d){
cout<<"Este dni ya esta registrado"<<endl;
cout<<"Dni: ";
cin>>d;
}
}
fclose(dV);
}


//CORREO
void correoV( char* cV){
FILE *correo;
correo=fopen("Vendedore.dat","rb");
if(correo==NULL){
cout<<"NO SE PUDO ABRIR ESTE ARCHIVO"<<endl;
return;
}
Vendedores objC;
while(cV[0]=='\0'){
cout<<"Campo incompleto"<<endl;
cout<<"Correo: ";
cin.ignore();
cin.getline(cV,30,'\n');
}
while(fread(&objC,sizeof(Vendedores),1,correo)!=0){
if(strcmp(objC.getCorreo(),cV)==0){
cout<<"Este correo ya esta registrado"<<endl;
cout<<"Correo: ";
cin.ignore();
cin.getline(cV,30,'\n');
}
}
fclose(correo);
}


//CORREO
void c1(char* c){
while(c[0]=='\0'){
rlutil::locate(38,15);
cout<<"Campo incompleto"<<endl;
rlutil::locate(39,13);
cin.ignore();
rlutil::locate(39,13);
cin.getline(c,30,'\n');
rlutil::locate(38,15);
cout<<"                   "<<endl;
}
}


//CLAVE
void c2(char* c){
while(c[0]=='\0'){
rlutil::locate(38,20);
cout<<"Campo incompleto"<<endl;
rlutil::locate(38,18);
cin.ignore();
rlutil::locate(38,18);
cin.getline(c,30,'\n');
cout<<"                   "<<endl;
}
}
};

#endif // CLASSVENDEDOR_H_INCLUDED
