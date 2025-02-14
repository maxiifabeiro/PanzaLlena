#ifndef CLSDETALLEVENTA_H_INCLUDED
#define CLSDETALLEVENTA_H_INCLUDED

int numeroAutomaticoDetalle();
int numeroAutomaticoCabeceraVenta();
int numeroAutomaticoPlatoVenta();
bool numeroVerificadoPlato(int n);

class Venta{
private:
    int numeroPedidoVenta;
    double totalPrecio;
    Fecha fechaVenta;
    bool estado;
public:
    Venta();

    void setNumeroPedidoVenta(int np) { numeroPedidoVenta = np;}
    void setTotalPrecio(double p) { totalPrecio = p; }
    void setFechaVenta(Fecha f){fechaVenta = f;}
    void setEstado(bool e) { estado = e; }
    int getNumeroPedidoVenta(){ return numeroPedidoVenta;}
    double getTotalPrecio(){return totalPrecio;}
    Fecha getFechaVenta (){return fechaVenta;}
    bool getEstado(){ return estado; }

    void Mostrar();
/// si una venta es mas grande que otra monetariamente
    bool operator >(Venta &ven){
    if (totalPrecio > ven.getTotalPrecio())
    {
    return true;
    }else return false;

    }
};

Venta::Venta(){estado = false;}

void Venta::Mostrar(){
    if (estado) {
        cout << "ID DE VENTA: " << numeroPedidoVenta << endl;
        cout << "FECHA DE VENTA: ";
        fechaVenta.Mostrar();
        cout << "PRECIO FINAL: $" << totalPrecio << endl;
    }
}

#endif // CLSDETALLEVENTA_H_INCLUDED
