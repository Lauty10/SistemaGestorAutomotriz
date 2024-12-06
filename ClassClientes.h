#ifndef CLASSCLIENTES_H_INCLUDED
#define CLASSCLIENTES_H_INCLUDED
#include <string.h>
#include "FuncionesDeclaraciones.h"

void menuDeVendedores(int id);
void menu();
void usuarioLogeado(int id);
void GraficarOpiciones(const char*,int,int,bool,int,int);
void GraficarLineasHorizontales(int,int,int,bool,int);

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
void setIdCliente(int idC);
void setNombreCliente(const char nombreC[30]);
void setDni(int dniC);
void setCorreoCliente(const char correoC[35]);
void setTelefono(const char tel[14]);
const char* getTelefono();
int getIdCliente();
const char* getNombreCliente();
int getDni();
const char* getCorreoCliente();
void setEstado(bool e);
bool getEstado();
void menuClientes(int id);
void cargarCliente();
void darDeAltaCliente(Clientes objCliente);
void listarClientes();
void darDeBajaCliente();
void buscarCliente();
void modificarCliente(int id);
void editarNombre();
void editarCorreo();
void editarTelefono();
void editarDni();
void nombre( char* nom);
void correo(char* dato);
void telefono1( char* tel);
void dni1(int d);
void estilo();
int generarIdCliente();
};



#endif // CLASSCLIENTES_H_INCLUDED
