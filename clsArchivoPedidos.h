#ifndef CLSARCHIVOPEDIDOS_H_INCLUDED
#define CLSARCHIVOPEDIDOS_H_INCLUDED

class ArchivoPedidos{
    private:
        char nombre[30];
    public:
        ArchivoPedidos(const char *n="pedidos.dat"){strcpy(nombre,n);}
        void limpiarArchivoPedidos();
        bool grabarRegistroPedidos(Pedido obj);
        bool modificarRegistroPedidos(Pedido obj, int pos);
        Pedido leerRegistroPedidos(int pos);
        void listarArchivoPedidos();
        int contarRegistrosPedidos();
        int buscarRegistroPedidos(int num);
};

void ArchivoPedidos::limpiarArchivoPedidos(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

bool ArchivoPedidos::grabarRegistroPedidos(Pedido obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return false;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

bool ArchivoPedidos::modificarRegistroPedidos(Pedido obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return false;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

Pedido ArchivoPedidos::leerRegistroPedidos(int pos){
    Pedido obj;
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

int ArchivoPedidos::contarRegistrosPedidos(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Pedido);
}

void ArchivoPedidos::listarArchivoPedidos(){
    int cant=contarRegistrosPedidos();
    Pedido obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistroPedidos(i);
        if(obj.getEstado()==true){
        obj.Mostrar();
        cout<<endl;}
    }
}

int ArchivoPedidos::buscarRegistroPedidos(int num){
    int cant=contarRegistrosPedidos();
    Pedido obj;
    int pos = -1;
    for(int i=0; i<cant; i++){
        obj=leerRegistroPedidos(i);
        if(num==obj.getNumeroPedido()){
            pos= i;
        }else {pos = -1;}
    }
    return pos;
}

#endif // CLSARCHIVOPEDIDOS_H_INCLUDED
