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
    system("cls");
    recuperarClave();
    break;

default:
    cout<<"Esta opcion no existe"<<endl;
    }
}
}

//FUNCION PARA RECUPERAR CLAVE
void recuperarClave(){
FILE *clave;
clave=fopen("Vendedores.dat","rb+");
if(clave==nullptr){
cout<<"ERROR AL INTENTAR ABRIR EL ARCHIVO DE REGISTROS"<<endl;
return; }
Vendedores objC;
int dni;
char correo[30];
char nuevaClave[30];
bool encontrado=false;
cout<<"Ingrese los siguientes datos para recuperar su clave: "<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"D.N.I: ";
cin>>dni;
cout<<"Correo: ";
cin.ignore();
cin.getline(correo,30,'\n');
while(fread(&objC, sizeof(Vendedores),1,clave)!=0){
if(strcmp(objC.getCorreo(),correo)==0 && objC.getDni()==dni) {
cout<<"Ingrese su nueva Clave:";
cin.ignore();
cin.getline(nuevaClave,30,'\n');
objC.setClave(nuevaClave);
long pos=ftell(clave)-sizeof(Vendedores);
fseek(clave,pos,SEEK_CUR);
fwrite(&objC, sizeof(Vendedores), 1, clave);
cout << "Su nueva clave fue guardada con exito" << endl;
encontrado=true;
break; }
}
if(!encontrado){
cout<<"LOS DATOS INGRESADOS NO ESTAN EN LA BASE DE DATOS"<<endl;
 }
fclose(clave);
system("pause");
system("cls");
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
        system("cls");
        recaudaciones();
        break;
    case 5:
        system("cls");
        realizarVenta();
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

void realizarVenta() {
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
    Recaudacion objRecaudacion;
    Fecha objFecha;
    objFecha.cargarFecha();
    int fechaAnio=objFecha.getAnio();
    int fechaMes=objFecha.getMes();
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
        if (idV == objVendedor.getIdVendedor() && objVendedor.getEstado()) {
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
        if (idC == objClientes.getIdCliente() && objClientes.getEstado()==true) {
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

    FILE* buscarVehiculo = fopen("Vehiculo.dat", "rb+");
    if (buscarVehiculo == NULL) {
        cout << "Error al buscar id del vehiculo..." << endl;
        fclose(buscarVehiculo);
        return;
    }
    Auto objAuto;
    bool autoEncontrado = false;
    while (fread(&objAuto, sizeof(Auto), 1, buscarVehiculo) != 0) {
        if (idA == objAuto.getId()){
            if(objAuto.getEstado()==true){
            long posicion=ftell(buscarVehiculo)-sizeof(Auto);
            autoEncontrado = true;
            objAuto.setEstado(false);
            fseek(buscarVehiculo,posicion,SEEK_SET);
            fwrite(&objAuto,sizeof(Auto),1,buscarVehiculo);
            cout << "Nombre del auto: " << objAuto.getNombreAuto() << endl;
            cout << "Marca del auto: " << objAuto.getMarcaAuto() << endl;
            cout << "Precio del auto: " << objAuto.getPrecioAuto() << endl;
            int guardarValor=objAuto.getPrecioAuto();
            cout << "Fecha de fabricacion del auto: " << objAuto.getAnioAuto() << endl;
            cout<<endl;
            cout << "---------------------------------------------------------------------------------------------------------------" << endl;
            int meses[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
            for(int j=0;j<=12;j++){
                if(fechaMes==meses[j]){
                    switch(fechaMes){
                case 0:
                cout<<"Error 0..."<<endl;
                    break;
                case 1:
                    cout<<"Esta factura corresponde al mes de "<<"Enero"<<" y al anio "<<fechaAnio<<endl;
                    objRecaudacion.cargarRecaudacion(guardarValor,fechaMes,fechaAnio);
                    break;
                case 2:
                    cout<<"Esta factura corresponde al mes de "<<"Febrero"<<" y al anio "<<fechaAnio<<endl;
                       objRecaudacion.cargarRecaudacion(guardarValor,fechaMes,fechaAnio);
                    break;
                case 3:
                    cout<<"Esta factura corresponde al mes de "<<"Marzo"<<" y al anio "<<fechaAnio<<endl;
                       objRecaudacion.cargarRecaudacion(guardarValor,fechaMes,fechaAnio);
                    break;
                case 4:
                    cout<<"Esta factura corresponde al mes de "<<"Abril"<<" y al anio "<<fechaAnio<<endl;
                       objRecaudacion.cargarRecaudacion(guardarValor,fechaMes,fechaAnio);
                    break;
                case 5:
                    cout<<"Esta factura corresponde al mes de "<<"Mayo"<<" y al anio "<<fechaAnio<<endl;
                       objRecaudacion.cargarRecaudacion(guardarValor,fechaMes,fechaAnio);
                    break;
                case 6:
                    cout<<"Esta factura corresponde al mes de "<<"Junio"<<" y al anio "<<fechaAnio<<endl;
                       objRecaudacion.cargarRecaudacion(guardarValor,fechaMes,fechaAnio);
                    break;
                case 7:
                    cout<<"Esta factura corresponde al mes de "<<"Julio"<<" y al anio "<<fechaAnio<<endl;
                       objRecaudacion.cargarRecaudacion(guardarValor,fechaMes,fechaAnio);
                    break;
                case 8:
                    cout<<"Esta factura corresponde al mes de "<<"Agosto"<<" y al anio "<<fechaAnio<<endl;
                       objRecaudacion.cargarRecaudacion(guardarValor,fechaMes,fechaAnio);
                    break;
                case 9:
                    cout<<"Esta factura corresponde al mes de "<<"Septiembre"<<" y al anio "<<fechaAnio<<endl;
                       objRecaudacion.cargarRecaudacion(guardarValor,fechaMes,fechaAnio);
                    break;
                case 10:
                    cout<<"Esta factura corresponde al mes de "<<"Octubre"<<" y al anio "<<fechaAnio<<endl;
                       objRecaudacion.cargarRecaudacion(guardarValor,fechaMes,fechaAnio);
                    break;
                case 11:
                    cout<<"Esta factura corresponde al mes de "<<"Noviembre"<<" y al anio "<<fechaAnio<<endl;
                       objRecaudacion.cargarRecaudacion(guardarValor,fechaMes,fechaAnio);
                    break;
                case 12:
                    cout<<"Esta factura corresponde al mes de "<<"Diciembre"<<" y al anio "<<fechaAnio<<endl;
                       objRecaudacion.cargarRecaudacion(guardarValor,fechaMes,fechaAnio);
                    break;
                    }
                }
            }
            break;
            }else{
            cout<<"El auto seleccionado se encuentra dado baja del sistema, no puede realizarse la venta..."<<endl;
            system("pause");
            system("cls");
            return;
            }
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
    system("cls");
    fclose(buscarCliente);
    fclose(buscarVehiculo);
    fclose(buscarVendedor);
}



//FUNCION PARA RECAUDACIONES
void recaudaciones(){
int opcion;
while(true){
cout<<"Menu de recaudaciones..."<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"1-)Recaudacion total"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"2_)Recaudacion por mes"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"0-)Salir"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"Ingrese la opcion que desee:";
cin>>opcion;

switch(opcion){
case 0:
    system("cls");
    menuDeVendedores();
    break;

case 1:
    system("cls");
    break;

case 2:
    system("cls");
    break;
}
}
}

//FUNCION ´PARA RECAUDACION TOTAL

