#ifndef CLASSADMINISTRADOR_H_INCLUDED
#define CLASSADMINISTRADOR_H_INCLUDED
#include <iostream>
#include <cstring>
#include <chrono>
#include <cstdio>

using namespace std;


class TicketAdmin {
private:
    int idT;
    char fechaActual[11];
    char infoTicket[85];
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
    void setInfo(const char it[85]) {
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

    void generarTicket(const char usuario[35]) {
        FILE *nuevoT;
        nuevoT = fopen("Ticket.dat", "wb");

        if (nuevoT == NULL) {
            cout << "Error al generar nuevo Ticket" << endl;
            return;
        }
        TicketAdmin obj;
        int idTicket = 0;
        cout << "Por favor complete la informacion para generar un ticket de soporte" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Ingrese un breve resumen del ticket y lo que hara en el sistema de soporte:";
        cin.ignore();
        cin.getline(infoTicket, 85, '\n');
        obj.setInfo(infoTicket);
        cout << "Ingrese la fecha actual ej: 01/01/1900:";
        cin.getline(fechaActual, 11, '\n');
        obj.setFecha(fechaActual);
        obj.setUsuario(usuario);
        idTicket = generarIdTicket();
        obj.setIdT(idTicket);
        fwrite(&obj, sizeof(TicketAdmin), 1, nuevoT);
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Ticket generado correctamente..." << endl;
        cout << "Numero de ticket: " << idTicket << endl;
        system("pause");
        fclose(nuevoT);
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




class Administrador {
private:
    char correo[35];
    char clave[20];
    char rol[6];
    bool estado;

public:
    Administrador(const char* correo = "administrador@gmail.com", const char* clave = "administrador2024", const char* r = "admin", bool e = true) {
        strcpy(this->correo, correo);
        strcpy(this->clave, clave);
        strcpy(this->rol, r);
        this->estado = e;
    }

    void setCorreo(const char correo[35]) {
        strcpy(this->correo, correo);
    }

    void setClave(const char clave[20]) {
        strcpy(this->clave, clave);
    }

    const char* getCorreo() const {
        return correo;
    }

    const char* getClave() const {
        return clave;
    }

    const char* getRol() const {
        return rol;
    }

    bool getEstado() const {
        return estado;
    }

    bool logeoDeUsuariosAdministradores() {
        Administrador admnis[4];
        admnis[0] = Administrador("lautaroAdmin19@gmail.com", "Riverplate1", "admin", true);
        admnis[1] = Administrador("melAdmin19@gmail.com", "12345678", "admin", true);
        admnis[2] = Administrador("marcosAdmin19@gmail.com", "123456789", "admin", true);
        admnis[3] = Administrador("francoAdmin19@gmail.com", "987654321", "admin", true);
        char correoAdmin[35];
        char claveAdmin[20];
        bool loginExitoso = false;
        cout << "Ingrese su correo:";
        cin.ignore();
        cin.getline(correoAdmin, 35, '\n');
        cout << "Ingrese su clave:";
        cin.getline(claveAdmin, 20, '\n');
        for (int j = 0; j < 4; j++) {
            if (strcmp(admnis[j].getCorreo(), correoAdmin) == 0 && strcmp(admnis[j].getClave(), claveAdmin) == 0) {
                loginExitoso = true;
                cout << endl;
                cout << "Credenciales de administrador correctas..." << endl;
                cout << "Iniciando sesión..." << endl;
                TicketAdmin objT;
                objT.generarTicket(correoAdmin);
                system("pause");
                return true;
            }
        }
        if (!loginExitoso) {
            cout << "Credenciales incorrectas. Intentelo nuevamente..." << endl;
            system("pause");
            system("cls");
            return false;
        }
    }
};


#endif
