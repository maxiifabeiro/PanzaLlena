#ifndef MENUPEDIDOS_H_INCLUDED
#define MENUPEDIDOS_H_INCLUDED

void menuPedidos(){
    ArchivoPedidos arcPed("pedidos.dat");
    while(true){
        system("cls");
        int opc;
        recuadro(40, 7, 40, 16, cAMARILLO, cNEGRO);
        gotoxy(45,9);
        cout<<"MENU PEDIDOS"<<endl;
        linecolor(45,10,22,cAMARILLO);
        gotoxy(45,11);
        cout<<"1 - AGREGAR NUEVO PEDIDO"<<endl;
        gotoxy(45,12);
        cout<<"2 - LISTAR PEDIDO POR NUMERO"<<endl;
        gotoxy(45,13);
        cout<<"3 - LISTAR TODOS LOS PEDIDOS"<<endl;
        gotoxy(45,14);
        cout<<"4 - MODIFICAR METODO DE PAGO"<<endl;
        gotoxy(45,15);
        cout<<"5 - ELIMINAR PEDIDO"<<endl;
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
                altaPedido();
                break;
            case 2:
                buscarRegistroPedidos();
                break;
            case 3:
                listarPedidos();
                break;
            case 4:
              modificarMetodoPago();
                break;
            case 5:
               bajaLogicaPedidos();
                break;
            case 0:
                return;
            default:
                cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
                system("pause");
                system("cls");
                break;
        }
        system("pause");
    }
}



#endif // MENUPEDIDOS_H_INCLUDED
