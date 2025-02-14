#ifndef FUNCIONESVENTA_H_INCLUDED
#define FUNCIONESVENTA_H_INCLUDED

bool numeroVerificadoPlato(int n)
{
    ArchivoCarta arcCar("carta.dat");
    int cantCar = arcCar.contarRegistrosCarta();

    for (int j = 0; j < cantCar; j++)
    {
        Carta obj = arcCar.leerRegistroCarta(j);
        if (n == obj.getIdCarta())
        {
            return true;
        }
    }
    return false;
}
bool existeNumeroPedido(int numeroPedido) {
    ArchivoVenta arcVen("ventas.dat");
    int cant = arcVen.contarRegistrosVentas();
    Venta ven;
    for (int i = 0; i < cant; i++) {
        ven = arcVen.leerRegistroVentas(i);
        if (ven.getNumeroPedidoVenta() == numeroPedido) {
            return true;
        }
    }
    return false;
}

void listarVentas()
{
    ArchivoVenta arcVen("ventas.dat");
    arcVen.listarArchivoVentas();
}

void altaVentas()
{
    ArchivoVenta arcVen("ventas.dat");
    ArchivoPedidos arcPed("pedidos.dat");
    Venta ven;
    Pedido obj;
    int regDelDia = 0;
    int cant = arcPed.contarRegistrosPedidos();

    for (int i = 0; i < cant; i++) {
        obj = arcPed.leerRegistroPedidos(i);
        if (obj.getFecha() == ven.getFechaVenta()) {
            regDelDia++;
        }
    }
    cout << regDelDia << " REGISTROS DEL DIA" << endl;
    cout << "DESEA GUARDAR LOS REGISTROS EN VENTAS? (S/N):";
    char respuesta;
    cin >> respuesta;
    if (respuesta == 'S' || respuesta == 's') {
        int c = 0;
        for (int i = 0; i < cant; i++) {
            obj = arcPed.leerRegistroPedidos(i);
            if (obj.getFecha() == ven.getFechaVenta()) {
                if (!existeNumeroPedido(obj.getNumeroPedido())) {
                    ven.setNumeroPedidoVenta(obj.getNumeroPedido());
                    ven.setTotalPrecio(obj.getTotal());
                    ven.setFechaVenta(obj.getFecha());
                    ven.setEstado(true);
                    if (arcVen.grabarRegistroVentas(ven)) {
                        c++;
                    }
                } else {
                    cout << "El pedido " << obj.getNumeroPedido() << " ya existe en ventas." << endl;
                }
            }
        }
        cout << c << " REGISTROS GRABADOS CON EXITO" << endl;
    } else {
        return;
    }
}

void modificarPrecioTotal()
{
    ArchivoVenta arcVen("ventas.dat");

    Venta ven;
    int num;

    int cantVen = arcVen.contarRegistrosVentas();

    cout<<"INGRESE EL NUMERO DE VENTA A MODIFICAR: ";
    cin>>num;

    for (int i = 0; i < cantVen; i++)
    {
        ven = arcVen.leerRegistroVentas(i);

        if (ven.getNumeroPedidoVenta() == num)
        {

            cout<<"EL MONTO ACTUAL DE LA VENTA ES: $"<<ven.getTotalPrecio()<<endl;

            cout<<"INGRESE EL NUEVO MONTO: $";
            double nuevototal;
            cin>>nuevototal;
            ven.setTotalPrecio(nuevototal);
            if(arcVen.modificarRegistroVentas(ven, i))
            {
                cout<<"MONTO MODIFICADO CON EXITO"<<endl;
            }
            else cout<<"MONTO NO MODIFICADO"<<endl;
        }
    }
}

void buscarRegistroVenta()
{
    int num;
    cout<<"INGRESE NUMERO DE VENTA A BUSCAR: ";
    cin>>num;
    system("cls");
    ArchivoVenta arcVen("ventas.dat");
    Venta obj;
    int pos = arcVen.buscarRegistroVentas(num);
    if (pos < 0)
    {
        cout << "EL NUMERO DE VENTA INGRESADO NO EXISTE EN EL ARCHIVO" << endl;
        system("cls");
        return;
    }
    obj = arcVen.leerRegistroVentas(pos);
    obj.Mostrar();
}

void bajaLogicaVenta()
{
    ArchivoVenta arcVen;

    int num;
    cout<<"INGRESE EL NUMERO DE VENTA A DAR DE BAJA: ";
    cin>>num;
    int pos=arcVen.buscarRegistroVentas(num);
    if(pos<0)
    {
        cout<<"EL NUMERO DE VENTA INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Venta obj;
    obj = arcVen.leerRegistroVentas(pos);
    obj.Mostrar();
    cout<<"¿DESEA BORRAR EL REGISTRO?(S/N): ";
    char respuesta;
    cin>>respuesta;
    if (respuesta == 'S' || respuesta == 's')
    {
        obj.setEstado(false);
        if(arcVen.modificarRegistroVentas(obj, pos))
        {
            cout<<"EL REGISTRO FUE ELIMINADO CON EXITO"<<endl;
        }
        else
        {
            cout<<"EL REGISTRO NO PUDO SER ELIMINADO"<<endl;
        }
    }
    else return;
}
#endif // FUNCIONESVENTA_H_INCLUDED
