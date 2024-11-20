#include <iostream>
#include "FuncionesDeclaraciones.h"
#include "ClassAuto.h"
#include <conio.h>
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
float recaudacionTotal=0;
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
    cout<<"7-)Recaudaciones"<<endl;
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
        system("cls");
        realizarVenta(recaudacionTotal);
        break;
    case 6:
        system("cls");
        editarMiCuenta();
        break;
    case 7:
        system("cls");
        recaudaciones(recaudacionTotal);
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
 cout << "Ingrese su clave: ";
    char ch;
    int index = 0;
    while (true) {
    ch = _getch();
    if (ch == 13) {
    claveBuscado[index] = '\0';
    break;
    }else if (ch == 8) {
     if (index > 0) {
     index--;
     cout << "\b \b";
    }
    }else{
    claveBuscado[index++] = ch;
    cout << "*";
    }
    }
cout << endl;
cout << "-----------------------------------------------------" << endl;
cout<<"Ingrese su DNI:";
cin>>DniBuscado;
cout<<"-------------------------------------------------------"<<endl;
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


//FUNCION PARA REALIZAR VENTA

void realizarVenta(float& recaudacionTotal) {
    int idV, idC, idA;
    cout << "Bienvenido al sector de ventas..." << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Por favor ingrese su id de vendedor: ";
    cin >> idV;
    cout << "-------------------------------------------------------" << endl;
    cout << "Por favor ingrese el id del cliente: ";
    cin >> idC;
    cout << "-------------------------------------------------------" << endl;
    cout << "Por favor ingrese el id del vehiculo: ";
    cin >> idA;
    cout << "-------------------------------------------------------" << endl;
    system("cls");
    cout << "CARGANDO FECHA DE LA VENTA"<<endl;
    cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    Fecha objFecha;
    objFecha.cargarFecha();
    cout << "CABEZERA"<<endl;
    cout << "---------------------------------------------------------------------------------------------------------------" << endl;
    cout<<"La fecha de venta es:";
    objFecha.mostrarFecha();
    cout << "Factura tipo: A"<<endl;
    objFecha.mostrarFecha();
    FILE* buscarVendedor = fopen("Vendedores.dat", "rb");
    if (buscarVendedor == NULL) {
        cout << "Error al buscar id del vendedor..." << endl;
        fclose(buscarVendedor);
        return;
    }
    Vendedores objVendedor;
    bool vendedorEncontrado = false;
    while (fread(&objVendedor, sizeof(Vendedores), 1, buscarVendedor) != 0) {
        if (idV == objVendedor.getIdVendedor()) {
            vendedorEncontrado = true;
    cout << "Vendedor que realizara la venta: " << objVendedor.getNombre() << endl;
    cout << "Email del vendedor que realizara la venta: " << objVendedor.getCorreo() << endl;
    cout << "DNI del vendedor que realizara la venta: " << objVendedor.getDni() << endl;
        break;
    }
    }
    if (!vendedorEncontrado) {
        cout << "Error al encontrar el vendedor" << endl;
        system("pause");
        system("cls");
        fclose(buscarVendedor);
        return;
    }
    FILE* buscarCliente = fopen("Clientes", "rb");
    if (buscarCliente == NULL) {
        cout << "Error al buscar id del cliente..." << endl;
        fclose(buscarCliente);
        return;
    }
    Clientes objClientes;
    bool clientesEncontrado = false;
    while (fread(&objClientes, sizeof(Clientes), 1, buscarCliente) != 0) {
        if (idC == objClientes.getIdCliente()) {
            clientesEncontrado = true;
            cout << "Cliente que realizara la compra: " << objClientes.getNombreCliente() << endl;
            cout << "Email del cliente que realizara la compra: " << objClientes.getCorreoCliente() << endl;
            cout << "DNI del cliente que realizara la compra: " << objClientes.getDni() << endl;
            cout << "Telefono del cliente que realizara la compra: " << objClientes.getTelefono() << endl;
            break;
        }
    }
    if (!clientesEncontrado) {
        cout << "Error al encontrar el cliente" << endl;
        system("pause");
        system("cls");
        fclose(buscarCliente);
        return;
    }
    cout << endl;
    cout << "DETALLE DE LA VENTA" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------" << endl;

    FILE* buscarVehiculo = fopen("Vehiculo.dat", "rb");
    if (buscarVehiculo == NULL) {
        cout << "Error al buscar id del vehiculo..." << endl;
        fclose(buscarVehiculo);
        return;
    }
    Auto objAuto;
    bool autoEncontrado = false;
    while (fread(&objAuto, sizeof(Auto), 1, buscarVehiculo) != 0) {
        if (idA == objAuto.getId()) {
            autoEncontrado = true;
            cout << "Nombre del auto: " << objAuto.getNombreAuto() << endl;
            cout << "Marca del auto: " << objAuto.getMarcaAuto() << endl;
            cout << "Precio del auto: " << objAuto.getPrecioAuto() << endl;
            cout << "Fecha de fabricacion del auto: " << objAuto.getAnioAuto() << endl;
    recaudacionTotal+=objAuto.getPrecioAuto();
            break;
        }
    }

    if (!autoEncontrado) {
        cout << "Error al encontrar el vehiculo" << endl;
        system("pause");
        system("cls");
        fclose(buscarVehiculo);
        return;
    }
    cout << "Factura generada..." << endl;
    system("pause");
    fclose(buscarCliente);
    fclose(buscarVehiculo);
    fclose(buscarVendedor);
}



//FUNCION PARA RECAUDACIONES

void recaudaciones(float& recaudacionTotal){
int opcion;
while(true){

cout<<"Menu de recaudaciones"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"1-)Recaudacion total"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"2_)Recaudacion por mes"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"0-)Salir..."<<endl;
cin>>opcion;

switch(opcion){
case 0:
    system("cls");
    menuDeVendedores();
    break;

case 1:
    system("cls");
    recaudacionTotal1(recaudacionTotal);
    break;

case 2:
    system("cls");
    break;

}
}
}

//FUNCION ´PARA RECAUDACION TOTAL

void recaudacionTotal1 (float& recaudacionTotal){
cout<<"Recaudacion total"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"La recaudacion total de todas las ventas es: "<<recaudacionTotal<<endl;
system("pause");
system("cls");
}
