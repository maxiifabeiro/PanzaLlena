#ifndef FUNCIONESCONFIGURACION_H_INCLUDED
#define FUNCIONESCONFIGURACION_H_INCLUDED

void backupEmpleados(){
    ArchivoEmpleados arcEmp;
    ArchivoEmpleados bkpEmp("empleados.bkp");
    Empleados obj;
    bkpEmp.limpiarArchivoEmpleados();
    int cant = arcEmp.contarRegistrosEmpleados();
    for (int i =0;i<cant ;i++ ){
        obj = arcEmp.leerRegistroEmpleados(i);
        bkpEmp.grabarRegistroEmpleados(obj);
    }
}

void backupClientes(){
    ArchivoClientes arcCli;
    ArchivoClientes bkpCli("clientes.bkp");
    Cliente obj;
    bkpCli.limpiarArchivoClientes();
    int cant = arcCli.contarRegistrosClientes();
    for (int i =0;i<cant ;i++ ){
        obj = arcCli.leerRegistroClientes(i);
        bkpCli.grabarRegistroClientes(obj);
    }
}

void backupCarta(){
    ArchivoCarta arcCar;
    ArchivoCarta bkpCar("carta.bkp");
    Carta obj;
    bkpCar.limpiarArchivoCarta();
    int cant = arcCar.contarRegistrosCarta();
    for (int i =0;i<cant ;i++ ){
        obj = arcCar.leerRegistroCarta(i);
        bkpCar.grabarRegistroCarta(obj);
    }
}

void backupPedidos(){
    ArchivoPedidos arcPed;
    ArchivoPedidos bkpPed("pedidos.bkp");
    Pedido obj;
    bkpPed.limpiarArchivoPedidos();
    int cant = arcPed.contarRegistrosPedidos();
    for (int i =0;i<cant ;i++ ){
        obj = arcPed.leerRegistroPedidos(i);
        bkpPed.grabarRegistroPedidos(obj);
    }
}

void backupVentas(){
    ArchivoVenta arcVen;
    ArchivoVenta bkpVen("ventas.bkp");
    Venta obj;
    bkpVen.limpiarArchivoVentas();
    int cant = arcVen.contarRegistrosVentas();
    for (int i =0;i<cant ;i++ ){
        obj = arcVen.leerRegistroVentas(i);
        bkpVen.grabarRegistroVentas(obj);
    }
}

void restaurarEmpleados(){
    ArchivoEmpleados arcEmp;
    ArchivoEmpleados bkpEmp("empleados.bkp");
    Empleados obj;
    arcEmp.limpiarArchivoEmpleados();
    int cant = bkpEmp.contarRegistrosEmpleados();
    for (int i =0;i<cant ;i++ ){
        obj = bkpEmp.leerRegistroEmpleados(i);
        arcEmp.grabarRegistroEmpleados(obj);
    }
}

void restaurarClientes(){
    ArchivoClientes arcCli;
    ArchivoClientes bkpCli("clientes.bkp");
    Cliente obj;
    arcCli.limpiarArchivoClientes();
    int cant = bkpCli.contarRegistrosClientes();
    for (int i =0;i<cant ;i++ ){
        obj = bkpCli.leerRegistroClientes(i);
        arcCli.grabarRegistroClientes(obj);
    }
}

void restaurarCarta(){
    ArchivoCarta arcCar;
    ArchivoCarta bkpCar("carta.bkp");
    Carta obj;
    arcCar.limpiarArchivoCarta();
    int cant = bkpCar.contarRegistrosCarta();
    for (int i =0;i<cant ;i++ ){
        obj = bkpCar.leerRegistroCarta(i);
        arcCar.grabarRegistroCarta(obj);
    }
}

void restaurarPedidos(){
    ArchivoPedidos arcPed;
    ArchivoPedidos bkpPed("pedidos.bkp");
    Pedido obj;
    arcPed.limpiarArchivoPedidos();
    int cant = bkpPed.contarRegistrosPedidos();
    for (int i =0;i<cant ;i++ ){
        obj = bkpPed.leerRegistroPedidos(i);
        arcPed.grabarRegistroPedidos(obj);
    }
}

void restaurarVentas(){
    ArchivoVenta arcVen;
    ArchivoVenta bkpVen("ventas.bkp");
    Venta obj;
    arcVen.limpiarArchivoVentas();
    int cant = bkpVen.contarRegistrosVentas();
    for (int i =0;i<cant ;i++ ){
        obj = bkpVen.leerRegistroVentas(i);
        arcVen.grabarRegistroVentas(obj);
    }
}

void establecerDatosdeInicio() {
    if(establecerDatosEmpleados()){cout<<"Datos empleados establecidos correctamente."<<endl;}
    if(establecerDatosClientes()){cout<<"Datos clientes establecidos correctamente."<<endl;}
    if(establecerDatosCarta()){cout<<"Datos carta establecidos correctamente."<<endl;}
    if(establecerDatosPedidos()){cout<<"Datos pedidos establecidos correctamente."<<endl;}
    if(establecerDatosVentas()){cout<<"Datos ventas establecidos correctamente."<<endl;}
}

bool establecerDatosEmpleados(){
    bool empValido=false;

    FILE* pEmp;
    FILE* pEmpleado;

    pEmpleado=fopen("empleados.ini","rb");
    if(pEmpleado==NULL){
        cout<<"Error al abrir los archivos."<<endl;
        return false;
    }

    pEmp = fopen("empleados.dat","ab");
    if(pEmp==NULL){
        cout<<"Error al abrir los archivos."<<endl;
        return false;
    }
    ArchivoEmpleados obj;
    obj.limpiarArchivoEmpleados();

    Empleados emple;

    while(fread(&emple,sizeof(Empleados),1,pEmpleado)==1){
        if(emple.getEstado()){
            fwrite(&emple,sizeof(Empleados),1,pEmp);
        }
    }
    fclose(pEmp);
    fclose(pEmpleado);
    empValido = true;


return empValido;
}

bool establecerDatosClientes(){
    bool cliValido=false;

    FILE* pCli;
    FILE* pCliente;

    pCliente=fopen("clientes.ini","rb");
    if(pCliente==NULL){
        cout<<"Error al abrir los archivos."<<endl;
        return false;
    }

    pCli = fopen("clientes.dat","ab");
    if(pCli==NULL){
        cout<<"Error al abrir los archivos."<<endl;
        return false;
    }
    ArchivoClientes obj;
    obj.limpiarArchivoClientes();

    Cliente client;

    while(fread(&client,sizeof(Cliente),1,pCliente)==1){
        if(client.getEstado()){
            fwrite(&client,sizeof(Cliente),1,pCli);
        }
    }
    fclose(pCli);
    fclose(pCliente);
    cliValido = true;


return cliValido;
}

bool establecerDatosCarta(){
    bool carValido=false;

    FILE* pCar;
    FILE* pCarta;

    pCarta=fopen("carta.ini","rb");
    if(pCarta==NULL){
        cout<<"Error al abrir los archivos."<<endl;
        return false;
    }

    pCar = fopen("carta.dat","ab");
    if(pCar==NULL){
        cout<<"Error al abrir los archivos."<<endl;
        return false;
    }
    ArchivoCarta obj;
    obj.limpiarArchivoCarta();

    Carta cart;

    while(fread(&cart,sizeof(Carta),1,pCarta)==1){
        if(cart.getEstado()){
            fwrite(&cart,sizeof(Carta),1,pCar);
        }
    }
    fclose(pCar);
    fclose(pCarta);
    carValido = true;


return carValido;
}

bool establecerDatosPedidos(){
    bool pedValido=false;

    FILE* pPed;
    FILE* pPedido;

    pPedido=fopen("pedidos.ini","rb");
    if(pPedido==NULL){
        cout<<"Error al abrir los archivos."<<endl;
        return false;
    }

    pPed = fopen("pedidos.dat","ab");
    if(pPed==NULL){
        cout<<"Error al abrir los archivos."<<endl;
        return false;
    }
    ArchivoPedidos obj;
    obj.limpiarArchivoPedidos();

    Pedido pedi;

    while(fread(&pedi,sizeof(Pedido),1,pPedido)==1){
        if(pedi.getEstado()){
            fwrite(&pedi,sizeof(Pedido),1,pPed);
        }
    }
    fclose(pPed);
    fclose(pPedido);
    pedValido = true;


return pedValido;
}

bool establecerDatosVentas(){
    bool venValido=false;

    FILE* pVen;
    FILE* pVenta;

    pVenta=fopen("ventas.ini","rb");
    if(pVenta==NULL){
        cout<<"Error al abrir los archivos."<<endl;
        return false;
    }

    pVen = fopen("ventas.dat","ab");
    if(pVen==NULL){
        cout<<"Error al abrir los archivos."<<endl;
        return false;
    }
    ArchivoVenta obj;
    obj.limpiarArchivoVentas();

    Venta vent;

    while(fread(&vent,sizeof(Venta),1,pVenta)==1){
        if(vent.getEstado()){
            fwrite(&vent,sizeof(Venta),1,pVen);
        }
    }
    fclose(pVen);
    fclose(pVenta);
    venValido = true;


return venValido;
}
#endif // FUNCIONESCONFIGURACION_H_INCLUDED
