#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

void cargarCadena(char *pal, int tam);
void ocultarCursor();
void mostrarCursor();
void gotoxy(short x, short y);
void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea, short colorFondo);
void hora();

/*FUNCIONES EMPLEADOS*/
int numeroAutomaticoEmpleados();
void listarEmpleados();
void altaEmpleados();
void modificarRegistroFechaEmpleado();
void bajaLogicaEmpleados();
void buscarRegistroEmpleados();

/*FUNCIONES CLIENTES*/
int numeroAutomaticoCliente();
void listarClientes();
void altaClientes();
void modificarRegistroFechaCliente();
void bajaLogicaCliente();
void buscarRegistroCliente();

/*FUNCIONES PEDIDOS*/
double obtenerPrecio(int id);
int numeroAutomaticoPedidos();
bool numeroVerificadoCliente(int n);
bool numeroVerificadoEmpleado(int n);
bool numeroVerificadoCarta(int n);
void listarPedidos();
void altaPedido();
void modificarMetodoPago();
void bajaLogicaPedidos();
void buscarRegistroPedidos();

/*FUNCIONES VENTAS*/
bool numeroVerificadoPlato(int n);
void listarVentas();
void altaVentas();
void modificarPrecioTotal();
void buscarRegistroVenta();
void bajaLogicaVenta();
bool existeNumeroPedido(int numeroPedido);

/*FUNCIONES CARTA*/
void listarCarta();
void altaCarta();
void modificarCarta();
void bajaLogicaCarta();
void buscarRegistroCarta();

/*FUNCIONES CONFIGURACION*/
bool establecerDatosEmpleados();
bool establecerDatosClientes();
bool establecerDatosCarta();
bool establecerDatosPedidos();
bool establecerDatosVentas();
void establecerDatosdeInicio();
void backupEmpleados();
void backupClientes();
void backupCarta();
void backupPedidos();
void backupVentas();
void restaurarEmpleados();
void restaurarClientes();
void restaurarCarta();
void restaurarPedidos();
void restaurarVentas();

#endif // PROTOTIPOS_H_INCLUDED
