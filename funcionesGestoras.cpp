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
do{
rlutil::hidecursor();
rlutil::setBackgroundColor(rlutil::BLACK);
rlutil::setColor(rlutil::WHITE);
GraficarLineasHorizontales(1,121,2,false,176);
GraficarLineasHorizontales(1,121,30,false,176);rlutil::locate(40,6);
rlutil::locate(35,6);
cout<<" GROUP 51 CAR CENTER"<<endl;
rlutil::locate(35,7);
cout<<"--------------------------------------------------------------"<<endl;
rlutil::locate(54,8);
cout<<"BIENVENIDO AL SISTEMA GESTOR"<<endl;
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
        Dibujar_Cuadro_Login("LOGEO VENDEDOR");
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
       Dibujar_Cuadro_Login("LOGEO ADMIN");
       logeoAdmin=objA.logeoDeUsuariosAdministradores();
       if(logeoAdmin==true){
       system("cls");
       menuDeSoporte();
       }
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
GraficarLineasHorizontales(1,121,2,false,176);
GraficarLineasHorizontales(1,121,30,false,176);
FILE *clave;
clave=fopen("Vendedores.dat","rb+");
if(clave==nullptr){
rlutil::locate(1,3);
cout<<"ERROR AL INTENTAR ABRIR EL ARCHIVO DE REGISTROS"<<endl;
return;
}
Vendedores objC;
int dni;
char correo[30];
char nuevaClave[30];
bool encontrado=false;
rlutil::locate(35,12);
cout<<"Por favor ingrese su dni de identidad para recuperar su clave"<<endl;
rlutil::locate(48,14);
cout<<"Por favor ingrese su dni:";
cin>>dni;
while(dni==0){
rlutil::locate(48,14);
cout<<"Vuelva a ingresar su dni:"<<endl;
cin>>dni;
}

system("cls");
GraficarLineasHorizontales(1,121,2,false,176);
GraficarLineasHorizontales(1,121,30,false,176);
rlutil::locate(40,12);
cout<<"Ingrese su correo para poder recuperar su clave"<<endl;
rlutil::locate(40,14);
cout<<"Ingrese su correo: ";
cin.ignore();
cin.getline(correo,30,'\n');
while(correo[0]==0){
rlutil::locate(38,16);
cout<<"El campo esta incompleto, vuelva a ingresar su correo"<<endl;
rlutil::locate(55,18);
cout<<"Ingrese su correo:";
cin.ignore();
cin.getline(correo,30,'\n');
}

system("cls");
GraficarLineasHorizontales(1,121,2,false,176);
GraficarLineasHorizontales(1,121,30,false,176);
while(fread(&objC, sizeof(Vendedores),1,clave)!=0){
if(strcmp(objC.getCorreo(),correo)==0 && objC.getDni()==dni) {
 char nuevaClave[30];
    int i = 0;
    rlutil::locate(40, 12);
    cout << "Datos validados correctamente en nuestro sistema..." << endl;
    rlutil::locate(50, 14);
    cout << "Ingrese su nueva Clave:";
    while (true) {
        char ch = _getch();
        if (ch == '\r') {
            nuevaClave[i] = '\0';
            break;
        } else if (ch == '\b' && i > 0) {
            cout << "\b \b";
            i--;
        } else if (ch != '\b') {
            nuevaClave[i] = ch;
            cout << "*";
            i++;
        }
    }
while(nuevaClave[0]==0){
    int j = 0;
    rlutil::locate(38, 14);
    cout << "El campo esta incompleto, vuelva a ingresar su clave" << endl;
    rlutil::locate(55, 16);
    cout << "Ingrese su clave:";
    while (true) {
        char ch = _getch();
        if (ch == '\r') {
            nuevaClave[j] = '\0';
            break;
        } else if (ch == '\b' && i > 0) {
            cout << "\b \b";
            i--;
        } else if (ch != '\b') {
            nuevaClave[j] = ch;
            cout << "*";
            i++;
        }
}
}
objC.setClave(nuevaClave);
long pos=ftell(clave)-sizeof(Vendedores);
fseek(clave,pos,SEEK_CUR);
fwrite(&objC, sizeof(Vendedores), 1, clave);
rlutil::locate(45,16);
cout << "Su nueva clave fue guardada con exito" << endl;
encontrado=true;
break; }
}
if(!encontrado){
rlutil::locate(40,12);
cout<<"LOS DATOS INGRESADOS NO ESTAN EN LA BASE DE DATOS"<<endl;
 }
fclose(clave);
rlutil::locate(45,14);
system("pause");
system("cls");
}


//MENU DE VENDEDORES
void menuDeVendedores(int id){
Clientes objCliente;
Vendedores objVendedores;
Auto objAuto;
TicketAdmin objT;
bool control_menu_vendedor=true;
int y=0;
do{
   rlutil::hidecursor();
   rlutil::setBackgroundColor(rlutil::BLACK);
   rlutil::setColor(rlutil::WHITE);
   GraficarLineasHorizontales(1,121,2,false,176);
   GraficarLineasHorizontales(1,121,30,false,176);
   rlutil::locate(40,6);
   bienvenidoUsuario(id);
   rlutil::locate(30,7);
   cout<<"-------------------------------------------------------------------"<<endl;
   GraficarOpiciones("Menu de clientes ",50,10,y==0,15,0);
   GraficarOpiciones("Menu de vendedores ",50,12,y==1,15,0);
   GraficarOpiciones("Menu de Autos ",50,14,y==2,15,0);
   GraficarOpiciones("Menu de Recaudaciones ",50,16,y==3,15,0);
   GraficarOpiciones("Realizar venta de vehiculo",50,18,y==4,15,0);
   GraficarOpiciones("Generar ticket para soporte ",50,20,y==5,15,0);
   GraficarOpiciones("Cerrar sesion",50,22,y==6,15,0);
   switch(rlutil::getkey()){
   case 14:
           y--;
           if(y<0){
           y=0;
          }
   break;
   case 15:
           y++;
           if(y>6){
           y=0;
           }
   break;
         case 1:
         switch(y){
         case 0:
                system("cls");
                objCliente.menuClientes(id);
         break;
         case 1:
                system("cls");
                objVendedores.funcionalidadesVendedor(id);
         break;
         case 2:
                system("cls");
                objAuto.menuAutos(id);
         break;
         case 3:
                system("cls");
                recaudaciones(id);
         break;
         case 4:
                system("cls");
                realizarVenta(id);
         break;
         case 5:
                system("cls");
                objT.generarTicket(id);
         break;
         case 6:
                rlutil::setBackgroundColor(rlutil::BLACK);
                system("cls");
                control_menu_vendedor=false;
         break;
           }
    break;
}
}while(control_menu_vendedor);
}



//FUNCION PARA REALIZAR VENTA

void realizarVenta(int idV) {
   GraficarLineasHorizontales(1,121,1,false,176);
   GraficarLineasHorizontales(1,121,30,false,176);
    int idC, idA;
    rlutil::locate(45,12);
    cout << "Bienvenido al sector de ventas..." << endl;
    rlutil::locate(45,14);
    cout << "Group Car Center 51..." << endl;
    rlutil::locate(45,16);
    system("pause");
    system("cls");

    GraficarLineasHorizontales(1,121,1,false,176);
    GraficarLineasHorizontales(1,121,30,false,176);
    rlutil::locate(45,12);
    cout << "Por favor ingrese el id del cliente: ";
    cin >> idC;
    bool resultado=validarId(idC);
    if(resultado==false){
    system("cls");
    return;
    }
    system("cls");


    GraficarLineasHorizontales(1,121,1,false,176);
    GraficarLineasHorizontales(1,121,30,false,176);
    rlutil::locate(45,12);
    cout<< "Por favor ingrese el id del vehiculo: ";
    cin >>idA;
    bool resultado2= validarIdAuto(idA);
    if(resultado2==false){
    system("cls");
    return;
    }
    system("cls");

    GraficarLineasHorizontales(1,121,1,false,176);
    GraficarLineasHorizontales(1,121,30,false,176);
    rlutil::locate(45,10);
    cout << "Ingrese la fecha del dia vigente..."<<endl;
    Recaudacion objRecaudacion;
    Fecha objFecha;
    rlutil::locate(45,12);
    objFecha.cargarFecha();
    int fechaDia=objFecha.getDia();
    int fechaAnio=objFecha.getAnio();
    int fechaMes=objFecha.getMes();
    bool resultado3=validarFecha(fechaDia,fechaMes,fechaAnio);
    if(resultado3==false){
    rlutil::locate(45,18);
    cout<<"La fecha no se pudo validar correcamente..."<<endl;
    rlutil::locate(45,20);
    system("pause");
    system("cls");
    return;
    }
    system("cls");

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
bool validarId(int i){
FILE *buscarCliente;
buscarCliente=fopen("Clientes","rb");
Clientes obj;
bool encontrado=false;
while(fread(&obj,sizeof(Clientes),1,buscarCliente)!=0){
    if(obj.getIdCliente()==i && obj.getEstado()==true){
        encontrado=true;
        rlutil::locate(45,14);
        cout<<"Cliente encontrado correctamente..."<<endl;
        rlutil::locate(45,16);
        system("pause");
        return true;
    }
}
if(!encontrado){
if(i==0){
rlutil::locate(45,14);
cout<<"Campo Cargado incorrectamente..."<<endl;
rlutil::locate(45,16);
cout<<"Ingrese el id: ";
cin>>i;
return true;
}else{
    rlutil::locate(30,14);
    cout<<"El vendedor se encuentra dado de baja o no se encuentra en nuestro sistema..."<<endl;
    rlutil::locate(45,16);
    system("pause");
    fclose(buscarCliente);
    return false;
}
}
fclose(buscarCliente);
}

bool validarIdAuto(int i){
FILE *buscarAuto;
buscarAuto=fopen("Vehiculo.dat","rb");
Auto obj;
bool encontrado=false;
while(fread(&obj,sizeof(Auto),1,buscarAuto)!=0){
    if(obj.getId()==i && obj.getEstado()==true){
        encontrado=true;
        rlutil::locate(45,14);
        cout<<"Vehiculo encontrado correctamente..."<<endl;
        rlutil::locate(45,16);
        system("pause");
        return true;
    }
}
if(!encontrado){
if(i==0){
rlutil::locate(45,14);
cout<<"Campo Cargado incorrectamente..."<<endl;
rlutil::locate(45,16);
cout<<"Ingrese el id: ";
cin>>i;
return true;
}else{
    rlutil::locate(30,14);
    cout<<"El Vehiculo se encuentra dado de baja o no se encuentra en nuestro sistema..."<<endl;
    rlutil::locate(45,16);
    system("pause");
    fclose(buscarAuto);
    return false;
}
}
fclose(buscarAuto);
}


bool validarFecha(int dia, int mes, int anio){
if(anio>=2024){
if(mes>0&&mes<=12 && mes!=2){
if(dia>0&&dia<=31){
    return true;
}else{
return false;
}
}else if(mes==2){
if(dia>0 && dia<=29){
    return true;
}
}else{
return false;
}
}else{
return false;
}
}


//FUNCION PARA RECAUDACIONES
void recaudaciones(int id){
Recaudacion obj;
bool control_menu_rec=true;
int y=0;
do{
   rlutil::hidecursor();
   rlutil::setBackgroundColor(rlutil::BLACK);
   rlutil::setColor(rlutil::WHITE);
   GraficarLineasHorizontales(1,121,1,false,176);
   GraficarLineasHorizontales(1,121,30,false,176);
   rlutil::locate(35,6);
   cout<<"GROUP 51 CAR CENTER"<<endl;
   rlutil::locate(35,7);
   cout<<"--------------------------------------------------------------"<<endl;
   rlutil::locate(36,8);
   cout<<"BIENVENIDO AQUI PODRA EDITAR LOS VEHICULOS"<<endl;
   GraficarOpiciones("Recaudacion total ",50,12,y==0,15,0);
   GraficarOpiciones("Recaudacion por mes y anio ",50,14,y==1,15,0);
   GraficarOpiciones("Recaudacion por anio ",50,16,y==2,15,0);
   GraficarOpiciones("Recaudacion por id de vendedor ",50,18,y==3,15,0);
   GraficarOpiciones("Volver atras ",50,20,y==4,15,0);
   switch(rlutil::getkey()){
   case 14:
           y--;
           if(y<0){
           y=0;
          }
   break;
   case 15:
           y++;
           if(y>4){
           y=0;
           }
   break;
         case 1:
         switch(y){
         case 0:
                system("cls");
                obj.recaudacionTotal();
         break;
         case 1:
                system("cls");
                obj.recaudacionMesyAnio();
         break;
         case 2:
                system("cls");
                obj.recaudacionXanio();
         break;
         case 3:
                system("cls");
                obj.recaudacionPorId();
                system("cls");
         break;
         case 4:
                rlutil::setBackgroundColor(rlutil::BLACK);
                system("cls");
                control_menu_rec=false;
         break;
           }
    break;
}
}while(control_menu_rec);

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
int y=0;
bool control_menu_soporte=true;
do{
   rlutil::hidecursor();
   rlutil::setBackgroundColor(rlutil::BLACK);
   rlutil::setColor(rlutil::WHITE);
   GraficarLineasHorizontales(1,121,2,false,176);
   GraficarLineasHorizontales(1,121,30,false,176);
   rlutil::locate(35,6);
   cout<<"GROUP 51 CAR CENTER - MENU DE SOPORTE"<<endl;
   rlutil::locate(35,7);
   cout<<"--------------------------------------------------------------"<<endl;
   rlutil::locate(35,8);
   cout<<"Bienvenido al men"<<char(163)<<" de soporte. "<<char(168)<<"Qu"<<char(130)<<" deseas hacer hoy"<<char(63);
   GraficarOpiciones("Dar de alta vendedores ",45,10,y==0,15,0);
   GraficarOpiciones("Dar de baja vendedores ",45,12,y==1,15,0);
   GraficarOpiciones("Editar vendedores ",45,14,y==2,15,0);
   GraficarOpiciones("Mostrar tickets generados en el sistema de soporte ",45,16,y==3,15,0);
   GraficarOpiciones("Mostrar solicitudes de alta ",45,18,y==4,15,0);
   GraficarOpiciones("Aprobar solicitudes de alta ",45,20,y==5,15,0);
   GraficarOpiciones("Dar de baja ticket ",45,22,y==6,15,0);
   GraficarOpiciones("Listar vendedores ",45,24,y==7,15,0);
   GraficarOpiciones("Salir ",45,26,y==8,15,0);
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
rlutil::locate(j,3);
cout<<char(205);
}
FILE *buscarMiSolicitud;
buscarMiSolicitud=fopen("Solicitud.dat","rb+");
if(buscarMiSolicitud==NULL){
    cout<<"Error al encontrar su solicitud"<<endl;
    return;
}
Solicitud objS;
Vendedores objV;
int idS;
rlutil::locate(35,10);
cout<<"Bienvenido aqui podra verificar el estado de su solicutud"<<endl;
rlutil::locate(45,12);
cout<<"Ingrese el ID de su solicitud:";
cin>>idS;
cin.ignore();
validarId(idS);
char nombre[30];
char correo[35];
int dni;
char clave[20];
char clave2[20];
int i = 0;
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
        rlutil::locate(45,14);
        cout<<"Solicitud aprobada..."<<endl;
        rlutil::locate(45,16);
        system("pause");
        break;
        }else{
        rlutil::locate(30,14);
        cout<<"La solicitud ya fue aprobada o no se encontro en nuestro sistema..."<<endl;
        rlutil::locate(45,16);
        system("pause");
        system("cls");
        return;
        }
        }
        }
FILE *Nuevoalta;
Nuevoalta=fopen("Vendedores.dat","ab");
if(Nuevoalta==NULL){
    cout<<"Error al dar de alta"<<endl;
    fclose(Nuevoalta);
    return;
}
system("cls");
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
rlutil::locate(j,3);
cout<<char(205);
}
rlutil::locate(35,10);
cout<<"Feliciades, su solicitud fue aprobada solo falta un paso"<<endl;
rlutil::locate(45,12);
 cout << "Ingrese su clave para su alta: ";
    while (true) {
        char ch = getch();
        if (ch == 13) {
            clave[i] = '\0';
            break;
        } else if (ch == 8) {
            if (i > 0) {
                i--;
                cout << "\b \b";
            }
        } else {
            clave[i] = ch;
            cout << "*";
            i++;
        }
    }
    i = 0;
    rlutil::locate(45,14);
    cout << "Vuelva a ingresar su clave: ";
    while (true) {
    char ch = getch();
    if (ch == 13) {
    clave2[i] = '\0';
    break;
    }else if (ch == 8) {
    if (i > 0) {
    i--;
    cout << "\b \b";
    }
    } else {
    clave2[i] = ch;
    cout << "*";
    i++;
    }
    }
if(strcmp(clave,clave2)==0){
 id=generarId();
 objV.setNombre(nombre);
 objV.setId(id);
 objV.setCorreo(correo);
 objV.setClave(clave);
 objV.setDni(dni);
 fwrite(&objV,sizeof(Vendedores),1,Nuevoalta);
 rlutil::locate(30,16);
 cout<<"Proceso finalizado. Fue dado de alta en el sistema correctamente"<<endl;
 fclose(Nuevoalta);
}
fclose(buscarMiSolicitud);
rlutil::locate(50,18);
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

void Dibujar_Cuadro_Login(const char*titulo){
GraficarLineasHorizontales(35,85,5,true,205);
GraficarLineasHorizontales(35,85,9,false,205);
GraficarLineasHorizontales(35,85,25,false,205);
GraficarLineasVerticales(34,85,6,25,186);
rlutil::locate(52,7);
cout<<titulo;
GraficarCeldas(38,80,13,"INGRESAR CORREO ELECTRONICO");
GraficarCeldas(38,80,18,"INGRESAR CLAVE");
}




