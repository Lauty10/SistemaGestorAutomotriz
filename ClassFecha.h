#ifndef CLASSFECHA_H_INCLUDED
#define CLASSFECHA_H_INCLUDED

class Fecha{
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha(int d=0, int m=0, int a=0){
    this->dia=d;
    this->mes=m;
    this->anio=a;
    }
    void setDia(int d){
    this->dia=d;
    }
    void setMes(int m){
    this->mes=m;
    }
    void setAnio(int a){
    this->anio=a;
    }
    int getDia(){
    return dia;
    }
    int getMes(){
    return mes;
    }
    int getAnio(){
    return anio;
    }

    void cargarFecha(){
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

    void cargarFechaAuto(){
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

    void mostrarFecha(){
    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio<<endl;
    }


};


#endif // CLASSFECHA_H_INCLUDED
