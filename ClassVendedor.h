#ifndef CLASSVENDEDOR_H_INCLUDED
#define CLASSVENDEDOR_H_INCLUDED
#include <cstring>
#include <string.h>

using namespace std;

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
    cout << "Ingrese la clave: ";
    cin.getline(clave, 20,'\n');
    setClave(clave);
    cout << "Ingrese el DNI: ";
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
   generar=fopen("Vendedores","rb");
   if(generar==NULL){
    dato=1;
    return dato;
   }
   Vendedores obj;
   while(fread(&obj,sizeof(Vendedores),1,generar)!=0){
    dato++;
   }
   return dato+1;
   fclose(generar);
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

bool iniciarSesion() {
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
    cout << "Ingresa su correo: ";
    cin.ignore();
    cin.getline(correoLogin, 35, '\n');
    cout << "Ingrese su clave: ";
    cin.getline(claveLogin, 20, '\n');
    while (fread(&obj, sizeof(Vendedores), 1, logeo) != 0) {
        if (strcmp(obj.getCorreo(), correoLogin) == 0 && strcmp(obj.getClave(), claveLogin) == 0) {
            inicio = true;
            cout << "Login realizado correctamente" << endl;
            fclose(logeo);
            system("pause");
            system("cls");
            return true;
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

};

#endif // CLASSVENDEDOR_H_INCLUDED
