#include <iostream>
#include "FuncionesDeclaraciones.h"
#include <conio.h>

using namespace std;

//FUNCIONES EJECUTADAS

void menu(){
Vendedores obj;
Administrador objA;
Solicitud objSolicitud;
int opcion,logeo, y=0;
bool logeoAdmin=false;;
int idLogeado;
bool control_del_menu=true;
rlutil::setColor(15);
rlutil::setBackgroundColor(rlutil::BLACK);
rlutil::setColor(rlutil::WHITE);
rlutil::cls();
do{
rlutil::setBackgroundColor(rlutil::BLACK);
rlutil::setColor(rlutil::WHITE);
for(int j=1;j<121;j++){
    rlutil::locate(j,1);
    cout<<char(176);
}
for(int j=1;j<121;j++){
    rlutil::locate(j,30);
    cout<<char(176);
}
rlutil::locate(40,6);
cout<<" GROUP 51 CAR CENTER"<<endl;
rlutil::locate(35,7);
cout<<"-------------------------------------------------------------"<<endl;
rlutil::locate(55,8);
cout<<"BIENVENIDO AL SISTEMA GESTOR"<<endl;
rlutil::hidecursor();
GraficarOpiciones(" INICIAR SESION ",45,11,y==0,15,0);
GraficarOpiciones(" OLVIDE MI CLAVE ",45,13,y==1,15,0);
GraficarOpiciones(" GENERAR SOLICITUD DE ALTA EN EL SISTEMA ",45,15,y==2,15,0);
GraficarOpiciones(" VER ESTADO DE MI SOLICITUD ",45,17,y==3,15,0);
GraficarOpiciones(" SOPORTE ",45,19,y==4,15,0);
GraficarOpiciones(" SALIR ",45,21,y==5,15,0);
switch(rlutil::getkey()){
case 14:
    y--;
    if(y<0){
        y=0;
    }
    break;
case 15:
    y++;
    if(y>5){
        y=0;
    }
    break;
case 1:
       switch(y){
   case 0:
        system("cls");
        rlutil::showcursor();
        Dibujar_Cuadro_Login();
        logeo=obj.iniciarSesion();
        if(logeo!=0){
        system("cls");
        menuDeVendedores(logeo);
        }
    break;
   case 1:
        system("cls");
        recuperarClave();
    break;
   case 2:
        system("cls");
        objSolicitud.cargarSolicitud();
        objSolicitud.nuevaSolicitud(objSolicitud);
    break;
   case 3:
       system("cls");
       estadoDeMiSolicitud();
       system("cls");
    break;
   case 4:
       rlutil::setBackgroundColor(rlutil::BLACK);
       system("cls");
       rlutil::setBackgroundColor(rlutil::BLACK);
       rlutil::setColor(10);
       Dibujar_Cuadro_Login();
       logeoAdmin=objA.logeoDeUsuariosAdministradores();
       if(logeoAdmin==true){
       system("cls");
       menuDeSoporte();
       }
       else{cout<<"Credenciales incorrectas";}
    break;
   case 5:
       system("cls");
       control_del_menu=false;
       system("pause");
    break;
   }
break;
}
}while(control_del_menu);

}

//FUNCION PARA RECUPERAR CLAVE
void recuperarClave(){
FILE *clave;
clave=fopen("Vendedores.dat","rb+");
if(clave==nullptr){
rlutil::locate(1,3);
cout<<"ERROR AL INTENTAR ABRIR EL ARCHIVO DE REGISTROS"<<endl;
return; }
Vendedores objC;
int dni;
char correo[30];
char nuevaClave[30];
bool encontrado=false;
rlutil::locate(45,3);
cout<<"Ingrese los siguientes datos para recuperar su clave: "<<endl;
rlutil::locate(45,4);
cout<<"-----------------------------------------------------"<<endl;
rlutil::locate(45,6);
cout<<"D.N.I: ";
cin>>dni;
while(dni==0){
rlutil::locate(45,7);
cout<<"Campo icompleto"<<endl;
rlutil::locate(51,6);
cin>>dni;
}

rlutil::locate(45,8);
cout<<"Correo: ";
cin.ignore();
cin.getline(correo,30,'\n');
while(correo[0]==0){
rlutil::locate(45,9);
cout<<"Campo incompleto"<<endl;
rlutil::locate(53,8);
cin.ignore();
rlutil::locate(53,8);
cin.getline(correo,30,'\n');
rlutil::locate(45,9);
cout<<"                    "<<endl;
}


while(fread(&objC, sizeof(Vendedores),1,clave)!=0){
if(strcmp(objC.getCorreo(),correo)==0 && objC.getDni()==dni) {
rlutil::locate(45,10);
cout<<"Ingrese su nueva Clave:";
cin.ignore();
cin.getline(nuevaClave,30,'\n');
while(nuevaClave[0]==0){
rlutil::locate(45,11);
cout<<"Campo incompleto"<<endl;
rlutil::locate(55,11);
cin.ignore();
rlutil::locate(55,11);
cin.getline(nuevaClave,30,'\n');
rlutil::locate(45,11);
cout<<"                    "<<endl;
}


objC.setClave(nuevaClave);
long pos=ftell(clave)-sizeof(Vendedores);
fseek(clave,pos,SEEK_CUR);
fwrite(&objC, sizeof(Vendedores), 1, clave);
rlutil::locate(45,12);
cout << "Su nueva clave fue guardada con exito" << endl;
encontrado=true;
break; }
}
if(!encontrado){
rlutil::locate(45,12);
cout<<"LOS DATOS INGRESADOS NO ESTAN EN LA BASE DE DATOS"<<endl;
 }
fclose(clave);
rlutil::locate(45,16);
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
for(int j=1;j<121;j++){
rlutil::locate(j,1);
cout<<char(176);
}
for(int j=1;j<121;j++){
rlutil::locate(j,30);
cout<<char(176);
}
for(int j=1;j<121;j++){
rlutil::locate(j,28);
cout<<char(205);
}
for(int j=1;j<121;j++){
rlutil::locate(j,5);
cout<<char(205);
}
    rlutil::locate(40,3);
    bienvenidoUsuario(id);
    rlutil::locate(45,9);
    cout<<"1-)Clientes"<<endl;
     rlutil::locate(45,11);
    cout<<"2-)Vendedores"<<endl;
     rlutil::locate(45,13);
    cout<<"3-)Autos"<<endl;
     rlutil::locate(45,15);
    cout<<"4-)Recaudaciones"<<endl;
     rlutil::locate(45,17);
    cout<<"5-)Realizar Venta"<<endl;
     rlutil::locate(45,19);
    cout<<"6-)Generar Ticket para soporte"<<endl;
     rlutil::locate(45,21);
    cout<<"0-)Salir..."<<endl;
     rlutil::locate(45,23);
    cout<<"Ingrese la opcion que desee:";
    cin>>opcion;
    cin.ignore();
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
    validarId(idC);
    cout << "-------------------------------------------------------" << endl;
    cout << "Por favor ingrese el id del vehiculo: ";
    cin >> idA;
    validarId(idA);
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
//VALIDACION PARA LA FUNCION DE VENTAS
void validarId(int i){
while(i==0){
cout<<"Campo incompleto"<<endl;
cout<<"Id: ";
cin>>i;
}
}


//FUNCION PARA RECAUDACIONES
void recaudaciones(int id){
int opcion;
while(true){
for(int j=1;j<121;j++){
    rlutil::locate(j,1);
    cout<<char(176);
}
for(int j=1;j<121;j++){
    rlutil::locate(j,30);
    cout<<char(176);
}
for(int j=1;j<121;j++){
    rlutil::locate(j,1);
    cout<<char(176);
}
for(int j=1;j<121;j++){
    rlutil::locate(j,30);
    cout<<char(176);
}
for(int j=1;j<121;j++){
rlutil::locate(j,27);
cout<<char(205);
     }
for(int j=1;j<121;j++){
rlutil::locate(j,3);
cout<<char(205);
}
rlutil::locate(42,5);
cout<<"RECAUDACIONES DE LA CONSESCIONARIA"<<endl;
rlutil::locate(38,6);
cout<<"--------------------------------------------------------------"<<endl;
rlutil::locate(65,7);
cout<<"GROUP 51 CAR CENTER"<<endl;
rlutil::locate(46,10);
cout<<"1-)Recaudacion total"<<endl;
rlutil::locate(46,12);
cout<<"2-)Recaudacion por mes y anio"<<endl;
rlutil::locate(46,14);
cout<<"3-)Recaudacion por anio"<<endl;
rlutil::locate(46,16);
cout<<"4-)Recaudacion por id de vendedor"<<endl;
rlutil::locate(46,18);
cout<<"0-)Volver atras"<<endl;
rlutil::locate(46,20);
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
    rlutil::locate(45,22);
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
for(int j=1;j<121;j++){
    rlutil::locate(j,1);
    cout<<char(176);
}
for(int j=1;j<121;j++){
    rlutil::locate(j,30);
    cout<<char(176);
}
int y=0;
bool control_menu_soporte=true;
do{
rlutil::setBackgroundColor(rlutil::BLACK);
rlutil::setColor(rlutil::BLACK);
rlutil::locate(2,2);
cout<<"BIENVENIDO AL MENU DE SOPORTE...";
rlutil::hidecursor();
GraficarOpiciones("Dar de alta vendedores ",45,5,y==0,10,0);
GraficarOpiciones("Dar de baja vendedores ",45,7,y==1,10,0);
GraficarOpiciones("Editar vendedores ",45,9,y==2,10,0);
GraficarOpiciones("Mostrar tickets generados en el sistema de soporte ",45,11,y==3,10,0);
GraficarOpiciones("Mostrar solicitudes de alta ",45,13,y==4,10,0);
GraficarOpiciones("Aprobar solicitudes de alta ",45,15,y==5,10,0);
GraficarOpiciones("Dar de baja ticket ",45,17,y==6,10,0);
GraficarOpiciones("Listar vendedores",45,19,y==7,10,0);
GraficarOpiciones("Salir ",45,21,y==8,10,0);
switch(rlutil::getkey()){
case 14:
    y--;
    if(y<0){
        y=0;
    }
    break;
case 15:
    y++;
    if(y>8){
        y=0;
    }
    break;
case 1:
       switch(y){
   case 0:
        system("cls");
        objV.cargarVendedor();
        objV.registrarVendedor(objV);
    break;
   case 1:
        system("cls");
        objV.bajaVendedores();
    break;
   case 2:
        system("cls");
        objV.menuMiCuenta();
    break;
   case 3:
       system("cls");
       objT.mostrarTickets();
    break;
   case 4:
       system("cls");
       objS.listarSolicitudes();
       break;
   case 5:
       system("cls");
       objS.aprobarSolicitudDeAlta();
    break;
   case 6:
       system("cls");
       objT.darDeBajaTickets();
    break;
   case 7:
       system("cls");
       objV.listarVendedores();
    break;
   case 8:
       rlutil::setBackgroundColor(rlutil::BLACK);
       system("cls");
       control_menu_soporte=false;
    break;
   }
break;
}
}while(control_menu_soporte);
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
validarId(idS);
char nombre[30];
char correo[35];
int dni;
char clave[20];
char clave2[20];
int id;
while(fread(&objS,sizeof(Solicitud),1,buscarMiSolicitud)!=0){
    if(idS==objS.getId()){
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
 cout<<"Proceso finalizado. Fue dado de alta en el sistema correctamente"<<endl;
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

void GraficarOpiciones(const char*opc_a_graficar,int columna,int fila,bool seleccion,int color1,int color2){
if (seleccion){
 rlutil::setBackgroundColor(color1);
 rlutil::setColor(color2);
 rlutil::locate(columna-2,fila);
 cout<< " " << opc_a_graficar << " " <<endl;
 }
 else{
 rlutil::setBackgroundColor(color2);
 rlutil::setColor(color1);
 }
 rlutil::locate(columna-2,fila);
 cout<< " " << opc_a_graficar << " " <<endl;
}



void GraficarCeldas(int desde_la_columna,int hasta_la_columna,int filas,const char*texto){
for(int x=desde_la_columna;x<hasta_la_columna;x++){
    if(x==desde_la_columna){
    rlutil::locate(x-1,filas);
    cout<<char(58);
    }
    else if(x==(hasta_la_columna-1)){
            rlutil::locate(x+1,filas);
            cout<<char(58);
           }
    rlutil::locate(x,filas-1);
    cout<<char(250);
    rlutil::locate(x,filas+1);
    cout<<char(46);
}
    rlutil::locate(desde_la_columna,filas-2);
    cout<<texto;

}

void GraficarLineasHorizontales(int desde_la_columna,int hasta_la_columna,int fila,bool esquinas,int caracter){
       if(esquinas){
       rlutil::locate(desde_la_columna-1,fila);
       cout<<char(201);
       rlutil::locate(hasta_la_columna,fila);
       cout<<char(187);
       }
       for(int x=desde_la_columna;x<hasta_la_columna;x++){
       rlutil::locate(x,fila);
       cout<<char(caracter);
       }
       }
void GraficarLineasVerticales(int desde_la_columna,int hasta_la_columna,int fila_inicial,int fila_final,int caracter){
       for(int x=fila_inicial;x<fila_final;x++){
       rlutil::locate(desde_la_columna,x);
       cout<<char(caracter);
       rlutil::locate(hasta_la_columna,x);
       cout<<char(caracter);
       }
       }

void Borrar(int columnas,int desde_fila,int hasta_fila,int saltoFila){
for(int x=desde_fila;x<=hasta_fila;x+=saltoFila){
rlutil::locate(columnas,x);
cout<<"                                                                                  ";
    }

}

void Dibujar_Cuadro_Login(){
GraficarLineasHorizontales(35,85,5,true,205);
GraficarLineasHorizontales(35,85,9,false,205);
GraficarLineasHorizontales(35,85,25,false,205);
GraficarLineasVerticales(34,85,6,25,186);
rlutil::locate(52,7);
cout<<"INICIO DE SESION";
GraficarCeldas(38,80,13,"CORREO ELECTRONICO");
GraficarCeldas(38,80,18,"CONTRASENIA");
}


