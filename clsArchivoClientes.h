#ifndef CLSARCHIVOCLIENTES_H_INCLUDED
#define CLSARCHIVOCLIENTES_H_INCLUDED

class ArchivoClientes{
    private:
        char nombre[30];
    public:
        ArchivoClientes(const char *n="clientes.dat"){strcpy(nombre,n);}
        void limpiarArchivoClientes();
        bool grabarRegistroClientes(Cliente obj);
        bool modificarRegistroClientes(Cliente obj, int pos);
        Cliente leerRegistroClientes(int pos);
        void listarArchivoClientes();
        int contarRegistrosClientes();
        int buscarRegistroClientes(int num);
};

void ArchivoClientes::limpiarArchivoClientes(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

bool ArchivoClientes::grabarRegistroClientes(Cliente obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return false;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

bool ArchivoClientes::modificarRegistroClientes(Cliente obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return false;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

Cliente ArchivoClientes::leerRegistroClientes(int pos){
    Cliente obj;
    obj.setNumeroCliente(-1);
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setNumeroCliente(-2);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoClientes::contarRegistrosClientes(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Cliente);
}

void ArchivoClientes::listarArchivoClientes(){
    int cant=contarRegistrosClientes();
    Cliente obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistroClientes(i);

        if(obj.getEstado()==true){
        obj.Mostrar();
        cout<<endl;}
    }
}

int ArchivoClientes::buscarRegistroClientes(int num){
    int cant=contarRegistrosClientes();
    int pos = -1;
    Cliente obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistroClientes(i);
        if(num==obj.getNumeroCliente()){
            pos = i;
        }else {pos = -1;}
    }
    return pos;
}



#endif // CLSARCHIVOCLIENTES_H_INCLUDED
