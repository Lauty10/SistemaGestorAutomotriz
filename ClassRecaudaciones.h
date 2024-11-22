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
system("pause");
system("cls");
}

//RECAUDACION POR MES Y ANIO

void recaudacionMesyAnio(){
int opcion;
int anio;
cout<<"INGRESE EL ANIO DE LA RECAUDACION: ";
cin>>anio;
while(true){
cout<<"1-)Enero"<<endl;
cout<<"2-)Febrero"<<endl;
cout<<"3-)Marzo"<<endl;
cout<<"4-)Abril"<<endl;
cout<<"5-)Mayo"<<endl;
cout<<"6-)Junio"<<endl;
cout<<"7-)Julio"<<endl;
cout<<"8-)Agosto"<<endl;
cout<<"9-)Septiembre"<<endl;
cout<<"10-)Octubre"<<endl;
cout<<"11-)Noviembre"<<endl;
cout<<"12-)Diciembre"<<endl;
cout<<"0-)Salir..."<<endl;
cin>>opcion;
switch(opcion){

case 0 :
    system("cls");
//    recaudaciones();
    break;
case 1:
    system("cls");
    recaudacionEnero(anio);
    break;

case 2:
    system("cls");
    recaudacionFebrero(anio);
    break;

case 3:
    system("cls");
    recaudacioMarzo(anio);
    break;

case 4:
    system("cls");
    recaudacioAbril(anio);
    break;

case 5:
    system("cls");
    recaudacioMayo(anio);
    break;

case 6:
    system("cls");
    recaudacionJunio(anio);
    break;

case 7:
    system("cls");
    recaudacionJulio(anio);
    break;

case 8:
    system("cls");
    recaudacionAgosto(anio);
    break;

case 9:
    system("cls");
    recaudacionSeptiembre(anio);
    break;

case 10:
    system("cls");
    recaudacionOctubre(anio);
    break;

case 11:
    system("cls");
    recaudacionNoviembre(anio);
    break;

case 12:
    system("cls");
    recaudacionDiciembre(anio);
    break;
}
}
}

//RECAUDACION ENERO
void recaudacionEnero(int anio){
FILE *enero;
enero=fopen("Recaudaciones.dat","rb");
if(enero==NULL){
cout<<"NO SE PUEDE ABRIR ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
int eneroR=0;
while(fread(&obj,sizeof(Recaudacion),1,enero)!=0){
if(obj.getMes()==1&&obj.getAnio()==anio){
eneroR+=obj.getIngreso();
}
}
fclose(enero);
cout<<"La recaudacion de enero del anio: "<<anio<<" es de: "<<eneroR<<endl;
system("pause");
system("cls");
}

//RECAUDACION FEBRERO
void recaudacionFebrero(int anio){
FILE *febrero;
febrero=fopen("Recaudaciones.dat","rb");
if(febrero==NULL){
cout<<"NO SE PUEDE ABRIR ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
int febreroR=0;
while(fread(&obj,sizeof(Recaudacion),1,febrero)!=0){
if(obj.getMes()==2&&obj.getAnio()==anio){
febreroR+=obj.getIngreso();
}
}
fclose(febrero);
cout<<"La recaudacion de febrero del anio: "<<anio<<" es de: "<<febreroR<<endl;
system("pause");
system("cls");
}

//RECAUDACION MARZO
void recaudacioMarzo(int anio){
FILE *marzo;
marzo=fopen("Recaudaciones.dat","rb");
if(marzo==NULL){
cout<<"NO SE PUEDE ABRIR ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
int marzoR=0;
while(fread(&obj,sizeof(Recaudacion),1,marzo)!=0){
if(obj.getMes()==3&&obj.getAnio()==anio){
marzoR+=obj.getIngreso();
}
}
fclose(marzo);
cout<<"La recaudacion de marzo del anio: "<<anio<<" es de: "<<marzoR<<endl;
system("pause");
system("cls");
}

//RECAUDACION ABRIL
void recaudacioAbril(int anio){
FILE *abril;
abril=fopen("Recaudaciones.dat","rb");
if(abril==NULL){
cout<<"NO SE PUEDE ABRIR ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
int abrilR=0;
while(fread(&obj,sizeof(Recaudacion),1,abril)!=0){
if(obj.getMes()==4&&obj.getAnio()==anio){
abrilR+=obj.getIngreso();
}
}
fclose(abril);
cout<<"La recaudacion de abril del anio: "<<anio<<" es de: "<<abrilR<<endl;
system("pause");
system("cls");
}

//RECAUDACION MAYO
void recaudacioMayo(int anio){
FILE *mayo;
mayo=fopen("Recaudaciones.dat","rb");
if(mayo==NULL){
cout<<"NO SE PUEDE ABRIR ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
int mayoR=0;
while(fread(&obj,sizeof(Recaudacion),1,mayo)!=0){
if(obj.getMes()==5&&obj.getAnio()==anio){
mayoR+=obj.getIngreso();
}
}
fclose(mayo);
cout<<"La recaudacion de mayo del anio: "<<anio<<" es de: "<<mayoR<<endl;
system("pause");
system("cls");
}

//RECAUDACION JUNIO
void recaudacionJunio(int anio){
FILE *junio;
junio=fopen("Recaudaciones.dat","rb");
if(junio==NULL){
cout<<"NO SE PUEDE ABRIR ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
int junioR=0;
while(fread(&obj,sizeof(Recaudacion),1,junio)!=0){
if(obj.getMes()==6&&obj.getAnio()==anio){
junioR+=obj.getIngreso();
}
}
fclose(junio);
cout<<"La recaudacion de junio del anio: "<<anio<<" es de: "<<junioR<<endl;
system("pause");
system("cls");
}


//RECAUDACION JULIO
void recaudacionJulio(int anio){
FILE *julio;
julio=fopen("Recaudaciones.dat","rb");
if(julio==NULL){
cout<<"NO SE PUEDE ABRIR ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
int julioR=0;
while(fread(&obj,sizeof(Recaudacion),1,julio)!=0){
if(obj.getMes()==7&&obj.getAnio()==anio){
julioR+=obj.getIngreso();
}
}
fclose(julio);
cout<<"La recaudacion de julio del anio: "<<anio<<" es de: "<<julioR<<endl;
system("pause");
system("cls");
}


//RECAUDACION AGOSTO
void recaudacionAgosto(int anio){
FILE *agosto;
agosto=fopen("Recaudaciones.dat","rb");
if(agosto==NULL){
cout<<"NO SE PUEDE ABRIR ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
int agostoR=0;
while(fread(&obj,sizeof(Recaudacion),1,agosto)!=0){
if(obj.getMes()==8&&obj.getAnio()==anio){
agostoR+=obj.getIngreso();
}
}
fclose(agosto);
cout<<"La recaudacion de agosto del anio: "<<anio<<" es de: "<<agostoR<<endl;
system("pause");
system("cls");
}


//RECAUDACION SEPTIEMBRE
void recaudacionSeptiembre(int anio){
FILE *septiembre;
septiembre=fopen("Recaudaciones.dat","rb");
if(septiembre==NULL){
cout<<"NO SE PUEDE ABRIR ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
int septiembreR=0;
while(fread(&obj,sizeof(Recaudacion),1,septiembre)!=0){
if(obj.getMes()==9&&obj.getAnio()==anio){
septiembreR+=obj.getIngreso();
}
}
fclose(septiembre);
cout<<"La recaudacion de septiembre del anio: "<<anio<<" es de: "<<septiembreR<<endl;
system("pause");
system("cls");
}


//RECAUDACION OCTUBRE
void recaudacionOctubre(int anio){
FILE *octubre;
octubre=fopen("Recaudaciones.dat","rb");
if(octubre==NULL){
cout<<"NO SE PUEDE ABRIR ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
int octubreR=0;
while(fread(&obj,sizeof(Recaudacion),1,octubre)!=0){
if(obj.getMes()==10&&obj.getAnio()==anio){
octubreR+=obj.getIngreso();
}
}
fclose(octubre);
cout<<"La recaudacion de octubre del anio: "<<anio<<" es de: "<<octubreR<<endl;
system("pause");
system("cls");
}


//RECAUDACION NOVIEMBRE
void recaudacionNoviembre(int anio){
FILE *noviembre;
noviembre=fopen("Recaudaciones.dat","rb");
if(noviembre==NULL){
cout<<"NO SE PUEDE ABRIR ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
int noviembreR=0;
while(fread(&obj,sizeof(Recaudacion),1,noviembre)!=0){
if(obj.getMes()==11&&obj.getAnio()==anio){
noviembreR+=obj.getIngreso();
}
}
fclose(noviembre);
cout<<"La recaudacion de noviembre del anio: "<<anio<<" es de: "<<noviembreR<<endl;
system("pause");
system("cls");
}

//RECAUDACION DICIEMBRE
void recaudacionDiciembre(int anio){
FILE *diciembre;
diciembre=fopen("Recaudaciones.dat","rb");
if(diciembre==NULL){
cout<<"NO SE PUEDE ABRIR ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
int diciembreR=0;
while(fread(&obj,sizeof(Recaudacion),1,diciembre)!=0){
if(obj.getMes()==12&&obj.getAnio()==anio){
diciembreR+=obj.getIngreso();
}
}
fclose(diciembre);
cout<<"La recaudacion de diciembre del anio: "<<anio<<" es de: "<<diciembreR<<endl;
system("pause");
system("cls");
}


//RECAUDACION POR ANIO
void recaudacionXanio(){
FILE *anios;
anios=fopen("Recaudaciones.dat","rb");
if(anios==NULL){
cout<<"NO SE PUDO ABRI ESTE ARCHIVO"<<endl;
return;
}
Recaudacion obj;
int anio;
float anioR=0;
cout<<"Ingrese el anio: ";
cin>>anio;
cout<<endl;
while(fread(&obj,sizeof(Recaudacion),1,anios)!=0){
if(obj.getAnio()==anio){
anioR+=getIngreso();
}
}
fclose(anios);
cout<<"La recaudacion para el anio "<<anio<<" es de: "<<anioR<<endl;
system("pause");
system("cls");
}
};

#endif // CLASSRECAUDACIONES_H_INCLUDED
