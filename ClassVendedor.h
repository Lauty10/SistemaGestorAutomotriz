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
void GraficarLineasHorizontales(int,int,int,bool,int);
void GraficarOpiciones(const char*,int,int,bool,int,int);

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
    objVal.estiloV();
    rlutil::locate(45,13);
    cout << "Ingrese el nombre del vendedor:";
    cin.getline(nombre, 30,'\n');
    objVal.nombreV(nombre);
    setNombre(nombre);
    system("cls");

    objVal.estiloV();
    rlutil::locate(45,13);
    cout << "Ingrese el correo del vendedor:";
    cin.getline(correo, 35,'\n');
    objVal.correoV(correo);
    setCorreo(correo);
    system("cls");

    objVal.estiloV();
     rlutil::locate(45,13);
    cout << "Ingrese la clave del vendedor: ";
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
    objVal.c2(clave);
    setClave(clave);
    system("cls");
    cout << endl;
    objVal.estiloV();
    rlutil::locate(45,13);
    cout << "Ingrese el dni del vendedor:";
    cin >> dni;
    cin.ignore();
    objVal.dniV(dni);
    setDni(dni);
    system("cls");
    idVendedor=generarIdVendedor();
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
    FILE *registro, *registro2;
    registro=fopen("Vendedores.dat","rb");
    if(registro==NULL){
        cout<<"Error al abrir el archivo de vendedores"<<endl;
        return;
    }
    Vendedores objC;
    while(fread(&objC, sizeof(Vendedores), 1, registro) != 0){
        if(strcmp(objC.getCorreo(), obj.getCorreo()) == 0 || objC.getDni()==obj.getDni()){
            system("cls");
            estiloV();
            rlutil::locate(45,14);
            cout<<"No se puede completar el registro."<<endl;
            rlutil::locate(45,16);
            cout<<"Datos repetidos o invalidos."<<endl;
            rlutil::locate(45,18);
            system("pause");
            system("cls");
            fclose(registro);
            return;
        }
    }
    fclose(registro);
    registro2 = fopen("Vendedores.dat", "ab");
    if(registro2 == NULL){
        cout << "Error al registrar vendedor" << endl;
        return;
    }
    estiloV();
    fwrite(&obj, sizeof(Vendedores), 1, registro2);
    rlutil::locate(45, 14);
    cout << "Vendedor registrado correctamente..." << endl;
    rlutil::locate(45, 16);
    cout<<"El id del vendedor es:"<<obj.getIdVendedor()<<endl;
    rlutil::locate(45, 18);
    system("pause");
    system("cls");
    fclose(registro2);
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
    bool orden=false;
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
    rlutil::setColor(rlutil::RED);
    rlutil::locate(38,22);
    cout<<"Los campos no fueron cargados correctamente"<<endl;
    fclose(logeo);
    rlutil::locate(38,23);
    system("pause");
    system("cls");
    orden=true;
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
    if (inicio==false && orden==false) {
    rlutil::setColor(rlutil::RED);
    rlutil::locate(38,22);
    cout << "Correo y/o clave incorrectos..." << endl;
    fclose(logeo);
    rlutil::locate(38,23);
    system("pause");
    system("cls");
    return false;
    }
}




void funcionalidadesVendedor(int id){
Vendedores obj;
bool control_menu_vendedores=true;
int y=0;
    do{
       rlutil::hidecursor();
       rlutil::setBackgroundColor(rlutil::BLACK);
       rlutil::setColor(rlutil::WHITE);
       GraficarLineasHorizontales(1,121,2,false,176);
       GraficarLineasHorizontales(1,121,30,false,176);
       rlutil::locate(35,6);
        cout<<"INFORMACION DE LOS VENDEDORES"<<endl;
        rlutil::locate(35,7);
        cout<<"--------------------------------------------------------------"<<endl;
        rlutil::locate(60,8);
        cout<<"GROUP 51 CAR CENTER"<<endl;
       GraficarOpiciones("Listar vendedores ",55,14,y==0,15,0);
       GraficarOpiciones("Buscar un vendedor ",55,16,y==1,15,0);
       GraficarOpiciones("Volver atras ",55,18,y==2,15,0);
       switch(rlutil::getkey()){
       case 14:
               y--;
               if(y<0){
               y=0;
               }
       break;
       case 15:
               y++;
               if(y>2){
               y=0;
               }
       break;
       case 1:
              switch(y){
              case 0:
                     system("cls");
                     obj.listarVendedores();
              break;
              case 1:
                     system("cls");
                     obj.buscarVendedor();
              break;
              case 2:
                     rlutil::setBackgroundColor(rlutil::BLACK);
                     system("cls");
                     control_menu_vendedores=false;
                     menuDeVendedores(id);
              break;
           }
    break;
  }
  }while(control_menu_vendedores);
}

void bajaVendedores(){
GraficarLineasHorizontales(1,121,2,false,176);
GraficarLineasHorizontales(1,121,4,false,205);
GraficarLineasHorizontales(1,121,30,false,176);
GraficarLineasHorizontales(1,121,27,false,205);
FILE *baja;
baja=fopen("Vendedores.dat","rb+");
if(baja==NULL){
    cout<<"Error al dar de baja vendedor..."<<endl;
}
bool encontrado=false;
int id;
Vendedores objV;
rlutil::locate(40,12);
cout<<"Ingrese el id del vendedor que desea dar de baja:";
cin>>id;
while(fread(&objV,sizeof(Vendedores),1,baja)!=0){
    if(objV.getIdVendedor()==id){
        encontrado=true;
        if(objV.getEstado()==true){
            encontrado=true;
            long posicion=ftell(baja)-sizeof(Vendedores);
            objV.setEstado(false);
            fseek(baja,posicion,SEEK_SET);
            fwrite(&objV,sizeof(Vendedores),1,baja);
            rlutil::locate(45,14);
            cout<<"Vendedor dado de baja correctamente..."<<endl;
            rlutil::locate(45,16);
            system("pause");
            break;
    }else{
    rlutil::locate(40,14);
    cout<<"El vendedor ya se encuentra dado de baja..."<<endl;
    rlutil::locate(45,16);
    system("pause");
    break;
    }
    }
    }
if(!encontrado){
    rlutil::locate(45,14);
    cout<<"El id del vendedor no fue encontrado..."<<endl;
    rlutil::locate(45,16);
    system("pause");
}
fclose(baja);
system("cls");
}




void listarVendedores(){
estiloV();
FILE *listaV;
listaV=fopen("Vendedores.dat","rb");
if(listaV==NULL){
    cout<<"Error al listar vendedores..."<<endl;
}
Vendedores objV;
int fila=9;
rlutil::locate(45,6);
cout<<"Vendedores registrados en el sistema"<<endl;
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
estiloV();
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
bool control_editarV=true;
int y=0;
    do{
       rlutil::hidecursor();
       rlutil::setBackgroundColor(rlutil::BLACK);
       rlutil::setColor(rlutil::WHITE);
       GraficarLineasHorizontales(1,121,2,false,176);
       GraficarLineasHorizontales(1,121,30,false,176);
       rlutil::locate(35,6);
       cout<<"GROUP 51 CAR CENTER - EDITAR VENDEDORES"<<endl;
       rlutil::locate(35,7);
       cout<<"--------------------------------------------------------------"<<endl;
       rlutil::locate(35,8);
       cout<<"Bienvenido, aqui podras editar los datos de los vendedores"<<endl;
       GraficarOpiciones("Editar nombre de vendedor",50,12,y==0,15,0);
       GraficarOpiciones("Editar correo de vendedor ",50,14,y==1,15,0);
       GraficarOpiciones("Editar clave de vendedor",50,16,y==2,15,0);
       GraficarOpiciones("Editar DNI de vendedor ",50,18,y==3,15,0);
       GraficarOpiciones("Volver atras ",50,20,y==4,15,0);
       switch(rlutil::getkey()){
       case 14:
               y--;
               if(y<0){
               y=0;
               }
       break;
       case 15:
               y++;
               if(y>4){
               y=0;
               }
       break;
       case 1:
              switch(y){
              case 0:
                     system("cls");
                     obj.editarMiNombre();
              break;
              case 1:
                     system("cls");
                     obj.editarMiCorreo();
              break;
              case 2:
                     system("cls");
                     obj.editarMiClave();
              break;
              case 3:
                     system("cls");
                     obj.editarDni();
              break;
              case 4:
                     rlutil::setBackgroundColor(rlutil::BLACK);
                     system("cls");
                     control_editarV=false;

              break;
           }
    break;
  }
  }while(control_editarV);
}



void editarMiNombre(){
estiloV();
FILE *nombrePersonal;
nombrePersonal=fopen("Vendedores.dat","rb+");
if(nombrePersonal==NULL){
    cout<<"Error al editar nombre..."<<endl;
}
Vendedores obj;
bool encontrado=false;
char nuevoNombre[30];
int id;
rlutil::locate(45,11);
cout<<"Ingrese el id del usuario a modificar:";
cin>>id;
while(fread(&obj,sizeof(Vendedores),1,nombrePersonal)!=0){
    if(id==obj.getIdVendedor()){
         encontrado=true;
        if(obj.getEstado()==true){
        long posicion=ftell(nombrePersonal)-sizeof(Vendedores);
        rlutil::locate(45,13);
        cout<<"Ingresa el nombre:";
        cin.ignore();
        cin.getline(nuevoNombre,30,'\n');
        obj.nombreV(nuevoNombre);
        system("cls");
        estiloV();
        obj.setNombre(nuevoNombre);
        fseek(nombrePersonal,posicion,SEEK_SET);
        fwrite(&obj,sizeof(Vendedores),1,nombrePersonal);
        rlutil::locate(45,14);
        cout<<"Nombre actualizado correctamente..."<<endl;
        rlutil::locate(45,16);
        system("pause");
        break;
        }else{
             system("cls");
             estiloV();
             rlutil::locate(45,14);
             cout<<"El vendedor ya se encuentra dado de baja..."<<endl;
             rlutil::locate(45,16);
             system("pause");
             break;
        }
    }
}
if(!encontrado){
    rlutil::locate(45,14);
    cout<<"Error al encontrar usuario con ese ID"<<endl;
    rlutil::locate(45,16);
    system("pause");
}
fclose(nombrePersonal);
system("cls");
}

void editarMiCorreo(){
estiloV();
FILE *correoPersonal;
correoPersonal=fopen("Vendedores.dat","rb+");
if(correoPersonal==NULL){
    cout<<"Error al editar correo..."<<endl;
}
Vendedores obj;
bool encontrado=false;
char nuevoCorreo[35];
int id;
rlutil::locate(45,11);
cout<<"Ingrese el id del usuario a modificar:";
cin>>id;
while(fread(&obj,sizeof(Vendedores),1,correoPersonal)!=0){
    if(id==obj.getIdVendedor()){
        encontrado=true;
        if(obj.getEstado()==true){
        long posicion=ftell(correoPersonal)-sizeof(Vendedores);
        rlutil::locate(45,13);
        cout<<"Ingresa el correo:";
        cin.ignore();
        cin.getline(nuevoCorreo,35,'\n');
        obj.correoV(nuevoCorreo);
        obj.setCorreo(nuevoCorreo);
        fseek(correoPersonal,posicion,SEEK_SET);
        fwrite(&obj,sizeof(Vendedores),1,correoPersonal);
        system("cls");
        estiloV();
        rlutil::locate(45,14);
        cout<<"Correo actualizado correctamente..."<<endl;
        rlutil::locate(45,16);
        system("pause");
        break;
        }else{
        system("cls");
        estiloV();
        rlutil::locate(45,14);
        cout<<"El vendedor ya se encuentra dado de baja..."<<endl;
        rlutil::locate(45,16);
        system("pause");
        break;
        }
    }
}
if(!encontrado){
    system("cls");
    estiloV();
    rlutil::locate(45,14);
    cout<<"Error al encontrar usuario con ese ID"<<endl;
    rlutil::locate(45,16);
    system("pause");
}
fclose(correoPersonal);
system("cls");
}

void editarMiClave(){
estiloV();
FILE *clavePersonal;
clavePersonal=fopen("Vendedores.dat","rb+");
if(clavePersonal==NULL){
    cout<<"Error al editar correo..."<<endl;
}
Vendedores obj;
bool encontrado=false;
char nuevaCLave[20];
int id;
 rlutil::locate(45,11);
cout<<"Ingrese el id del usuario a modificar:";
cin>>id;
while(fread(&obj,sizeof(Vendedores),1,clavePersonal)!=0){
    if(id==obj.getIdVendedor()){
        encontrado=true;
        if(obj.getEstado()==true){
        long posicion=ftell(clavePersonal)-sizeof(Vendedores);
        rlutil::locate(45,13);
        cout<<"Ingresa la clave:";
        cin.ignore();
        cin.getline(nuevaCLave,20,'\n');
        obj.c2(nuevaCLave);
        obj.setClave(nuevaCLave);
        fseek(clavePersonal,posicion,SEEK_SET);
        fwrite(&obj,sizeof(Vendedores),1,clavePersonal);

        system("cls");
        estiloV();
        rlutil::locate(45,14);
        cout<<"Clave actualizada correctamente..."<<endl;
        rlutil::locate(45,16);
        system("pause");
        break;
        }else{
         system("cls");
         estiloV();
         rlutil::locate(45,14);
         cout<<"El vendedor ya se encuentra dado de baja..."<<endl;
         rlutil::locate(45,16);
         system("pause");
         break;
        }
    }
}
if(!encontrado){
    system("cls");
    estiloV();
    rlutil::locate(45,14);
    cout<<"Error al encontrar usuario con ese ID"<<endl;
    rlutil::locate(45,16);
    system("pause");
}
fclose(clavePersonal);
system("cls");
}

void editarDni(){
estiloV();
FILE *dniPersonal;
dniPersonal=fopen("Vendedores.dat","rb+");
if(dniPersonal==NULL){
    cout<<"Error al editar dni..."<<endl;
}
Vendedores obj;
bool encontrado=false;
int nuevoDni;
int id;
rlutil::locate(45,11);
cout<<"Ingrese el id del usuario a modificar:";
cin>>id;
while(fread(&obj,sizeof(Vendedores),1,dniPersonal)!=0){
    if(id==obj.getIdVendedor()){
        encontrado=true;
        if(obj.getEstado()==true){
        long posicion=ftell(dniPersonal)-sizeof(Vendedores);
        rlutil::locate(45,13);
        cout<<"Ingresa el dni:";
        cin>>nuevoDni;
        obj.dniV(nuevoDni);
        obj.setDni(nuevoDni);
        fseek(dniPersonal,posicion,SEEK_SET);
        fwrite(&obj,sizeof(Vendedores),1,dniPersonal);
        system("cls");
        estiloV();
        rlutil::locate(45,14);
        cout<<"Dni actualizado correctamente..."<<endl;
        rlutil::locate(45,16);
        system("pause");
        break;
        }else{
         system("cls");
         estiloV();
         rlutil::locate(45,14);
         cout<<"El vendedor ya se encuentra dado de baja..."<<endl;
         rlutil::locate(45,16);
         system("pause");
         break;
        }
    }
}
if(!encontrado){
    system("cls");
    estiloV();
    rlutil::locate(45,14);
    cout<<"Error al encontrar usuario con ese ID"<<endl;
    rlutil::locate(45,16);
    system("pause");
}
fclose(dniPersonal);
system("cls");
}


//VALIDACIONES
//NOMBRE
void nombreV(char* nV){
while(nV[0]=='\0'){
rlutil::locate(45,15);
cout<<"El campo incompleto"<<endl;
rlutil::locate(45,17);
cout<<"Ingrese el nombre del vendedor: ";
cin.getline(nV,30,'\n');
}
system("cls");
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
 rlutil::locate(45,15);
cout<<"El campo incompleto"<<endl;
 rlutil::locate(45,17);
cout<<"Ingrese el dni:";
cin>>d;
}
while(fread(&objd,sizeof(Vendedores),1,dV)!=0){
if(objd.getDni()==d){
 rlutil::locate(45,15);
cout<<"Este dni ya se encuentra registrado"<<endl;
 rlutil::locate(45,17);
cout<<"Ingrese el dni: ";
cin>>d;
}
}
fclose(dV);
}


//CORREO
void correoV( char* cV){
FILE *correo;
correo=fopen("Vendedores.dat","rb");
if(correo==NULL){
cout<<"NO SE PUDO ABRIR ESTE ARCHIVO"<<endl;
return;
}
Vendedores objC;
while(cV[0]=='\0'){
rlutil::locate(45,15);
cout<<"El campo incompleto"<<endl;
rlutil::locate(45,17);
cout<<"Ingrese el correo:";
cin.getline(cV,30,'\n');
}
while(fread(&objC,sizeof(Vendedores),1,correo)!=0){
if(strcmp(objC.getCorreo(),cV)==0){
rlutil::locate(45,15);
cout<<"Este correo ya se encuentra registrado"<<endl;
rlutil::locate(45,17);
cout<<"Ingrese el correo:";
cin.getline(cV,30,'\n');
}
}
fclose(correo);
}


//CLAVE
void c2(char* c){
while(c[0]=='\0'){
rlutil::locate(45,15);
cout<<"El campo incompleto"<<endl;
rlutil::locate(45,17);
cout<<"Ingrese la clave:";
cin.getline(c,30,'\n');
}
}

void estiloV(){
for(int j=1;j<121;j++){
rlutil::locate(j,1);
    cout<<char(176);
}
for(int j=1;j<121;j++){
    rlutil::locate(j,30);
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

#endif // CLASSVENDEDOR_H_INCLUDED
