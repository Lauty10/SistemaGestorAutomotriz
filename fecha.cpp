#include <iostream>
#include "ClassFecha.h"
#include "rlutil.h"

using namespace std;

  void Fecha::setDia(int d){
    this->dia=d;
    }
    void Fecha::setMes(int m){
    this->mes=m;
    }
    void Fecha::setAnio(int a){
    this->anio=a;
    }
    int Fecha::getDia(){
    return dia;
    }
    int Fecha::getMes(){
    return mes;
    }
    int Fecha::getAnio(){
    return anio;
    }
    void Fecha::cargarFecha(){
    rlutil::locate(45,12);
    cout<<"Ingrese el dia de la fecha:";
    cin>>dia;
    setDia(dia);
    rlutil::locate(45,14);
    cout<<"Ingrese el mes de la fecha:";
    cin>>mes;
    setMes(mes);
    rlutil::locate(45,16);
    cout<<"Ingrese el anio de la fecha:";
    cin>>anio;
    setAnio(anio);
    }

    void Fecha::cargarFechaAuto(){
    cout<<"Ingrese el dia de la fecha:";
    cin>>dia;
    setDia(dia);
    cout<<"Ingrese el mes de la fecha:";
    cin>>mes;
    setMes(mes);
    cout<<"Ingrese el anio de la fecha:";
    cin>>anio;
    setAnio(anio);
    }

    void Fecha::mostrarFecha(){
    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio<<endl;
    }
