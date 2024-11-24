#ifndef FUNCIONESDECLARACIONES_H_INCLUDED
#define FUNCIONESDECLARACIONES_H_INCLUDED
#include "ClassVendedor.h"
#include "ClassClientes.h"
#include "ClassFecha.h"
#include "ClassRecaudaciones.h"
#include "ClassAuto.h"
#include "ClassAdministrador.h"
#include "ClassTicket.h"

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
void generarSolicutudDeAlta();


#endif // FUNCIONESDECLARACIONES_H_INCLUDED
