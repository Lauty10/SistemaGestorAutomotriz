#include <iostream>
#include "ClassAdministrador.h"
#include <cstring>
#include <chrono>
#include <cstdio>
#include "rlutil.h"

using namespace std;

  void Administrador::setCorreo(const char correo[35]) {
        strcpy(this->correo, correo);
    }

    void Administrador::setClave(const char clave[20]) {
        strcpy(this->clave, clave);
    }

    const char* Administrador::getCorreo(){
        return correo;
    }

    const char* Administrador::getClave(){
        return clave;
    }

    const char* Administrador::getRol() {
        return rol;
    }

    bool Administrador::getEstado() {
        return estado;
    }

   bool Administrador::logeoDeUsuariosAdministradores() {
    Administrador admnis[4];
    admnis[0] = Administrador("lautaroAdmin19@gmail.com", "Riverplate1", "admin", true);
    admnis[1] = Administrador("melAdmin19@gmail.com", "12345678", "admin", true);
    admnis[2] = Administrador("marcosAdmin19@gmail.com", "123456789", "admin", true);
    admnis[3] = Administrador("maxiprofe@gmail.com", "12345678", "admin", true);
    char correoAdmin[35];
    char claveAdmin[20];
    int i = 0;
    rlutil::locate(39, 13);
    rlutil::showcursor();
    cin.getline(correoAdmin, 35, '\n');
    rlutil::locate(39, 18);
    while (i < 19) {
        char ch = _getch();
        if (ch == 13) {
            break;
        } else if (ch == 8) {
            if (i > 0) {
                i--;
                cout << "\b \b";
            }
        } else {
            claveAdmin[i] = ch;
            i++;
            cout << "*";
        }
    }
    claveAdmin[i] = '\0';
    bool usuarioValido = false;
    for (int j = 0; j < 4; j++) {
        if (strcmp(correoAdmin, "") != 0 && strcmp(claveAdmin, "") != 0) {
            if (strcmp(admnis[j].getCorreo(), correoAdmin) == 0 && strcmp(admnis[j].getClave(), claveAdmin) == 0) {
                usuarioValido = true;
                break;
            }
        }
    }
    if (usuarioValido) {
        return true;
    } else {
        rlutil::locate(40, 22);
        rlutil::setColor(rlutil::RED);
        cout << "Correo y/o clave incorrectos..." << endl;
        rlutil::resetColor();
        rlutil::locate(40, 23);
        system("pause");
        system("cls");
        return false;
    }
}
