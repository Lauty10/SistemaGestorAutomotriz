#ifndef CLASSRECAUDACIONES_H_INCLUDED
#define CLASSRECAUDACIONES_H_INCLUDED

class Recaudacion{
private:
    int ingreso;
    int mesDelIngreso;
    int anioDelIngreso;
public:
    Recaudacion(int i=0,int m=0,int a=0){
    this->ingreso=i;
    this->mesDelIngreso=m;
    this->anioDelIngreso=a;
    }
    void setIngreso(int i){
    this->ingreso=i;
    }
    void setMesIngreso(int i){
    this->mesDelIngreso=i;
    }
    void setAnioIngreso(int i){
    this->anioDelIngreso=i;
    }
    int getIngreso(){
    return ingreso;
    }
    int getMes(){
    return mesDelIngreso;
    }
    int getAnio(){
    return anioDelIngreso;
    }

    void cargarRecaudacion(int importe, int mes, int anio){
    FILE *nuevaRecaudacion;
    nuevaRecaudacion=fopen("Recaudaciones.dat","ab");
    if(nuevaRecaudacion==NULL){
        cout<<"Error al grabar nueva recaudacion"<<endl;
    }
    Recaudacion objR;
    objR.setIngreso(importe);
    objR.setMesIngreso(mes);
    objR.setAnioIngreso(anio);
    fwrite(&objR,sizeof(Recaudacion),1,nuevaRecaudacion);
    cout<<"Venta realizada con exito..."<<endl;
    fclose(nuevaRecaudacion);
    }
};

#endif // CLASSRECAUDACIONES_H_INCLUDED
