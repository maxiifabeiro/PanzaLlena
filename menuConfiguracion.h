#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

void menuConfiguracion(){
    ocultarCursor();
    while(true){
        system("cls");
        int opc;
        recuadro(40, 7, 58, 20, cAMARILLO, cNEGRO);
        gotoxy(45,9);
        cout<<"MENU CONFIGURACION"<<endl;
        linecolor(45,10,22,cAMARILLO);
        gotoxy(45,11);
        cout<<"1 - COPIA DE SEGURIDAD DE ARCHIVO DE EMPLEADOS "<<endl;
        gotoxy(45,12);
        cout<<"2 - COPIA DE SEGURIDAD DE ARCHIVO DE CLIENTES"<<endl;
        gotoxy(45,13);
        cout<<"3 - COPIA DE SEGURIDAD DE ARCHIVO DE CARTA"<<endl;
        gotoxy(45,14);
        cout<<"4 - COPIA DE SEGURIDAD DE ARCHIVO PEDIDOS "<<endl;
        gotoxy(45,15);
        cout<<"5 - COPIA DE SEGURIDAD DE ARCHIVO VENTAS "<<endl;
        gotoxy(45,16);
        cout<<"6 - RESTAURAR ARCHIVO DE EMPLEADOS "<<endl;
        gotoxy(45,17);
        cout<<"7 - RESTAURAR ARCHIVO DE CLIENTES"<<endl;
        gotoxy(45,18);
        cout<<"8 - RESTAURAR ARCHIVO DE CARTA"<<endl;
        gotoxy(45,19);
        cout<<"9 - RESTAURAR ARCHIVO DE PEDIDOS "<<endl;
        gotoxy(45,20);
        cout<<"10 - RESTAURAR ARCHIVO DE VENTAS "<<endl;
        gotoxy(45,21);
        cout<<"11 - ESTABLECER DATOS DE INICIO"<<endl;
        linecolor(45,22,22,cAMARILLO);
        gotoxy(45,23);
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        gotoxy(45,25);
        linecolor(45,25,22,cAMARILLO);
        gotoxy(45,26);
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                backupEmpleados();
                break;
            case 2:
                backupClientes();
                break;
            case 3:
                backupCarta();
                break;
            case 4:
                backupPedidos();
                break;
            case 5:
                backupVentas();
                break;
            case 6:
                restaurarEmpleados();
                break;
            case 7:
                restaurarClientes();
                break;
            case 8:
                restaurarCarta();
                break;
            case 9:
                restaurarPedidos();
                break;
            case 10:
                restaurarVentas();
                break;
            case 11:
                establecerDatosdeInicio();
                break;
            case 0:
                return;
            default:
                cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
                system("pause");
                break;
        }
        system("pause");
    }
}


#endif // MENUCONFIGURACION_H_INCLUDED
