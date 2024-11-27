#ifndef CLASSSOLICITUDALTA_H_INCLUDED
#define CLASSSOLICITUDALTA_H_INCLUDED
#include <string.h>

class Solicitud{
private:
    int id;
    char nombre[30];
    char correo[35];
    char clave[20];
    int dni;
    bool estado;
    bool aprobado;
public:
    Solicitud(int i=0,const char* n="XXX", const char* c="XXX", const char* cl="NuevoVendedor", int d=0, bool e=false, bool a=false){
    this->id=i;
    strcpy(this->nombre,n);
    strcpy(this->correo,c);
    strcpy(this->clave,cl);
    this->dni=d;
    this->estado=e;
    this->aprobado=a;
    }
void setId(int idS){
this->id=idS;
}
void setNombre(char n[30]){
strcpy(this->nombre,n);
}
void setCorreo(char c[35]){
strcpy(this->correo,c);
}
void setClave(char cl[20]){
strcpy(this->clave,cl);
}
void setDni(int d){
this->dni=d;
}
void setEstado(bool e){
this->estado=e;
}
void setAprobado(bool a){
this->aprobado=a;
}
int getIdSolicitud(){
return id;
}
const char* getNombre(){
return nombre;
}
const char* getCorreo(){
return correo;
}
const char* getClave(){
return clave;
}
int getDni(){
return dni;
}
bool getEstado(){
return estado;
}
bool getAprobado(){
return aprobado;
}


void cargarSolicitud(){
Solicitud objS;
int soli;
cout<<"Bienvenido complete los datos solicitados para generar una solicitud de alta en el sistema..."<<endl;
cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
cout<<"Ingrese su nombre:";
cin.getline(nombre,30,'\n');
objS.validarN(nombre);
setNombre(nombre);
cout<<"Ingrese su correo:";
cin.getline(correo,35,'\n');
objS.validarC(correo);
setCorreo(correo);
cout<<"Ingrese su dni:";
cin>>dni;
cin.ignore();
objS.validarD(dni);
setDni(dni);
soli=generarIdSolicitud();
setId(soli);
cout<<"------------------------------------------------------------"<<endl;
cout<<"El numero de solicitud es:"<<getIdSolicitud()<<endl;

}

void nuevaSolicitud(Solicitud objS){
FILE *soli;
soli=fopen("Solicitud.dat","ab");
if(soli==NULL){
    cout<<"Error al crear una nueva solicitud..."<<endl;
}
fwrite(&objS,sizeof(Solicitud),1,soli);
cout<<"Solicitud generada correcamente..."<<endl;
fclose(soli);
system("pause");
system("cls");
}

 int generarIdSolicitud(){
   FILE *generar;
   int dato=0;
   generar=fopen("Solicitud.dat","rb");
   if(generar==NULL){
    dato=1;
    fclose(generar);
    return dato;
   }
   Solicitud obj;
   while(fread(&obj,sizeof(Solicitud),1,generar)!=0){
    dato++;
   }
   fclose(generar);
   return dato+1;
    }

void listarSolicitudes(){
FILE *soli;
soli=fopen("Solicitud.dat","rb");
if(soli==NULL){
    cout<<"Error al listar solicitud..."<<endl;
}
Solicitud obj;
cout<<"Bienvenido estos son los vendedores que estan esperando la aprobacion en el sistema..."<<endl;
cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
while(fread(&obj,sizeof(Solicitud),1,soli)!=0){
    if(obj.getEstado()==false){
        cout<<"Nombre del usuario a dar de alta:"<<obj.getNombre()<<endl;
        cout<<"Correo del usuario a dar de alta:"<<obj.getCorreo()<<endl;
        cout<<"Dni del usuario a dar de alta:"<<obj.getDni()<<endl;
        cout<<"El id de la solicitud es:"<<obj.getIdSolicitud()<<endl;
        cout<<"------------------------------------------------------------"<<endl;
    }
}
system("pause");
system("cls");
fclose(soli);
}

void aprobarSolicitudDeAlta(){
FILE *buscarS;
buscarS=fopen("Solicitud.dat","rb+");
if(buscarS==NULL){
    cout<<"Error al buscar solicitud"<<endl;
}
int id;
cout<<"Ingrese el id de la solicitud que quiere aprobar:";
cin>>id;
Solicitud objS;
bool buscar=false;
while(fread(&objS,sizeof(Solicitud),1,buscarS)!=0){
    if(objS.getEstado()==false){
        if(objS.getIdSolicitud()==id){
            buscar=true;
            long posicion=ftell(buscarS)-sizeof(Solicitud);
            objS.setEstado(true);
            objS.setAprobado(true);
            fseek(buscarS,posicion,SEEK_SET);
            fwrite(&objS,sizeof(Solicitud),1,buscarS);
            cout<<"Solicitud aprobada correctamente..."<<endl;
            system("pause");
            break;
        }
    }else{
    cout<<"La solicitud ya se encuentra aprobada..."<<endl;
    system("pause");
    system("cls");
    break;
    }
}
if(!buscar){
    cout<<"Solicitud no encontrada..."<<endl;
     system("pause");
}
fclose(buscarS);
system("cls");
}



//VALIDACIONES
//Nombre
void validarC(char* c){
FILE *correo;
correo=fopen("Solicitud.dat","rb");
if(correo==NULL){
cout<<"NO SE PUDO ABRIR ESTE ARCHIVO"<<endl;
return;
}
Solicitud obj;
if(c[0]==0){
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
void validarN(char* n){
if(n[0]==0){
cout<<"Campo incompleto"<<endl;
cout<<"Nombre: ";
cin.ignore();
cin.getline(n,30,'\n');
}
}

//DNI
void validarD(int d){
if(d==0){
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

};

#endif // CLASSSOLICITUDALTA_H_INCLUDED
