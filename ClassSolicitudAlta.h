#ifndef CLASSSOLICITUDALTA_H_INCLUDED
#define CLASSSOLICITUDALTA_H_INCLUDED
#include <string.h>

class Solicitud{
private:
    char nombre[30];
    char correo[35];
    char clave[20];
    int dni;
    bool estado;
    bool aprobado;
    int id;
public:
    Solicitud(const char* n="XXX", const char* c="XXX", const char* cl="NuevoVendedor", int d=0, bool e=false, bool a=false,int i=0){
    strcpy(this->nombre,n);
    strcpy(this->correo,c);
    strcpy(this->clave,cl);
    this->dni=d;
    this->estado=e;
    this->aprobado=a;
    this->id=i;
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
void setId(int idN){
this->id=idN;
}
int getId(){
return id;
}


void cargarSolicitud(){
    int nuevaSoli;
    nuevaSoli=generarIdSolicitud();
    setId(nuevaSoli);
    cout << "Bienvenido, complete los datos solicitados para generar una solicitud de alta en el sistema..." << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Ingrese su nombre:";
    cin.getline(nombre, 30, '\n');
    setNombre(nombre);
    cout << "Ingrese su correo:";
    cin.getline(correo, 35, '\n');
    setCorreo(correo);
    cout << "Ingrese su dni:";
    cin >> dni;
    cin.ignore();
    setDni(dni);
    cout << "------------------------------------------------------------" << endl;
    cout << "El número de solicitud es: " << getId() << endl;
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
        cout<<"El id de la solicitud es:"<<obj.getId()<<endl;
        cout<<"------------------------------------------------------------"<<endl;
    }
}
system("pause");
system("cls");
fclose(soli);
}

void aprobarSolicitudDeAlta(){
    FILE *aprobarS;
    aprobarS = fopen("Solicitud.dat", "rb+");
    if(aprobarS == NULL){
        cout << "Error al aprobar solicitud" << endl;
        return;
    }
    Solicitud objS;
    int id;
    bool encontrado = false;
    cout << "Ingrese el id de la solicitud que desea aprobar: ";
    cin >> id;
    while(fread(&objS, sizeof(Solicitud), 1, aprobarS) != 0){
        if(objS.getId() == id && objS.getEstado()==false){
            long posicion = ftell(aprobarS) - sizeof(Solicitud);
            objS.setAprobado(true);
            objS.setEstado(true);
            fseek(aprobarS, posicion, SEEK_SET);
            fwrite(&objS, sizeof(Solicitud), 1, aprobarS);
            cout << "Solicitud aprobada correctamente..." << endl;
            system("pause");
            encontrado = true;
            break;
        }
    }
    if(!encontrado){
        cout << "Error al buscar la solicitud" << endl;
        system("pause");
        system("cls");
    }
    system("cls");
    fclose(aprobarS);
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
