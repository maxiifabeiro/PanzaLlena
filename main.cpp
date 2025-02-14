#include <iostream>
#include <cstring>
#include <ctime>
#include "rlutil.h"

using namespace std;

#include "prototipos.h"
#include "funcionesGlobales.h"
#include "clsFecha.h"
#include "clsEmpleados.h"
#include "clsCliente.h"
#include "clsCarta.h"
#include "clsPedido.h"
#include "ClsVenta.h"
#include "clsArchivoEmpleados.h"
#include "clsArchivoClientes.h"
#include "clsArchivoCarta.h"
#include "clsArchivoPedidos.h"
#include "clsArchivoVenta.h"
#include "funcionesEmpleados.h"
#include "funcionesClientes.h"
#include "funcionesCarta.h"
#include "funcionesPedidos.h"
#include "funcionesVenta.h"
#include "funcionesConfiguracion.h"
#include "menuEmpleados.h"
#include "menuCliente.h"
#include "menuCarta.h"
#include "menuPedidos.h"
#include "menuVentas.h"
#include "menuConfiguracion.h"
#include "reportes.h"

int main(){
    ocultarCursor();
    while(true){
        int opc;
        recuadro(40, 7, 40, 16, cAMARILLO, cNEGRO);
        gotoxy(45,8);
        hora();
        linecolor(45,9,22,cAMARILLO);
        gotoxy(45,10);
        cout<<"MENU PRINCIPAL"<<endl;
        linecolor(45,11,22,cAMARILLO);
        gotoxy(45,12);
        cout<<"1 - MENU EMPLEADOS"<<endl;
        gotoxy(45,13);
        cout<<"2 - MENU CLIENTE"<<endl;
        gotoxy(45,14);
        cout<<"3 - MENU CARTA"<<endl;
        gotoxy(45,15);
        cout<<"4 - MENU PEDIDO"<<endl;
        gotoxy(45,16);
        cout<<"5 - MENU VENTAS"<<endl;
        gotoxy(45,17);
        cout<<"6 - MENU CONFIGURACION"<<endl;
        gotoxy(45,18);
        cout<<"7 - MENU REPORTES"<<endl;
        gotoxy(45,19);
        cout<<"0 - SALIR"<<endl;
        gotoxy(45,20);
        linecolor(45,21,22,cAMARILLO);
        gotoxy(45,22);
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                menuEmpleados();
                break;
            case 2:
                menuCliente();
                break;
            case 3:
                menuCarta();
                break;
            case 4:
                menuPedidos();
                break;
            case 5:
                menuVentas();
                break;
            case 6:
                menuConfiguracion();
                break;
            case 7:
                menuReportes();
                break;
            case 0:
                return 0;
            default:
                cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
                system("pause");
                system("cls");
                break;
        }
    }
    return 0;
}
