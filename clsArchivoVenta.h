#ifndef CLSARCHIVOVENTA_H_INCLUDED
#define CLSARCHIVOVENTA_H_INCLUDED
class ArchivoVenta {
private:
        char nombre[30];
    public:
        ArchivoVenta(const char *n="ventas.dat"){strcpy(nombre,n);}
        void limpiarArchivoVentas();
        bool grabarRegistroVentas(Venta obj);
        bool modificarRegistroVentas(Venta obj, int pos);
        Venta leerRegistroVentas(int pos);
        void listarArchivoVentas();
        int contarRegistrosVentas();
        int buscarRegistroVentas(int num);
};


void ArchivoVenta::limpiarArchivoVentas() {
    FILE*p = fopen("ventas.dat", "wb");
    if (p == NULL) { return; }
    fclose(p);
}

bool ArchivoVenta::grabarRegistroVentas(Venta obj) {
    FILE* p = fopen("ventas.dat", "ab");
    if (p == NULL) { return false; }
    fwrite(&obj, sizeof(obj), 1, p);
    fclose(p);
    return true;
}
bool ArchivoVenta::modificarRegistroVentas(Venta obj, int pos) {
    FILE* p = fopen("ventas.dat", "rb+");
    if (p == NULL) {
        return false;
    }
    fseek(p, pos * sizeof(Venta), SEEK_SET);
    fwrite(&obj, sizeof(Venta), 1, p);
    fclose(p);
    return true;
}


Venta ArchivoVenta::leerRegistroVentas(int pos) {
    Venta obj;
    obj.setNumeroPedidoVenta(-1);
    FILE* p = fopen("ventas.dat", "rb");
    if (p == NULL) {
        obj.setNumeroPedidoVenta(-2);
        return obj;
    }
    fseek(p, pos * sizeof(obj), 0);
    fread(&obj, sizeof(obj), 1, p);
    fclose(p);
    return obj;
}

int ArchivoVenta::contarRegistrosVentas() {
    FILE* p = fopen("ventas.dat", "rb");
    if (p == NULL) { return -1; }
    fseek(p, 0, 2);
    int cantBytes = ftell(p);
    fclose(p);
    return cantBytes / sizeof(Venta);
}

void ArchivoVenta::listarArchivoVentas() {
    int cant = contarRegistrosVentas();
    Venta obj;
    for (int i = 0; i < cant; i++) {
        obj = leerRegistroVentas(i);
        if (obj.getEstado() == true) {
            obj.Mostrar();
            cout << endl;
        }
    }
}

int ArchivoVenta::buscarRegistroVentas(int num) {
    int cant = contarRegistrosVentas();
    Venta obj;
    int pos = -1;
    for (int i = 0; i < cant; i++) {
        obj = leerRegistroVentas(i);
        if (num == obj.getNumeroPedidoVenta()) {
            pos = i;
        }else {pos = -1;}
    }
    return pos;
}

#endif // CLSARCHIVOVENTA_H_INCLUDED
