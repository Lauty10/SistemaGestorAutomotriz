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
void setIngreso(int i);
void setMesIngreso(int i);
void setAnioIngreso(int i);
void setIdVendedor(int i);
int getIdVendedor();
int getIngreso();
int getMes();
int getAnio();
void cargarRecaudacion(int importe, int mes, int anio, int idDelVendedor);
void recaudacionTotal();
void recaudacionMesyAnio();
void recaudacionXanio();
void recaudacionPorId();

};

#endif // CLASSRECAUDACIONES_H_INCLUDED
