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
void setNombre(char n[30]);
void setCorreo(char c[35]);
void setClave(char cl[20]);
void setDni(int d);
void setEstado(bool e);
void setAprobado(bool a);
const char* getNombre();
const char* getCorreo();
const char* getClave();
int getDni();
bool getEstado();
bool getAprobado();
void setId(int idN);
int getId();
void cargarSolicitud();
void nuevaSolicitud(Solicitud objS);
int generarIdSolicitud();
void aprobarSolicitudDeAlta();
void validarC(char* c);
void validarN(char* n);
void validarD(int d);
void listarSolicitudes();
void estiloV();

};

#endif // CLASSSOLICITUDALTA_H_INCLUDED
