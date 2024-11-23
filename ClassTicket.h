#ifndef CLASSTICKET_H_INCLUDED
#define CLASSTICKET_H_INCLUDED
#include "ClassVendedor.h"

class TicketAdmin {
private:
    int idT;
    char fechaActual[11];
    char infoTicket[35];
    char usuarioTicket[35];

public:
    TicketAdmin(int i = 0, const char* f = "01/01/1990", const char* iT = "XXX", const char* uT = "usuario123@gmail.com") {
        strcpy(this->fechaActual, f);
        strcpy(this->infoTicket, iT);
        strcpy(this->usuarioTicket, uT);
        this->idT = i;
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
    cout << "Por favor complete los siguientes datos para generar un ticket:" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Ingrese el asunto del ticket: ";
    cin.ignore();
    cin.getline(infoTicket, 35);
    objT.setInfo(infoTicket);
    cout << "Ingrese la fecha del ticket (Ej: 01/01/1900): ";
    cin.getline(fechaActual, 11);
    objT.setFecha(fechaActual);
    objT.setUsuario(usuario);
    idT = generarIdTicket();
    objT.setIdT(idT);
    fwrite(&objT, sizeof(TicketAdmin), 1, nuevoT);
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Ticket generado correctamente..." << endl;
    cout << "El numero del ticket es: " << idT << endl;
    fclose(nuevoT);
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
};


#endif // CLASSTICKET_H_INCLUDED
