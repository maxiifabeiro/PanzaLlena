#ifndef MENUVENTAS_H_INCLUDED
#define MENUVENTAS_H_INCLUDED

void menuVentas(){
    while(true){
        system("cls");
        int opc;
        recuadro(40, 7, 40, 16, cAMARILLO, cNEGRO);
        gotoxy(45,9);
        cout<<"MENU VENTAS"<<endl;
        linecolor(45,10,22,cAMARILLO);
        gotoxy(45,11);
        cout<<"1 - AGREGAR VENTAS DEL DIA"<<endl;
        gotoxy(45,12);
        cout<<"2 - LISTAR VENTA POR NUMERO"<<endl;
        gotoxy(45,13);
        cout<<"3 - LISTAR TODAS LAS VENTAS"<<endl;
        gotoxy(45,14);
        cout<<"4 - MODIFICAR VALOR $ DE LA VENTA"<<endl;
        gotoxy(45,15);
        cout<<"5 - ELIMINAR VENTA"<<endl;
        gotoxy(45,16);
        cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl;
        gotoxy(45,17);
        linecolor(45,18,22,cAMARILLO);
        gotoxy(45,19);
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                altaVentas();
                break;
            case 2:
                buscarRegistroVenta();
                break;
            case 3:
                listarVentas();
                break;
            case 4:
                modificarPrecioTotal();
                break;
            case 5:
                bajaLogicaVenta();
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



#endif // MENUVENTAS_H_INCLUDED
