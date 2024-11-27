#ifndef FUNCIONESDECLARACIONES_H_INCLUDED
#define FUNCIONESDECLARACIONES_H_INCLUDED
#include "ClassVendedor.h"
#include "ClassClientes.h"
#include "ClassFecha.h"
#include "ClassRecaudaciones.h"
#include "ClassAuto.h"
#include "ClassAdministrador.h"
#include "ClassTicket.h"
#include "ClassSolicitudAlta.h"
#include "rlutil.h"

void menu();
void menuDeVendedores(int id);
void editarMiCuenta();
void realizarVenta(int id);
void recaudaciones(int id);
void recuperarClave();
int numeroDeVenta();
void recaudacionTotal();
void recaudacionMesyAnio();
void menuDeSoporte();
void bienvenidoUsuario(int id);
int generarId();
void estadoDeMiSolicitud();
void validacion1(int d);
void validacion2(char* c);
void validacion3(char* clave);
void validarId(int i);

void GraficarOpiciones(const char*,int,int,bool,int,int);
void GraficarCeldas(int,int,int,const char*);
void GraficarLineasHorizontales(int,int,int,bool,int);
void GraficarLineasVerticales(int,int,int,int,int);
void Borrar(int,int,int,int);
void Dibujar_Cuadro_Login();
int Mover_Cursor_Teclas(int,int);


#endif // FUNCIONESDECLARACIONES_H_INCLUDED
