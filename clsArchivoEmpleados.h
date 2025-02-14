#ifndef CLSARCHIVOEMPLEADOS_H_INCLUDED
#define CLSARCHIVOEMPLEADOS_H_INCLUDED

class ArchivoEmpleados{
    private:
        char nombre[30];
    public:
        ArchivoEmpleados(const char *n="empleados.dat"){strcpy(nombre,n);}
        void limpiarArchivoEmpleados();
        bool grabarRegistroEmpleados(Empleados obj);
        bool modificarRegistroEmpleados(Empleados obj, int pos);
        Empleados leerRegistroEmpleados(int pos);
        void listarArchivoEmpleados();
        int contarRegistrosEmpleados();
        int buscarRegistroEmpleados(int num);
};

void ArchivoEmpleados::limpiarArchivoEmpleados(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

bool ArchivoEmpleados::grabarRegistroEmpleados(Empleados obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return false;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

bool ArchivoEmpleados::modificarRegistroEmpleados(Empleados obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return false;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

Empleados ArchivoEmpleados::leerRegistroEmpleados(int pos){
    Empleados obj;
    obj.setIdEmpleado(-1);
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setIdEmpleado(-2);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoEmpleados::contarRegistrosEmpleados(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Empleados);
}

void ArchivoEmpleados::listarArchivoEmpleados(){
    int cant=contarRegistrosEmpleados();
    Empleados obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistroEmpleados(i);

        if(obj.getEstado()==true){
        obj.Mostrar();
        cout<<endl;}
    }
}

int ArchivoEmpleados::buscarRegistroEmpleados(int num){
    int cant=contarRegistrosEmpleados();
    int pos= -1;
    Empleados obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistroEmpleados(i);
        if(num==obj.getIdEmpleado()){
              pos = i;
              break;
        }
    }
    return pos;
}


#endif // CLSARCHIVOEMPLEADOS_H_INCLUDED
