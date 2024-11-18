#include <iostream>
#include "FuncionesDeclaraciones.h"

using namespace std;

//FUNCIONES EJECUTADAS
void menu(){
int opcion;
bool logeo;
Vendedores obj;
while(true){
    cout<<"BIENVENIDO AL MENU PRINCIPAL...."<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"1-)Registrarse"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"2-)Iniciar sesion"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"3-)Recuperar contraseña"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"0-)Salir del programa"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Ingrese la opcion que desee:";
    cin>>opcion;
    switch(opcion){
case 0:
    break;
case 1:
    system("cls");
    obj.cargarVendedor();
    obj.registrarVendedor(obj);
    break;
case 2:
    system("cls");
    logeo=obj.iniciarSesion();
    if(logeo==true){
        system("cls");
        menuDeVendedores();
    }
    break;
case 3:
    break;
default:
    cout<<"Esta opcion no existe"<<endl;
    }
}
}

//MENU DE VENDEDORES
void menuDeVendedores(){
Clientes objCliente;
int opcion;
while(true){
    cout<<"Bienvenido al menu de vendedores.........."<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"1-)Clientes"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"2-)Vendedores"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"3-)Autos"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"4-)Facturaciones"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"5-)Mi cuenta"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"0-)Salir..."<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Ingrese la opcion que desee:";
    cin>>opcion;
    switch(opcion){
    case 0:
        break;
    case 1:
        system("cls");
        objCliente.menuClientes();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;
    }
}
}

