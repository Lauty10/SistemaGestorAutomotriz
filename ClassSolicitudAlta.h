#ifndef CLASSSOLICITUDALTA_H_INCLUDED
#define CLASSSOLICITUDALTA_H_INCLUDED
#include <string.h>

class Solicitud{
private:
    char nombre[30];
    char correo[35];
    char clave[20];
    char dni[10];
    bool estado;
    bool aprobado;
    int id;
public:
    Solicitud(const char* n="XXX", const char* c="XXX", const char* cl="NuevoVendedor", const char* dni="XXXX-XXXX", bool e=false, bool a=false,int i=0){
    strcpy(this->nombre,n);
    strcpy(this->correo,c);
    strcpy(this->clave,cl);
    strcpy(this->dni,dni);
    this->estado=e;
    this->aprobado=a;
    this->id=i;
    }
void setNombre(char n[30]);
void setCorreo(char c[35]);
void setClave(char cl[20]);
void setDni(char dni[9]);
void setEstado(bool e);
void setAprobado(bool a);
const char* getNombre();
const char* getCorreo();
const char* getClave();
const char* getDni();
bool getEstado();
bool getAprobado();
void setId(int idN);
int getId();
bool abrir_crear_arch_solicitud();

void cargarSolicitud();
void nuevaSolicitud(Solicitud objS);
int generarIdSolicitud();
void aprobarSolicitudDeAlta();
int validarC(char* c);
bool validarNombre(char* n);
int validarD(char* d);
void listarSolicitudes();
void estiloV();

};

#endif // CLASSSOLICITUDALTA_H_INCLUDED
