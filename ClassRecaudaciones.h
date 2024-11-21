#ifndef CLASSRECAUDACIONES_H_INCLUDED
#define CLASSRECAUDACIONES_H_INCLUDED

class Recaudacion{
private:
    int ingreso;
    int mesDelIngreso;
    int anioDelIngreso;
    int idVendedor;
public:
    Recaudacion(int i=0,int m=0,int a=0,int id=0){
    this->ingreso=i;
    this->mesDelIngreso=m;
    this->anioDelIngreso=a;
    this->idVendedor=id;
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
    void setIdVendedor(int i){
    this->idVendedor=i;
    }
    int getIdVendedor(){
    return idVendedor;
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

    void cargarRecaudacion(int importe, int mes, int anio, int idDelVendedor){
    FILE *nuevaRecaudacion;
    nuevaRecaudacion=fopen("Recaudaciones.dat","wb");
    if(nuevaRecaudacion==NULL){
        cout<<"Error al grabar nueva recaudacion"<<endl;
    }
    Recaudacion objR;
    objR.setIngreso(importe);
    objR.setMesIngreso(mes);
    objR.setAnioIngreso(anio);
    objR.setIdVendedor(idDelVendedor);
    fwrite(&objR,sizeof(Recaudacion),1,nuevaRecaudacion);
    cout<<"Venta realizada con exito..."<<endl;
    fclose(nuevaRecaudacion);
    }
};

#endif // CLASSRECAUDACIONES_H_INCLUDED
