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

    cout<<"Ingrese el dia de la fecha:";
    cin>>dia;
    fechaV(dia);
    setDia(dia);
    cout<<"Ingrese el mes de la fecha:";
    cin>>mes;
    fechaV(mes);
    setMes(mes);
    cout<<"Ingrese el anio de la fecha:";
    cin>>anio;
    fechaV(anio);
    setAnio(anio);
    cout<<"Fecha cargada correctamente..."<<endl;
    system("pause");
    system("cls");
    }

    void mostrarFecha(){
    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio<<endl;
    }

//VALIDACION
void fechaV(int f){
while(f==0){
cout<<"Campo inclompleto"<<endl;
cin>>f;
}
}

};


#endif // CLASSFECHA_H_INCLUDED
