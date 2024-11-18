#ifndef CLASSCLIENTES_H_INCLUDED
#define CLASSCLIENTES_H_INCLUDED
#include <string.h>

//Volver a los menus
void menuDeVendedores();
void menu();

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
    void menuClientes(){
    int opcion;
    Clientes objCliente;
    cout<<"USTED ESTA GESTIONANDO A LOS CLIENTES..."<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"1-)Dar de alta cliente"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"2-)Dar de baja cliente"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"3-)Modificar cliente"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"4-)Listar clientes"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"5-)Buscar un cliente"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"0-)Volver atras"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"Ingresa la opcion que desee:";
    cin>>opcion;
    switch(opcion){
case 0:
    system("cls");
    menuDeVendedores();
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
cout<<"Ingrese el nombre del cliente:";
cin.ignore();
cin.getline(nombreCliente,30,'\n');
cout<<"Ingrese el correo del cliente:";
cin.getline(correoCliente, 35,'\n');
cout<<"Ingrese el telefono del cliente:";
cin.getline(telefono, 14,'\n');
cout<<"Ingrese el dni del cliente:";
cin>>dni;
cout<<"------------------------------------------------------------"<<endl;
cout<<"Cliente registrado correctamente..."<<endl;
cout<<"Nombre:"<<getNombreCliente()<<endl;
cout<<"Correo:"<<getCorreoCliente()<<endl;
cout<<"Telefono:"<<getTelefono()<<endl;
cout<<"Dni:"<<getDni()<<endl;
cout<<"ID:"<<getIdCliente()<<endl;
cout<<"------------------------------------------------------------"<<endl;
}

void darDeAltaCliente(Clientes objCliente){
FILE *clienteCargado;
clienteCargado=fopen("Clientes","ab");
if(clienteCargado==NULL){
    cout<<"Error al dar de alta nuevo cliente..."<<endl;
}
fwrite(&objCliente,sizeof(Clientes),1,clienteCargado);
cout<<"Cliente cargado correctamente en el sistema..."<<endl;
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
    cout<<"Error al generar lista de clientes..."<<endl;
}
Clientes listaObj;
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
cout<<"Ingrese el ID del usuario a dar de baja:";
cin>>baja;
FILE *bajaUsuario;
bajaUsuario=fopen("Clientes","rb+");
if(bajaUsuario==NULL){
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
        cout<<"Cliente dado de baja correctamente..."<<endl;
        system("pause");
        break;
    }
}
if(!encontrado){
    cout<<"ID no encontrado..."<<endl;
    system("pause");
}
fclose(bajaUsuario);
system("cls");
}

void buscarCliente(){
int busqueda;
cout<<"Ingrese el ID del cliente buscado:";
cin>>busqueda;
FILE *busquedaPersonalizada;
busquedaPersonalizada=fopen("Clientes","rb");
if(busquedaPersonalizada==NULL){
    cout<<"Error al encontrar cliente..."<<endl;
    fclose(busquedaPersonalizada);
}
Clientes obj;
bool encontrado=false;
while(fread(&obj,sizeof(Clientes),1,busquedaPersonalizada)!=0){
    if(busqueda==obj.getIdCliente()){
encontrado=true;
cout<<"Cliente encontrado:"<<endl;
cout<<"Nombre del cliente:"<<obj.getNombreCliente()<<endl;
cout<<"Correo del cliente:"<<obj.getCorreoCliente()<<endl;
cout<<"Telefono del cliente:"<<obj.getTelefono()<<endl;
cout<<"Dni del cliente:"<<obj.getDni()<<endl;
cout<<"ID del cliente:"<<obj.getIdCliente()<<endl;
cout<<"------------------------------------------------------------"<<endl;
system("pause");
break;
    }
}
if(!encontrado){
    cout<<"Cliente no encontrado..."<<endl;
    system("pause");
}
fclose(busquedaPersonalizada);
system("cls");
}

void modificarCliente(){
Clientes objModificar;
int opcion;
cout<<"Usted esta editando los clientes..."<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"-1)Editar nombre"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"-2)Editar Correo"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"-3)Editar telefono"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"-4)Editar dni"<<endl;
cout<<"------------------------------------------------------------"<<endl;
cout<<"Eliga la opcion que desee:";
cin>>opcion;
switch(opcion){
case 1:
    system("cls");
    objModificar.editarNombre();
    break;
case 2:
    system("cls");
    objModificar.editarCorreo();
    break;
case 3:
    system("cls");
    objModificar.editarTelefono();
    break;
case 4:
    system("cls");
    objModificar.editarDni();
    break;
case 0:
    system("cls");
    menuDeVendedores();
default:
    cout<<"Opcion incorrecta..."<<endl;
}
}

void editarNombre(){
FILE *editar;
editar=fopen("Clientes","rb+");
if(editar==NULL){
    cout<<"Error al editar nombre..."<<endl;
    fclose(editar);
}
Clientes nombreObj;
bool encontrado=false;
int idBuscado;
cout<<"Ingrese el id del cliente buscado:";
cin>>idBuscado;
while(fread(&nombreObj,sizeof(Clientes),1,editar)!=0){
    if(idBuscado==nombreObj.getIdCliente()){
        cout<<"Cliente encontrado correctamente"<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        encontrado=true;
        long longitud=ftell(editar)-sizeof(Clientes);
        char nuevoNombre[30];
        cout<<"Ingresa el nombre:";
        cin.ignore();
        cin.getline(nuevoNombre,30,'\n');
        nombreObj.setNombreCliente(nuevoNombre);
        fseek(editar,longitud,SEEK_SET);
        fwrite(&nombreObj,sizeof(Clientes),1,editar);
        cout<<"Nombre editado correctamente..."<<endl;
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

void editarCorreo(){
FILE *editar;
editar=fopen("Clientes","rb+");
if(editar==NULL){
    cout<<"Error al editar correo..."<<endl;
    fclose(editar);
}
Clientes correoObj;
bool encontrado=false;
int idBuscado;
cout<<"Ingrese el id del cliente buscado:";
cin>>idBuscado;
while(fread(&correoObj,sizeof(Clientes),1,editar)!=0){
    if(idBuscado==correoObj.getIdCliente()){
        cout<<"Cliente encontrado correctamente"<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        encontrado=true;
        long longitud=ftell(editar)-sizeof(Clientes);
        char nuevoCorreo[30];
        cout<<"Ingresa el nombre:";
        cin.ignore();
        cin.getline(nuevoCorreo,30,'\n');
        correoObj.setCorreoCliente(nuevoCorreo);
        fseek(editar,longitud,SEEK_SET);
        fwrite(&correoObj,sizeof(Clientes),1,editar);
        cout<<"Correo editado correctamente..."<<endl;
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
