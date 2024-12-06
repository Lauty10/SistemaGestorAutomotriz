#ifndef CLASSVENDEDOR_H_INCLUDED
#define CLASSVENDEDOR_H_INCLUDED
#include <cstring>
#include <string.h>
#include <conio.h>
#include "rlutil.h"

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
void setId(int idV);
void setNombre(char nombre[30]);
void setDni(int dni);
void setCorreo(char correo[35]);
void setClave(char clave[20]);
void setRol(char rol[6]);
void setEstado(bool est=false);
int getIdVendedor();
const char* getNombre();
int getDni();
const char* getCorreo();
const char* getClave();
const char* getRol();
bool getEstado();
void cargarVendedor();
int generarIdVendedor();
void registrarVendedor(Vendedores obj);
int iniciarSesion();
void funcionalidadesVendedor(int id);
void bajaVendedores();
void listarVendedores();
void buscarVendedor();
void menuMiCuenta();
void editarMiNombre();
void editarMiCorreo();
void editarMiClave();
void editarDni();
void nombreV(char* nV);
void dniV(int d);
void correoV(char* cV);
void c2(char* c);
void estiloV();

};

#endif // CLASSVENDEDOR_H_INCLUDED
