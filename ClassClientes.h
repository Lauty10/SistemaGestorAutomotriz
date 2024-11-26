#ifndef CLASSCLIENTES_H_INCLUDED
#define CLASSCLIENTES_H_INCLUDED
#include <string.h>
#include "FuncionesDeclaraciones.h"
//Volver a los menus
void menuDeVendedores(int id);
void menu();
void usuarioLogeado(int id);

class Clientes {
private:
    int idCliente;
    char nombreCliente[30];
    int dni;
    char correoCliente[35];
    char telefono[14];
    bool estado;

public:
    Clientes(int idC = 0, const char* nombreC = "XXX", int dniC = 1000000, const char* correoC = "cliente123@gmail.com", const char* claveC = "12345678",const char* tel="+541123542343", bool e=true) {
        this->idCliente = idC;
        strcpy(this->nombreCliente, nombreC);
        this->dni = dniC;
        strcpy(this->correoCliente, correoC);
        strcpy(this->telefono, tel);
    }
    void setIdCliente(int idC){
    this->idCliente = idC;
    }
    void setNombreCliente(const char nombreC[30]){
        strcpy(this->nombreCliente, nombreC);
    }
    void setDni(int dniC){
        this->dni = dniC;
    }
    void setCorreoCliente(const char correoC[35]){
    strcpy(this->correoCliente, correoC);
    }

     void setTelefono(const char tel[14]){
     strcpy(this->telefono,tel);
     }

     const char* getTelefono(){
     return telefono;
     }

    int getIdCliente(){
        return idCliente;
    }
    const char* getNombreCliente() {
        return nombreCliente;
     }
    int getDni(){
    return dni;
    }
    const char* getCorreoCliente() {
       return correoCliente;
        }
    void setEstado(bool e){
    this->estado=e;
    }
    bool getEstado(){
    return estado;
    }

    //MENU PARA CLIENTES
    void menuClientes(int id){
    int opcion;
    Clientes objCliente;
    rlutil::locate(45,5);
    cout<<"USTED ESTA GESTIONANDO A LOS CLIENTES..."<<endl;
    rlutil::locate(45,8);
    cout<<"1-)Dar de alta cliente"<<endl;
    rlutil::locate(45,10);
    cout<<"2-)Dar de baja cliente"<<endl;
    rlutil::locate(45,12);
    cout<<"3-)Modificar cliente"<<endl;
    rlutil::locate(45,14);
    cout<<"4-)Listar clientes"<<endl;
    rlutil::locate(45,16);
    cout<<"5-)Buscar un cliente"<<endl;
    rlutil::locate(45,18);
    cout<<"0-)Volver atras"<<endl;
    rlutil::locate(45,20);
    cout<<"Ingresa la opcion que desee:";
    rlutil::locate(45,22);
    cin>>opcion;
    switch(opcion){
case 0:
    system("cls");
    menuDeVendedores(id);
    break;
case 1:
    system("cls");
    objCliente.cargarCliente();
    objCliente.darDeAltaCliente(objCliente);
    break;
case 2:
    system("cls");
    objCliente.darDeBajaCliente();
    break;
case 3:
    system("cls");
    objCliente.modificarCliente();
    break;
case 4:
    system("cls");
    objCliente.listarClientes();
    break;
case 5:
    system("cls");
    objCliente.buscarCliente();
    break;
default:
    cout<<"Opcion no encontrada"<<endl;
    }
}

void cargarCliente(){
idCliente=generarIdCliente();
rlutil::locate(1,1);
cout<<"Cargar cliente"<<endl;
rlutil::locate(1,2);
cout<<"----------------------------------------------------"<<endl;
rlutil::locate(1,4);
cout<<"Ingrese el nombre del cliente:";
cin.ignore();
cin.getline(nombreCliente,30,'\n');
rlutil::locate(1,6);
cout<<"Ingrese el correo del cliente:";
cin.getline(correoCliente, 35,'\n');
rlutil::locate(1,8);
cout<<"Ingrese el telefono del cliente:";
cin.getline(telefono, 14,'\n');
rlutil::locate(1,10);
cout<<"Ingrese el dni del cliente:";
cin>>dni;
rlutil::locate(1,12);
cout<<"-----------------------------------------------------"<<endl;
rlutil::locate(1,14);
cout<<"Cliente registrado correctamente..."<<endl;
rlutil::locate(1,16);
cout<<"-----------------------------------------------------"<<endl;
rlutil::locate(1,18);
cout<<"Nombre:"<<getNombreCliente()<<endl;
rlutil::locate(1,20);
cout<<"Correo:"<<getCorreoCliente()<<endl;
rlutil::locate(1,22);
cout<<"Telefono:"<<getTelefono()<<endl;
rlutil::locate(1,24);
cout<<"Dni:"<<getDni()<<endl;
rlutil::locate(1,26);
cout<<"ID:"<<getIdCliente()<<endl;
rlutil::locate(1,28);
cout<<"------------------------------------------------------"<<endl;
}

void darDeAltaCliente(Clientes objCliente){
FILE *clienteCargado;
clienteCargado=fopen("Clientes","ab");
if(clienteCargado==NULL){
    rlutil::locate(1,31);
    cout<<"Error al dar de alta nuevo cliente..."<<endl;
}
fwrite(&objCliente,sizeof(Clientes),1,clienteCargado);
rlutil::locate(1,31);
cout<<"Cliente cargado correctamente en el sistema..."<<endl;
rlutil::locate(1,34);
system("pause");
system("cls");
fclose(clienteCargado);
}

 int generarIdCliente() {
   FILE *generar;
   int dato=0;
   generar=fopen("Clientes","rb");
   if(generar==NULL){
    dato=1;
    return dato;
   }
   Clientes obj;
   while(fread(&obj,sizeof(Clientes),1,generar)!=0){
    dato++;
   }
   return dato+1;
   fclose(generar);
    }



void listarClientes(){
FILE *clientesLista;
clientesLista=fopen("Clientes","rb");
if(clientesLista==NULL){
    rlutil::locate(1,3);
    cout<<"Error al generar lista de clientes..."<<endl;
}
Clientes listaObj;
rlutil::locate(1,2);
cout<<"Estos son todos los clientes"<<endl;
rlutil::locate(1,3);
cout<<"------------------------------------------------------------"<<endl;
while(fread(&listaObj,sizeof(Clientes),1,clientesLista)!=0){
    if(listaObj.getEstado()==true){
cout<<"Nombre del cliente:"<<listaObj.getNombreCliente()<<endl;
cout<<"Correo del cliente:"<<listaObj.getCorreoCliente()<<endl;
cout<<"Telefono del cliente:"<<listaObj.getTelefono()<<endl;
cout<<"Dni del cliente:"<<listaObj.getDni()<<endl;
cout<<"ID del cliente:"<<listaObj.getIdCliente()<<endl;
cout<<"------------------------------------------------------------"<<endl;
    }
}
fclose(clientesLista);
system("pause");
system("cls");
}

void darDeBajaCliente(){
int baja;
rlutil::locate(1,2);
cout<<"Dar de baja cliente"<<endl;
rlutil::locate(1,3);
cout<<"------------------------------------------------------------"<<endl;
rlutil::locate(1,5);
cout<<"Ingrese el ID del usuario a dar de baja:";
cin>>baja;
FILE *bajaUsuario;
bajaUsuario=fopen("Clientes","rb+");
if(bajaUsuario==NULL){
    rlutil::locate(1,7);
    cout<<"Error al dar de baja cliente"<<endl;
}
Clientes clienteBuscado;
bool encontrado=false;
while(fread(&clienteBuscado,sizeof(Clientes),1,bajaUsuario)!=0){
    if(baja==clienteBuscado.getIdCliente()){
        encontrado=true;
        long posicion=ftell(bajaUsuario)-sizeof(Clientes);
        clienteBuscado.setEstado(false);
        fseek(bajaUsuario,posicion,SEEK_SET);
        fwrite(&clienteBuscado,sizeof(Clientes),1,bajaUsuario);
        rlutil::locate(1,7);
        cout<<"Cliente dado de baja correctamente..."<<endl;
        rlutil::locate(1,9);
        system("pause");
        break;
    }
}
if(!encontrado){
    rlutil::locate(1,7);
    cout<<"ID no encontrado..."<<endl;
    system("pause");
}
fclose(bajaUsuario);
rlutil::locate(1,9);
system("cls");
}

void buscarCliente(){
int busqueda;
rlutil::locate(1,2);
cout<<"Buscar cliente"<<endl;
rlutil::locate(1,3);
cout<<"------------------------------------------------------------"<<endl;
rlutil::locate(1,5);
cout<<"Ingrese el ID del cliente buscado:";
cin>>busqueda;
FILE *busquedaPersonalizada;
busquedaPersonalizada=fopen("Clientes","rb");
if(busquedaPersonalizada==NULL){
    rlutil::locate(1,7);
    cout<<"Error al encontrar cliente..."<<endl;
    fclose(busquedaPersonalizada);
}
Clientes obj;
bool encontrado=false;
while(fread(&obj,sizeof(Clientes),1,busquedaPersonalizada)!=0){
    if(busqueda==obj.getIdCliente()){
encontrado=true;
rlutil::locate(1,7);
cout<<"Cliente encontrado:"<<endl;
rlutil::locate(1,8);
cout<<"------------------------------------------------------------"<<endl;
rlutil::locate(1,10);
cout<<"Nombre del cliente:"<<obj.getNombreCliente()<<endl;
rlutil::locate(1,11);
cout<<"Correo del cliente:"<<obj.getCorreoCliente()<<endl;
rlutil::locate(1,12);
cout<<"Telefono del cliente:"<<obj.getTelefono()<<endl;
rlutil::locate(1,14);
cout<<"Dni del cliente:"<<obj.getDni()<<endl;
rlutil::locate(1,16);
cout<<"ID del cliente:"<<obj.getIdCliente()<<endl;
rlutil::locate(1,18);
cout<<"------------------------------------------------------------"<<endl;
rlutil::locate(1,20);
system("pause");
break;
    }
}
if(!encontrado){
    rlutil::locate(1,7);
    cout<<"Cliente no encontrado..."<<endl;
    rlutil::locate(1,9);
    system("pause");
}
fclose(busquedaPersonalizada);
rlutil::locate(1,20);
system("cls");
}

void modificarCliente(){
int opcion;
rlutil::locate(45,3);
cout<<"Usted esta editando los clientes..."<<endl;
rlutil::locate(45,5);
cout<<"-1)Editar nombre"<<endl;
rlutil::locate(45,7);
cout<<"-2)Editar Correo"<<endl;
rlutil::locate(45,9);
cout<<"-3)Editar telefono"<<endl;
rlutil::locate(45,11);
cout<<"-4)Editar dni"<<endl;
rlutil::locate(45,13);
cout<<"Eliga la opcion que desee:";
cin>>opcion;
switch(opcion){
case 1:
    system("cls");
    editarNombre();
    break;
case 2:
    system("cls");
    editarCorreo();
    break;
case 3:
    system("cls");
    editarTelefono();
    break;
case 4:
    system("cls");
    editarDni();
    break;
case 0:
    system("cls");
default:
    rlutil::locate(45,15);
    cout<<"Opcion incorrecta..."<<endl;
}
}

void editarNombre(){
FILE *editar;
editar=fopen("Clientes","rb+");
if(editar==NULL){
    rlutil::locate(1,3);
    cout<<"Error al editar nombre..."<<endl;
    fclose(editar);
}
Clientes nombreObj;
bool encontrado=false;
int idBuscado;
rlutil::locate(1,2);
cout<<"Editar nombre"<<endl;
rlutil::locate(1,3);
cout<<"------------------------------------------------------------"<<endl;
rlutil::locate(1,5);
cout<<"Ingrese el id del cliente a editar:";
cin>>idBuscado;
while(fread(&nombreObj,sizeof(Clientes),1,editar)!=0){
    if(idBuscado==nombreObj.getIdCliente()){
        rlutil::locate(1,7);
        cout<<"Cliente encontrado correctamente"<<endl;
        rlutil::locate(1,9);
        cout<<"Nombre:"<<nombreObj.getNombreCliente()<<endl;
        encontrado=true;
        long longitud=ftell(editar)-sizeof(Clientes);
        char nuevoNombre[30];
        rlutil::locate(1,11);
        cout<<"Ingresa el nuevo nombre:";
        cin.ignore();
        cin.getline(nuevoNombre,30,'\n');
        nombreObj.setNombreCliente(nuevoNombre);
        fseek(editar,longitud,SEEK_SET);
        fwrite(&nombreObj,sizeof(Clientes),1,editar);
        rlutil::locate(1,13);
        cout<<"Nombre editado correctamente..."<<endl;
        rlutil::locate(1,15);
        system("pause");
        break;
    }
}
if(!encontrado){
rlutil::locate(1,7);
cout<<"No se encontro el id correspondiente"<<endl;
rlutil::locate(1,9);
system("pause");
}
fclose(editar);
rlutil::locate(1,17);
system("cls");
}

void editarCorreo(){
FILE *editar;
editar=fopen("Clientes","rb+");
if(editar==NULL){
    rlutil::locate(1,3);
    cout<<"Error al editar correo..."<<endl;
    fclose(editar);
}
Clientes correoObj;
bool encontrado=false;
int idBuscado;
rlutil::locate(1,2);
cout<<"Editar correo"<<endl;
rlutil::locate(1,3);
cout<<"------------------------------------------------------------"<<endl;
rlutil::locate(1,5);
cout<<"Ingrese el id del cliente buscado:";
cin>>idBuscado;
while(fread(&correoObj,sizeof(Clientes),1,editar)!=0){
    if(idBuscado==correoObj.getIdCliente()){
        rlutil::locate(1,7);
        cout<<"Cliente encontrado correctamente"<<endl;
        rlutil::locate(1,9);
        cout<<"Correo: "<<correoObj.getCorreoCliente()<<endl;
        encontrado=true;
        long longitud=ftell(editar)-sizeof(Clientes);
        char nuevoCorreo[30];
        rlutil::locate(1,11);
        cout<<"Ingresa el nuevo correo:";
        cin.ignore();
        cin.getline(nuevoCorreo,30,'\n');
        correoObj.setCorreoCliente(nuevoCorreo);
        fseek(editar,longitud,SEEK_SET);
        fwrite(&correoObj,sizeof(Clientes),1,editar);
        rlutil::locate(1,13);
        cout<<"Correo editado correctamente..."<<endl;
        rlutil::locate(1,15);
        system("pause");
        break;
    }
}
if(!encontrado){
rlutil::locate(1,7);
cout<<"No se encontro el id correspondiente"<<endl;
rlutil::locate(1,9);
system("pause");
}
fclose(editar);
system("cls");
}




void editarTelefono(){
FILE *editar;
editar=fopen("Clientes","rb+");
if(editar==NULL){
    cout<<"Error al editar telefono..."<<endl;
     fclose(editar);
}
Clientes TelefonObj;
bool encontrado=false;
int idBuscado;
cout<<"Ingrese el id del cliente buscado:";
cin>>idBuscado;
while(fread(&TelefonObj,sizeof(Clientes),1,editar)!=0){
    if(idBuscado==TelefonObj.getIdCliente()){
        cout<<"Cliente encontrado correctamente"<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        encontrado=true;
        long longitud=ftell(editar)-sizeof(Clientes);
        char nuevoTel[14];
        cout<<"Ingresa el telefono:";
        cin.ignore();
        cin.getline(nuevoTel,30,'\n');
        TelefonObj.setTelefono(nuevoTel);
        fseek(editar,longitud,SEEK_SET);
        fwrite(&TelefonObj,sizeof(Clientes),1,editar);
        cout<<"Telefono editado correctamente..."<<endl;
        system("pause");
        break;
    }
}
if(!encontrado){
cout<<"No se encontro el id correspondiente"<<endl;
system("pause");
}
fclose(editar);
system("cls");
}


void editarDni(){
FILE *editar;
editar=fopen("Clientes","rb+");
if(editar==NULL){
    cout<<"Error al editar DNI..."<<endl;
    fclose(editar);
}
Clientes DniObj;
bool encontrado=false;
int idBuscado;
cout<<"Ingrese el id del cliente buscado:";
cin>>idBuscado;
while(fread(&DniObj,sizeof(Clientes),1,editar)!=0){
    if(idBuscado==DniObj.getIdCliente()){
        cout<<"Cliente encontrado correctamente"<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        encontrado=true;
        long longitud=ftell(editar)-sizeof(Clientes);
        int dniNuevo;
        cout<<"Ingresa el dni:";
        cin.ignore();
        cin>>dniNuevo;
        DniObj.setDni(dniNuevo);
        fseek(editar,longitud,SEEK_SET);
        fwrite(&DniObj,sizeof(Clientes),1,editar);
        cout<<"Dni editado correctamente..."<<endl;
        system("pause");
        break;
    }
}
if(!encontrado){
cout<<"No se encontro el id correspondiente"<<endl;
system("pause");
}
fclose(editar);
system("cls");
}


};



#endif // CLASSCLIENTES_H_INCLUDED
