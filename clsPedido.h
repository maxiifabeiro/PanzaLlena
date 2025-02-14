#ifndef CLSPEDIDO_H_INCLUDED
#define CLSPEDIDO_H_INCLUDED
#include <cstring>

/*METODO DE PAGO
1- EFECTIVO
2- DEBITO
3- CREDITO*/

int numeroAutomaticoPedidos();
bool numeroVerificadoCliente(int n);
bool numeroVerificadoEmpleado(int n);
bool numeroVerificadoCarta(int n);
double obtenerPrecio(int id);


class Pedido {
private:
    Fecha fecha;
    int numeroPedido;
    int numeroCliente;
    int idEmpleado;
    int idCarta;
    int metodoPago;
    char detallePedido[30];
    int cantidad;
    char agregado;
    double extra;
    double total;
    bool estado;
public:

    Pedido();

    void setFecha(Fecha f){fecha = f;}
    void setNumeroPedido(int numP){numeroPedido = numP;}
    void setNumeroCliente(int numC){numeroCliente = numC;}
    void setIdEmpleado(int idEmp){idEmpleado = idEmp;}
    void setIdCarta(int idCartaVenta){idCarta = idCartaVenta;}
    void setMetodoPago(int metPago){metodoPago = metPago;}
    void setDetallePedido(const char* detalleP){strcpy(detallePedido, detalleP);}
    void setCantidad(int c){cantidad = c;}
    void setAgregado(char a){agregado = a;}
    void setExtra(double e){extra = e;}
    void setTotal(double t){total = t;}
    void setEstado(bool e){estado = e;}

    Fecha getFecha(){return fecha;}
    int getNumeroPedido(){return numeroPedido;}
    int getNumeroCliente(){return numeroCliente;}
    int getIdEmpleado(){return idEmpleado;}
    int getIdCarta(){return idCarta;}
    int getMetodoPago(){return metodoPago;}
    const char*getDetallePedido(){return detallePedido;}
    int getCantidad(){return cantidad;}
    char getAgregado(){return agregado;}
    double getExtra(){return extra;}
    double getTotal(){return total;}
    bool getEstado(){return estado;}

    // Sobrecarga del operador ==
    bool operator==(const Pedido& otro) const {
        return fecha == otro.fecha &&
               numeroPedido == otro.numeroPedido &&
               numeroCliente == otro.numeroCliente &&
               idEmpleado == otro.idEmpleado &&
               idCarta == otro.idCarta &&
               metodoPago == otro.metodoPago &&
               strcmp(detallePedido, otro.detallePedido) == 0 &&
               cantidad == otro.cantidad &&
               agregado == otro.agregado &&
               extra == otro.extra &&
               total == otro.total &&
               estado == otro.estado;
    }

    void Cargar();
    void Mostrar();
    bool agregarArticulos();

};

Pedido::Pedido(){estado = false;}

void Pedido::Cargar() {
    cout << "FECHA: ";
    fecha.Mostrar();
    numeroPedido = numeroAutomaticoPedidos();
    cout << "NUMERO DE PEDIDO: " << numeroPedido << endl;
    cout << "NUMERO DE CLIENTE: ";
    cin >> numeroCliente;
    if (numeroVerificadoCliente(numeroCliente)) {
        cout << "NUMERO CLIENTE EXISTENTE, CONTINUE CON LA CARGA" << endl;
    } else {
        cout << "NUMERO DE CLIENTE INEXISTENTE" << endl;
        return;
    }
    cout << "INGRESE ID DEL EMPLEADO: ";
    cin >> idEmpleado;
    if (numeroVerificadoEmpleado(idEmpleado)) {
        cout << "ID EMPLEADO EXISTENTE, CONTINUE CON LA CARGA" << endl;
    } else {
        cout << "ID EMPLEADO INEXISTENTE" << endl;
        return;
    }
    cout << "INGRESE ID DE LA CARTA: ";
    cin >> idCarta;
        if (numeroVerificadoCarta(idCarta)) {
            cout << "ID CARTA EXISTENTE, CONTINUE CON LA CARGA" << endl;
        } else {
            cout << "ID CARTA INEXISTENTE" << endl;
            return;
        }
    cout<< "CANTIDAD: ";
    cin>>cantidad;
    if (cantidad <=0){
    cout<<"la cantidad debe ser 1 o mas" <<endl;
    return;
    }
    if (idCarta != 5000){
    cout<<"PAPAS(S/N): ";
    cin>> agregado;
    if (agregado == 'S' ||agregado == 's'){
    extra = obtenerPrecio(5000)*cantidad;
    agregado = 1;
    }else {
        extra = 0;
        agregado = 0;
    }
    }else{
    extra = 0;
    agregado = 0;
    }
    cout<<"1- EFECTIVO | 2- DEBITO | 3- CREDITO (15% recargo)"<<endl;
    cout << "INGRESE METODO DE PAGO: ";
    cin >> metodoPago;
    if (metodoPago == 1 || metodoPago == 2 || metodoPago == 3) {
        cout << "METODO CONFIRMADO" << endl;
    } else {
        cout << "METODO DE PAGO INVALIDO" << endl;
        return;
    }
    cout << "DETALLES DEL PEDIDO: ";
    cargarCadena(detallePedido, 29);

    total = ((obtenerPrecio(idCarta)*cantidad)+extra);
    if(metodoPago == 3){
    total =(total + (total*0.15));
    }
    cout<<endl;
    cout<<"PRECIO TOTAL: $"<<total<<endl;

    estado = true;
}

void Pedido::Mostrar(){


    if(estado==true){
    cout<<"FECHA: ";
    fecha.Mostrar();
    cout<<"NUMERO DE PEDIDO: "<<numeroPedido<<endl;
    cout<<"NUMERO DE CLIENTE: "<<numeroCliente<<endl;
    cout<<"ID DEL EMPLEADO: "<<idEmpleado<<endl;
    cout<<"ID DE LA CARTA: "<<idCarta<<endl;
    cout<<"CANTIDAD: "<<cantidad<<endl;
    cout<<"PAPAS: ";
    if(idCarta== 5000){
        cout<<"-"<<endl;
    }else if (agregado == 1){
    cout<<"SI"<<endl;
    }else cout<<"NO"<<endl;
    cout<<"METODO DE PAGO: "<<metodoPago<<endl;
    cout<<"DETALLES DEL PEDIDO: "<<detallePedido<<endl;
    cout<<"PRECIO TOTAL: "<<total<<endl;
}
}
#endif // CLSPEDIDO_H_INCLUDED
