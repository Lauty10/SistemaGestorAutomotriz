#ifndef CLASSAUTO_H_INCLUDED
#define CLASSAUTO_H_INCLUDED
#include <string.h>

using namespace std;

class Auto{
private:
int idDelAuto;
char nombreAuto[20];
char marcaAuto[20];
float precioAuto;
bool estado;

public:
Auto(int id=0, const char* nombreA="XXX", const char* marcaA="XXX", float precioA=0.0, bool estado=true){
this->idDelAuto=id;
strcpy(this->nombreAuto,nombreA);
strcpy(this->marcaAuto,marcaA);
this->precioAuto=precioA;
this-> estado=estado;
}
void setIdAuto(int id);
void setNombreAuto(char nombreA[20]);
void setMarcaAuto(char marcaA[20]);
void setPrecioAuto(float precioA);
void setEstado(bool estadoA=false);
int getId();
const char* getNombreAuto();
const char* getMarcaAuto();
float getPrecioAuto();
bool getEstado();
void menuAutos(int id);
void altaAuto();
int generarIdAuto();
void modificarAutos(int id);
void modificarNombre();
void modificarMarca();
void modificarPrecio();
void darBaja();
void listarVehiculos();
void buscarVehiculo();
void NombreV(char* n);
bool precioV(float p);
void marcaV(char* m);
void fechaV(char* f);
void estiloAuto();
};

#endif // CLASSAUTO_H_INCLUDED
