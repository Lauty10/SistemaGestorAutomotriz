#ifndef CLASSADMINISTRADOR_H_INCLUDED
#define CLASSADMINISTRADOR_H_INCLUDED
#include <iostream>
#include <cstring>
#include <chrono>
#include <cstdio>
#include "rlutil.h"

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
    void setCorreo(const char correo[35]);
    void setClave(const char clave[20]);
    const char* getCorreo();
    const char* getClave();
    const char* getRol();
    bool getEstado() ;
    bool logeoDeUsuariosAdministradores();
};


#endif
