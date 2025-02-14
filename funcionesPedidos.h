#ifndef FUNCIONESPEDIDOS_H_INCLUDED
#define FUNCIONESPEDIDOS_H_INCLUDED

double obtenerPrecio(int id);

int numeroAutomaticoPedidos(){
    Pedido obj;
    ArchivoPedidos arcPed("pedidos.dat");
    int i, num = 1;
    int cantPed = arcPed.contarRegistrosPedidos();

        for(i = 1; i <= cantPed; i++){
            obj = arcPed.leerRegistroPedidos(i);
            num++;
        }
    return num;
}



bool numeroVerificadoCliente(int n) {
    Cliente obj;
    ArchivoClientes arcCli("clientes.dat");
    int cantCli = arcCli.contarRegistrosClientes();
    bool encontrado = false;

    for (int j = 0; j < cantCli; j++) {
        obj = arcCli.leerRegistroClientes(j);
        if (n == obj.getNumeroCliente()) {
            encontrado = true;
            break;
        }
    }
    return encontrado;
}


bool numeroVerificadoEmpleado(int n) {
    Empleados obj;
    ArchivoEmpleados arcEmp("empleados.dat");
    int cantEmp = arcEmp.contarRegistrosEmpleados();
    bool encontrado = false;

    for (int j = 0; j < cantEmp; j++) {
        obj = arcEmp.leerRegistroEmpleados(j);
        if (n == obj.getIdEmpleado()) {
            encontrado = true;
            break;
        }
    }
    return encontrado;
}

bool numeroVerificadoCarta(int n) {
    Carta obj;
    ArchivoCarta arcCar("carta.dat");
    int cantCar = arcCar.contarRegistrosCarta();
    bool encontrado = false;

    for (int j = 0; j < cantCar; j++) {
        obj = arcCar.leerRegistroCarta(j);
        if (n == obj.getIdCarta()) {
            encontrado = true;
            break;
        }
    }
    return encontrado;
}


void listarPedidos(){
    ArchivoPedidos arcPed;
    arcPed.listarArchivoPedidos();
}

void altaPedido(){
    ArchivoPedidos arcPed("pedidos.dat");

    Pedido obj;
    obj.Cargar();
    int pos=arcPed.buscarRegistroPedidos(obj.getNumeroPedido());
    if(pos >= 0){
        cout<<"YA EXISTE PEDIDO CON ESE NUMERO EN EL ARCHIVO"<<endl;
        obj.setEstado(false);
    }
    if(obj.getEstado()==true){
        if (arcPed.grabarRegistroPedidos(obj)){
        cout<<"EL REGISTRO FUE GRABADO CON EXITO"<<endl;
        }else{
        cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
        }
    }
}

void modificarMetodoPago() {
    ArchivoVenta arcVen("ventas.dat");
    ArchivoPedidos arcPed("pedidos.dat");
    Venta ven;
    Pedido obj;
    int num;
    int cantVen = arcVen.contarRegistrosVentas();
    double totalNuevo;


        cout<<"INGRESE EL NUMERO DE PEDIDO A MODIFICAR: ";
        cin>>num;

        int pos = arcPed.buscarRegistroPedidos(num);
        if (pos < 0) {
        cout << "EL NUMERO DE PEDIDO NO EXISTE EN EL ARCHIVO" << endl;
        return;
        }
        obj = arcPed.leerRegistroPedidos(pos);
        if (obj.getEstado()){
        cout << "METODO DE PAGO ACTUAL: " << obj.getMetodoPago() << endl;
        cout << "INGRESE NUEVO METODO DE PAGO (1, 2, o 3): ";
        int nuevoMetodoPago;
        cin >> nuevoMetodoPago;
        if (nuevoMetodoPago == 1 || nuevoMetodoPago == 2 || nuevoMetodoPago == 3) {
            cout << "METODO CONFIRMADO" << endl;
        if (nuevoMetodoPago == 3 || obj.getMetodoPago() == 3){

            if (nuevoMetodoPago == 3){

                totalNuevo = (obj.getTotal() + (obj.getTotal()*0.15));
                obj.setTotal(totalNuevo);
                obj.setMetodoPago(nuevoMetodoPago);
            }else {

                totalNuevo = (obtenerPrecio(obj.getIdCarta())*obj.getCantidad())+obj.getExtra();
                obj.setTotal(totalNuevo);
                obj.setMetodoPago(nuevoMetodoPago);

            }
        }
        }
        }
       if(arcPed.modificarRegistroPedidos(obj, pos)){

         cout << "NUEVO TOTAL: $" <<totalNuevo<<endl;
         cout << "MODIFICADO CON EXITO" << endl;

    } else {
        cout << "NO PUDO SER MODIFICADO" << endl;
    }


    for (int i = 0; i < cantVen; i++) {
        ven = arcVen.leerRegistroVentas(i);
            if (ven.getNumeroPedidoVenta() == obj.getNumeroPedido()) {

                ven.setTotalPrecio(totalNuevo);

                    if (arcVen.modificarRegistroVentas(ven, i)) {
                       cout<<""<<endl;
                    } else {
                        cout<<""<<endl;
                    }
                }
            }
}

void bajaLogicaPedidos() {
    ArchivoPedidos arcPed;
    Pedido reg;
    int num;
    int pos;
    cout << "INGRESE EL NUMERO DE PEDIDO A DAR DE BAJA: ";
    cin >> num;
    pos = arcPed.buscarRegistroPedidos(num);
    if (pos < 0) {
        cout << "EL NUMERO DE PEDIDO INGRESADO NO FUE ENCONTRADO" << endl;
        return;
    }
    reg = arcPed.leerRegistroPedidos(pos);
    reg.Mostrar();
    cout << "¿DESEA BORRAR EL REGISTRO? (S/N): ";
    char respuesta;
    cin >> respuesta;
    if (respuesta == 'S' || respuesta == 's') {
        reg.setEstado(false);
    if (arcPed.modificarRegistroPedidos(reg, pos)) {
        cout << "REGISTRO ELIMINADO" << endl;
    } else {
        cout << "NO SE PUDO ELIMINAR EL REGISTRO" << endl;
    }
}else return;
}

void buscarRegistroPedidos(){

    int num;
    cout << "INGRESE EL NUMERO DE PEDIDO A BUSCAR: ";
    cin >> num;
    system("cls");
    Pedido obj;
    ArchivoPedidos arcPed;
    int cant=arcPed.contarRegistrosPedidos();

    for(int i=0; i<cant; i++){
        obj=arcPed.leerRegistroPedidos(i);

        if(num==obj.getNumeroPedido() && obj.getEstado()){
        obj.Mostrar();
        break;
        }
    }
}

double obtenerPrecio(int id){
double precio;
ArchivoCarta arcCar("carta.dat");
Carta reg;
int cant = arcCar.contarRegistrosCarta();

for (int i= 0; i<cant; i++){

    reg = arcCar.leerRegistroCarta(i);
    if (reg.getIdCarta() == id){
        precio = reg.getPrecio();
    }
}
return precio;
}
#endif // FUNCIONESPEDIDOS_H_INCLUDED
