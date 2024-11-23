#ifndef CLASSADMINISTRADOR_H_INCLUDED
#define CLASSADMINISTRADOR_H_INCLUDED
#include <iostream>
#include <cstring>
#include <chrono>
#include <cstdio>

using namespace std;

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

    const char* getCorreo(){
        return correo;
    }

    const char* getClave(){
        return clave;
    }

    const char* getRol() {
        return rol;
    }

    bool getEstado() {
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
                cout << "Iniciando sesion..." << endl;
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
