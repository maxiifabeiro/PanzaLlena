#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED
void puntoA();
void puntoB();
void puntoC();
void puntoD();
void solucionPunto2();
void solucionPunto3();

void menuReportes(){
    while(true){
        system("cls");
        int opc;
        recuadro(40, 7, 40, 16, cAMARILLO, cNEGRO);
        gotoxy(45,9);
        cout<<"MENU REPORTES"<<endl;
        linecolor(45,10,22,cAMARILLO);
        gotoxy(45,11);
        cout<<"1 - PUNTO A"<<endl;
        gotoxy(45,12);
        cout<<"2 - PUNTO B"<<endl;
        gotoxy(45,13);
        cout<<"3 - PUNTO C"<<endl;
        gotoxy(45,14);
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        gotoxy(45,15);
        linecolor(45,16,22,cAMARILLO);
        gotoxy(45,17);
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                puntoA();
                break;
            case 2:
                puntoB();
                break;
            case 3:
                puntoC();
                break;
            case 4:
                puntoD();
                break;
            case 0:
                return;
            default:
                cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
                system("pause");
                system("cls");
                return;
        }
        system("pause");
    }
}
///Generar un archivo que contenga las hamburguesas con un valor superior a 5000,
///el archivo debe contener nombre, precio y estado y mostrarlo
class PuntoA {
private:
    char nombre [30];
    double precio;
    bool estado;
public:
    void setNombre(const char * n){strcpy(nombre, n);}
    void setPrecio(double p){precio = p;}
    void setEstado(bool e){estado = e;}
    const char* getNombre(){return nombre;}
    double getPrecio(){return precio;}
    bool getEstado(){return estado;}

    void Mostrar(){
    cout<<nombre<<endl;
    cout<<precio<<endl;
    }
};
class ArchivoPuntoA{
private:
    char nombre [30];
public:
    ArchivoPuntoA(const char* n="ArchivoPuntoA.dat"){strcpy(nombre, n);}

    bool grabarRegistroP(PuntoA obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return false;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}
PuntoA leerRegistroCartaP(int pos){
    PuntoA obj;
    obj.setPrecio(-1);
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setPrecio(-2);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
int contarRegistrosCartaP(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (PuntoA);
}

};
void puntoA(){
ArchivoCarta arcCar;
ArchivoPuntoA arcP;
Carta reg;
PuntoA aux;
int cant = arcCar.contarRegistrosCarta();
int c=0;
PuntoA *Reg;
for (int i = 0; i<cant; i++){
    reg = arcCar.leerRegistroCarta(i);

    if(reg.getPrecio() > 5000 && reg.getEstado()){
     aux.setNombre(reg.getNombre());
     aux.setPrecio(reg.getPrecio());
     aux.setEstado(true);
     c++;
     if(arcP.grabarRegistroP(aux)){cout<<"exito"<<endl;}
    }
}
Reg = new PuntoA [c];
if(Reg == nullptr){return;}

for (int i=0; i<c;i++){
    Reg[i] = arcP.leerRegistroCartaP(i);
    Reg[i].Mostrar();
}
delete []Reg;
}
/*HACER UNA FUNCION QUE CREE UN VECTOR DE FORMA DINAMICA PARA CARGAR LOS REGISTROS DEL ARCHIVO DE CARTA
QUE SEAN DE UNA CATEGORIA QUE SE INGRESA POR TECLADO. MOSTRAR EL CONTENIDO DEL VECTOR*/
void puntoB(){
ArchivoCarta arcCar;
Carta reg;
int cant = arcCar.contarRegistrosCarta();
char nuevo;
cout<<"ingrese la cat a mostrar: ";
cin>>nuevo;

int c =0;
Carta *Reg;
for (int i=0; i<cant;i++){
    reg = arcCar.leerRegistroCarta(i);

    if(nuevo == reg.getCategoria()){
    c++;
    }
}

Reg = new Carta[c];
if(Reg == nullptr){return;}

int posA=0;

for (int i=0; i<cant;i++){
    reg = arcCar.leerRegistroCarta(i);

    if(nuevo == reg.getCategoria()){
    Reg[posA] = arcCar.leerRegistroCarta(i);
    posA++;
    }
}
for (int i=0; i<c;i++){
    Reg[i].Mostrar();

}
}
///CANTIDAD DE PEDIDOS REALIZADOS POR UN CLIENTE QUE SE INGRESA POR TECLADO
void puntoC(){
ArchivoPedidos arcPed;

Pedido reg;
int cant = arcPed.contarRegistrosPedidos();
int nuevo;
cout<<"ingrese el num cliente a mostrar: ";
cin>>nuevo;

int c =0;

for (int i=0; i<cant;i++){
    reg = arcPed.leerRegistroPedidos(i);

    if(nuevo == reg.getNumeroCliente()){
    c++;
    }
}
cout<<"ese cliente tuvo : "<<c<<" cantidad de pedidos"<<endl;
}
///SOBRECARGAR VENTAS
void puntoD() {
    ArchivoVenta arcVen;
    Venta reg;
    Venta ultimaVenta;

    int num;

    cout << "INGRESE EL ID DE VENTA A COMPARAR CON LA ULTIMA VENTA REGISTRADA: ";
    cin >> num;

    int cant = arcVen.contarRegistrosVentas();
    bool ventaEncontrada = false;

    for (int i = 0; i < cant; i++) {
        reg = arcVen.leerRegistroVentas(i);
        if (num == reg.getNumeroPedidoVenta()) {
            ventaEncontrada = true;
            break;
        }
    }

    if (!ventaEncontrada) {
        cout << "La venta con el ID proporcionado no se encontro" << endl;
        return;
    }

    ultimaVenta = arcVen.leerRegistroVentas(cant - 1);

    if (reg > ultimaVenta) {
        cout << "La venta ingresada es mayor que la ultima venta registrada." << endl;
    } else {
        cout << "La venta ingresada es menor o igual que la ultima venta registrada." << endl;
    }
}

/*HACER UNA FUNCION QUE CREE UN VECTOR DE FORMA DINAMICA PARA CARGAR LOS REGISTROS DEL ARCHIVO DE CARTA
QUE SEAN DE UNA CATEGORIA QUE SE INGRESA POR TECLADO. MOSTRAR EL CONTENIDO DEL VECTOR*/
void solucionPunto2(){
    char categoria;
    cout << "INGRESE CATEGORIA: " << endl;
    cin >> categoria;
    system("cls");
    Carta *p;
    Carta cat;
    ArchivoCarta archiCar("carta.dat");
    int cant = archiCar.contarRegistrosCarta();
    int cantCategoria = 0;
    for (int i = 0; i < cant; i++) {
         cat = archiCar.leerRegistroCarta(i);
        if (cat.getCategoria() == categoria) {
            cantCategoria++;
        }
    }
    if(cantCategoria == 0){
        cout<<"NO HAY CARTAS CON ESA CATEGORIA"<<endl;
        return;
    }
    p = new Carta[cantCategoria];
    if(p==NULL){
     cout<<"Error de asignacion de memoria"<<endl;
     return;
    }
    int posActual = 0;
    for (int i = 0; i < cant; i++) {
         cat = archiCar.leerRegistroCarta(i);
        if (cat.getCategoria() == categoria) {
            p[posActual] = cat;
            posActual++;
        }
    }
    for (int j = 0; j < cantCategoria; j++) {
        p[j].Mostrar();
        cout << endl;
    }
    delete[] p;
}

//cantidad de pedidos por un cliente que se ingresa por teclado
void solucionPunto3() {
    int cliente;
    cout << "INGRESE NUMERO DE CLIENTE: " << endl;
    cin >> cliente;
    system("cls");

    Cliente cli;
    Pedido ped;
    ArchivoClientes archCli("clientes.dat");
    ArchivoPedidos archPed("pedidos.dat");

    int cantCli = archCli.contarRegistrosClientes();
    int cantPed = archPed.contarRegistrosPedidos();

    bool clienteEncontrado = false;

    for (int i = 0; i < cantCli; i++) {
        cli = archCli.leerRegistroClientes(i);
        if (cli.getNumeroCliente() == cliente) {
            int cont = 0;
            for (int j = 0; j < cantPed; j++) {
                ped = archPed.leerRegistroPedidos(j);
                if (ped.getNumeroCliente() == cliente) {
                    cont++;
                }
            }
            cout << "CLIENTE: " << cli.getNombre() << " CANTIDAD DE PEDIDOS: " << cont << endl;
            clienteEncontrado = true;
            break;
        }
    }

    if (!clienteEncontrado) {
        cout << "No se encontraron pedidos para el cliente ingresado." << endl;
    }
}

bool operator==(const Carta &car) const {
        return getPrecio() == car.getPrecio();
}

#endif // REPORTES_H_INCLUDED
