#include <iostream>
#include "FuncionesDeclaraciones.h"
#include "ClassAuto.h"
using namespace std;

//FUNCIONES EJECUTADAS
void menu(){
int opcion;
bool logeo;
Vendedores obj;
int idLogeado;
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
Vendedores objVendedores;
Auto objAuto;
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
    cout<<"5-)Realizar Venta"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"6-)Mi cuenta"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"0-)Salir..."<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Ingrese la opcion que desee:";
    cin>>opcion;
    switch(opcion){
    case 0:
        menu();
        break;
    case 1:
        system("cls");
        objCliente.menuClientes();
        break;
    case 2:
        system("cls");
        objVendedores.funcionalidadesVendedor();
        break;
    case 3:
        system("cls");
        objAuto.menuAutos();
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        system("cls");
        editarMiCuenta();
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;
    }
}
}

//Editar mi cuenta
void editarMiCuenta(){
char correoBuscado[35];
char claveBuscado[20];
int DniBuscado;
cout<<"Por favor ingrese los datos solicitados para validar su identidad..."<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"Ingrese su correo:";
cin.ignore();
cin.getline(correoBuscado,35,'\n');
cout<<"-----------------------------------------------------"<<endl;
cout<<"Ingrese su clave:";
cin.getline(claveBuscado,20,'\n');
cout<<"-----------------------------------------------------"<<endl;
cout<<"Ingrese su DNI:";
cin>>DniBuscado;
cout<<"-----------------------------------------------------"<<endl;
FILE *buscar;
buscar=fopen("Vendedores.dat","rb");
if(buscar==NULL){
    cout<<"Error al entrar al archivo de Vendedores"<<endl;
}
Vendedores objV;
while(fread(&objV,sizeof(Vendedores),1,buscar)!=0){
    if(strcmp(objV.getCorreo(),correoBuscado)==0 && strcmp(objV.getClave(),claveBuscado)==0 && objV.getDni()==DniBuscado){
        if(objV.getEstado()==true){
                fclose(buscar);
                int idDelVendedor;
                char nombreObtenido[30];
                idDelVendedor=objV.getIdVendedor();
                const char *nombre=objV.getNombre();
                strcpy(nombreObtenido,nombre);
                system("cls");
                objV.menuMiCuenta(idDelVendedor,nombreObtenido);
        }else{
        cout<<"El vendedor se encuentra dado de baja en el sistema..."<<endl;
        system("pause");
        system("cls");
        break;
        }
    }
}
fclose(buscar);
}



