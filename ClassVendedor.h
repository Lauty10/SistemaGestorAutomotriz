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
    cout << "Ingrese el nombre del vendedor: ";
    cin.ignore();
    cin.getline(nombre, 30,'\n');
    setNombre(nombre);
    cout << "Ingrese el correo: ";
    cin.getline(correo, 35,'\n');
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
    cin.ignore();
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
    while (fread(&obj, sizeof(Vendedores), 1, logeo) != 0) {
        if (strcmp(obj.getCorreo(), correoLogin) == 0 && strcmp(obj.getClave(), claveLogin) == 0) {
            inicio = true;
            //cout << "Login realizado correctamente" << endl;
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
cout<<"Menu de vendedores..."<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"-1)Listar vendedores"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"-2)Buscar un vendedor"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"0-)Volver atras"<<endl;
cout<<"------------------------------------------------------------"<<endl;
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
FILE *listaV;
listaV=fopen("Vendedores.dat","rb");
if(listaV==NULL){
    cout<<"Error al listar vendedores..."<<endl;
}
Vendedores objV;
while(fread(&objV,sizeof(Vendedores),1,listaV)!=0){
    if(objV.getEstado()==true){
    cout<<"Nombre:"<<objV.getNombre()<<endl;
    cout<<"Correo:"<<objV.getCorreo()<<endl;
    cout<<"Dni:"<<objV.getDni()<<endl;
    cout<<"Rol:"<<objV.getRol()<<endl;
    cout<<"Estado:"<<objV.getEstado()<<endl;
    cout<<"ID:"<<objV.getIdVendedor()<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    }

}
fclose(listaV);
system("pause");
system("cls");
}

void buscarVendedor(){
FILE *buscarV;
buscarV=fopen("Vendedores.dat","rb");
if(buscarV==NULL){
    cout<<"Error al buscar vendedor..."<<endl;
}
Vendedores listaV;
int idBuscado;
cout<<"Ingrese el id del vendedor que esta buscando:";
cin>>idBuscado;
bool buscado=false;
while(fread(&listaV,sizeof(Vendedores),1,buscarV)!=0){
    if(idBuscado==listaV.getIdVendedor()){
    buscado=true;
    cout<<"Vendedor encontrado:"<<endl;
    cout<<"Nombre:"<<listaV.getNombre()<<endl;
    cout<<"Correo:"<<listaV.getCorreo()<<endl;
    cout<<"Dni:"<<listaV.getDni()<<endl;
    cout<<"ID:"<<listaV.getIdVendedor()<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    system("pause");
    }
}
if(!buscado){
    cout<<"El id del vendedor no pudo ser encontrado..."<<endl;
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
};

#endif // CLASSVENDEDOR_H_INCLUDED
