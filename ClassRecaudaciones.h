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
    nuevaRecaudacion=fopen("Recaudaciones.dat","ab");
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


//RECAUDACION TOTAL
void recaudacionTotal(){
FILE *recaudacionT;
recaudacionT=fopen("Recaudaciones.dat","rb");
if(recaudacionT==NULL){
cout<<"NO SE PUDO ABRIR ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
float totalR=0;
while(fread(&obj,sizeof(Recaudacion),1,recaudacionT)!=0){
totalR+=obj.getIngreso();
}
fclose(recaudacionT);
cout<<"LA RECAUDACION TOTAL ES DE: "<<totalR<<endl;
cout<<endl;
system("pause");
system("cls");
}

//RECAUDACION POR MES Y ANIO

void recaudacionMesyAnio(){
int mes;
int anio;
int recaudacionT=0;
cout<<"Ingrese el anio:";
cin>>anio;
cout<<"Ingrese el mes para obtener informacion de sus recaudaciones:";
cin>>mes;
FILE *informacion;
informacion=fopen("Recaudaciones.dat","rb");
if(informacion==NULL){
    cout<<"Error al obtener las recaudaciones"<<endl;
    fclose(informacion);
    return;
}
Recaudacion obj;
while(fread(&obj,sizeof(Recaudacion),1,informacion)!=0){
    if(anio==obj.getAnio() && mes==obj.getMes()){
        recaudacionT+=obj.getIngreso();
    }
}
cout<<"La recaudacion es de:"<<recaudacionT<<endl;
system("pause");
system("cls");
cout<<endl;
fclose(informacion);
}




//RECAUDACION POR ANIO
void recaudacionXanio(){
int ingresos=0;
FILE *anios;
anios=fopen("Recaudaciones.dat","rb");
if(anios==NULL){
cout<<"No se pudo abrir este archivo"<<endl;
return;
}
Recaudacion obj;
int anio;
cout<<"Ingrese el anio: ";
cin>>anio;
cout<<endl;
while(fread(&obj,sizeof(Recaudacion),1,anios)!=0){
if(obj.getAnio()==anio){
ingresos+=obj.getIngreso();
}
}
cout<<"La recaudacion para el anio "<<anio<<" es de: "<<ingresos<<endl;
cout<<endl;
fclose(anios);
system("pause");
system("cls");
}

void recaudacionPorId(){
int idV;
float recaudacion=0;
cout<<"Ingrese el id del vendedor para saber sus recaudaciones:";
cin>>idV;
FILE *informacion;
informacion=fopen("Recaudaciones.dat","rb");
if(informacion==NULL){
    cout<<"Error al obtener la informacion del vendedor..."<<endl;
}
Recaudacion obj;
while(fread(&obj,sizeof(Recaudacion),1,informacion)!=0){
    if(obj.getIdVendedor()==idV){
        recaudacion+=obj.getIngreso();
    }
}
cout<<"Las recaudaciones del vendedor son:"<<recaudacion;
cout<<endl;
system("pause");
system("cls");
fclose(informacion);
}

};

#endif // CLASSRECAUDACIONES_H_INCLUDED
