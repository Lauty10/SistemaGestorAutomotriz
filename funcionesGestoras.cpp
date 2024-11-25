#include <iostream>
#include "FuncionesDeclaraciones.h"
#include <conio.h>

using namespace std;

//FUNCIONES EJECUTADAS

void menu(){
Vendedores obj;
Administrador objA;
Solicitud objS;
int opcion,logeo;
bool logeoAdmin;
int idLogeado;
rlutil::setColor(15);
rlutil::setBackgroundColor(9);
rlutil::setColor(rlutil::WHITE);
rlutil::cls();
for(int j=1;j<121;j++){
        rlutil::locate(j,1);
         cout<<char(176);
}

for(int j=1;j<121;j++){
        rlutil::locate(j,30);
         cout<<char(176);
}

for(int j=20;j<100;j++){
        rlutil::locate(j,3);
         cout<<"-";
}
for(int j=20;j<100;j++){
        rlutil::locate(j,27);
         cout<<"-";
}

while(true){
    rlutil::locate(45,7);
    cout<<"BIENVENIDO AL MENU PRINCIPAL"<<endl;
    rlutil::locate(45,9);
    cout<<"1-)Iniciar sesion"<<endl;
    rlutil::locate(45,11);
    cout<<"2-)Recuperar clave"<<endl;
    rlutil::locate(45,13);
    cout<<"3-)Generar solicitud de alta en el sistema"<<endl;
    rlutil::locate(45,15);
    cout<<"4-)Ver estado de mi solicitud"<<endl;
    rlutil::locate(45,17);
    cout<<"5-)Soporte"<<endl;
    rlutil::locate(45,19);
    cout<<"0-)Salir del programa"<<endl;
    rlutil::locate(45,22);
    cout<<"Ingrese la opcion que desee:";
    cin>>opcion;
    switch(opcion){
case 0:
    return;
case 1:
    system("cls");
    logeo=obj.iniciarSesion();
    if(logeo!=0){
        system("cls");
        menuDeVendedores(logeo);
    }
    break;
case 2:
    system("cls");
    recuperarClave();
    break;
case 3:
    system("cls");
    objS.cargarSolicitud();
    objS.nuevaSolicitud(objS);
    break;
case 4:
    system("cls");
    estadoDeMiSolicitud();
     system("cls");
    break;
case 5:
    system("cls");
    logeoAdmin=objA.logeoDeUsuariosAdministradores();
    if(logeoAdmin==true){
        system("cls");
        menuDeSoporte();
    }
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
void menuDeVendedores(int id){
Clientes objCliente;
Vendedores objVendedores;
Auto objAuto;
TicketAdmin objT;
int opcion;
while(true){
    rlutil::locate(3,2);
    bienvenidoUsuario(id);
    rlutil::locate(45,7);
    cout<<"1-)Clientes"<<endl;
     rlutil::locate(45,9);
    cout<<"2-)Vendedores"<<endl;
     rlutil::locate(45,11);
    cout<<"3-)Autos"<<endl;
     rlutil::locate(45,13);
    cout<<"4-)Recaudaciones"<<endl;
     rlutil::locate(45,15);
    cout<<"5-)Realizar Venta"<<endl;
     rlutil::locate(45,17);
    cout<<"6-)Generar Ticket para soporte"<<endl;
     rlutil::locate(45,19);
    cout<<"0-)Salir..."<<endl;
     rlutil::locate(45,21);
    cout<<"Ingrese la opcion que desee:";
    cin>>opcion;
    switch(opcion){
    case 0:
        system("cls");
        menu();
        break;
    case 1:
        system("cls");
        objCliente.menuClientes(id);
        break;
    case 2:
        system("cls");
        objVendedores.funcionalidadesVendedor(id);
        break;
    case 3:
        system("cls");
        objAuto.menuAutos(id);
        break;
    case 4:
        system("cls");
        recaudaciones(id);
        break;
    case 5:
        system("cls");
        realizarVenta(id);
        break;
    case 6:
        system("cls");
        objT.generarTicket(id);
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;
    }
}
}


//FUNCION PARA REALIZAR VENTA

void realizarVenta(int idV) {
    int idC, idA;
    cout << "Bienvenido al sector de ventas..." << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Por favor ingrese el id del cliente: ";
    cin >> idC;
    cout << "-------------------------------------------------------" << endl;
    cout << "Por favor ingrese el id del vehiculo: ";
    cin >> idA;
    cout << "-------------------------------------------------------" << endl;
    cout<<endl;
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
    cout<<"Numero de factura:"<<numeroDeVenta()<<endl;
    FILE* buscarVendedor = fopen("Vendedores.dat", "rb");
    if (buscarVendedor == NULL) {
        cout << "Error al buscar id del vendedor..." << endl;
        fclose(buscarVendedor);
        return;
    }
    Vendedores objVendedor;
    int idParaRecaudacion;
    bool vendedorEncontrado = false;
    while (fread(&objVendedor, sizeof(Vendedores), 1, buscarVendedor) != 0) {
        if (idV == objVendedor.getIdVendedor() && objVendedor.getEstado()) {
            vendedorEncontrado = true;
           idParaRecaudacion=objVendedor.getIdVendedor();
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
            cout << "Fecha de fabricacion del auto: " << objAuto.getAnioAuto() << endl;
            cout<<endl;
            cout << "---------------------------------------------------------------------------------------------------------------" << endl;
            int guardarValor=objAuto.getPrecioAuto();
            objRecaudacion.cargarRecaudacion(guardarValor,fechaMes,fechaAnio,idParaRecaudacion);
            int meses[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
            for(int j=0;j<=12;j++){
                if(fechaMes==meses[j]){
                    switch(fechaMes){
                case 0:
                cout<<"Error 0..."<<endl;
                    break;
                case 1:
                    cout<<"Esta factura corresponde al mes de "<<"Enero"<<" y al anio "<<fechaAnio<<endl;
                    break;
                case 2:
                    cout<<"Esta factura corresponde al mes de "<<"Febrero"<<" y al anio "<<fechaAnio<<endl;
                    break;
                case 3:
                    cout<<"Esta factura corresponde al mes de "<<"Marzo"<<" y al anio "<<fechaAnio<<endl;
                    break;
                case 4:
                    cout<<"Esta factura corresponde al mes de "<<"Abril"<<" y al anio "<<fechaAnio<<endl;
                    break;
                case 5:
                    cout<<"Esta factura corresponde al mes de "<<"Mayo"<<" y al anio "<<fechaAnio<<endl;
                    break;
                case 6:
                    cout<<"Esta factura corresponde al mes de "<<"Junio"<<" y al anio "<<fechaAnio<<endl;
                    break;
                case 7:
                    cout<<"Esta factura corresponde al mes de "<<"Julio"<<" y al anio "<<fechaAnio<<endl;
                    break;
                case 8:
                    cout<<"Esta factura corresponde al mes de "<<"Agosto"<<" y al anio "<<fechaAnio<<endl;
                    break;
                case 9:
                    cout<<"Esta factura corresponde al mes de "<<"Septiembre"<<" y al anio "<<fechaAnio<<endl;
                    break;
                case 10:
                    cout<<"Esta factura corresponde al mes de "<<"Octubre"<<" y al anio "<<fechaAnio<<endl;
                    break;
                case 11:
                    cout<<"Esta factura corresponde al mes de "<<"Noviembre"<<" y al anio "<<fechaAnio<<endl;
                    break;
                case 12:
                    cout<<"Esta factura corresponde al mes de "<<"Diciembre"<<" y al anio "<<fechaAnio<<endl;
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
void recaudaciones(int id){
int opcion;
while(true){
cout<<"Menu de recaudaciones..."<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"1-)Recaudacion total"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"2-)Recaudacion por mes y anio"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"3-)Recaudacion por anio"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"4-)Recaudacion por id de vendedor"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"0-)Salir"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"Ingrese la opcion que desee:";
cin>>opcion;
Recaudacion obj;
switch(opcion){
case 0:
    system("cls");
    menuDeVendedores(id);
    break;
case 1:
    system("cls");
    obj.recaudacionTotal();
    break;
case 2:
    system("cls");
    obj.recaudacionMesyAnio();
    break;
case 3:
    system("cls");
    obj.recaudacionXanio();
    break;
case 4:
    system("cls");
    obj.recaudacionPorId();
    system("cls");
    break;
default:
    cout<<"Esta opcion es incorrecta..."<<endl;
}
}
}

int numeroDeVenta() {
    FILE *numeroDeFactura;
    int venta = 0;
    numeroDeFactura = fopen("Recaudaciones.dat", "rb");
    if (numeroDeFactura == NULL) {
        return 1000001;
    }
    Recaudacion obj;
    while (fread(&obj, sizeof(Recaudacion), 1, numeroDeFactura) != 0) {
        venta++;
    }
    fclose(numeroDeFactura);
    return venta + 1000000;
}

//Menu de Soporte
void menuDeSoporte(){
Vendedores objV;
Administrador objA;
TicketAdmin objT;
Solicitud objS;
int opcion;
while(true){
cout<<"Bienvenido al menu de soporte..."<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"-1)Dar de alta vendedores"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"-2)Dar de baja vendedores"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"-3)Editar vendedores"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"-4)Mostrar tickets generados en el sistema de soporte"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"-5)Mostrar solicitudes de alta"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"-6)Aprobar solicitudes de alta"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"-7)Cerrar ticket"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"-8)Listar vendedores"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"-0)Salir"<<endl;
cout<<"-----------------------------------------------------"<<endl;
cout<<"Eliga la opcion que desee:";
cin>>opcion;
switch(opcion){
case 0:
    system("cls");
    menu();
    break;
case 1:
    system("cls");
    objV.cargarVendedor();
    objV.registrarVendedor(objV);
    break;
case 2:
    system("cls");
    objV.bajaVendedores();
    break;
case 3:
    system("cls");
    objV.menuMiCuenta();
    break;
case 4:
    system("cls");
    objT.mostrarTickets();
    break;
case 5:
    system("cls");
    objS.listarSolicitudes();
    break;
case 6:
    system("cls");
    objS.aprobarSolicitudDeAlta();
    break;
case 7:
    system("cls");
    objT.darDeBajaTickets();
    break;
case 8:
    system("cls");
    objV.listarVendedores();
    break;
}
}
}

void estadoDeMiSolicitud(){
FILE *buscarMiSolicitud;
buscarMiSolicitud=fopen("Solicitud.dat","rb+");
if(buscarMiSolicitud==NULL){
    cout<<"Error al encontrar su solicitud"<<endl;
    return;
}
Solicitud objS;
Vendedores objV;
int idS;
cout<<"Ingrese el ID de su solicitud:";
cin>>idS;
char nombre[30];
char correo[35];
int dni;
char clave[20];
char clave2[20];
int id;
while(fread(&objS,sizeof(Solicitud),1,buscarMiSolicitud)!=0){
    if(idS==objS.getIdSolicitud()){
        if(objS.getAprobado()==true){
        strcpy(nombre,objS.getNombre());
        strcpy(correo,objS.getCorreo());
        dni=objS.getDni();
        long posicion = ftell(buscarMiSolicitud) - sizeof(Solicitud);
        objS.setAprobado(false);
        fseek(buscarMiSolicitud, posicion, SEEK_SET);
        fwrite(&objS,sizeof(Solicitud),1,buscarMiSolicitud);
        cout<<"Solicitud aprobada..."<<endl;
        system("pause");
        system("cls");
        break;
        }else{
        cout<<"La solicitud ya fue aprobada o no se encontro en nuestro sistema..."<<endl;
        system("pause");
        system("cls");
        return;
        }
        }
        }
system("pause");
system("cls");

FILE *Nuevoalta;
Nuevoalta=fopen("Vendedores.dat","ab");
if(Nuevoalta==NULL){
    cout<<"Error al dar de alta"<<endl;
    fclose(Nuevoalta);
    return;
}
cout<<"Ingrese su clave para terminar su alta:";
cin.ignore();
cin.getline(clave,20,'\n');

cout<<"Vuelva a ingresar su clave:";
cin.getline(clave2,20,'\n');

if(strcmp(clave,clave2)==0){
 id=generarId();
 objV.setNombre(nombre);
 objV.setId(id);
 objV.setCorreo(correo);
 objV.setClave(clave);
 objV.setDni(dni);
 fwrite(&objV,sizeof(Vendedores),1,Nuevoalta);
 cout<<"Proceso finalizado fue dato de alta en el sistema correctamente"<<endl;
 fclose(Nuevoalta);
}
fclose(buscarMiSolicitud);
system("pause");
system("cls");
}



 int generarId(){
   FILE *generar;
   int dato=0;
   generar=fopen("Vendedores.dat","rb");
   if(generar==NULL){
    dato=1;
    fclose(generar);
    return dato;
   }
   Vendedores obj;
   while(fread(&obj,sizeof(Vendedores),1,generar)!=0){
    dato++;
   }
   fclose(generar);
   return dato+1;
    }


void bienvenidoUsuario(int id){
FILE *buscarVendedor;
buscarVendedor=fopen("Vendedores.dat","rb");
if(buscarVendedor==NULL){
    cout<<"Error al encontrar vendedor..."<<endl;
}
Vendedores obj;
char nombre[35];
while(fread(&obj,sizeof(Vendedores),1,buscarVendedor)!=0){
    if(id==obj.getIdVendedor()){
        strcpy(nombre,obj.getNombre());
    }
}
cout<<"Bienvenido al sistema "<<nombre<<endl;
fclose(buscarVendedor);
}



