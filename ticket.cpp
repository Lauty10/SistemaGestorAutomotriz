#include <iostream>
#include "ClassTicket.h"
#include "ClassVendedor.h"

void GraficarLineasHorizontales(int,int,int,bool,int);

using namespace std;

   void TicketAdmin::setIdT(int id) {
        this->idT = id;
    }
    void TicketAdmin::setInfo(const char it[35]) {
        strcpy(this->infoTicket, it);
    }
    void TicketAdmin::setUsuario(const char uT[35]) {
        strcpy(this->usuarioTicket, uT);
    }
    void TicketAdmin::setTicket(bool t){
    this->ticket=t;
    }
    int TicketAdmin::getId(){
        return idT;
    }
    const char* TicketAdmin::getInfoT(){
        return infoTicket;
    }
    const char* TicketAdmin::getUsuario(){
        return usuarioTicket;
    }
    bool TicketAdmin::getTicket(){
    return ticket;
    }

void TicketAdmin::generarTicket(int id) {
    FILE *infoId;
    infoId = fopen("Vendedores.dat", "rb");
    if (infoId == NULL) {
        cout << "Error al obtener info del cliente" << endl;
        return;
    }

    Vendedores objV;
    char usuario[35];
    bool encontrado = false;

    while (fread(&objV, sizeof(Vendedores), 1, infoId) != 0) {
        if (id == objV.getIdVendedor()) {
            encontrado = true;
            strcpy(usuario, objV.getCorreo());
            break;
        }
    }

    if (!encontrado) {
        cout << "Error al encontrar el usuario" << endl;
        fclose(infoId);
        return;
    }
    fclose(infoId);
    FILE *nuevoT;
    nuevoT = fopen("Ticket.dat", "ab");
    if (nuevoT == NULL) {
        cout << "Error al generar nuevo ticket" << endl;
        return;
    }
    GraficarLineasHorizontales(1,121,2,false,176);
    GraficarLineasHorizontales(1,121,30,false,176);
    TicketAdmin objT;
    int idT;
    rlutil::locate(30,10);
    cout << "Por favor complete los siguientes datos para generar un ticket" << endl;
    rlutil::locate(45,12);
    cout << "Ingrese el asunto del ticket:";
    cin.getline(infoTicket, 35);
    objT.ticketV(infoTicket);
    objT.setInfo(infoTicket);
    system("cls");

    objT.setUsuario(usuario);
    idT = generarIdTicket();
    objT.setIdT(idT);
    objT.setTicket(true);
    fwrite(&objT, sizeof(TicketAdmin), 1, nuevoT);
    GraficarLineasHorizontales(1,121,2,false,176);
    GraficarLineasHorizontales(1,121,30,false,176);
    rlutil::locate(45,14);
    cout << "Ticket generado correctamente..." << endl;
    rlutil::locate(45,16);
    cout << "El numero del ticket es:"<<idT<<endl;
    fclose(nuevoT);
    rlutil::locate(45,18);
    system("pause");
    system("cls");
}

    int TicketAdmin::generarIdTicket() {
        FILE *generar;
        int dato = 0;
        generar = fopen("Ticket.dat", "rb");
        if (generar == NULL) {
            dato = 1;
            return dato;
        }
        TicketAdmin obj;
        while (fread(&obj, sizeof(TicketAdmin), 1, generar) != 0) {
            dato++;
        }
        fclose(generar);
        return dato+1;
    }

//MOSTRAR TICKETS
void TicketAdmin::mostrarTickets(){
FILE *tickets;
tickets=fopen("Ticket.dat","rb+");
if(tickets==NULL){
rlutil::locate(1,6);
cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
return;
}
rlutil::locate(40,3);
cout<<"Estos son todos los tikets generados en nuestro sistema..."<<endl;
TicketAdmin obj;
while(fread(&obj,sizeof(TicketAdmin),1,tickets)!=0){
if(obj.getTicket()==true){
cout<<endl;
cout<<"El id del ticket es: "<<obj.getId()<<endl;
cout<<"El usuario del ticket es: "<<obj.getUsuario()<<endl;
cout<<"El asunto del del ticket es: "<<obj.getInfoT()<<endl;
cout<<"-------------------------------------------------------------"<<endl;
}
}
fclose(tickets);
system("pause");
system("cls");

}


void TicketAdmin::darDeBajaTickets(){
GraficarLineasHorizontales(1,121,1,false,176);
GraficarLineasHorizontales(1,121,3,false,205);
GraficarLineasHorizontales(1,121,30,false,176);
GraficarLineasHorizontales(1,121,28,false,205);
FILE *baja;
baja=fopen("Ticket.dat","rb+");
if(baja==NULL){
cout<<"ESTE ARCHIVO NO SE PUDO ABRIR"<<endl;
return;
}
TicketAdmin objA;
int i;
bool encontrado=false;
rlutil::locate(40,12);
cout<<"Ingrese el id del ticket a dar de baja: ";
cin>>i;

while(fread(&objA,sizeof(TicketAdmin),1,baja)!=0){
if(objA.getTicket()==true && objA.getId()==i){
objA.setTicket(false);
encontrado=true;
long posicion=ftell(baja)-sizeof(TicketAdmin);
fseek(baja,posicion,SEEK_SET);
fwrite(&objA,sizeof(TicketAdmin),1,baja);
rlutil::locate(42,14);
cout<<"Ticket dado de baja correctamente"<<endl;
rlutil::locate(42,16);
system("pause");
break;
}
}
if(!encontrado){
rlutil::locate(40,14);
cout<<"El ticket ya fue dado de baja o no se encontro en el sistema..."<<endl;
rlutil::locate(40,16);
system("pause");
system("cls");
return;
}
system("cls");
fclose(baja);
}

void TicketAdmin::ticketV(char* asunto){
while(asunto[0]=='\0'){
 rlutil::locate(45,14);
cout<<"Es necesario completar este campo"<<endl;
rlutil::locate(45,16);
cout<<"Ingres el asunto del ticket: ";
cin.getline(asunto,35);
}
}

void TicketAdmin::fechaV(char* f){
while(f[0]=='\0'){
rlutil::locate(45,14);
cout<<"Es necesario completar este campo"<<endl;
rlutil::locate(45,16);
cout<<"Ingrese la fecha del ticket:";
cin.getline(f,11);
}
}
