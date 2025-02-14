#ifndef CLSARCHIVOCARTA_H_INCLUDED
#define CLSARCHIVOCARTA_H_INCLUDED

class ArchivoCarta{
    private:
        char nombre[30];
    public:
        ArchivoCarta(const char *n="carta.dat"){strcpy(nombre,n);}
        void limpiarArchivoCarta();
        bool grabarRegistroCarta(Carta obj);
        bool modificarRegistroCarta(Carta obj, int pos);
        Carta leerRegistroCarta(int pos);
        void listarArchivoCarta();
        int contarRegistrosCarta();
        int buscarRegistroCarta(int num);
};

void ArchivoCarta::limpiarArchivoCarta(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

bool ArchivoCarta::grabarRegistroCarta(Carta obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return false;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

bool ArchivoCarta::modificarRegistroCarta(Carta obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return false;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

Carta ArchivoCarta::leerRegistroCarta(int pos){
    Carta obj;
    obj.setIdCarta(-1);
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setIdCarta(-2);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoCarta::contarRegistrosCarta(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Carta);
}

void ArchivoCarta::listarArchivoCarta(){
    int cant=contarRegistrosCarta();
    Carta obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistroCarta(i);

        if(obj.getEstado()==true){

        obj.Mostrar();
        cout<<endl;
        }
    }
}

int ArchivoCarta::buscarRegistroCarta(int num){
    int cant=contarRegistrosCarta();
    int pos = -1;
    Carta obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistroCarta(i);
        if(num==obj.getIdCarta()){
            pos = i;
        }else{pos = -1;}
    }
    return pos;
}

#endif // CLSARCHIVOCARTA_H_INCLUDED
