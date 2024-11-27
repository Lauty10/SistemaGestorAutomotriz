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
    rlutil::locate(42,5);
    cout<<"GESTIONANDO A LOS CLIENTES"<<endl;
    rlutil::locate(38,6);
    cout<<"--------------------------------------------------------------"<<endl;
    rlutil::locate(65,7);
    cout<<"GROUP 51 CAR CENTER"<<endl;
    rlutil::locate(45,9);
    cout<<"1-)Dar de alta cliente"<<endl;
    rlutil::locate(45,11);
    cout<<"2-)Dar de baja cliente"<<endl;
    rlutil::locate(45,13);
    cout<<"3-)Modificar cliente"<<endl;
    rlutil::locate(45,15);
    cout<<"4-)Listar clientes"<<endl;
    rlutil::locate(45,17);
    cout<<"5-)Buscar un cliente"<<endl;
    rlutil::locate(45,19);
    cout<<"0-)Volver atras"<<endl;
    rlutil::locate(45,21);
    cout<<"Ingresa la opcion que desee:";
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
    objCliente.modificarCliente(id);
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

Clientes obj;
rlutil::locate(43,6);
cout<<"CARGA LA INFORMCION DEL CLIENTE EN EL SISTEMA"<<endl;
rlutil::locate(36,7);
cout<<"--------------------------------------------------------------"<<endl;
rlutil::locate(43,10);
cout<<"Ingrese el nombre del cliente:";
cin.ignore();
cin.getline(nombreCliente,30,'\n');
rlutil::locate(43,11);
obj.nombre(nombreCliente);
rlutil::locate(43,12);
cout<<"Ingrese el correo del cliente:";
cin.getline(correoCliente, 35,'\n');
rlutil::locate(43,12);
obj.correo(correoCliente);
rlutil::locate(43,14);
cout<<"Ingrese el telefono del cliente:";
cin.getline(telefono, 14,'\n');
rlutil::locate(43,15);
obj.telefono1(telefono);
rlutil::locate(43,16);
cout<<"Ingrese el dni del cliente:";
cin>>dni;
rlutil::locate(43,17);
obj.dni1(dni);
rlutil::locate(43,18);
cout<<"Cliente registrado correctamente..."<<endl;
rlutil::locate(43,20);
cout<<"ID:"<<getIdCliente()<<endl;
}

void darDeAltaCliente(Clientes objCliente){
FILE *clienteCargado;
clienteCargado=fopen("Clientes","ab");
if(clienteCargado==NULL){
    rlutil::locate(1,31);
    cout<<"Error al dar de alta nuevo cliente..."<<endl;
}
fwrite(&objCliente,sizeof(Clientes),1,clienteCargado);
rlutil::locate(43,22);
cout<<"Cliente cargado correctamente en el sistema..."<<endl;
rlutil::locate(43,24);
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
FILE *clientesLista;
clientesLista=fopen("Clientes","rb");
if(clientesLista==NULL){
    rlutil::locate(1,3);
    cout<<"Error al generar lista de clientes..."<<endl;
}
Clientes listaObj;
rlutil::locate(50,6);
cout<<"Estos son los clientes en nuestro sistema"<<endl;
rlutil::locate(30,7);
cout<<"--------------------------------------------------------------------------------"<<endl;
int fila = 9;
    while (fread(&listaObj, sizeof(Clientes), 1, clientesLista) != 0) {
        if (listaObj.getEstado() == true) {
            rlutil::locate(1, fila);
            cout << "Nom: " << listaObj.getNombreCliente() << endl;
            rlutil::locate(30, fila);
            cout << "Cor: " << listaObj.getCorreoCliente() << endl;
            rlutil::locate(60, fila);
            cout << "Tel: " << listaObj.getTelefono() << endl;
            rlutil::locate(90, fila);
            cout << "DNI: " << listaObj.getDni() << endl;
            rlutil::locate(110, fila);
            cout << "ID: " << listaObj.getIdCliente() << endl;
            fila++;
            if (fila > 25) {
                system("cls");
                fila = 8;
            }
        }
    }
    fclose(clientesLista);
    rlutil::locate(45, 25);
    system("pause");
    system("cls");
}

void darDeBajaCliente(){
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
int baja;
rlutil::locate(50,10);
cout<<"DAR DE BAJA A CLIENTE DEL SISTEMA"<<endl;
rlutil::locate(38,11);
cout<<"------------------------------------------------------------"<<endl;
rlutil::locate(45,13);
cout<<"Ingrese el ID del usuario a dar de baja:";
cin>>baja;
FILE *bajaUsuario;
bajaUsuario=fopen("Clientes","rb+");
if(bajaUsuario==NULL){
    rlutil::locate(45,15);
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
        rlutil::locate(45,15);
        cout<<"Cliente dado de baja correctamente..."<<endl;
        rlutil::locate(1,9);
        rlutil::locate(45,17);
        system("pause");
        break;
    }
}
if(!encontrado){
    rlutil::locate(45,15);
    cout<<"ID no encontrado..."<<endl;
    rlutil::locate(45,17);
    system("pause");
}
fclose(bajaUsuario);
rlutil::locate(1,9);
system("cls");
}

void buscarCliente(){
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
int busqueda;
rlutil::locate(45,6);
cout<<"BUSCAR CLIENTE EN EL SISTEMA"<<endl;
rlutil::locate(30,8);
cout<<"-------------------------------------------------------------------------"<<endl;
rlutil::locate(45,10);
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
rlutil::locate(45,12);
cout<<"Cliente encontrado...."<<endl;
rlutil::locate(45,14);
cout<<"Nombre del cliente:"<<obj.getNombreCliente()<<endl;
rlutil::locate(45,16);
cout<<"Correo del cliente:"<<obj.getCorreoCliente()<<endl;
rlutil::locate(45,18);
cout<<"Telefono del cliente:"<<obj.getTelefono()<<endl;
rlutil::locate(45,20);
cout<<"Dni del cliente:"<<obj.getDni()<<endl;
rlutil::locate(45,22);
cout<<"ID del cliente:"<<obj.getIdCliente()<<endl;
rlutil::locate(45,26);
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

void modificarCliente(int id){
int opcion;
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
rlutil::locate(45,8);
cout<<"AQUI PODRA EDITAR LA INFORMACION DE LOS CLIENTES"<<endl;
rlutil::locate(45,10);
cout<<"-1)Editar nombre"<<endl;
rlutil::locate(45,12);
cout<<"-2)Editar Correo"<<endl;
rlutil::locate(45,14);
cout<<"-3)Editar telefono"<<endl;
rlutil::locate(45,16);
cout<<"-4)Editar dni"<<endl;
rlutil::locate(45,18);
cout<<"-0)Volver atras"<<endl;
rlutil::locate(45,20);
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
    menuDeVendedores(id);
default:
    rlutil::locate(45,15);
    cout<<"Opcion incorrecta..."<<endl;
}
}

void editarNombre(){
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
rlutil::locate(45,12);
cout<<"Ingrese el id del cliente a editar:";
cin>>idBuscado;
rlutil::locate(36,13);
cout<<"-----------------------------------------------------------------"<<endl;
while(fread(&nombreObj,sizeof(Clientes),1,editar)!=0){
    if(idBuscado==nombreObj.getIdCliente()){
        rlutil::locate(45,15);
        cout<<"Cliente encontrado correctamente"<<endl;
        rlutil::locate(3,8);
        cout<<"El nombre actual es: "<<nombreObj.getNombreCliente()<<endl;
        encontrado=true;
        long longitud=ftell(editar)-sizeof(Clientes);
        char nuevoNombre[30];
        rlutil::locate(45,17);
        cout<<"Ingresa el nuevo nombre:";
        cin.ignore();
        cin.getline(nuevoNombre,30,'\n');
        rlutil::locate(45,18);
        nombreObj.nombre(nuevoNombre);
        nombreObj.setNombreCliente(nuevoNombre);
        fseek(editar,longitud,SEEK_SET);
        fwrite(&nombreObj,sizeof(Clientes),1,editar);
        rlutil::locate(45,19);
        cout<<"Nombre editado correctamente..."<<endl;
        rlutil::locate(45,21);
        system("pause");
        break;
    }
}
if(!encontrado){
rlutil::locate(45,15);
cout<<"No se encontro el id correspondiente"<<endl;
rlutil::locate(45,17);
system("pause");
}
fclose(editar);
rlutil::locate(1,17);
system("cls");
}

void editarCorreo(){
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
rlutil::locate(55,9);
cout<<"Editar correo"<<endl;
rlutil::locate(30,10);
cout<<"-----------------------------------------------------------------------"<<endl;
rlutil::locate(45,12);
cout<<"Ingrese el id del cliente buscado:";
cin>>idBuscado;
while(fread(&correoObj,sizeof(Clientes),1,editar)!=0){
    if(idBuscado==correoObj.getIdCliente()){
        rlutil::locate(45,14);
        cout<<"Cliente encontrado correctamente"<<endl;
        rlutil::locate(3,6);
        cout<<"El correo actual es : "<<correoObj.getCorreoCliente()<<endl;
        encontrado=true;
        long longitud=ftell(editar)-sizeof(Clientes);
        char nuevoCorreo[30];
        rlutil::locate(45,16);
        cout<<"Ingresa el nuevo correo:";
        cin.ignore();
        cin.getline(nuevoCorreo,30,'\n');
        rlutil::locate(45,17);
        correoObj.correo(nuevoCorreo);
        correoObj.setCorreoCliente(nuevoCorreo);
        fseek(editar,longitud,SEEK_SET);
        fwrite(&correoObj,sizeof(Clientes),1,editar);
        rlutil::locate(45,18);
        cout<<"Correo editado correctamente..."<<endl;
        rlutil::locate(45,20);
        system("pause");
        break;
    }
}
if(!encontrado){
rlutil::locate(45,14);
cout<<"No se encontro el id correspondiente"<<endl;
rlutil::locate(45,16);
system("pause");
}
fclose(editar);
system("cls");
}




void editarTelefono(){
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
FILE *editar;
editar=fopen("Clientes","rb+");
if(editar==NULL){
    cout<<"Error al editar telefono..."<<endl;
     fclose(editar);
}
Clientes TelefonObj;
bool encontrado=false;
int idBuscado;
rlutil::locate(55,10);
cout<<"Editar numero telefonico"<<endl;
rlutil::locate(30,11);
cout<<"-----------------------------------------------------------------------"<<endl;
rlutil::locate(45,13);
cout<<"Ingrese el id del cliente buscado:";
cin>>idBuscado;
while(fread(&TelefonObj,sizeof(Clientes),1,editar)!=0){
    if(idBuscado==TelefonObj.getIdCliente()){
        rlutil::locate(45,15);
        cout<<"Cliente encontrado correctamente"<<endl;
        rlutil::locate(1,5);
        cout<<"El telefono actual es: "<<TelefonObj.getTelefono()<<endl;
        encontrado=true;
        long longitud=ftell(editar)-sizeof(Clientes);
        char nuevoTel[30];
        rlutil::locate(45,17);
        cout<<"Ingresa el telefono:";
        cin.ignore();
        cin.getline(nuevoTel,30,'\n');
        rlutil::locate(45,18);
        TelefonObj.telefono1(nuevoTel);
        TelefonObj.setTelefono(nuevoTel);
        fseek(editar,longitud,SEEK_SET);
        fwrite(&TelefonObj,sizeof(Clientes),1,editar);
        rlutil::locate(45,19);
        cout<<"Telefono editado correctamente..."<<endl;
        rlutil::locate(45,21);
        system("pause");
        break;
    }
}
if(!encontrado){
rlutil::locate(45,15);
cout<<"No se encontro el id correspondiente"<<endl;
rlutil::locate(45,17);
system("pause");
}
fclose(editar);
system("cls");
}


void editarDni(){
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
FILE *editar;
editar=fopen("Clientes","rb+");
if(editar==NULL){
    cout<<"Error al editar DNI..."<<endl;
    fclose(editar);
}
Clientes DniObj;
bool encontrado=false;
int idBuscado;
rlutil::locate(55,10);
cout<<"Editar numero de dni"<<endl;
rlutil::locate(30,11);
cout<<"-----------------------------------------------------------------------"<<endl;
rlutil::locate(45,13);
cout<<"Ingrese el id del cliente buscado:";
cin>>idBuscado;
while(fread(&DniObj,sizeof(Clientes),1,editar)!=0){
    if(idBuscado==DniObj.getIdCliente()){
        rlutil::locate(45,15);
        cout<<"Cliente encontrado correctamente"<<endl;
        rlutil::locate(1,5);
        cout<<"El dni actual es:"<<DniObj.getDni()<<endl;
        encontrado=true;
        long longitud=ftell(editar)-sizeof(Clientes);
        int dniNuevo;
        rlutil::locate(45,17);
        cout<<"Ingresa el dni:";
        cin.ignore();
        cin>>dniNuevo;
        rlutil::locate(45,18);
        DniObj.dni1(dniNuevo);
        DniObj.setDni(dniNuevo);
        fseek(editar,longitud,SEEK_SET);
        fwrite(&DniObj,sizeof(Clientes),1,editar);
        rlutil::locate(45,19);
        cout<<"Dni editado correctamente..."<<endl;
        rlutil::locate(45,21);
        system("pause");
        break;
    }
}
if(!encontrado){
rlutil::locate(55,15);
cout<<"No se encontro el id correspondiente"<<endl;
rlutil::locate(55,17);
system("pause");
}
fclose(editar);
system("cls");
}

//VALIDACIONES
//NOMBRE
void nombre( char* nom){
if(nom[0]=='\0'){
cout<<"Campo incompleto"<<endl;
cout<<"Nombre: ";
cin.ignore();
cin.getline(nom,30,'\n');
}
}


//CORREO
void correo( char* dato){
FILE *correo;
correo=fopen("Clientes","rb");
if(correo==NULL){
cout<<"NO SE PUDO ABRIR ESTE ARCHIVO"<<endl;
return;
}
Clientes objC;
if(dato[0]=='\0'){
cout<<"Campo incompleto"<<endl;
cout<<"Correo: ";
cin.ignore();
cin.getline(dato,30,'\n');
}
while(fread(&objC,sizeof(Clientes),1,correo)!=0){
if(strcmp(objC.getCorreoCliente(),dato)==0){
cout<<"Este correo ya esta registrado"<<endl;
cout<<"Correo: ";
cin.ignore();
cin.getline(dato,30,'\n');
}
}
fclose(correo);
}


//TELEFONO
void telefono1( char* tel){
if(tel[0]=='\0'){
cout<<"Campo incompleto"<<endl;
cout<<"Telefono: ";
cin.ignore();
cin.getline(tel,30,'\n');
}
}


//DNI
void dni1( int d){
FILE *dni;
dni=fopen("Clientes","rb");
if(dni==NULL){
cout<<"NO SE PUDO ABRIR ESTE ARCHIVO"<<endl;
return;
}
Clientes objd;
if(d==0){
cout<<"Campo incompleto"<<endl;
cout<<"Dni: ";
cin>>d;
}
while(fread(&objd,sizeof(Clientes),1,dni)!=0){
if(objd.getDni()==d){
cout<<"Este dni ya esta registrado"<<endl;
cout<<"Dni: ";
cin>>d;
}
}
fclose(dni);
}
};



#endif // CLASSCLIENTES_H_INCLUDED
