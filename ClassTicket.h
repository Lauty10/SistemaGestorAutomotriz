#ifndef CLASSTICKET_H_INCLUDED
#define CLASSTICKET_H_INCLUDED
#include "ClassVendedor.h"

class TicketAdmin {
private:
    int idT;
    char fechaActual[11];
    char infoTicket[35];
    char usuarioTicket[35];
    bool ticket;

public:
    TicketAdmin(int i = 0, const char* f = "01/01/1990", const char* iT = "XXX", const char* uT = "usuario123@gmail.com", bool t=false) {
        strcpy(this->fechaActual, f);
        strcpy(this->infoTicket, iT);
        strcpy(this->usuarioTicket, uT);
        this->idT = i;
        this->ticket=t;
    }
    void setIdT(int id) {
        this->idT = id;
    }
    void setFecha(const char f[11]) {
        strcpy(this->fechaActual, f);
    }
    void setInfo(const char it[35]) {
        strcpy(this->infoTicket, it);
    }
    void setUsuario(const char uT[35]) {
        strcpy(this->usuarioTicket, uT);
    }
    void setTicket(bool t=false){
    this->ticket=t;
    }
    int getId() const {
        return idT;
    }
    const char* getFecha(){
        return fechaActual;
    }
    const char* getInfoT(){
        return infoTicket;
    }
    const char* getUsuario(){
        return usuarioTicket;
    }
    bool getTicket(){
    return ticket;
    }


void generarTicket(int id) {
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


    TicketAdmin objT;
    int idT;
    rlutil::locate(1,1);
    cout << "-------------------------------------------------------------------" << endl;
    rlutil::locate(1,3);
    cout << "Por favor complete los siguientes datos para generar un ticket:" << endl;
    rlutil::locate(1,5);
    cout << "-------------------------------------------------------------------" << endl;
      rlutil::locate(1,6);
    cout << "Ingrese el asunto del ticket: ";
    cin.ignore();
    rlutil::locate(1,7);
    cin.getline(infoTicket, 35);
    objT.setInfo(infoTicket);
    rlutil::locate(1,9);
    cout << "Ingrese la fecha del ticket (Ej: 01/01/1900): ";
    rlutil::locate(1,10);
    cin.getline(fechaActual, 11);
    objT.setFecha(fechaActual);
    objT.setUsuario(usuario);
    idT = generarIdTicket();
    objT.setIdT(idT);
    objT.setTicket(true);
    fwrite(&objT, sizeof(TicketAdmin), 1, nuevoT);
    rlutil::locate(1,12);
    cout << "Ticket generado correctamente..." << endl;
    rlutil::locate(1,14);
    cout << "El numero del ticket es: " << idT << endl;
    fclose(nuevoT);
    rlutil::locate(1,18);
    system("pause");
    system("cls");
}

    int generarIdTicket() {
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
        return dato + 1;
    }

//MOSTRAR TICKETS
void mostrarTickets(){
FILE *tickets;
tickets=fopen("Ticket.dat","rb+");
if(tickets==NULL){
rlutil::locate(1,6);
cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
return;
}
rlutil::locate(1,3);
cout<<"Estos son todos los tikets"<<endl;
TicketAdmin obj;
while(fread(&obj,sizeof(TicketAdmin),1,tickets)!=0){
if(obj.getTicket()==true){

cout<<"Fecha: "<<obj.getFecha()<<endl;

cout<<"Id del ticket: "<<obj.getId()<<endl;

cout<<"Usuario: "<<obj.getUsuario()<<endl;

cout<<"Informacion del ticket: "<<obj.getInfoT()<<endl;

cout<<"------------------------------------------------------------"<<endl;
}
}
fclose(tickets);
system("pause");
system("cls");

}


void darDeBajaTickets(){
FILE *baja;
baja=fopen("Ticket.dat","rb+");
if(baja==NULL){
cout<<"ESTE ARCHIVO NO SE PUDO ABRIR"<<endl;
return;
}
TicketAdmin objA;
int i;
bool encontrado=false;
rlutil::locate(1,2);
cout<<"Ingrese el id del ticket a dar de baja: ";
cin>>i;

while(fread(&objA,sizeof(TicketAdmin),1,baja)!=0){
if(objA.getTicket()==true && objA.getId()==i){
objA.setTicket(false);
encontrado=true;
long posicion=ftell(baja)-sizeof(TicketAdmin);
fseek(baja,posicion,SEEK_SET);
fwrite(&objA,sizeof(TicketAdmin),1,baja);
rlutil::locate(1,4);
cout<<"Ticket dado de baja correctamente"<<endl;
rlutil::locate(1,8);
system("pause");
break;
}
}
if(!encontrado){
rlutil::locate(1,4);
cout<<"NO SE ENCONTRO EL ID INGRESADO"<<endl;
rlutil::locate(1,8);
system("pause");
system("cls");
return;
}
system("cls");
fclose(baja);
}

};


#endif // CLASSTICKET_H_INCLUDED
